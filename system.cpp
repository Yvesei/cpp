#include "system.h"
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
#include "composant.h"

using namespace std;


System::System() {
    
}

// Getter: Returns the vector of dataflows
vector<dataflow*> System::getDataflows() {
    return dataflows;
}

// Adds a new dataflow to the system
void System::addDataflow(dataflow* newDataflow) {
    dataflows.push_back(newDataflow);
}

// Removes a dataflow from the system
void System::removeDataflow(dataflow* targetDataflow) {
    for (auto it = dataflows.begin(); it != dataflows.end(); ++it) {
        if (*it == targetDataflow) {
            dataflows.erase(it);
            break; // Break after removing to avoid invalidating the iterator
        }
    }
}

    void System::addComposant(composant* node) {
        if (graph.find(node) == graph.end()) {
            graph[node] = {};
        }
    }

    void System::addEdge(composant* from, composant* to) {
        graph[from].push_back(to);
    }
    const vector<composant*>& System::getNeighbors(composant* node) {
        return graph[node];
    }
// void System::controleIntegrite(composant* startNode) {
//     vector<composant*> currentPath;      // Tracks the current path
//     vector<composant*> bestPath;         // Stores the best path
//     unordered_map<composant*, bool> visited; // Tracks visited nodes during traversal

//     stack<pair<composant*, int>> dfsStack;  // DFS stack: {current node, current neighbor index}
//     dfsStack.push({startNode, 0});          // Start DFS from the initial node
//     currentPath.push_back(startNode);

//     while (!dfsStack.empty()) {
//         auto [current, neighborIndex] = dfsStack.top();
//         dfsStack.pop();

//         // If we're revisiting a node, remove it from the current path
//         if (neighborIndex == 0) {
//             cout << "Checking Composant: " << current->getId() << endl;
//             if (!current->isProtege()) {
//                 cout << "Composant " << current->getId() << " is not protected. Backtracking...\n";
//                 currentPath.pop_back();
//                 continue;
//             }
//         }

//         // Get neighbors of the current node
//         const vector<composant*>& neighbors = graph[current];

//         // Explore neighbors starting from the current index
//         bool hasUnvisitedNeighbor = false;
//         for (int i = neighborIndex; i < neighbors.size(); ++i) {
//             composant* neighbor = neighbors[i];

//             // Check if the neighbor has been visited
//             if (!visited[neighbor]) {
//                 dfsStack.push({current, i + 1}); // Save current state
//                 dfsStack.push({neighbor, 0});   // Move to the next node
//                 currentPath.push_back(neighbor);
//                 visited[neighbor] = true;
//                 hasUnvisitedNeighbor = true;
//                 break;
//             }
//         }

//         // If no unvisited neighbors, backtrack
//         if (!hasUnvisitedNeighbor) {
//             if (currentPath.size() > bestPath.size()) {
//                 bestPath = currentPath;
//             }
//             visited[current] = false; // Allow revisiting during backtracking
//             currentPath.pop_back();
//         }
//     }

//     // Print the best path
//     cout << "Chemin avec integrite maximale: ";
//     for (const auto& node : bestPath) {
//         cout << node->getId() << " -> ";
//     }
//     cout << "END\n";
// }

    void System::printBestPath() const {
        cout << "Chemin avec integrite maximale: ";
        for (auto node : bestPath) {
            cout << node->getId() << " -> ";
        }
        cout << "END" << endl;
    }