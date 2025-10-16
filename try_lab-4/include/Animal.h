#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

class Animal {
    string name;
    int age;
    string sound;
    public:
        Animal(): name("no_name"), age(0), sound("silence"){
        }
        Animal(string name, int age, string sound): name(name), age(age), sound(sound) {
        }
        ~Animal(){
        }
        void print() const;
        int getAge() const;
        const string& getName() const;
};

void addAnimal(Animal*& animals, int& size, const Animal& newAnimal);
void removeAnimal(Animal*& animals, int& size, const string& name);
void sortAnimals(Animal* animals, int size);

#endif
