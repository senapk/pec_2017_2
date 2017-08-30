#include <iostream>
#include <vector>
using namespace std;


template <class T>
T read(){
    T t;
    cin >> t;
    return t;
}

struct Operacao{
    string descricao;
    float valor;
    Operacao(string descricao = "", float valor = 0){
        this->descricao = descricao;
        this->valor = valor;
    }
};

class Conta{
private:
    int id;
    float saldo{0};
    vector<Operacao> extrato;
public:
    Conta(int id = 0){
        this->id = id;
    }
    float getSaldo(){
        return this->saldo;
    }
    int getId(){
        return this->id;
    }
    void setId(int id){
        this->id = id;
    }

    bool saque(float valor){
        if((this->saldo < valor) || (valor < 0))
            return false;

        this->saldo -= valor;
        this->extrato.push_back(Operacao("Saque: ", valor));

        return true;
    }

    bool deposito(float valor){
        if(valor < 1)
            return false;

        this->saldo += valor;
        this->extrato.push_back(Operacao("Deposito: ", valor));
        return true;
    }
    vector<Operacao> getExtrato(){
        return this->extrato;
    }

};

void inicializar(Conta& conta){
    conta = Conta(5);
    conta.deposito(50);
    conta.saque(10);
    conta.deposito(200);
    conta.saque(1000);//nao deve aparecer esse saque
}

void interacaoUsuario(Conta& conta){
    string op;
    cout << "digite help" << endl;
    while(op != "fim"){
        cin >> op;

        if(op == "help"){
            cout << "iniciar _id" << endl
                 << "saldo" << endl
                 << "saque _valor" << endl
                 << "deposito _valor" << endl
                 << "extrato" << endl
                 << "fim" << endl;
        }

        if(op == "iniciar"){
            conta = Conta(read<int>());
        }
        if(op == "saldo"){
            cout << conta.getSaldo() << endl;
        }
        if(op == "deposito"){
            cout << (conta.deposito(read<float>())? "ok" : "erro") << endl;
        }
        if(op == "saque"){
            cout << (conta.saque(read<float>())? "ok" : "erro") << endl;
        }
        if(op == "extrato"){
            // vector<Operacao> extrato = conta.getExtrato();
            for(auto operacao : conta.getExtrato()){
                cout << operacao.descricao << operacao.valor << endl;
            }
        }
    }
}

int main(){
    Conta conta;
    inicializar(conta);
    interacaoUsuario(conta);
}




























