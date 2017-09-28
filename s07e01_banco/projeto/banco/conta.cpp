#include "conta.h"




bool Conta::getAtiva() const
{
    return ativa;
}

void Conta::setAtiva(bool value)
{
    ativa = value;
}

vector<Operacao> Conta::getExtrato() const
{
    return extrato;
}

bool Conta::sacar(float value){
    if(value > saldo){
        cerr << "Valor insuficiente" << endl;
        return false;
    }
    saldo -= value;
    extrato.push_back(Operacao("Saque", -value));
    return true;
}

bool Conta::depositar(float value){
    saldo += value;
    extrato.push_back(Operacao("Deposito", value));
    return true;
}

bool Conta::transferir(Conta &other, float value){
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

}

int Conta::getNumero() const
{
    return numero;
}

void Conta::setNumero(int value)
{
    numero = value;
}
