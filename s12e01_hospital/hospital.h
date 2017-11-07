#ifndef HOSPITAL
#define HOSPITAL
#include <map>
#include <vector>
#include <iostream>
#include "poo_aux.h"
using namespace std;
using namespace poo;

class Medico;
class Plantao;

class Paciente{
    map<string, Medico*> m_med;
public:
    string id;
    Paciente(string id = ""){
        this->id = id;
    }


    vector<Medico*> getMedicos();
    string toString(){
        return id;
    }
    TO_OSTREAM(Paciente)
    friend class Medico;
};

class Plantao{
    map<string, Medico*> m_med;
public:
    string id;
    Plantao(string id = ""){
        this->id = id;
    }

    vector<Medico*> getMedicos(){
        return poo::map_values(m_med);
    }
    string toString(){
        return id;
    }
    TO_OSTREAM(Plantao)
    friend class Medico;
};


class Medico{
    map<string, Paciente*> m_pac;
    map<string, Plantao*> m_pla;
public:
    string id;
    Medico(string id = ""){
        this->id = id;
    }

    vector<Paciente*> getPacientes(){
        return poo::map_values(m_pac);
    }
    vector<Plantao*> getPlantoes(){
        return poo::map_values(m_pla);
    }

    void addPlantao(Plantao * pla){
        if(m_pla.count(pla->id))
            return;
        this->m_pla[pla->id] = pla;
        pla->m_med[this->id] = this;
    }

    void rmPlantao(string idPla){
        if(!this->m_pla.count(idPla))
            return;
        this->m_pla[idPla]->m_med.erase(this->id);
        this->m_pla.erase(idPla);
    }

    void addPaciente(Paciente * pac){
        if(m_pac.count(pac->id))
            return;
        this->m_pac[pac->id] = pac;
        pac->m_med[this->id] = this;
    }

    void rmPaciente(string idPac){
        if(!this->m_pac.count(idPac))
            return;
        this->m_pac[idPac]->m_med.erase(this->id);
        this->m_pac.erase(idPac);
    }
    string toString(){
        return id;
    }
    TO_OSTREAM(Medico)
};

vector<Medico *> Paciente::getMedicos(){
    return poo::map_values(m_med);
}


#endif // HOSPITAL



