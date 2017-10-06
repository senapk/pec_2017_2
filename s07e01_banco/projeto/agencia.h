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

    Cliente * getCliente(string cpf){
        //map<string, Cliente>::iterator it = clientes.find(cpf);
        auto it = clientes.find(cpf);
        if(it == clientes.end())
            return nullptr;
        return &it->second;
    }

    vector<Cliente*> getAllClientes(){
        vector<Cliente*> vet;
        for(auto& par: clientes)
            vet.push_back(&par.second);
        return vet;
    }

    bool abrirConta(string cpf){
        auto it = clientes.find(cpf);
        if(it == clientes.end())
            return false;
        Cliente &cli = it->second;
        int cont = 0;
        for(Conta * conta : cli.getAllContas())
            if(conta->getAtiva())
                cont++;
        if(cont < MAX_CONTAS_ATIVAS)
            cli.addConta(Conta(nextConta++));
        return true;
    }

    friend ostream& operator<<(ostream &os, Agencia ag){
        cout << "Agencia" << endl;
        for(auto cli : ag.getAllClientes()){
            os << (*cli) << endl;
        }
        return os;
    }
};












#endif // AGENCIA_H
