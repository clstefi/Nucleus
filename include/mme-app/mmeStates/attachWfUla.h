/*
 * Copyright 2020-present Infosys Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */
 
 /******************************************************
 * attachWfUla.h
 * This is an auto generated file.
 * Please do not edit this file.
 * All edits to be made through template source file
 * <TOP-DIR/scripts/SMCodeGen/templates/stateMachineTmpls/state.h.tt>
 ******************************************************/
 
#ifndef __AttachWfUla__
#define __AttachWfUla__

#include "state.h"

namespace mme {

	class AttachWfUla : public SM::State
	{
		public:
			/******************************************
			* Instance 
			*    Creates static instance for the state
			*******************************************/
			static AttachWfUla* Instance();

			/****************************************
			* AttachWfUla
			*    Destructor
			****************************************/
			~AttachWfUla();			
			
			/******************************************
			* initialize
			*  Initializes action handlers for the state
			* and next state
			******************************************/
			void initialize();
	
		private:
			/****************************************
			* AttachWfUla
			*    Private constructor
			****************************************/
			AttachWfUla();  
	};
};
#endif // __AttachWfUla__
