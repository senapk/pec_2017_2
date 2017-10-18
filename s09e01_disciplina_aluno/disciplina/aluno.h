#ifndef ALUNO_H
#define ALUNO_H

#include "disciplina.h"
#include <iostream>
#include <vector>
using namespace std;

class Aluno{
    vector<Disc*> disciplinas;
    void addDisciplina(Disc * disciplina){
        disciplinas.push_back(disciplina);
    }
    void rmDisciplina(string idDisc){
        for(auto it = disciplinas.begin(); it != disciplinas.end(); it++){
            if((*it)->nome == idDisc){
                disciplinas.erase(it);
                break;
            }
        }
    }

public:
    string nome;

    Aluno(string nome = ""){
        this->nome = nome;
    }

    void comprarTicket(float value){
        if(value < 1.10)
            cout << "saldo insuficiente" << endl;
    }

    string toString(){
        string saida = nome + "[ ";
        for(auto disc: disciplinas)
            saida += disc->nome + " ";
        saida += "]";
        return saida;
    }

    friend class Disc;
};

#endif // ALUNO_H
