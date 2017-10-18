#include <iostream>
#include "repo.h"
#include "split.h"
using namespace std;

class Cliente;
class Animal{
public:
    int id;
    string nome;
    string especie;
    Cliente * dono;
    Animal(int id = 0, string nome = "", string especie = ""){
    }
};

class Cliente{
    string idCli;
    Repository<Animal> animais;
    Cliente(int id):
        animais("animais")
    {
        this->idCli = id;
    }

    void add(Animal ani){
        animais.add(ani.nome, ani);
    }
};

class Servico{
public:
    string idSer;
    float value;
    Servico(string id, float value){
        idSer = id;
        this->value = value;
    }
};

class Venda{
public:
    int idVen;
    string idCli;
    int idAni;
    string idSer;
    Venda(int idVen, string idCli, int idAni, string idSer){
        this->idVen = idVen;
        this->idCli = idCli;
        this->idAni = idAni;
        this->idSer = idSer;
    }
};

class Controller{
    int nextIdAni {0};
    int nextIdVen {0};
    Repository<Animal> rani;
    Repository<Cliente> rcli;
    Repository<Servico> rser;
    Repository<Venda> rven;
    Controller():
        rani("animal"), rcli("cliente"), rser("servico"), rven("venda")
    {

    }

    string process(string line){
            auto ui = split(line);
            auto cmd = ui[0];

            if(cmd == "addCli")
                rcli.add(ui[1], Cliente(ui[1]));
            if(cmd == "getAllCli"){
                return vet2str<Cliente>("Clientes\n  ", rcli.getValues(), "\n  ");
            }
            if(cmd == "addAni"){
                Animal ani(nextIdAni, ui[2], ui[3]);
                rcli.at(ui[1]).add(ani);
                rani.add(nextIdAni++, ani);
            }
            if(cmd == "getAllAni"){
                return vet2str<Animal>("Animais\n  ", rani.getValues(), "\n  ");
            }
            if(cmd == "show"){
                return agenda.getContato(ui[1])->toString();
                return "done";
            }
            if(cmd == "showAll"){
                return agenda.toString();
            }
            if(cmd == "search"){
                auto resp = agenda.search(ui[1]);
                string saida = "";
                for(auto contato : resp)
                    saida += contato.toString() + "\n";
                return saida;
            }
            if(cmd == "fav"){
                agenda.favoritar(ui[1]);
                return "done";
            }
            if(cmd == "desfav"){
                agenda.desfavoritar(ui[1]);
                return "done";
            }
            if(cmd == "showFav"){
                string saida = "";
                auto favs = agenda.getFavoritos();
                for(auto contato : favs)
                    saida += contato.toString() + "\n";
                return saida;
            }
            if(cmd == "fim"){
                return "";
            }
            return "comando invalido";
        }


        void commandLine() {
            string line = "";
            while(line != "fim"){
                cout << "(help): ";
                getline(cin, line);
                if(line == "")
                    continue;
                cout << ">> " << line << endl;
                try {
                    cout << process(line) << endl;
                } catch(const string& e) {
                    cout << e << endl;
                }
            }
        }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

