#include "Person.h"
#include "helpers.h"
#include <random>
#define CRIT_AGE 35.0

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

// upper is excluded
float getRandomFloat(float lower, float upper) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(lower, upper);
    float randomFloat = dist(gen);

    return randomFloat;
}
