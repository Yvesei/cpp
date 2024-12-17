#ifndef SYSTEM_H
#define SYSTEM_H


#include "dataflow.h"
#include <vector>
using namespace std;
class System{
    vector <dataflow*> dataflows;
    public:
        System();
        vector <dataflow*> getDataflows();
        void addDataflow(dataflow* dataflow);
        void removeDataflow(dataflow* dataflow);


};

#endif