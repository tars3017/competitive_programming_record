#include "function.h"

Animal::Animal(Zoo *zoo, string name) {
    zoo->born(name);
    belong = zoo;
    species = name;
}

Dog::Dog(Zoo *zoo): Animal(zoo, "Dog") {}

Dog::~Dog() {}

Cat::Cat(Zoo *zoo): Animal(zoo, "Cat") {}

Cat::~Cat() {}

Caog::Caog(Zoo *zoo): 
Animal(zoo, "Caog"), Dog(zoo), Cat(zoo) {}

void Caog::barking() {
    cout << "woof!woof!meow!\n";
}

void Caog::carton() {
    cout << "it looks so happy!\n";
}

void Caog::throwBall() {
    cout << "it looks happy!\n";
}

Caog::~Caog() {}