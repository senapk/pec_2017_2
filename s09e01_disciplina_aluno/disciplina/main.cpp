#include <iostream>
#include <vector>
using namespace std;

class Aluno;

class Disc{
    vector<Aluno*> alunos;
public:
    string nome;
    Disc(string nome){
        this->nome = nome;
    }
    void addAluno(Aluno * aluno);
    string toString();
};

class Aluno{

    vector<Disc*> disciplinas;

    void addDisciplina(Disc * disciplina){
        disciplinas.push_back(disciplina);
    }

public:
    string nome;

    Aluno(string nome){
        this->nome = nome;
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



void Disc::addAluno(Aluno *aluno){
    alunos.push_back(aluno);
    aluno->addDisciplina(this);
}

string Disc::toString(){
    string saida = nome + "[ ";
    for(auto aluno : alunos)
        saida += aluno->nome + " ";
    saida += "]";
    return saida;
}

int main()
{

    Disc fup("fup"), poo("poo"), ed("ed");
    Aluno marisa("marisa"), raquel("raquel"), david("david");

    fup.addAluno(&marisa);
    fup.addAluno(&raquel);
    ed.addAluno(&marisa);

    cout << fup.toString() << endl;//marisa e raquel
    cout << marisa.toString() << endl; //fup e ed
    return 0;
}



