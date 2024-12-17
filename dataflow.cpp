#include "dataflow.h"
#include <iostream>  
#include <string>

dataflow::dataflow(std::string m_data) {
    data = m_data;
}

string dataflow::calculerSignature() {   
    std::cout << "dataflow: Calculating signature..." << std::endl;   
    static const char* base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    string encoded;
    int val = 0;
    int valb = -6;

    for (unsigned char c : data) {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0) {
            encoded.push_back(base64_chars[(val >> valb) & 0x3F]);
            valb -= 6;
        }
    }

    if (valb > -6) {
        encoded.push_back(base64_chars[((val << 8) >> (valb + 8)) & 0x3F]);
    }

    while (encoded.size() % 4) {
        encoded.push_back('=');
    }
 
    std::cout << "Encoded Signature (Base64): " << encoded << std::endl;
    signature = encoded;
    std::cout << "Signature calculated successfully!" << std::endl;
    return signature;
}
void dataflow::controleIntegrite() {
    if (demande_protection == true) {
        std::cout << "Checking data integrity..." << std::endl;
    }
    else {
        std::cout << "Data integrity check not requested." << std::endl;
    }
}
string dataflow::getData() {
    return this->data;
}
string dataflow::getSignature() {
    return this->signature;
}
bool dataflow::getDemandeProtection() {
    return this->demande_protection;
}


