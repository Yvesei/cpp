#ifndef SYSTEM_H
#define SYSTEM_H


#include "dataflow.h"
#include "composant.h"
#include <vector>
using namespace std;
class System{
    vector <dataflow*> dataflows;
    unordered_map<composant*, vector<composant*>> graph; 
    vector<composant*> bestPath;
    public:
        System();
        vector <dataflow*> getDataflows();
        void addDataflow(dataflow* dataflow);
        void removeDataflow(dataflow* dataflow);
        void printBestPath() const;
        void addComposant(composant* node);
        void addEdge(composant* from, composant* to);
        void controleIntegrite(composant* startNode);
        const vector<composant*>& getNeighbors(composant* node);

};

#endif