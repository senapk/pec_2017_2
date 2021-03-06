#ifndef SPLIT_H
#define SPLIT_H
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

template <class T>
T cast(std::string palavra){
    T value;
    std::stringstream(palavra) >> value;
    return value;
}

inline int Int(std::string word){
    return cast<int>(word);
}

inline int Float(std::string word){
    return cast<float>(word);
}

std::vector<std::string> split(const std::string& line){
    std::vector<std::string> saida;
    std::istringstream ss(line);
    std::string palavra;
    while(ss){
        ss >> palavra;
        saida.push_back(palavra);
    }
    return saida;
}

template<class T>
std::string vet2str(std::string prefix, std::vector<T> vet, std::string separ){
    std::stringstream ss;
    ss << prefix;
    for(auto elem : vet)
        ss << elem.toString() << separ;
    return ss.str();
}

template<class T>
std::vector<T> map2vet(std::map<std::string, T> &mapa){
    std::vector<T> vet;
    for(auto& par: mapa)
        vet.push_back(par.second);
    return vet;
}


#endif // SPLIT_H

