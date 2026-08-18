#include <iostream>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <algorithm>
#include "Person.h"

void setupData(std::vector<Person>* population);
float getDeathWeight();
int modifyData(std::vector<Person>* population);
bool isMateSuccessful();
bool isMateable();
void displayYear(std::vector<Person>* population, int year)

int main() {
    std::cout << "Start Sim" << std::endl;

    // create population of people
    std::vector<Person>* population = new std::vector<Person>();
    setupData(population);

    //sim loop
    bool keepGoing = true;
    int year = 0;

    while (keepGoing) {
        year ++;

        modifyData(population);
        
        displayYear(population, year);

        if (year > 99) {
            keepGoing = false;
        }
    }

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
    //for each person (el in array)
    for (int i = 0; i < population->size(); i++) {
        //determine death
        if (Person::willDie(population->at(i).getAge(), population->at(i).getMutation())) {
            //if they died
            //mark death flag
            population->at(i).setIsDead(true);
        }

        population->at(i).incrementAge();
    }

    // make mating vector
    std::vector<int> matingVector(population->size());
    std::iota(matingVector.begin(), matingVector.end(), 0);

    for (int i = 0; i < population->size(); i++) {
        if (population->at(i).isMateable()) {
            //remove value from matingVector
            std::vector<int>::iterator matingVectorIndex = std::find(matingVector.begin(), matingVector.end(), 2);
            if (matingVectorIndex != matingVector.end()) {
                matingVector.erase(matingVectorIndex);
            }
            
            Person mate1 = population->at(i);

        }
        else {
            
        }

    }
        //mate
        //make array from 0 - len(population)
        //if currentPerson isMateable()
            //save as mate1
        //pick random value
            //if is mateable()
                //remove and save as mate
            //else
                //remove
        //mate(%) -> append new person to list with mutation as (x+y)/2 + rand()
    
    return 0;
}
void displayYear(std::vector<Person>* population, int year) {

    std::cout << "-------------------------------" << std::endl;
    
    std::cout << "Year: " << year << std::endl;

    for (int i = 0; i < population->size(); i++) {
        std::cout << "Person (" << i << ") is Dead? " << population->at(i).getIsDead() << " Age: " << population->at(i).getAge() << " Mutation: " << population->at(i).getMutation() << std::endl;
    }
}
