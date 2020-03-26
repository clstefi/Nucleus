  
/*
 * Copyright 2019-present Infosys Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */
 
/**************************************
 * detachStart.cpp
 * This is an auto generated file.
 * Please do not edit this file.
 * All edits to be made through template source file
 * <TOP-DIR/scripts/SMCodeGen/templates/stateMachineTmpls/state.cpp.tt>
 **************************************/

#include "mmeSmDefs.h"
#include "actionTable.h"
#include "actionHandlers/actionHandlers.h"

#include "mmeStates/detachStart.h"	
#include "mmeStates/detachWfDelSessionResp.h"

using namespace mme;
using namespace SM;

/******************************************************************************
* Constructor
******************************************************************************/
DetachStart::DetachStart():State(detach_start)
{
}

/******************************************************************************
* Destructor
******************************************************************************/
DetachStart::~DetachStart()
{
}

/******************************************************************************
* creates and returns static instance
******************************************************************************/
DetachStart* DetachStart::Instance()
{
        static DetachStart state;
        return &state;
}

/******************************************************************************
* initializes eventToActionsMap
******************************************************************************/
void DetachStart::initialize()
{
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::del_session_req);
                actionTable.setNextState(DetachWfDelSessionResp::Instance());
                eventToActionsMap.insert(pair<uint16_t, ActionTable>(DETACH_REQ_FROM_UE, actionTable));
        }
}
