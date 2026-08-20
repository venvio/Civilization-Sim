#ifndef PERSON_H
#define PERSON_H
#include <random>

class Person {
    private:
        bool isDead = false;
        int age = 0;
        float mutation = 0.0;

        float calculateMutation(float mutation1, float mutation2) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<float> dist(-1.0f, 1.0f);
            float randomNumber = dist(gen);

            float newMutation = (mutation1 + mutation2) / 2;
            newMutation += randomNumber;

            return newMutation;
        }

        float getDeathWeight() {

            float initialChanceOfDeath = 0.0;
            float chanceOfDeathAtMaxAge = 100.0;
            int maxAge = 25;

            float deathWeight = ((chanceOfDeathAtMaxAge - initialChanceOfDeath) / maxAge) * this->age + initialChanceOfDeath - this->mutation;

            return deathWeight;
        }
    
    public:
        // constructor
        Person(float mutation1, float mutation2) {
            mutation = calculateMutation(mutation1, mutation2);
        }

        // setters and getters
        bool getIsDead() {
            return isDead;
        }

        void setIsDead(bool isDead) {
            this->isDead = isDead;
        }

        int getAge() {
            return age;
        }

        void setAge(int age) {
            this->age = age;
        }

        void incrementAge() {
            age++;
        }

        float getMutation() {
            return mutation;
        }

        void setMutation(float mutation) {
            this->mutation = mutation;
        }

        // will determine if an individual person dies at start of new year
        bool willDie() {
            // takes age and mutation and returns if they have died
            bool willDieResult = false;

            // as age goes up, so does death chance
            float deathWeight = this->getDeathWeight();

            if (deathWeight > 75) {
                // randomize death
                if (rand() % 2 == 0) {
                    willDieResult = true;
                }
            }

            return willDieResult;
        }
};

#endif
