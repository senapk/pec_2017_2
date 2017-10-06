#include <iostream>
#include <vector>
#include <algorithm>

class Passageiro {
    std::string cpf; //unico no sistema
};

class Vagao {
    std::string id;
    std::vector<Passageiro*> cadeiras;
    Vagao(std::string id, int capacidade):
        cadeiras(capacidade, nullptr)
    {
//        for(int i = 0; i < capacidade; i++)
//            cadeiras.push_back(nullptr);
    }

    int lotacao() {
//        int cont = 0;
//        for(auto pass : cadeiras)
//            if(pass)
//                cont++;
//        return cont;
        return cadeiras.size() - std::count(cadeiras.begin(), cadeiras.end(), nullptr);
    }

    bool embarque(Passageiro * passageiro) {
//        for(int i = 0; i < (int) cadeiras.size(); i++){
//            if(!cadeiras[i]){
//                cadeiras[i] = passageiro;
//                return true;
//            }
//        }
//        return false;

        for(Passageiro* &pass : cadeiras){
            if(!pass){
                pass = passageiro;
                return true;
            }
        }
        return false;
    }

    Passageiro * desembarque(string nome) {

    }
};

void poneis_malditos(){
    int a = 1;
    int * x = &a;
    *x = 5;//a se torna 5

    int * y = x;
    *y = 6;//a se torna 6

    y = nullptr;

    auto &z = x;
    z = nullptr;

    int c = 8;
    int &d = c;
}
