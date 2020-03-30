/*
 * timeoutManager.cpp
 *
 *  Created on: Feb 16, 2020
 *      Author: Anjana_Sreekumar
 */

#include "timeoutManager.h"
#include "log.h"

#include <cstring>
#include <stdio.h>
#include <sys/timerfd.h>
#include <unistd.h>

TimeoutManager::Timer::Timer() : fd_m(0)
{
    tspec_m.it_value.tv_sec = defaultTimeoutDurationSeconds_c;
    tspec_m.it_value.tv_nsec = defaultTimeoutDurationNanoSeconds_c;
    tspec_m.it_interval.tv_sec = defaultTimeoutDurationSeconds_c;
    tspec_m.it_interval.tv_nsec = defaultTimeoutDurationNanoSeconds_c;

    initTimer();
}

TimeoutManager::Timer::Timer(const struct itimerspec &tspec) : fd_m(0)
{
    memcpy(&tspec_m, &tspec, sizeof(struct itimerspec));

    initTimer();
}

TimeoutManager::Timer::~Timer()
{
}

void TimeoutManager::Timer::initTimer()
{
    fd_m = timerfd_create(CLOCK_MONOTONIC, 0);
    if (fd_m <= 0)
    {
        log_msg(LOG_ERROR, "Failed to create timer\n");	    
    }
    else
    {
        log_msg(LOG_DEBUG, "Timer created successfully\n");
    }	
}

bool TimeoutManager::Timer::startTimer()
{
    log_msg(LOG_DEBUG, "TimeoutManager::Timer::startTimer() ENTRY\n");    

    bool rc = false;

    if (fd_m != 0)
    {
        if (timerfd_settime(fd_m, 0, &tspec_m, NULL) == -1)
        {
            log_msg(LOG_ERROR, "Failed to set timeout duration\n");

            rc = false;

            // thread abort.
        }
    }

    log_msg(LOG_DEBUG,"TimeoutManager::Timer::startTimer()-EXIT\n");

    return rc;
}

bool TimeoutManager::Timer::stopTimer()
{
    bool rc = false;
    log_msg(LOG_DEBUG,"TimeoutManager::Timer::stopTimer-ENTRY\n");

    if (fd_m != 0)
    {
        struct itimerspec next_timeout;

        next_timeout.it_value.tv_sec = 0;
        next_timeout.it_value.tv_nsec = 0;
        next_timeout.it_interval.tv_sec = 0;
        next_timeout.it_interval.tv_nsec = 0;

        if (timerfd_settime(fd_m, 0, &next_timeout, NULL) == -1)
        {
            log_msg(LOG_ERROR,"Failed to set timeout duration\n");
            rc = false;

            // thread abort.
        }
    }
    log_msg(LOG_DEBUG,"TimeoutManager::Timer::stopTimer-EXIT\n");
    return rc;
}

int TimeoutManager::Timer::getTimerFd() const
{
    return fd_m;
}

TimeoutManager::TimeoutManager(Callback appCb):
        timerQueue_m(), timer_m()
{
    appCb_m = appCb;
    thread_m = std::thread([this] { run(); });
}

TimeoutManager::~TimeoutManager()
{

}

void TimeoutManager::startTimer(TimerContext* timer_p)
{
    timerQueue_m.add(timer_p);
}

uint32_t TimeoutManager::cancelTimer(TimerContext* timer_p)
{
    return timerQueue_m.remove(timer_p);
}

void TimeoutManager::run()
{
    log_msg(LOG_DEBUG, "Run TimeoutManager\n");

    timer_m.startTimer();

    uint32_t bytesRead = 0;
    size_t dataSize = sizeof(uint64_t);
    uint64_t expiryCount = 0;

    while (true)
    {
        bytesRead = read(timer_m.getTimerFd(), &expiryCount, dataSize);
        if (bytesRead > 0)
            timerQueue_m.onTimer(appCb_m);
    }
}
