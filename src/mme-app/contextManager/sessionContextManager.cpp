 /*
 * Copyright 2020-present Infosys Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */ 
/******************************************************************************
 * sessionContextManager.cpp
 * This is an auto generated file.
 * Please do not edit this file.
 * All edits to be made through template source file
 * <TOP-DIR/scripts/SMCodeGen/templates/ctxtManagerTmpls/blockPoolManager.cpp.tt>
 ******************************************************************************/

#include "memPoolManager.h"
#include "contextManager/dataBlocks.h"
#include "contextManager/sessionContextManager.h"

using namespace cmn::memPool;

namespace mme
{
	/******************************************************************************
	* Constructor
	******************************************************************************/
	SessionContextManager::SessionContextManager(int numOfBlocks):poolManager_m(numOfBlocks)
	{
	}
	
	/******************************************************************************
	* Destructor
	******************************************************************************/
	SessionContextManager::~SessionContextManager()
	{
	}
	
	/******************************************************************************
	* Allocate SessionContext data block
	******************************************************************************/
	SessionContext* SessionContextManager::allocateSessionContext()
	{
		SessionContext* SessionContext_p = poolManager_m.allocate();
		return SessionContext_p;
	}
	
	/******************************************************************************
	* Deallocate a SessionContext data block
	******************************************************************************/
	void SessionContextManager::deallocateSessionContext(SessionContext* SessionContextp )
	{
		poolManager_m.free( SessionContextp );
	}
}