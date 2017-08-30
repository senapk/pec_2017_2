#include <iostream>
#include <vector>

using namespace std;

template <class T>
T read(){
    T t;
    cin >> t;
    return t;
}

struct Telefone{
    string description;
    string number;

    Telefone(string descricao = "", string fone = ""):
        description(descricao), number(fone)
    {
    }
};

#include <sstream>
class Contato{
public:
    string nome;
    string email;
    vector<Telefone> fones;


    Contato(string nome = ""):
        nome(nome)
    {
    }

    string toString(){
        stringstream ss;
        ss << "Nome: " << this->nome << endl;
        for(auto fone : fones)
            ss << "[" << fone.description << ", " << fone.number << "]";
       ss << endl;
       return ss.str();
    }

    bool addTelefone(Telefone telefone){
        for(auto tel : fones)
            if(tel.number == telefone.number)
                return false;
        fones.push_back(telefone);
        return true;
    }

    bool removerTelefone(string number){
        for(int i = 0; i < (int)fones.size(); i++){
            if(fones[i].number == number){
                fones.erase(fones.begin() + i);
                return true;
            }

        }
        return false;
    }
};

void intUsuario(Contato& contato){

    string op = "";
    while(op != "fim"){
        cout << "Digite comando ou help: ";
        cin >> op;
        if(op == "help"){
            cout << "iniciar $nome" << endl;
            cout << "setNome $nome" << endl;
            cout << "addFone $descricao $number" << endl;
            cout << "show" << endl;
        }
        if(op == "iniciar"){
            contato = Contato (read<string>());
            cout << "Contato criado!" << endl;
        }
        if(op == "setNome"){
            contato.nome = read<string>();
            cout << "Nome alterado!\n";
        }
        if(op == "addFone"){
            string descricao = read<string>();
            string numero = read<string>();

            if(contato.addTelefone(Telefone(descricao, numero))){
                cout << "Telefone adicionado! :)" << endl;
            }else{
                cout << "Alguma coisa errada não esta certa" << endl;
            }
        }
        if(op == "show"){
            cout << contato.toString();
        }
    }

}

int main()
{
    Contato contato;
    intUsuario(contato);
    return 0;
}













