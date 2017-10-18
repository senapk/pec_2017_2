#include "disciplina.h"
#include "aluno.h"

void Disc::addAluno(Aluno *aluno){
    for(auto elem: this->alunos)
        if(elem->nome == aluno->nome)
            throw "aluno " + aluno->nome + " ja esta na disciplina";
    alunos.push_back(aluno);
    aluno->addDisciplina(this);
}

void Disc::rmAluno(string idAluno){
    for(auto it = alunos.begin(); it != alunos.end(); it++) {
        Aluno * aluno = *it;
        if(aluno->nome == idAluno){
            aluno->rmDisciplina(nome);
            alunos.erase(it);
            break;
        }
    }
}

string Disc::toString(){
    string saida = nome + "[ ";
    for(auto aluno : alunos)
        saida += aluno->nome + " ";
    saida += "]";
    return saida;
}

