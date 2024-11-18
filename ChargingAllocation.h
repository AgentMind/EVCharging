#ifndef CHARGINGALLOCATIONASS2_H
#define CHARGINGALLOCATIONASS2_H

#include <iostream>
#include <vector>
#include <fstream>

#include "RandomDemands.txt"
#include "Vehicle.h"
#include "ChargingStation.h"
#include "Constant.h"

using namespace std;

class ChargingAllocation //Class for Allocating Chargers 
{

private:
    vector<Vehicle> vehicles; //Vehicle vector
    vector<ChargingStation> chargingStations; // Charging Station vector

public:
    void chargeMain();  //Main function for everything in this class
    void readVehicles();  //Function to read vehicles from file
    void vehicleCharging();   //Function for charger stuff
    void printOutRecharge();   //Function to print out recharge details
};

void ChargingAllocation::printOutRecharge()
{
    // Header for information with rechargers
    cout << endl
         << "Vehicle Information:" << endl;
    cout << "##########################################################################################################################################################" << endl;
    cout << setw(5) << "Vehicle ID: " << setw(25) << "Destination Name: " << setw(25) << "CapacityRange: " << setw(30) << "Remaining Range: " << setw(30) << "First Recharge: " << setw(30) << "Second Recharge: " << endl;
    cout << "##########################################################################################################################################################" << endl;


    //Print statement 
    for (int v = 0; v < vehicles.size(); v++)
    {
        cout << setw(5) << vehicles[v].getVehicleId();
        cout << setw(27) << nameMap[vehicles[v].getDestinationId()];
        cout << setw(25) << vehicles[v].getCapacity();
        cout << setw(25) << vehicles[v].getRemainRange();
        cout << setw(30) << (vehicles[v].getFirstStation() == 13 ? "----" : nameMap[vehicles[v].getFirstStation()]); //13 means its null
        cout << setw(30) << (vehicles[v].getSecondStation() == 13 ? "----" : nameMap[vehicles[v].getSecondStation()]);
        cout << endl;
    }
}

void ChargingAllocation::vehicleCharging()
{

    for (int a = 0; a < vehicles.size(); a++) //increment through all objects in vehicles vector
    {

        int firstStation = 0;
        int secondStation = 0;

        if (vehicles[a].getRemainRange() >= chargingStations[0].distanceToSydney(vehicles[a].getDestinationId())) //If the range is enough to reach destination then get null else continue 
        {
            firstStation = 13;
            secondStation = 13;
        }
        else
        {

            for (int i = 0; i <= vehicles[a].getDestinationId(); i++) // get first recharge  
            {
                if (vehicles[a].getRemainRange() >= chargingStations[0].distanceToSydney(i))
                {
                    firstStation = i;
                }
            }

            for (int j = firstStation; j <= vehicles[a].getDestinationId(); j++) // get second recharge
            {

                if ((vehicles[a].getCapacity() + chargingStations[0].distanceToSydney(firstStation)) >= chargingStations[0].distanceToSydney(j))
                {
                    if (j == vehicles[a].getDestinationId()) //if the first recharge get you to destination then null
                    {
                        secondStation = 13;
                    }
                    else
                    {
                        secondStation = j;
                    }
                }
            }
        }

        vehicles[a].setFirstStation(firstStation); // saves into vector 
        vehicles[a].setSecondStation(secondStation);
    }
}

void ChargingAllocation::readVehicles()
{

    int decision; //user prompt to choose random or fixed 
    cout << endl
         << "Type 1 for randomDemand, 2 for fixedDemand" << endl;
    cin >> decision;

    ifstream fin;  //input file

    if (decision == 1) // if 1 then random, if 2 then charging 
    {
        fin.open("RandomDemands.txt");
    }
    else if (decision == 2)
    {
        fin.open("ChargingDemands.txt");
    }
    else
    {
        cout << "Invalid choice" << endl;
        exit(1); //  terminate program
    }

    char ignore;
    int vehicleId;
    int destinationId;
    int capacityRange;
    int remainRange;

    while (!fin.eof()) // while not end of file
    {
        fin >> ignore >> vehicleId >> ignore >> destinationId >> ignore >> capacityRange >> ignore >> remainRange >> ignore; //input data into variables 
        Vehicle v(vehicleId, 0, destinationId, capacityRange, remainRange); // constructor  to create vehicle object
        vehicles.push_back(v);  // adds to vector
    }
    fin.close(); // close file 
}

void ChargingAllocation::chargeMain()
{

    // header 
    cout << endl
         << "Vehicle Information:" << endl;
    cout << "##########################################################################################################################" << endl;
    cout << setw(5) << "Vehicle ID: " << setw(25) << "Current City: " << setw(25) << "Destination Name: " << setw(25) << "CapacityRange: " << setw(30) << "Remaining Range: " << endl;
    cout << "##########################################################################################################################" << endl;

    //print  vehicle information 
    for (int q = 0; q < vehicles.size(); q++)
    {
        cout << setw(5) << vehicles[q].getVehicleId();
        cout << setw(25) << nameMap[0];
        cout << setw(27) << nameMap[vehicles[q].getDestinationId()];
        cout << setw(25) << vehicles[q].getCapacity();
        cout << setw(25) << vehicles[q].getRemainRange();
        cout << endl;
    }
    
    //print charging  information 
    chargingStations[0].displayStationInfo();
    //call other functions 
    vehicleCharging();
    printOutRecharge();
}

#endif