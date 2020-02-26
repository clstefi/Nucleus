 /*
 * Copyright 2019-present, Infosys Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
 /******************************************************
 * niDetachWfS1RelComp.h
 * This is an auto generated file.
 * Please do not edit this file.
 * All edits to be made through template source file
 * <TOP-DIR/scripts/SMCodeGen/templates/stateMachineTmpls/state.h.tt>
 ******************************************************/
 
#ifndef __NiDetachWfS1RelComp__
#define __NiDetachWfS1RelComp__

#include "state.h"

namespace mme {

	class NiDetachWfS1RelComp : public SM::State
	{
		public:
			/******************************************
			* Instance 
			*    Creates static instance for the state
			*******************************************/
			static NiDetachWfS1RelComp* Instance();

			/****************************************
			* NiDetachWfS1RelComp
			*    Destructor
			****************************************/
			~NiDetachWfS1RelComp();			
			
			/******************************************
			* initialize
			*  Initializes action handlers for the state
			* and next state
			******************************************/
			void initialize();
	
		private:
			/****************************************
			* NiDetachWfS1RelComp
			*    Private constructor
			****************************************/
			NiDetachWfS1RelComp();  
	};
};
#endif // __NiDetachWfS1RelComp__
