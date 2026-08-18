#include <iostream>
#include <vector>
#include "Person.h"

std::vector<Person> setupData();
float getDeathWeight();
int modifyData();
bool isMateSuccessful();
bool isMateable();

int main() {
    std::cout << "Start Sim" << std::endl;

    // create population of people
    std::vector<Person> population = setupData();

    //sim loop
    bool keepGoing = true;
    int year;

    while (keepGoing) {
        year ++;

        modifyData(population);

        if (year > 100) {
            keepGoing = false;
        }

        std::
    }

    modifyData(population);
}

std::vector<Person> setupData() {
    std::vector<Person> population;

    // create some people
    Person person1 = Person(0.2, 0.4);
    Person person2 = Person(0.9, 0.18);

    population.push_back(person1);
    population.push_back(person2);

    return population;
}

int modifyData(std::vector<Person> population) {
    //for each person (el in array)
    for (int i = 0; i < population.size(); i++) {
        //determine death
        



        //determine death
        //if they died
            //mark death flag
    //for each person
        //mate
        //make array from 0 - len(population)
        //if currentPerson isMateable()
            //remove from array
            //save as mate1
        //pick random value
            //if is mateable()
                //remove and save as mate
            //else
                //remove
        //mate(%) -> append new person to list with mutation as (x+y)/2 + rand()
    }
    return 0;
}

float getDeathWeight() {
    return 0.0;
}

bool isMateSuccessful() {
    return true;
}

bool isMateable() {
    return true;
}