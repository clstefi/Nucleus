

/*
 * Copyright 2021-present Infosys Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */
 
/**************************************
 * s1HandoverStates.cpp
 * This is an auto generated file.
 * Please do not edit this file.
 * All edits to be made through template source file
 * <TOP-DIR/scripts/SMCodeGen/templates/stateMachineTmpls/state.cpp.tt>
 **************************************/


#include "actionTable.h"
#include "actionHandlers/actionHandlers.h"
#include <mmeSmDefs.h>
#include <utils/mmeStatesUtils.h>
#include <utils/mmeTimerTypes.h>

#include "mmeStates/s1HandoverStates.h"

using namespace mme;
using namespace SM;


/******************************************************************************
* Constructor
******************************************************************************/
IntraS1HoStart::IntraS1HoStart():State()
{
        stateEntryAction = &MmeStatesUtils::on_state_entry;
        stateExitAction = &MmeStatesUtils::on_state_exit;
        eventValidator = &MmeStatesUtils::validate_event;
		
}

/******************************************************************************
* Destructor
******************************************************************************/
IntraS1HoStart::~IntraS1HoStart()
{
}

/******************************************************************************
* creates and returns static instance
******************************************************************************/
IntraS1HoStart* IntraS1HoStart::Instance()
{
        static IntraS1HoStart state;
        return &state;
}

/******************************************************************************
* initializes eventToActionsMap
******************************************************************************/
void IntraS1HoStart::initialize()
{
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::send_ho_request_to_target_enb);
                actionTable.setNextState(S1HoWfHoRequestAck::Instance());
                eventToActionsMap[INTRA_S1HO_START] = actionTable;
        }
}

/******************************************************************************
* returns stateId
******************************************************************************/
uint16_t IntraS1HoStart::getStateId()const
{
	return intra_s1_ho_start;
}

/******************************************************************************
* returns stateName
******************************************************************************/
const char* IntraS1HoStart::getStateName()const
{
	return "intra_s1_ho_start";
}

/******************************************************************************
* Constructor
******************************************************************************/
S1HoWfHoRequestAck::S1HoWfHoRequestAck():State()
{
        stateEntryAction = &MmeStatesUtils::on_state_entry;
        stateExitAction = &MmeStatesUtils::on_state_exit;
        eventValidator = &MmeStatesUtils::validate_event;
		
}

/******************************************************************************
* Destructor
******************************************************************************/
S1HoWfHoRequestAck::~S1HoWfHoRequestAck()
{
}

/******************************************************************************
* creates and returns static instance
******************************************************************************/
S1HoWfHoRequestAck* S1HoWfHoRequestAck::Instance()
{
        static S1HoWfHoRequestAck state;
        return &state;
}

/******************************************************************************
* initializes eventToActionsMap
******************************************************************************/
void S1HoWfHoRequestAck::initialize()
{
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::process_ho_request_ack);
                actionTable.addAction(&ActionHandlers::send_ho_command_to_src_enb);
                actionTable.setNextState(S1HoWfHoNotify::Instance());
                eventToActionsMap[HO_REQUEST_ACK_FROM_ENB] = actionTable;
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::process_ho_failure);
                actionTable.addAction(&ActionHandlers::send_ho_prep_failure_to_src_enb);
                actionTable.addAction(&ActionHandlers::abort_handover);
                eventToActionsMap[HO_FAILURE_FROM_TARGET_ENB] = actionTable;
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::send_s1_rel_cmd_to_target_enb);
                actionTable.addAction(&ActionHandlers::send_ho_prep_failure_to_src_enb);
                actionTable.addAction(&ActionHandlers::abort_handover);
                eventToActionsMap[ABORT_EVENT] = actionTable;
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::process_ho_cancel_req);
                actionTable.addAction(&ActionHandlers::send_ho_cancel_ack_to_src_enb);
                actionTable.addAction(&ActionHandlers::abort_handover);
                eventToActionsMap[HO_CANCEL_REQ_FROM_SRC_ENB] = actionTable;
        }
}

/******************************************************************************
* returns stateId
******************************************************************************/
uint16_t S1HoWfHoRequestAck::getStateId()const
{
	return s1_ho_wf_ho_request_ack;
}

/******************************************************************************
* returns stateName
******************************************************************************/
const char* S1HoWfHoRequestAck::getStateName()const
{
	return "s1_ho_wf_ho_request_ack";
}

/******************************************************************************
* Constructor
******************************************************************************/
S1HoWfHoNotify::S1HoWfHoNotify():State()
{
        stateEntryAction = &MmeStatesUtils::on_state_entry;
        stateExitAction = &MmeStatesUtils::on_state_exit;
        eventValidator = &MmeStatesUtils::validate_event;
		
}

/******************************************************************************
* Destructor
******************************************************************************/
S1HoWfHoNotify::~S1HoWfHoNotify()
{
}

/******************************************************************************
* creates and returns static instance
******************************************************************************/
S1HoWfHoNotify* S1HoWfHoNotify::Instance()
{
        static S1HoWfHoNotify state;
        return &state;
}

/******************************************************************************
* initializes eventToActionsMap
******************************************************************************/
void S1HoWfHoNotify::initialize()
{
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::process_ho_notify);
                actionTable.addAction(&ActionHandlers::send_mb_req_to_sgw_for_ho);
                actionTable.setNextState(S1HoWfModifyBearerResponse::Instance());
                eventToActionsMap[HO_NOTIFY_FROM_ENB] = actionTable;
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::send_mme_status_tranfer_to_target_enb);
                actionTable.setNextState(S1HoWfHoNotify::Instance());
                eventToActionsMap[ENB_STATUS_TRANFER_FROM_SRC_ENB] = actionTable;
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::process_ho_cancel_req);
                actionTable.addAction(&ActionHandlers::send_s1_rel_cmd_to_target_enb);
                actionTable.addAction(&ActionHandlers::send_ho_cancel_ack_to_src_enb);
                actionTable.addAction(&ActionHandlers::abort_handover);
                eventToActionsMap[HO_CANCEL_REQ_FROM_SRC_ENB] = actionTable;
        }
}

