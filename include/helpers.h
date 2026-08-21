#ifndef HELPERS_H
#define HELPERS_H

bool matingRoll(int mate1Value, int mate2Value, std::vector<Person>* population);
float getRandomFloat(float lower, float upper);
bool checkStopCondition(std::vector<Person>* population, int year);
void displaySummary(std::vector<Person>* population, int year);
void breedPopulation(std::vector<Person>* population);
void setupData(std::vector<Person>* population);
int runSimulation(std::vector<Person>* population);

#endif
