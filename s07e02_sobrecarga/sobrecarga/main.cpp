#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Macaco{
public:
    string nome;
    int idade;
    char sexo;

    Macaco(string nome, int idade, char sexo){
        this->nome = nome;
        this->idade = idade;
        this->sexo = sexo;
    }

    Macaco operator+(Macaco other){
        if(this->sexo != 'F')
            cout << "Nao eh femea" << endl;
        if(other.sexo != 'M')
            cout << "O par tem que ser macho" << endl;
        return Macaco(nome.substr(0, 3) +
                     other.nome.substr(3), 0,
                     rand() % 2 == 0 ? 'F' : 'M');
    }

    void operator*(){
        if(sexo == 'M')
            cout << "EEEEEE" << endl;
        else
            cout << "eeeeee" << endl;
    }

    bool operator[](Macaco other){
        return (sexo == 'M' && other.sexo == 'M');
    }

    friend ostream& operator<<(ostream& os, const Macaco& other){

    }
};




void operator+ (Macaco& one, int idade){
    one.idade += idade;
}

int main()
{
    srand(time(NULL));
    Macaco matheusa("Deusa", 12, 'F');
    Macaco andreio("Marcelino", 19, 'M');
    Macaco filho =  matheusa + andreio;
    *andreio;
    cout << filho.nome << " " << filho.idade
         << " " << filho.sexo << endl;
    cout << (filho[andreio]) << endl;
    return 0;
}









