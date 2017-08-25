#include <iostream>
#include <vector>

using namespace std;

class Circense{
public:
    string nome;
    string especialidade;
    Circense(string nome = "Tanguinha", string especialidade = "palhaco"){
        this->nome = nome;
        this->especialidade = especialidade;
    }
    float salario;
};

class Pessoa{
public:
    string nome;
    vector<string> preferencias;
    int idade;
    int alegria{0};

    Pessoa(string nome = "", int idade = 18, vector<string> preferencias = vector<string>()){
        this->nome = nome;
        this->idade = idade;
        this->alegria = 0;
        this->preferencias = preferencias;
    }

    void verEspetaculo(vector<Circense>& vetor){

        for (Circense& circense : vetor)
            for(string pref : preferencias)
                if(circense.especialidade == pref )
                    this->alegria += 1;

        /* MODO INDEXADO
         * for (int i = 0; i < vetor.size(); i++)
            for(int j = 0; j < preferencias.size(); j++)
                if(vetor[i].especialidade == preferencias[j])
                    this->alegria += 1;

        */

    }

    void addPreferencias(string pref){
        preferencias.push_back(pref);
    }


};


#include <vector>
#include <sstream>
int main(){
    vector<Pessoa> plateia = {Pessoa("Bia", 5, {"palhaco", "domador", "magico"}),
                              Pessoa("Ruy", 50, {"contorcionista"}),
                              Pessoa("Ana", 8, vector<string>(10, "palhaco"))};
    vector<Circense> atracoes = {Circense("Tanguinha", "palhaco"),
                                 Circense("Shazam", "magico"),
                                 Circense("Juvenal", "domador"),
                                 Circense("Valentina", "contorcionista")};
    for(Pessoa &pessoa : plateia)
        pessoa.verEspetaculo(atracoes);

    for(Pessoa &pessoa : plateia)
        cout << pessoa.nome << " " << pessoa.alegria << "\n";

}

























