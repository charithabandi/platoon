//
// Copyright (C) 2012-2021 Michele Segata <segata@ccs-labs.org>
//
// SPDX-License-Identifier: GPL-2.0-or-later
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#include "plexe/maneuver/ExitAtBack.h"
#include "plexe/apps/GeneralPlatooningApp.h"

namespace plexe {

ExitAtBack::ExitAtBack(GeneralPlatooningApp* app)
    : JoinAtBack(app)
{
}

ExitAtBack::~ExitAtBack()
{}

void ExitAtBack::startManeuver(const void* parameters)
{
	//Create a packet informing the front car that you want to leave
	//on receiving the message, the front car will update its information and send an ack
	//on receiving the ack, the car moves to the next lane and changes it platoon info
	// Do we need to broadcast the platoon change info to all other cars?
	// We have to if we are using that information in any of the joins

	printf("Exit Platoon: [%d]\n", positionHelper->getId());	
	ExitPlatoonRequest *req = createExitPlatoonRequest(positionHelper->getId(), positionHelper->getExternalId(), 
							   positionHelper->getPlatoonId(), positionHelper->getFrontId(), 
							   traciVehicle->getLaneIndex(), positionHelper->getFrontId());
	app->sendUnicast(req, positionHelper->getFrontId());
}

void ExitAtBack::handleExitPlatoonRequest(const ExitPlatoonRequest* msg)
{
	printf("[%d] Received PlatoonRequest from [%d]\n", positionHelper->getId(), msg->getVehicleId());
	// The message should be received by the front car to the sender.
	//bool permitted = true;
	if (app->isInManeuver()) return;
	if (positionHelper->getId() != msg->getFrontId()) return;
	if (traciVehicle->getLaneIndex() != msg->getCurrentLaneIndex()) return;
	positionHelper->setBackId(-1);
	ExitPlatoonResponse *resp = createExitPlatoonResponse(positionHelper->getId(), positionHelper->getExternalId(),
							      positionHelper->getPlatoonId(), msg->getVehicleId(),
							      traciVehicle->getLaneIndex());
	printf("[%d] send PlatoonResponse to [%d]", positionHelper->getId(), msg->getVehicleId());
	app->sendUnicast(resp, msg->getVehicleId()); 
}

void ExitAtBack::handleExitPlatoonResponse(const ExitPlatoonResponse* msg)
{

	//change lane
	//set mode to ACC
	//remove the frontId
	printf("[%d] Received PlatoonResponse from [%d]\n", positionHelper->getId(), msg->getVehicleId());
	positionHelper->setFrontId(-1);
	positionHelper->setPlatoonId(msg->getPlatoonId()+1);
	//positionHelper->setPlatoonLane(msg->getCurrentLaneIndex() + 1);
	plexeTraciVehicle->setFixedLane(msg->getCurrentLaneIndex() + 1);
	app->setPlatoonRole(PlatoonRole::NONE);
	plexeTraciVehicle->setActiveController(ACC);
/*
        ExitPlatoonResponseAck* ack = createExitPlatoonResponseAck(positionHelper->getId(), positionHelper->getExternalId(), 
                                                                   positionHelper->getPlatoonId(), msg->getVehicleId(), 
                                                                   );
        app->sendUnicast(ack, msg->getVehicleId());
    }
*/
}

bool ExitAtBack::handleSelfMsg(cMessage* msg)
{
return 0;	
}
} // namespace plexe
