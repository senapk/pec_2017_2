#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <iostream>
#include <map>

template <class T>
class Repository {
    std::map<std::string, T> _mapa;
    std::string nomeTipo;
public:
    Repository(std::string nomeTipo = ""){
        this->nomeTipo = nomeTipo;
    }

    //adiciona se a chave ainda nao existir
    T * add(std::string key, T t){
        if(_mapa.count(key) == 1)
            throw nomeTipo + " " + key + " ja existe";
        _mapa[key] = t;
        return &_mapa[key];
    }

    //retorna se o objeto está no repositório
    bool has(std::string key){
        return _mapa.count(key);
    }

    //retorna se conseguiu remover
    void rm(std::string key){
        if(!_mapa.erase(key))
            throw nomeTipo + " " + key + " nao existe";
    }

    //retorna o endereço do objeto
    T * get(std::string key){
        if(_mapa.count(key) == 0)
            throw nomeTipo + " " + key + " nao existe";
        return &_mapa[key];
    }

    //retorna o endereço do objeto
    T& at(std::string key){
        if(_mapa.count(key) == 0)
            throw nomeTipo + " " + key + " nao existe";
        return _mapa[key];
    }

    //retonar um vetor com a cópia dos elementos
    std::vector<T> values(){
        std::vector<T> vet;
        for(auto& par : _mapa)
            vet.push_back(par.second);
        return vet;
    }

    //retorna um vetor com a cópia das chaves
    std::vector<std::string> keys(){
        std::vector<std::string> vet;
        for(auto& par : _mapa)
            vet.push_back(par.first);
        return vet;
    }
};

#endif // REPOSITORY_H

