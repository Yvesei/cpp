#include "composant.h"
#include "dataflow.h"
#include "traitement.h"
#include "system.h"
#include <iostream>

int main() {

    System system;


    dataflow* df1 = new dataflow("Hello, World!");
    dataflow* df2 = new dataflow("Secure Data");


    system.addDataflow(df1);
    system.addDataflow(df2);

    
    traitement* traitement1 = new traitement(creation);
    traitement* traitement2 = new traitement(write);

    
    composant comp;
    comp.addTraitement(traitement1);
    comp.addTraitement(traitement2);

    
    comp.setProtege(true);
    comp.setCalculSignaturePossible(true);

    
    std::cout << "\n--- traitement1 : Requesting Signature Calculation ---" << std::endl;
    traitement1->demandeSignature(df1);

    std::cout << "\n--- traitement2 : On peut calcluer signature? ---" << std::endl;
    if (traitement2->demandeSignature(df2) == df2->getSignature()) {
        std::cout << "Signatures match!" << std::endl;
    }else{
     std::cout << "\n--- traitement2 : Requesting Signature Calculation again---" << std::endl;
     traitement2->demandeSignature(df2);
    }
    
    std::cout << "\n--- Requesting Integrity Control ---" << std::endl;
    df1->controleIntegrite();
    df2->controleIntegrite();

    
    std::cout << "\n--- Listing System Dataflows ---" << std::endl;
    for (auto df : system.getDataflows()) {
        std::cout << "Dataflow Address: " << df->getData() << std::endl;
    }

    
    delete df1;
    delete df2;
    delete traitement1;
    delete traitement2;

    return 0;
}
