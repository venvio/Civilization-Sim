#include "Person.h"
#include "helpers.h"
#include <vector>
#include <iostream>

int main() {
    std::cout << "Welcome to Civilization Sim." << std::endl;
    std::cout << "How many people are in your initial colony?: ";
    int n;
    std::cin >> n;

    // create population of people
    std::vector<Person>* population = new std::vector<Person>();
    initializePopulation(population, n);
    std::cout << "Population has " << population->size() << "people." << std::endl;

    //sim loop
    bool stop = false;
    int year = 0;

    while (!stop) {
        // display beginning of year stats
        displaySummary(population, year);

        // run simulation
        int deathCount = 0;
        runSimulation(population, &deathCount);
        
        // increment year
        year++;

        // checks whether simulation should continue
        stop = checkStopCondition(population, year);
    }

    delete population;
    return 0;
}


