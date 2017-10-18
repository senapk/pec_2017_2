#include <iostream>
#include <vector>
#include "aluno.h"
#include "disciplina.h"
#include "manager.h"
#include "split.h"

using namespace std;

class Controller {
    Manager<Disc> mdis;
    Manager<Aluno> malu;
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
