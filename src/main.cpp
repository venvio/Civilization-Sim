#include <iostream>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <algorithm>
#include "Person.h"
#include "helpers.h"

void setupData(std::vector<Person>* population);
float getDeathWeight();
int modifyData(std::vector<Person>* population);
void displaySummary(std::vector<Person>* population, int year);
void breedPopulation(std::vector<Person>* population);

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
        modifyData(population);
        
        // display simulation data
        displaySummary(population, year);

        // checks whether simulation should continue
        stop = checkStopCondition(population, year);
    }

    delete population;
    return 0;
}

void setupData(std::vector<Person>* population) {

    // create some people
    Person person1 = Person(0.2, 0.4);
    Person person2 = Person(0.9, 0.18);

    population->push_back(person1);
    population->push_back(person2);
}

int modifyData(std::vector<Person>* population) {
    // phase 1: determine deaths
    // we go backward through the vector so we can safely remove indices and not skip over subsequent people
    for (int i = population->size() - 1; i >=0 ; i--) {
        // death test
        if (Person::willDie(population->at(i).getAge(), population->at(i).getMutation())) {
            // they died, mark flag
            //population->at(i).setIsDead(true);

            // erase them from population
            population->erase(population->begin() + i);
        }

        // increment age if they survived
        population->at(i).incrementAge();
    }

    // phase 2: breed
    breedPopulation(population);

    return 0;
}

void breedPopulation(std::vector<Person>* population) {
    // make mating vector
    std::vector<int> matingVector(population->size());
    // fill vector with values 1,2,3,...,n
    std::iota(matingVector.begin(), matingVector.end(), 0);

    while(matingVector.size() > 0) {
        // get mate 1
        int mate1Index = rand() % matingVector.size();
        int mate1Value = matingVector[mate1Index];
        //remove mate 1 from matingVector
        std::vector<int>::iterator matingVectorIndex = std::find(matingVector.begin(), matingVector.end(), mate1Value);
        if (matingVectorIndex != matingVector.end()) {
            matingVector.erase(matingVectorIndex);
        }

        // check for last person
        if (matingVector.size() == 0) {
            break;
        }

        // get mate 2
        int mate2Index = rand() % matingVector.size();
        int mate2Value = matingVector[mate2Index];

        //remove mate 2 from matingVector
        matingVectorIndex = std::find(matingVector.begin(), matingVector.end(), mate2Value);
        if (matingVectorIndex != matingVector.end()) {
            matingVector.erase(matingVectorIndex);
        }

        // roll for breed
        if (matingRoll(mate1Value, mate2Value, population)) {
            // breed
            int mate1Mutation = population->at(mate1Value).getMutation();
            int mate2Mutation = population->at(mate2Value).getMutation();
            Person offspring(mate1Mutation, mate2Mutation);
            
            // add offspring to population
            population->push_back(offspring);
        }
        else {
            // breeding failed
            continue;
        }
    }
}

// displays summary information
void displaySummary(std::vector<Person>* population, int year) {
    std::cout << "Year: " << year << " Population size: " << population->size() << std::endl;
}
