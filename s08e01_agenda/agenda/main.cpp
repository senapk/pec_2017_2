#ifndef AGENDA_H
#define AGENDA_H
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Fone {
    string foneId;
    string numero;
    Fone(string id, string numero);

    static bool validate(string numero) {
        string data = "1234567890()- ";
        for(auto c : numero)
            if(data.find(c) == string::npos)
                return false;
        return true;
    }
};

class Contato {
    string nome;
    vector<Fone> fones;
    bool favorited;
public:
    string getNome();

    bool addFone(Fone fone);
    bool rmFone(string foneId);
    vector<Fone> getAllFones();

    bool isFavorited();
    void setFavorited(bool value);

    string toString();
};

class Agenda {
    map<string, Contato> contatos;
    map<string, Contato> favoritos;

public:
    bool addContato(Contato cont){
        return contatos.insert(make_pair(cont.nome, cont)).second;
    }

    bool rmContato(string nome) {
        if(contatos.erase(nome)){
            favoritos.erase(nome);
            return true;
        }
        return false;
    }

    Contato * getContato(string nome){
        auto it = contatos.find(nome);
        return (it != contatos.end()) ? (&it->second) : nullptr;
    }

    bool favoritar(string nome) {
        Contato * contato = getContato(nome);
        if(!contato || contato->isFavorited())
            return false;
        contato->setFavorited(true);
        favoritos[nome] = contato;
        return true;
    }

    bool desfavoritar(string nome){
        auto contato = getContato(nome);
        if(contato && contato->isFavorited()){
            contato->setFavorited(false);
            favoritos.erase(nome);
            return true;
        }
        return false;
    }

    vector<Contato> getFavoritos(){
        vector<Contato> resp;
        for(auto par : favoritos)
            resp.push_back(par.second);
        return resp;
    }

    vector<Contato> patternSearch(string pattern){
        vector<Contato> resp;
        for(auto par : contatos)
            if(par.second.toString().find(pattern) != string::npos)
                resp.push_back(par.second);
        return resp;
    }
};

class Controller {
    Agenda agenda;
    void commandLine() {
        blablablalblabla

        if("addFone"){
            string nome, numero, foneId;
            cin >> nome >> foneId >> numero;
            auto contato = agenda.getContato(nome);

            if(!contato){
                cout << "Contato nao existe";
                continue;
            }
            cout << (contato->addFone(Fone(foneId, numero)) ?
                "Sucesso Brother" : "Id duplicado") << endl;
        }
    }
};


#endif // AGENDA_H

