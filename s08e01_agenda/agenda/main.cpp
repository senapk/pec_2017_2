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
            if(data.find(c) == data.end())
                return false;
        return true;
    }
    //(85} recados: 3232-5050
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
//    void test(){
//        map<string, int> dividas;
//        dividas.size();
//        dividas.count("gvt");
//        //adicionando
//        dividas["gvt"] = 150;
//        dividas.insert(make_pair("gvt", 150));
////        dividas.at("marcia") = 3;//lanca um excessao
//        //obter
//        cout << dividas.at("gvt") << divitas["gvt"] << endl;


//    }

    bool addContato(Contato cont){
        string nome = cont.getNome();


//        //modo 1
//        if(contatos.count(nome) == 1)
//            return false;
//        contatos[nome] = cont;
//        contatos.at(nome) = cont;

//        return true;

        //modo 2
        return contatos.insert(make_pair(nome, cont)).first;

        //modo 3
//        auto it = contatos.find(nome);
//        if(it != contatos.end())
//            return false;
//        contatos[nome] = cont;
//        return true;
    }

    bool rmContato(string nome) {
        //modo 1
//        auto it_par = contatos.find(nome);
//        if(it_par == contatos.end())
//            return false;

//        Contato& contato = it_par->second;

//        if(contato.isFavorited()){
//            contato.setFavorited(false);
//            favoritos.erase(nome);
//        }
//        contatos.erase(it_par);

        //modo 2
        if(contatos.erase(nome))
            favoritos.erase(nome);

    }

    Contato * getContato(string nome){
        auto it = contatos.find(nome);
        return (it != contatos.end()) ? (&it->second) : nullptr;
    }

    bool favoritar(string nome) {
        //indo pelos contatos
        Contato * contato = getContato(nome);
        if(!contato || contato->isFavorited())
            return false;
        contato->setFavorited(true);
        favoritos[nome] = contato;
        return true;
    }

    bool desfavoritar(string nome){
//        auto contato = getContato(nome);
//        if(!contato || !contato->isFavorited())
//            return false;
//        contato->setFavorited(false);
//        favoritos.erase(nome);
//        return true;

        //forma otimizada
        auto it = favoritos.find(nome);
        if(it == favoritos.end())
            return false;
        it->second.setFavorited(false);
        favoritos.erase(it);

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

