/*
 * Copyright (c) 2003-2018, Great Software Laboratory Pvt. Ltd.
 * Copyright (c) 2017 Intel Corporation
 * Copyright (c) 2019, Infosys Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#include "err_codes.h"
#include "options.h"
#include "ipc_api.h"
#include "main.h"
#include "s1ap.h"
#include "s1ap_config.h"
#include "sctp_conn.h"
#include "s1ap_structs.h"
#include "s1ap_msg_codes.h"
#include "msgType.h"


extern int g_enb_fd;
extern int g_sctp_fd;
extern ipc_handle ipc_S1ap_Hndl;

int
s1_attach_complete_handler(struct proto_IE *s1_esm_resp_ies)
{
	struct s1_incoming_msg_data_t attachComplete= {0};

	/*****Message structure***
	*/
	log_msg(LOG_INFO, "Parse s1ap-nas attach complete message:--\n");

	/*Validate all eNB info*/

	/*Create Q structure for stage 1 to MME.
	  contains init UE information.*/
	attachComplete.msg_type = attach_complete;	
	for(int i = 0; i < s1_esm_resp_ies->no_of_IEs; i++)
    {
        switch(s1_esm_resp_ies->data[i].IE_type)
        {
            case S1AP_IE_MME_UE_ID:
                {
	                attachComplete.ue_idx = s1_esm_resp_ies->data[i].val.mme_ue_s1ap_id;
                }break;
            default:
                log_msg(LOG_WARNING,"Unhandled IE");
        }
    }
	
    attachComplete.msg_data.attach_complete_Q_msg_m.status = SUCCESS;
	
	
	attachComplete.destInstAddr = htonl(mmeAppInstanceNum_c);
	attachComplete.srcInstAddr = htonl(s1apAppInstanceNum_c);

	int i = send_tipc_message(ipc_S1ap_Hndl, mmeAppInstanceNum_c, (char *)&attachComplete, S1_READ_MSG_BUF_SIZE);

	if (i < 0) {
		log_msg(LOG_ERROR, "Error to write in s1_attach_complete_handler\n");
	} else {
		/*Send S1Setup response*/
		log_msg(LOG_INFO, "Attach complete send to mme-app stage8. Bytes send %d\n", i);
	}

	//TODO: free IEs
	return SUCCESS;
}

