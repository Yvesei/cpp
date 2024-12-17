#ifndef COMPOSANT_H
#define COMPOSANT_H

#include "traitement.h"
#include <iostream>
#include <vector>
using namespace std;

class composant {
    vector<traitement*> traitements;
    bool protege;
    bool calculSignaturePossible;

public:
    composant();                         
    void addTraitement(traitement* tr);
    void removeTraitement(traitement* tr);
    vector<traitement*> getTraitements() const;


    void setProtege(bool status);
    bool isProtege() const;


    void setCalculSignaturePossible(bool status);
    bool isCalculSignaturePossible() const;
};
#endif