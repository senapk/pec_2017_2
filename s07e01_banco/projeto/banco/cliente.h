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

    bool addConta(Conta conta);

    Conta * getConta(int numero);

    string getCpf() const;
    void setCpf(const string &value);
    map<int, Conta> getContas() const;
};




#endif // CLIENTE_H
