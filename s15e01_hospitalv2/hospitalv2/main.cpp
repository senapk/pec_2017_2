#include <iostream>
#include <list>
#include <functional>
#include <algorithm>

using namespace std;


class Banco{
    list<function<void(int)>> observadores;

    saque(int value){
        for(auto obs : this->observadores)
            obs(value);
    }
};

class Gerente{
    string msgs;
    Gerente(Banco * banco){
        banco.addObs([&msgs](int x){
            if(x > 500)
                msgs.push_back("valor excessivo");
        });
    }
}




//struct Msg{
//    string nome;
//    string desc;
//    Msg(string nome, string desc){
//        this->nome = nome;
//        this->desc = desc;
//    }
//};

//class Pessoa{
//public:
//    string nome;
//    list<Msg> msgs;
//    void sendMsg(string nome, Msg msg){
//        auto pessoas = obterDests();
//        auto it = std::find_if(pessoas.begin(), pessoas.end(), [nome](Pessoa * p){
//            return p->nome == nome;
//        });
//        if(it == pessoas.end())
//            return;
//        Pessoa *p = *it;
//        p->msgs.push_back(msg);
//    }
//    virtual list<Pessoa*> obterDests() = 0;
//    list<Msg> lerMsgs(){
//        return msgs;
//    }
//};

//class Medico;

//class Paciente: public Pessoa{
//public:
//    string diag;
//    list<Medico*> medicos;
//    list<Pessoa*> obterDests(){
//        list<Pessoa*> pessoas;
//        for(auto medico: medicos)
//            pessoas.push_back(medico);
////        std::transform(medicos.begin(), medicos.end(),
////                       std::back_inserter(pessoas),
////                       [](Medico * m){return m});
//        return pessoas;
//    }
//};

//class Medico: public Pessoa{
//public:
//    string espec;
//    list<Paciente*> pacientes;
//    void atender(Paciente * pac){
////        for(Paciente * elem : pacientes)
////            if(elem->nome == pac->nome)
////                return false;
//        auto it = std::find_if(pacientes.begin(), pacientes.end(),
//        [pac](Paciente * elem){
//            return elem->nome == pac->nome;
//        });
//        if(it != pacientes.end())
//            return;
//        pacientes.push_back(pac);
//        pac->medicos.push_back(this);
//    }
//};

//void facaIssoemC(int (*f)(int,int)){
//    cout << f(3, 4) << endl;
//}

//void facaIssoemCpp(function<int(int, int)> f){
//    cout << f(3, 4) << endl;
//}

//int soma(int a, int b){
//    return a + b;
//}

int main()
{
//    int x = 5;
//    auto flambda = [&x](int y, int z){return x-- + y * z;};
//    facaIssoemC(soma);
//    facaIssoemCpp(soma);
//    facaIssoemCpp(flambda);
//    facaIssoemCpp(flambda);
//    facaIssoemCpp(flambda);


    list<string> nomes = {"davi", "andreia", "felipe", "aurilene"};

    list<int> numeros = {1, 3, 4, 2, 5, 6};

//    int result = std::accumulate(numeros.begin(), numeros.end(), 0,
//                                 [](int x, int y){return x + y;});

    string sresult = std::accumulate(nomes.begin(), nomes.end(), string(""),
                                    [](string a, string b)-> string {return a + " " + b;});

    std::remove_if(nomes.begin(), nomes.end(), [](string s){return s[0] == 'a';});

    //std::random_shuffle(nomes.begin(), nomes.end());

    cout << sresult << endl;
    sresult = std::accumulate(nomes.begin(), nomes.end(), string(""),
                                    [](string a, string b)-> string {return a + " " + b;});

    cout << sresult << endl;



    return 0;
}










