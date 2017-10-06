#ifndef CONTA_H
#define CONTA_H

#include <iostream>
#include <vector>
using namespace std;

class Operacao {
public:
    string descricao;
    float valor;
    float saldoParcial;
    Operacao(string desc = "" , float valor = 0.0f, float saldo = 0.0f):
        descricao(desc), valor(valor), saldoParcial(saldo)
    {}

    friend ostream& operator<<(ostream& os, const Operacao& op){
        os << "Desc: " << op.descricao
           << ", Valor: " << op.valor
           << ", Saldo: " << op.saldoParcial;
        return os;
    }
};



class Conta {
    vector<Operacao> extrato;
    float saldo {0.0};
    int numero;
    bool ativa{true};
    char * coisa;

public:
    Conta(int numero = 0):
        numero(numero)
    {
    }

    bool sacar(float value){
        if(value > saldo){
            cerr << "Valor insuficiente" << endl;
            return false;
        }
        saldo -= value;
        extrato.push_back(Operacao("Saque", -value));
        return true;
    }
    bool depositar(float value){
        saldo += value;
        extrato.push_back(Operacao("Deposito", value));
        return true;
    }
    bool transferir(Conta& other, float value){
        if(value > saldo){
            cerr << "Valor insuficiente para transferir" << endl;
            return false;
        }
        this->saldo -= value;
        extrato.push_back(
                    Operacao("Tranferencia para " + to_string(other.numero), -value));

        other.saldo += value;
        other.extrato.push_back(
                    Operacao("Tranferencia de" + to_string(this->numero), value));

        return true;
    }

    int getNumero() const
    {
        return numero;
    }
    void setNumero(int value)
    {
        numero = value;
    }
    bool getAtiva() const
    {
        return ativa;
    }
    void setAtiva(bool value)
    {
        ativa = value;
    }
    vector<Operacao> getExtrato() const
    {
        return extrato;
    }

    friend ostream& operator<<(ostream& os, Conta conta){
        os << "Num: " << conta.numero
           << " Saldo: " << conta.saldo
           << " Status: " << conta.ativa;
        return os;
    }
};

#endif // CONTA_H









