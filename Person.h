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
    
    public:
        Person(float mutation1, float mutation2) {
            mutation = calculateMutation(mutation1, mutation2);
        }

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

        float getMutation() {
            return mutation;
        }

        void setMutation(float mutation) {
            this->mutation = mutation;
        }

        static bool willDie(int age, float mutation) {

            // takes age and mutation and returns if they have died

            bool willDieResult = false;

            //TODO: make it real
            if (age > 10) {
                willDieResult = true;
            }

            return willDieResult;
        }
};

#endif