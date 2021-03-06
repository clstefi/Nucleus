/*
 * Copyright 2020-present Infosys Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */
 
 /******************************************************
 * dedDeactWfSessionTearup.h
 * This is an auto generated file.
 * Please do not edit this file.
 * All edits to be made through template source file
 * <TOP-DIR/scripts/SMCodeGen/templates/stateMachineTmpls/state.h.tt>
 ******************************************************/
 
#ifndef __DedDeactWfSessionTearup__
#define __DedDeactWfSessionTearup__

#include "state.h"

namespace mme {

	class DedDeactWfSessionTearup : public SM::State
	{
		public:
			/******************************************
			* Instance 
			*    Creates static instance for the state
			*******************************************/
			static DedDeactWfSessionTearup* Instance();

			/****************************************
			* DedDeactWfSessionTearup
			*    Destructor
			****************************************/
			~DedDeactWfSessionTearup();			
			
			/******************************************
			* initialize
			*  Initializes action handlers for the state
			* and next state
			******************************************/
			void initialize();
	
		private:
			/****************************************
			* DedDeactWfSessionTearup
			*    Private constructor
			****************************************/
			DedDeactWfSessionTearup();  
	};
};
#endif // __DedDeactWfSessionTearup__
