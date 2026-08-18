#include <iostream>
#include <vector>
#include "Person.h"

void setupData(std::vector<Person>* population);
float getDeathWeight();
int modifyData(std::vector<Person>* population);
bool isMateSuccessful();
bool isMateable();

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

        if (year > 99) {
            keepGoing = false;
        }

        std::cout << population->at(0).getIsDead() << " year: " << year << std::endl;
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