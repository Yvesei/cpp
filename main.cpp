#include "composant.h"
#include "dataflow.h"
#include "traitement.h"
#include "system.h"
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

     unordered_map<composant*, vector<composant*>> graph; 

int main() {

    vector<composant*> currentPath;
    vector<composant*> bestPath;
    unordered_map<composant*, bool> visited;

    stack<pair<composant*, int>> dfsStack;

     System system;

    
    dataflow* df1 = new dataflow("Hello, World!");
    dataflow* df2 = new dataflow("Secure Data");

    system.addDataflow(df1);
    system.addDataflow(df2);

    
    traitement* traitement1 = new traitement(creation);
    traitement* traitement2 = new traitement(write);

    
    composant* A = new composant(1);
    composant* B = new composant(2);
    composant* C = new composant(3);
    composant* D = new composant(4);
    composant* E = new composant(5);
    composant* F = new composant(6);

    
    A->addTraitement(traitement1);
    B->addTraitement(traitement2);
    C->addTraitement(traitement1);
    D->addTraitement(traitement2);
    E->addTraitement(traitement1);
    F->addTraitement(traitement2);

    
    A->setProtege(true);
    B->setProtege(true);
    C->setProtege(false);
    D->setProtege(true);
    E->setProtege(false);
    F->setProtege(true);

    A->setCalculSignaturePossible(true);
    B->setCalculSignaturePossible(true);
    C->setCalculSignaturePossible(false);
    D->setCalculSignaturePossible(true);
    E->setCalculSignaturePossible(false);
    F->setCalculSignaturePossible(true);

    
    system.addComposant(A);
    system.addComposant(B);
    system.addComposant(C);
    system.addComposant(D);
    system.addComposant(E);
    system.addComposant(F);

    
    system.addEdge(A, B);
    system.addEdge(B, C);
    system.addEdge(B, D);
    system.addEdge(C, E);
    system.addEdge(D, F);

    
    composant* startNode = A;
    cout << "Starting Integrity Control...\n\n";


    dfsStack.push({startNode, 0});
    currentPath.push_back(startNode);

    while (!dfsStack.empty()) {
        auto [current, neighborIndex] = dfsStack.top();
        dfsStack.pop();

        
        if (neighborIndex == 0) {
            cout << "Checking Composant: " << current->getId() << endl;

            if (traitement2->demandeSignature(df2) == df2->getSignature()) {
                cout << "Signatures match! \n" << endl;
            }else{
            cout << "\n--- traitement " << current->getId() << " : Requesting Signature Calculation Again ---" << endl;
            current->getTraitements()[1]->demandeSignature(df1);
            }


            if (!current->isProtege()) {
                cout << "Erreur: Composant " << current->getId() << " is not protected. Backtracking...\n \n \n";
                currentPath.pop_back();
                continue;
            }
        }


        const vector<composant*>& neighbors = system.getNeighbors(current);


        bool hasUnvisitedNeighbor = false;
        for (int i = neighborIndex; i < neighbors.size(); ++i) {
            composant* neighbor = neighbors[i];
            if (!visited[neighbor]) {
                dfsStack.push({current, i + 1}); 
                dfsStack.push({neighbor, 0});   
                currentPath.push_back(neighbor);
                visited[neighbor] = true;
                hasUnvisitedNeighbor = true;
                break;
            }
        }


        if (!hasUnvisitedNeighbor) {
            if (currentPath.size() > bestPath.size()) {
                bestPath = currentPath;
            }
            visited[current] = false; 
            currentPath.pop_back();
        }
    }


    cout << "Chemin avec integrite   |   ";
    for (const auto& node : bestPath) {
        cout << node->getId() << " -> ";
    }
    cout << "   |\n";

    
    delete df1;
    delete df2;
    delete traitement1;
    delete traitement2;
    delete A;
    delete B;
    delete C;
    delete D;
    delete E;
    delete F;

    return 0;
}
