#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include "conta.h"
#include <map>
using namespace std;

class Cliente
{
    string cpf;
    map<int, Conta> contas;

public:
    Cliente(string cpf = "")
    {
        this->cpf = cpf;
    }

    bool addConta(Conta conta){
        return contas.insert(make_pair(conta.getNumero(), conta)).second;
    }

    Conta * getConta(int numero){
        auto it = contas.find(numero);
        if(it == contas.end())
            return nullptr;
        return &it->second;
    }

    string getCpf() const
    {
        return cpf;
    }
    void setCpf(const string &value)
    {
        cpf = value;
    }

    vector<Conta> getAllContas() const{
        vector<Conta> vet;
        for(auto par : contas)
            vet.push_back(par.second);
        return vet;
    }

    friend ostream& operator<<(ostream& os, const Cliente& cli){
        os << "Cpf: " << cli.cpf << endl;
        for(const Conta& conta: cli.getAllContas())
            os << conta << endl;
        return os;
    }
};





#endif // CLIENTE_H
