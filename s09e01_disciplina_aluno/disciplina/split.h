#ifndef SPLIT
#define SPLIT
#include <sstream>
#include <vector>

std::vector<std::string> split(std::string line){
    std::vector<std::string> vet;
    std::stringstream ss(line);
    std::string palavra;
    while(ss >> palavra)
        vet.push_back(palavra);
    return vet;
}

template <class T>
T cast(std::string word){
    T value;
    std::stringstream ss(word);
    ss >> value;
    if(!ss)
        throw "Conversao invalida da palavra " + word;
    return value;
}

inline int Int(std::string word){
    return cast<int>(word);
}

inline int Float(std::string word){
    return cast<float>(word);
}

#endif // SPLIT


