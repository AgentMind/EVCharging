#include <iostream>
#include "ChargingStation.h"
#include "Vehicle.h"
#include "DemandGenerator.h"
#include "ChargingAllocation.h"

using namespace std;

int main()
{

    DemandGenerator dg;

    dg.generateRandomDemand();

    ChargingAllocation ca;

    ca.readVehicles();
    ca.chargeMain();
}
