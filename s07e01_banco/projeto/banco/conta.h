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

    bool sacar(float value);
    bool depositar(float value);
    bool transferir(Conta& other, float value);

    int getNumero() const;
    void setNumero(int value);
    bool getAtiva() const;
    void setAtiva(bool value);
    vector<Operacao> getExtrato() const;
};

#endif // CONTA_H
