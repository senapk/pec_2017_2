#ifndef AGENDA_H
#define AGENDA_H
#include <iostream>
#include <vector>
#include <map>
#include "split.h"

using namespace std;

class Fone {
public:
    string idFone;
    string numero;
    Fone(string id = "", string numero = ""){
        this->idFone = id;
        this->numero = numero;
    }

    static bool validate(string numero) {
        string data = "1234567890()- ";
        for(auto c : numero)
            if(data.find(c) == string::npos)
                return false;
        return true;
    }
};

class Agenda;

class Contato {
    string nome;
    map<string, Fone> fones;
    bool favorited;

    void setFavorited(bool value){
        favorited = value;
    }
public:

    Contato(string nome = ""){
        this->nome = nome;
        favorited = false;
    }

    string getNome(){
        return nome;
    }

    void addFone(Fone fone){
        if(fones.count(fone.idFone) == 1)
            throw string("  fone " + fone.idFone + " ja existe");
        if(!Fone::validate(fone.numero))
            throw string("  fone " + fone.numero + " invalido");
        fones[fone.idFone] = fone;
    }

    void rmFone(string idFone){
        if(!fones.erase(idFone))
            throw string("  fone " + idFone + " nao existe");
    }

    vector<Fone> getFones(){
        vector<Fone> resp;
        for(auto par: fones)
            resp.push_back(par.second);
        return resp;
    }

    bool isFavorited(){
        return favorited;
    }



    string toString(){
        string saida = "";
        saida += favorited ? "@" : "-";
        saida += " " + this->nome;
        for(auto fone : getFones())
            saida += "[" + fone.idFone + " " + fone.numero + "]";
        return saida;
    }
    friend class Agenda;
};

class Agenda {
    map<string, Contato*> contatos;
    map<string, Contato*> favoritos;

public:
    void addContato(Contato cont){
        string nome = cont.getNome();
        if(contatos.count(nome) == 1)
            throw string("  contato " + cont.getNome() + " ja existe");
        contatos[nome] = new Contato(cont);
    }

    void rmContato(string nome) {
        Contato * cont = getContato(nome);
        if(contatos.erase(nome))
            favoritos.erase(nome);
        delete cont;
    }

    Contato * getContato(string nome){
        if(contatos.count(nome))
            return contatos[nome];
        throw string("  contato " + nome + " nao existe");
    }

    void favoritar(string nome) {
        Contato * contato = getContato(nome);
        if(contato->isFavorited())
            return;
        contato->setFavorited(true);
        favoritos[nome] = contato;
    }

    void desfavoritar(string nome){
        Contato * contato = getContato(nome);
        if(contato->isFavorited()){
            contato->setFavorited(false);
            favoritos.erase(nome);
        }
    }

    vector<Contato> getFavoritos(){
        vector<Contato> resp;
        for(auto par : favoritos)
            resp.push_back(*par.second);
        return resp;
    }

    vector<Contato> getContatos(){
        vector<Contato> resp;
        for(auto par : contatos)
            resp.push_back(*par.second);
        return resp;
    }

    vector<Contato> search(string pattern){
        vector<Contato> resp;
        for(auto par : contatos)
            if(par.second->toString().find(pattern) != string::npos)
                resp.push_back(*par.second);
        return resp;
    }

    string toString(){
        string saida = "Agenda\n";
        for(auto contato : getContatos())
            saida += contato.toString() + "\n";
        return saida;
    }
};

class Controller {

    Agenda agenda;
public:

    string process(string line){
        auto ui = split(line);
        auto cmd = ui[0];

        if(cmd == "help"){
            return "  # crud de contatos                         \n"
                   "  addContato _idContato                      \n"
                   "  rmContato  _idContato                      \n"
                   "                                             \n"
                   "  # crud de telefone                         \n"
                   "  addFone    _idContato _idFone _number      \n"
                   "  rmFone     _idContato _idFone              \n"
                   "                                             \n"
                   "  # buscas e visualizações                   \n"
                   "  show       _idContato                      \n"
                   "  showAll                                    \n"
                   "  search     _pattern                        \n"
                   "                                             \n"
                   "  # favoritos                                \n"
                   "  fav        _idContato                      \n"
                   "  desfav     _idContato                      \n"
                   "  showFav                                    \n"
                   "                                             \n"
                   "  # default                                  \n"
                   "  fim                                        \n"
                   "  help                                       \n";
        }
        if(cmd == "addContato"){
            agenda.addContato(Contato(ui[1]));
            return "done";
        }
        if(cmd == "rmContato"){
            agenda.rmContato(ui[1]);
            return "done";
        }
        if(cmd == "addFone"){
            agenda.getContato(ui[1])->addFone(Fone(ui[2], ui[3]));
            return "done";
        }
        if(cmd == "rmFone"){
            agenda.getContato(ui[1])->rmFone(ui[2]);
            return "done";
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
    Controller c;
    c.commandLine();
    return 0;
}


#endif // AGENDA_H

