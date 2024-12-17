#include "composant.h"
#include <algorithm>  

using namespace std;
composant::composant() : protege(false), calculSignaturePossible(false) {}

composant::composant(int a) : id(a), protege(false), calculSignaturePossible(false) {}

void composant::addTraitement(traitement* tr) {
    traitements.push_back(tr);
}


void composant::removeTraitement(traitement* tr) {
    // remove traitement
}


vector<traitement*> composant::getTraitements() const {
    return traitements;
}


void composant::setProtege(bool status) {
    protege = status;
}


bool composant::isProtege() const {
    return protege;
}


void composant::setCalculSignaturePossible(bool status) {
    calculSignaturePossible = status;
}


bool composant::isCalculSignaturePossible() const {
    return calculSignaturePossible;
}

int composant::getId(){
    return this->id;
}