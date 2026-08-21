#include "Person.h"
#include "helpers.h"
#include <vector>
#include <iostream>

int main() {
    std::cout << "Welcome to Civilization Sim." << std::endl;
    std::cout << "How many people are in your initial colony?: " << std::endl;
    int n;
    std::cin >> n;

    // create population of people
    std::vector<Person>* population = new std::vector<Person>();
    initializePopulation(population, n);

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


