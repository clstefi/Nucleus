
/*
 * Copyright 2020-present Infosys Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */
 
/**************************************
 * defaultMmeState.cpp
 * This is an auto generated file.
 * Please do not edit this file.
 * All edits to be made through template source file
 * <TOP-DIR/scripts/SMCodeGen/templates/stateMachineTmpls/state.cpp.tt>
 **************************************/


#include "actionTable.h"
#include "actionHandlers/actionHandlers.h"
#include "mmeSmDefs.h"
#include "utils/mmeStatesUtils.h"
#include "utils/mmeTimerTypes.h"

#include "mmeStates/defaultMmeState.h"

using namespace mme;
using namespace SM;

/******************************************************************************
* Constructor
******************************************************************************/
DefaultMmeState::DefaultMmeState():State(default_mme_state)
{
        stateEntryAction = &MmeStatesUtils::on_state_entry;
        stateExitAction = &MmeStatesUtils::on_state_exit;
        eventValidator = &MmeStatesUtils::validate_event;
}

/******************************************************************************
* Destructor
******************************************************************************/
DefaultMmeState::~DefaultMmeState()
{
}

/******************************************************************************
* creates and returns static instance
******************************************************************************/
DefaultMmeState* DefaultMmeState::Instance()
{
        static DefaultMmeState state;
        return &state;
}

/******************************************************************************
* initializes eventToActionsMap
******************************************************************************/
void DefaultMmeState::initialize()
{
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::default_attach_req_handler);
                eventToActionsMap.insert(pair<uint16_t, ActionTable>(ATTACH_REQ_FROM_UE, actionTable));
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::default_detach_req_handler);
                eventToActionsMap.insert(pair<uint16_t, ActionTable>(DETACH_REQ_FROM_UE, actionTable));
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::default_s1_release_req_handler);
                eventToActionsMap.insert(pair<uint16_t, ActionTable>(S1_REL_REQ_FROM_UE, actionTable));
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::default_ddn_handler);
                eventToActionsMap.insert(pair<uint16_t, ActionTable>(DDN_FROM_SGW, actionTable));
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::default_service_req_handler);
                eventToActionsMap.insert(pair<uint16_t, ActionTable>(SERVICE_REQUEST_FROM_UE, actionTable));
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::default_cancel_loc_req_handler);
                eventToActionsMap.insert(pair<uint16_t, ActionTable>(CLR_FROM_HSS, actionTable));
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::default_tau_req_handler);
                eventToActionsMap.insert(pair<uint16_t, ActionTable>(TAU_REQUEST_FROM_UE, actionTable));
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::default_s1_ho_handler);
                eventToActionsMap.insert(pair<uint16_t, ActionTable>(HO_REQUIRED_FROM_ENB, actionTable));
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::default_erab_mod_indication_handler);
                eventToActionsMap.insert(pair<uint16_t, ActionTable>(ERAB_MOD_INDICATION_FROM_ENB, actionTable));
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::default_create_bearer_req_handler);
                eventToActionsMap.insert(pair<uint16_t, ActionTable>(CREATE_BEARER_REQ_FROM_GW, actionTable));
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::handle_paging_failure);
                eventToActionsMap.insert(pair<uint16_t, ActionTable>(PAGING_FAILURE, actionTable));
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::default_delete_bearer_req_handler);
                eventToActionsMap.insert(pair<uint16_t, ActionTable>(DELETE_BEARER_REQ_FROM_GW, actionTable));
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::handle_detach_failure);
                eventToActionsMap.insert(pair<uint16_t, ActionTable>(DETACH_FAILURE, actionTable));
        }
}
