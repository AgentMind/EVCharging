#ifndef CHARGINGSTATIONASS2_H
#define CHARGINGSTATIONASS2_H

#include <iostream>
#include <iomanip>

#include "Constant.h"

using namespace std;

class ChargingStation
{
private:
    int cityId;
    string cityName;
    int distanceToLastCity;
    int numberOfChargers;

public:
    ChargingStation(int stationId) //constructor  
    {
        this->distanceToLastCity = distanceMap[stationId];
        this->numberOfChargers = chargersMap[stationId];
        this->cityId = stationId;
        this->cityName = nameMap[stationId];
    }

    void displayStationInfo();
    int distanceToSydney(int cityId);
};

void ChargingStation::displayStationInfo() // display station info
{
    cout << endl
         << "Charging Station Information:" << endl;
    cout << "####################################################################################################" << endl;
    cout << setw(5) << "City ID: " << setw(20) << "City Name: " << setw(30) << "Distance to Sydney: " << setw(30) << "Number of Chargers: " << endl;
    cout << "####################################################################################################" << endl;

    for (int q = 0; q < 12; q++)
    {
        int cityId = q;
        cout << setw(5) << cityId;
        cout << setw(20) << nameMap[q];
        cout << setw(23) << distanceToSydney(q);
        cout << setw(30) << chargersMap[q];
        cout << endl;
    }
}

int ChargingStation::distanceToSydney(int cityId) //calc the distance to sydney
{
    int totalDistance = 0;

    for (int i = 0; i <= cityId; i++)
    {
        totalDistance = totalDistance + distanceMap[i];
    }

    return totalDistance;
}

#endif