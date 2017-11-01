#include <iostream>
#include <vector>
#include "manager.h"
#include "split.h"

using namespace std;

using namespace std;

class Disc;
class RelAluDisc;

class Aluno{
    map<string, Disc*> m_disc;
public:
    string nome;
    Aluno(string nome){
        this->nome = nome;
    }

    vector<Disc*> getDisc(){
        return map2vet(m_disc);
    }
    string toString(){
        return nome;
    }
    friend class RelAluDisc;
};

class Disc{
    map<string, Aluno*> m_alunos;
public:
    string nome;
    Disc(string nome){
        this->nome = nome;
    }

    vector<Aluno*> getAlunos(){
        return map2vet(m_alunos);
    }
    string toString(){
        return nome;
    }
    friend class RelAluDisc;
};


class RelAluDisc{
    void attach(Aluno * aluno, Disc * disc){
        if(aluno->m_disc.count(disc->nome))
            return;
        aluno->m_disc[disc->nome] = disc;
        disc->m_alunos[aluno->nome] = aluno;
    }

    void detach(Aluno * aluno, Disc * disc){
        if(!aluno->m_disc.count(disc->nome))
            return;
        aluno->m_disc.erase(disc->nome);
        disc->m_alunos.erase(aluno->nome);
    }
};

class Controller {

public:
    Controller(){
    }

    string process(string line){
        auto ui = split(line);
        auto cmd = ui[0];

        if(cmd == "help"){
            return  "addA  _aluno \n"
                    "addD  _disc \n"
                    "addAD _aluno _disc\n"
                    "showD _disc\n"
                    "showA _aluno\n"
                    "showDs \n"
                    "showAs \n"
                    "rmAD _aluno _disc";
        }
        else if(cmd == "addA")
            malu.add(ui[1], Aluno(ui[1]));
        else if(cmd == "addD")
            mdis.add(ui[1], Disc(ui[1]));
        else if(cmd == "addAD")
            mdis.at(ui[2]).addAluno(&malu.at(ui[1]));
        else if(cmd == "showA")
            return malu.at(ui[1]).toString();
        else if(cmd == "showD")
            return mdis.at(ui[1]).toString();
        else if(cmd == "rmAD")
            mdis.at(ui[2]).rmAluno(malu.at(ui[1]).nome);
        else
            return "comando invalido";
        return "done";
    }


    void commandLine() {
        string line = "";
        cout << "Digite help ou cmd" << endl;
        while(line != "fim"){
            cout << ">> ";
            getline(cin, line);
            if(line == "" || line.substr(0, 2) == "  ")
                continue;
            cout << line << endl;
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

/*
addA davi
addA rex
addA ivo
addD fup
addD ed
addD poo
addAD davi fup
addAD rex fup
addAD ivo fup
addAD davi ed
addAD davi poo
addAD rex ed
showA davi
  davi [ fup ed poo ]
showD fup
  fup [ davi rex ivo ]
showD ed
  ed [ davi ]
rmAD davi fup
showD fup
  fup [ rex ivo ]


*/
