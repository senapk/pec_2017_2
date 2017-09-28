#ifndef AGENCIA_H
#define AGENCIA_H
#include <map>
#include "cliente.h"
#include "conta.h"

using namespace std;

class Agencia
{
    map<string, Cliente> clientes;
    int nextConta {0};
public:
    const int MAX_CONTAS_ATIVAS = 2;

    Agencia()
    {
    }

    bool addCliente(string cpf){
        auto it = clientes.find(cpf);
        if(it != clientes.end())
            return false;

        clientes[cpf] = Cliente(cpf);
        clientes[cpf].addConta(nextConta++);
        return true;
    }

    bool abrirConta(string cpf){
        auto it = clientes.find(cpf);
        if(it == clientes.end())
            return false;
        Cliente &cli = it->second;
        int cont = 0;
        for(auto par : cli.getContas())
            if(par.second.getAtiva())
                cont++;
        if(cont < MAX_CONTAS_ATIVAS)
            cli.addConta(nextConta++);
    }
};

#endif // AGENCIA_H
