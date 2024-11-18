#ifndef VEHICLEASS2_H
#define VEHICLEASS2_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "Constant.h"
#include "ChargingStation.h"

using namespace std;

class Vehicle
{
private:
    int vehicleId;
    int currentCityId;
    int destinationId;
    int capacityRange;
    int remainRange;
    int firstStation;
    int secondStation;
    // vector<int> chargingStations; //IGNORE

public:
    Vehicle(int vehicleId, int currentCityId, int destinationId, int capacityRange, int remainRange) //constructor
    {
        this->vehicleId = vehicleId;
        this->currentCityId = currentCityId;
        this->destinationId = destinationId;
        this->capacityRange = capacityRange;
        this->remainRange = remainRange;
    }
    
    void setFirstStation(int firstStation)
    {
        this->firstStation = firstStation;
    }
    void setSecondStation(int secondStation)
    {
        this->secondStation = secondStation;
    }

    // void displayVehicleInfo(); //IGNORE
    // int calcFarthestCity(); // IGNORE 
    int getFirstStation()
    {
        return firstStation;
    }
    int getSecondStation()
    {
        return secondStation;
    }
    int getVehicleId()
    {
        return vehicleId;
    }
    int getRemainRange()
    {
        return remainRange;
    }
    int getDestinationId()
    {
        return destinationId;
    }
    int getCurrentCityId()
    {
        return currentCityId;
    }
    int getCapacity()
    {
        return capacityRange;
    }
};

// int Vehicle::calcFarthestCity() // IGNORE 
// {
//     int distance = 0;
//     int remainRange = this->remainRange;
//     int currentCityId = this->currentCityId;
//     int destinationId = this->destinationId;

//     for (int i = currentCityId; i <= destinationId; i++)
//     {

//         if (remainRange < 0)
//         {

//             return distance;
//         }

//         distance = distance + distanceMap[i];
//         remainRange = remainRange - distanceMap[i];
//     }

//     return distance;
// }

#endif