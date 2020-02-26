  
/*
 * Copyright 2019-present Infosys Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */
 
/**************************************
 * attachWfAuthRespValidate.cpp
 * This is an auto generated file.
 * Please do not edit this file.
 * All edits to be made through template source file
 * <TOP-DIR/scripts/SMCodeGen/templates/stateMachineTmpls/state.cpp.tt>
 **************************************/

#include "smEnumTypes.h"
#include "actionTable.h"
#include "actionHandlers/actionHandlers.h"

#include "mmeStates/attachWfAuthRespValidate.h"	
#include "mmeStates/attachWfSecCmp.h"	
#include "mmeStates/attachWfAia.h"

using namespace mme;
using namespace SM;

/******************************************************************************
* Constructor
******************************************************************************/
AttachWfAuthRespValidate::AttachWfAuthRespValidate():State(State_e::attach_wf_auth_resp_validate)
{
}

/******************************************************************************
* Destructor
******************************************************************************/
AttachWfAuthRespValidate::~AttachWfAuthRespValidate()
{
}

/******************************************************************************
* creates and returns static instance
******************************************************************************/
AttachWfAuthRespValidate* AttachWfAuthRespValidate::Instance()
{
        static AttachWfAuthRespValidate state;
        return &state;
}

/******************************************************************************
* initializes eventToActionsMap
******************************************************************************/
void AttachWfAuthRespValidate::initialize()
{
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::sec_mode_cmd_to_ue);
                actionTable.setNextState(AttachWfSecCmp::Instance());
                eventToActionsMap.insert(pair<Event_e, ActionTable>(Event_e::AUTH_RESP_SUCCESS, actionTable));
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::send_air_to_hss);
                actionTable.setNextState(AttachWfAia::Instance());
                eventToActionsMap.insert(pair<Event_e, ActionTable>(Event_e::AUTH_RESP_SYNC_FAILURE, actionTable));
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::send_auth_reject);
                eventToActionsMap.insert(pair<Event_e, ActionTable>(Event_e::AUTH_RESP_FAILURE, actionTable));
        }
}
