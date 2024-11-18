#ifndef DEMANDGENERATORASS2_H
#define DEMANDGENERATORASS2_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Constant.h"
#include "RandomDemands.txt"

using namespace std;

class DemandGenerator
{
public:
    void generateRandomDemand();
};

void DemandGenerator::generateRandomDemand() //generate random demand 
{
    srand(time(0));
    ofstream fout;

    fout.open("RandomDemands.txt"); 
    int demands = rand() % 51 + 150;

    for (int i = 0; i < demands; i++) // generate random demand
    {
        int vehicleId = 200 + i;
        int destinationId = rand() % 11 + 1;
        int capacityRange = rand() % 201 + 350;
        int remainRange = rand() % (capacityRange + 1) + 300;

        fout << "[";
        fout << vehicleId << "," << destinationId << "," << capacityRange << "," << remainRange;
        fout << "]" << endl;
    }
    fout.close();
}

#endif