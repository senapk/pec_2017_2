#include <iostream>
#include "poo_aux.h"
#include "hospital.h"
#include "poo_controller.h"
#include "poo_repository.h"

using namespace std;
using namespace poo;


class Hospital : public Controller{
    Repository<Medico> r_med;
    Repository<Plantao> r_pla;
    Repository<Paciente> r_pac;

public:
    Hospital():
        r_med("medico"),
        r_pla("plantao"),
        r_pac("paciente")
    {
    }

    string process(string line){
        auto ui = poo::split(line, ' ');
        auto cmd = ui[0];
        if(cmd == "addPac"){//_pac _pac _pac _pac
            for(int i = 1; i < (int) ui.size(); i++){
                try{
                    r_pac.add(ui[i], Paciente(ui[i]));
                }catch(string e){
                    cout << tab(e) << endl;
                }
            }
        }
        else if(cmd == "addPla"){//_pla _pla _pla
            for(int i = 1; i < (int) ui.size(); i++){
                r_pla.add(ui[i], Plantao(ui[i]));
            }
        }
        else if(cmd == "addMed"){//
            for(int i = 1; i < (int) ui.size(); i++){
                r_med.add(ui[i], Medico(ui[i]));
            }
        }
        else if(cmd == "show"){
            return "Med: " + r_med.keys() + "\n" +
                   "Pac: " + r_pac.keys() + "\n" +
                   "Pla: " + r_pla.keys();
        }else if(cmd == "tieMedPac"){//_med _pac _pac _pac
            for(int i = 2; i < (int) ui.size(); i++)
                r_med.get(ui[1])->addPaciente(r_pac.get(ui[i]));
        }else if(cmd == "tieMedPla"){//_med _pla _pla ..
            for(int i = 2; i < (int) ui.size(); i++){
                try{
                    r_med.get(ui[1])->addPlantao(r_pla.get(ui[i]));
                }catch(string e){
                    cout << poo::tab(e) << endl;
                }
            }
        }else if(cmd == "pac"){//_pac
            return "Pac" + r_pac.get(ui[1])->id +
                    " Med:" + *r_pac.get(ui[1])->getMedicos();
        }else if(cmd == "pla"){//_pla
            return "Pla" + r_pla.get(ui[1])->id +
                    " Med:" + *r_pla.get(ui[1])->getMedicos();
        }else{
            return "comando invalido";
        }
        return "done";
    }
};

int main(){
    Hospital h;
    h.commandLine();
}
/*














  */





