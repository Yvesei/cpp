#ifndef TRAITEMENT_H
#define TRAITEMENT_H

#include<iostream>
#include "dataflow.h"
#include <string>
using namespace std;
enum type{
    creation,
    read,
    write,
    storage,
    transit,
};

class traitement{
    type m_type;
    public:
        traitement(type t);
        string demandeSignature(dataflow* dataflow);
        void besoinControleIntegrite();
};
#endif
