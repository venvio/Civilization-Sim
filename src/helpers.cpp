#include "Person.h"
#include "helpers.h"
#include "config.h"
#include <random>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <algorithm>

// determines whether or not two mates produce offspring
bool matingRoll(int mate1Value, int mate2Value, std::vector<Person>* population) {
    // get base roll
    float roll = getRandomFloat(0.0, 1.01);

    // get average
    int averageAge = (population->at(mate1Value).getAge() + population->at(mate2Value).getAge()) / 2;

    if (averageAge > CRIT_AGE) {
        // get coefficient
        // if this is < 0, this means the two mates have average age > CRIT_AGE, no debuff
        float coeff = (float(averageAge) - CRIT_AGE) / 10.0;

        // subtract from base roll
        roll = roll - coeff;
    }

    if (roll >= 0.5) {
        return true;
    }
    else {
        return false;
    }
}

// returns true if simulation should stop running
bool checkStopCondition(std::vector<Person>* population, int year) {
    if (population->size() == 0 || year == MAX_YEARS) {
        return true;
    }
    else {
        return false;
    }
}

// returns random float between given lower and upper bound.
// upper is exclusive
float getRandomFloat(float lower, float upper) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(lower, upper);
    float randomFloat = dist(gen);

    return randomFloat;
}

// displays summary information
void displaySummary(std::vector<Person>* population, int year) {
    std::cout << "Year " << year << " begins. Population is " << population->size() << std::endl;
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

int initializePopulation(std::vector<Person>* population, int n) {
    for (int i = 0; i < n; i++) {
        //get 'parent' mutations
        float mutation1 = getRandomFloat(0.0, 0.99);
        float mutation2 = getRandomFloat(0.0, 0.99);
        Person person = Person(mutation1, mutation2);
        population->push_back(person);
    }

    return 0;
}

int runSimulation(std::vector<Person>* population, int* deathCount) {
    // phase 1: determine deaths
    // we go backward through the vector so we can safely remove indices and not skip over subsequent people
    for (int i = population->size() - 1; i >=0 ; i--) {
        // death test
        if (population->at(i).willDie()) {
            // erase them from population
            population->erase(population->begin() + i);
            deathCount += 1;

        } else {
            // increment age if they survived
            population->at(i).incrementAge();
        }
    }

    // phase 2: breed
    breedPopulation(population);

    return 0;
}
