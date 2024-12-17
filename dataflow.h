#ifndef DATAFLOW_H
#define DATAFLOW_H


#include <iostream>
#include <string>
using namespace std;

class dataflow{
    string data;
    string signature;
    bool demande_protection;
    public:
        dataflow(std::string m_data);
        string calculerSignature();
        void controleIntegrite();
        string getData();
        string getSignature();
};

#endif