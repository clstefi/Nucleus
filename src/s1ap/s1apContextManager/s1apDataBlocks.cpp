/*
 * Copyright 2019-present Infosys Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**************************************
 *
 * This is an auto generated file.
 * Please do not edit this file.
 * All edits to be made through template source file
 * <TOP-DIR/scripts/SMCodeGen/templates/ctxtManagerTmpls/dataBlocks.cpp.tt>
 ***************************************/
#include "s1apContextManager/s1apDataBlocks.h"

namespace mme
{
	/******************************************************************************
	*******************************************************************************
	*							EnbContext
	*******************************************************************************
	******************************************************************************/
	
	/******************************************************************************
	* Constructor
	******************************************************************************/
	EnbContext::EnbContext():           
            enbFd_m(0),
            enbId_m(0),
            s1apEnbUeId_m(0),
            contextID_m(0),
            tai_m(),
            enbnameLen_m(0)
	{
		memset(enbname_m,0,sizeof(enbname_m));
	
	}
	
	/******************************************************************************
	* Destructor
	******************************************************************************/
	EnbContext::~EnbContext()
	{
	}	
	
	/******************************************************************************
	* sets enbFd
	******************************************************************************/
	void EnbContext::setEnbFd( int enbFd_i )
	{
		enbFd_m = enbFd_i;
	}
	
	/******************************************************************************
	* returns enbFd
	******************************************************************************/	
        int EnbContext::getEnbFd() const
        {
                return enbFd_m;
        }

	
	/******************************************************************************
	* sets enbId
	******************************************************************************/
	void EnbContext::setEnbId( int enbId_i )
	{
		enbId_m = enbId_i;
	}
	
	/******************************************************************************
	* returns enbId
	******************************************************************************/	
        int EnbContext::getEnbId() const
        {
                return enbId_m;
        }

	
	/******************************************************************************
	* sets s1apEnbUeId
	******************************************************************************/
	void EnbContext::setS1apEnbUeId( int s1apEnbUeId_i )
	{
		s1apEnbUeId_m = s1apEnbUeId_i;
	}
	
	/******************************************************************************
	* returns s1apEnbUeId
	******************************************************************************/	
        int EnbContext::getS1apEnbUeId() const
        {
                return s1apEnbUeId_m;
        }

	
	/******************************************************************************
	* sets contextID
	******************************************************************************/
	void EnbContext::setContextID( uint32_t contextID_i )
	{
		contextID_m = contextID_i;
	}
	
	/******************************************************************************
	* returns contextID
	******************************************************************************/	
        uint32_t EnbContext::getContextID() const
        {
                return contextID_m;
        }

	
	/******************************************************************************
	* sets tai
	******************************************************************************/
	void EnbContext::setTai( const TAI& tai_i )
	{
		tai_m = tai_i;
	}
	
	/******************************************************************************
	* returns tai
	******************************************************************************/	
        const TAI& EnbContext::getTai() const
        {
                return tai_m;
        }

	
	/******************************************************************************
	* sets enbname
	******************************************************************************/
	void EnbContext::setEnbname( const char* enbname_i,uint16_t len )
	{
		enbnameLen_m=len;
		memcpy(enbname_m, enbname_i, (enbnameLen_m * sizeof(char)));
	}
	
	/******************************************************************************
	* returns enbname
	******************************************************************************/	
        const char* EnbContext::getEnbname() const
        {
                return enbname_m;
        }

	/******************************************************************************
	* returns enbnameLen
	******************************************************************************/	
	uint16_t EnbContext::getEnbnameLen() const
	{
    		return enbnameLen_m;
	}
	
} // mme
