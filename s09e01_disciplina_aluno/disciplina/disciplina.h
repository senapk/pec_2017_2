#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <iostream>
#include <vector>
using namespace std;

// #include "aluno.h" ERRRRRRRRRRRRRRRRRRRRRRRRO
class Aluno;//foward declaration

class Disc{
    vector<Aluno*> alunos;
public:
    string nome;
    Disc(string nome = ""){
        this->nome = nome;
    }

    void addAluno(Aluno * aluno);
    void rmAluno(string idAluno);

    string toString();
};

#endif // DISCIPLINA_H
