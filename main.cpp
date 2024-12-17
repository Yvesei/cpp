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

//     System system;


//     dataflow* df1 = new dataflow("Hello, World!");
//     df1->getDemandeProtection();
//     dataflow* df2 = new dataflow("Secure Data");


//     system.addDataflow(df1);
//     system.addDataflow(df2);

    
//     traitement* traitement1 = new traitement(creation);
//     traitement* traitement2 = new traitement(write);

    
//     composant comp;
//     comp.addTraitement(traitement1);
//     comp.addTraitement(traitement2);

    
//     comp.setProtege(true);
//     comp.setCalculSignaturePossible(true);

    
//     std::cout << "\n--- traitement1 : Requesting Signature Calculation ---" << std::endl;
//     traitement1->demandeSignature(df1);

//     std::cout << "\n--- traitement2 : On peut calcluer signature? ---" << std::endl;
//     if (traitement2->demandeSignature(df2) == df2->getSignature()) {
//         std::cout << "Signatures match!" << std::endl;
//     }else{
//      std::cout << "\n--- traitement2 : Requesting Signature Calculation again---" << std::endl;
//      traitement2->demandeSignature(df2);
//     }
    
//     std::cout << "\n--- Requesting Integrity Control ---" << std::endl;
//     df1->controleIntegrite();
//     // un erreur 
//     df2->controleIntegrite();

    
//     std::cout << "\n--- Listing System Dataflows ---" << std::endl;
//     for (auto df : system.getDataflows()) {
//         std::cout << "Dataflow: " << df->getData() << std::endl;
//     }

    
//     delete df1;
//     delete df2;
//     delete traitement1;
//     delete traitement2;


System system;

    // Creating components
    composant* A = new composant(1);
    composant* B = new composant(2);
    composant* C = new composant(3);
    composant* D = new composant(4);
    composant* E = new composant(5);
    composant* F = new composant(6);

    // Setting protection state
    A->setProtege(true);
    B->setProtege(true);
    C->setProtege(false);
    D->setProtege(true);
    E->setProtege(false);
    F->setProtege(true);

    // Adding components to the system
    system.addComposant(A);
    system.addComposant(B);
    system.addComposant(C);
    system.addComposant(D);
    system.addComposant(E);
    system.addComposant(F);

    // Adding edges (connections)
    system.addEdge(A, B);
    system.addEdge(B, C);
    system.addEdge(B, D);
    system.addEdge(C, E);
    system.addEdge(D, F);

    // Start of the integrity control
    composant* startNode = A;
    std::cout << "Integrity Control...\n";

    // Data structures for traversal
    std::vector<composant*> currentPath;      // Tracks the current path
    std::vector<composant*> bestPath;         // Stores the best path
    std::unordered_map<composant*, bool> visited; // Tracks visited nodes

    std::stack<std::pair<composant*, int>> dfsStack;  // DFS stack
    dfsStack.push({startNode, 0});          // Start DFS from the initial node
    currentPath.push_back(startNode);

    while (!dfsStack.empty()) {
        auto [current, neighborIndex] = dfsStack.top();
        dfsStack.pop();

        // If revisiting a node, handle backtracking
        if (neighborIndex == 0) {
            std::cout << "Checking Composant: " << current->getId() << std::endl;
            if (!current->isProtege()) {
                std::cout << "Composant " << current->getId() << " is not protected. Backtracking...\n";
                currentPath.pop_back();
                continue;
            }
        }

        // Get neighbors using the System class
        const std::vector<composant*>& neighbors = system.getNeighbors(current);

        // Explore neighbors
        bool hasUnvisitedNeighbor = false;
        for (int i = neighborIndex; i < neighbors.size(); ++i) {
            composant* neighbor = neighbors[i];

            if (!visited[neighbor]) {
                dfsStack.push({current, i + 1}); // Save current state
                dfsStack.push({neighbor, 0});   // Move to the next node
                currentPath.push_back(neighbor);
                visited[neighbor] = true;
                hasUnvisitedNeighbor = true;
                break;
            }
        }

        // If no unvisited neighbors, backtrack
        if (!hasUnvisitedNeighbor) {
            if (currentPath.size() > bestPath.size()) {
                bestPath = currentPath;
            }
            visited[current] = false; // Allow revisiting during backtracking
            currentPath.pop_back();
        }
    }

    // Print the best path
    std::cout << "Chemin avec integrite maximale: ";
    for (const auto& node : bestPath) {
        std::cout << node->getId() << " -> ";
    }
    std::cout << "END\n";

    // Cleanup dynamically allocated memory
    delete A;
    delete B;
    delete C;
    delete D;
    delete E;
    delete F;

    return 0;
}
