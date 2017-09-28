#include "cliente.h"

string Cliente::getCpf() const
{
    return cpf;
}

void Cliente::setCpf(const string &value)
{
    cpf = value;
}

map<int, Conta> Cliente::getContas() const
{
    return contas;
}

bool Cliente::addConta(Conta conta){
    return contas.insert(make_pair(conta.numero, conta)).second;
}

Conta *Cliente::getConta(int numero){
    auto it = contas.find(numero);
    if(it == contas.end())
        return nullptr;
    return &it->second;
}

