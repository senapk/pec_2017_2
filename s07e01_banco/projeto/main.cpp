#include <iostream>
#include "agencia.h"
#include "cliente.h"
#include "conta.h"

using namespace std;

int main()
{
    Agencia agencia;
    cout << agencia << endl;


    agencia.addCliente("david");
    Cliente * david = agencia.getCliente("david");
    agencia.addCliente("neuvania");
    agencia.abrirConta("david");
    cout << *david << endl;
    auto neuv = agencia.getCliente("neuvania");
    cout << *neuv << endl;

    cout << agencia << endl;
    return 0;
}




