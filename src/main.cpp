#include "Person.h"
#include "helpers.h"
#include <vector>
#include <iostream>


int main() {
    std::cout << "Start Sim" << std::endl;

    // create population of people
    std::vector<Person>* population = new std::vector<Person>();
    setupData(population);

    //sim loop
    bool stop = false;
    int year = 0;

    while (!stop) {
        year ++;

        // run simulation
        runSimulation(population);
        
        // display simulation data
        displaySummary(population, year);

        // checks whether simulation should continue
        stop = checkStopCondition(population, year);
    }

    delete population;
    return 0;
}