/******************************************************************************
* returns stateId
******************************************************************************/
uint16_t S1HoWfHoNotify::getStateId()const
{
	return s1_ho_wf_ho_notify;
}

/******************************************************************************
* returns stateName
******************************************************************************/
const char* S1HoWfHoNotify::getStateName()const
{
	return "s1_ho_wf_ho_notify";
}

/******************************************************************************
* Constructor
******************************************************************************/
S1HoWfModifyBearerResponse::S1HoWfModifyBearerResponse():State()
{
        stateEntryAction = &MmeStatesUtils::on_state_entry;
        stateExitAction = &MmeStatesUtils::on_state_exit;
        eventValidator = &MmeStatesUtils::validate_event;
		
}

/******************************************************************************
* Destructor
******************************************************************************/
S1HoWfModifyBearerResponse::~S1HoWfModifyBearerResponse()
{
}

/******************************************************************************
* creates and returns static instance
******************************************************************************/
S1HoWfModifyBearerResponse* S1HoWfModifyBearerResponse::Instance()
{
        static S1HoWfModifyBearerResponse state;
        return &state;
}

/******************************************************************************
* initializes eventToActionsMap
******************************************************************************/
void S1HoWfModifyBearerResponse::initialize()
{
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::process_mb_resp_for_ho);
                actionTable.addAction(&ActionHandlers::send_s1_rel_cmd_to_src_enb_for_ho);
                actionTable.addAction(&ActionHandlers::is_tau_required);
                actionTable.setNextState(S1HoWfTauCheck::Instance());
                eventToActionsMap[MB_RESP_FROM_SGW] = actionTable;
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::send_mme_status_tranfer_to_target_enb);
                actionTable.setNextState(S1HoWfModifyBearerResponse::Instance());
                eventToActionsMap[ENB_STATUS_TRANFER_FROM_SRC_ENB] = actionTable;
        }
}

/******************************************************************************
* returns stateId
******************************************************************************/
uint16_t S1HoWfModifyBearerResponse::getStateId()const
{
	return s1_ho_wf_modify_bearer_response;
}

/******************************************************************************
* returns stateName
******************************************************************************/
const char* S1HoWfModifyBearerResponse::getStateName()const
{
	return "s1_ho_wf_modify_bearer_response";
}

/******************************************************************************
* Constructor
******************************************************************************/
S1HoWfTauCheck::S1HoWfTauCheck():State()
{
        stateEntryAction = &MmeStatesUtils::on_state_entry;
        stateExitAction = &MmeStatesUtils::on_state_exit;
        eventValidator = &MmeStatesUtils::validate_event;
		
}

/******************************************************************************
* Destructor
******************************************************************************/
S1HoWfTauCheck::~S1HoWfTauCheck()
{
}

/******************************************************************************
* creates and returns static instance
******************************************************************************/
S1HoWfTauCheck* S1HoWfTauCheck::Instance()
{
        static S1HoWfTauCheck state;
        return &state;
}

/******************************************************************************
* initializes eventToActionsMap
******************************************************************************/
void S1HoWfTauCheck::initialize()
{
        {
                ActionTable actionTable;
                actionTable.setNextState(S1HoWfTauRequest::Instance());
                eventToActionsMap[TAU_REQUIRED] = actionTable;
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::ho_complete);
                eventToActionsMap[TAU_NOT_REQUIRED] = actionTable;
        }
}

/******************************************************************************
* returns stateId
******************************************************************************/
uint16_t S1HoWfTauCheck::getStateId()const
{
	return s1_ho_wf_tau_check;
}

/******************************************************************************
* returns stateName
******************************************************************************/
const char* S1HoWfTauCheck::getStateName()const
{
	return "s1_ho_wf_tau_check";
}

/******************************************************************************
* Constructor
******************************************************************************/
S1HoWfTauRequest::S1HoWfTauRequest():State()
{
        stateEntryAction = &MmeStatesUtils::on_state_entry;
        stateExitAction = &MmeStatesUtils::on_state_exit;
        eventValidator = &MmeStatesUtils::validate_event;
		
}

/******************************************************************************
* Destructor
******************************************************************************/
S1HoWfTauRequest::~S1HoWfTauRequest()
{
}

/******************************************************************************
* creates and returns static instance
******************************************************************************/
S1HoWfTauRequest* S1HoWfTauRequest::Instance()
{
        static S1HoWfTauRequest state;
        return &state;
}

/******************************************************************************
* initializes eventToActionsMap
******************************************************************************/
void S1HoWfTauRequest::initialize()
{
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::process_tau_request);
                actionTable.addAction(&ActionHandlers::send_tau_response_to_ue);
                actionTable.addAction(&ActionHandlers::ho_complete);
                eventToActionsMap[TAU_REQUEST_FROM_UE] = actionTable;
        }
}

/******************************************************************************
* returns stateId
******************************************************************************/
uint16_t S1HoWfTauRequest::getStateId()const
{
	return s1_ho_wf_tau_request;
}

/******************************************************************************
* returns stateName
******************************************************************************/
const char* S1HoWfTauRequest::getStateName()const
{
	return "s1_ho_wf_tau_request";
}