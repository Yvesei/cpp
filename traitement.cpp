#include "traitement.h"
#include <iostream>
#include <string>  


string traitement::demandeSignature(dataflow* dataflow) {
    std::cout << "Requesting signature calculation..." << std::endl;
    // here we should send a request to the dataflux to calculate the signature
    return dataflow->calculerSignature();
}


void traitement::besoinControleIntegrite() {
    std::cout << "Requesting integrity control..." << std::endl;
}

traitement::traitement(type t){
    this->m_type = t;
}


