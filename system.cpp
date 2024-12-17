#include "system.h"


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
