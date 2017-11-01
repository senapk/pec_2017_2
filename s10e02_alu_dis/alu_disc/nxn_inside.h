#ifndef NXN_INSIDE
#define NXN_INSIDE

#include <vector>
#include "manager.h"
#include "split.h"

namespace nxn_inside{
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

}

#endif // NXN_INSIDE

