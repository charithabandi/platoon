#pragma once

#include <algorithm>

#include "plexe/maneuver/JoinManeuver.h"
#include "plexe/utilities/BasePositionHelper.h"
#include "plexe/maneuver/JoinAtBack.h"
#include "veins/modules/mobility/traci/TraCIConstants.h"
#include "veins/base/utils/Coord.h"

using namespace veins;

namespace plexe {

class ExitAtBack : public JoinAtBack {

public:
    /**
     * Constructor
     *
     * @param app pointer to the generic application used to fetch parameters and inform it about a concluded maneuver
     */
    ExitAtBack(GeneralPlatooningApp* app);
    virtual ~ExitAtBack();
    virtual void startManeuver(const void* parameters) override;

    virtual void handleExitPlatoonRequest(const ExitPlatoonRequest* msg) override;
    virtual void handleExitPlatoonResponse(const ExitPlatoonResponse* msg) override;

    virtual bool handleSelfMsg(cMessage* msg) override;

protected:

};

} // namespace plexe
