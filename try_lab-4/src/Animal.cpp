#include "Animal.h"
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

void Animal::print() const{
    cout << "Imię: " << name << ", Wiek: " << age << ", Dzwięk: " << sound << endl;
    // Imię: Burek, Wiek: 5, Dźwięk: Hau!
}
int Animal::getAge() const{
    return age;
}
const string& Animal::getName() const{
    return name;
}

void addAnimal(Animal*& animals, int& size, const Animal& newAnimal){
    animals = (Animal*)realloc(animals, sizeof(Animal)*(++size));
    animals[size-1] = newAnimal;
cout<<size;
}

void removeAnimal(Animal*& animals, int& size, const string& name){
    int count = 0;
    for(int i = 0; i < size; i++){
        if(animals[i].getName() == name) count++;
    }
    cout << size;
    int new_size = size - count;
    Animal* new_farm = new Animal[new_size];
    int j = 0;
    for(int i = 0; i < size; i++) {
        if(animals[i].getName() != name) {
            new_farm[j++] = animals[i];
        }
    }
    delete [] animals;
    animals = new_farm;
    size = new_size;
}

bool comp(const Animal& a, const Animal& b){
    return a.getAge() < b.getAge();
}

void sortAnimals(Animal* animals, int size){
    sort(animals, animals + size, comp);
}
