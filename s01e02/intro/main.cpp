#include <iostream>

using namespace std;

struct Comida{
    string nome;
    int vnut;
    Comida(string _nome, int _vnut){
        nome = _nome;
        vnut = _vnut;
    }
};

enum Tipo{Borboleta, Unicornio, Baleia};

struct Tamagochi{
    Tipo tipo;
    int idade;
    string nome;
    int fome;
    bool vivo;
    int fomeMax {10};
    int forca;
    int vida;

    Tamagochi(string nome, Tipo tipo){
        this->nome = nome;
        this->tipo = tipo;
        idade = 0;
        fome = 0;
        vivo = true;
        forca = 3 + rand() % 3;
        vida = 10 + rand() % 5;
    }

    virtual void levarDano(int value){
        this->vida -= value;
        if(vida < 0)
            vivo = false;
    }

    void atacar(Tamagochi &other){
        cout << nome << "(" << vida << ")"
             << " ataca "
             << other.nome << "(" << other.vida << ")"
             << endl;
        if(!vivo){
            cout << nome << "esta morto" << endl;
            return;
        }
        int dano = rand () % this->forca;
        other.levarDano(dano);
        cout << "golpe " << dano;
        if(other.vivo){
            int golpe = rand () % other.forca;
            this->levarDano(golpe);
            cout << " , contragolpe " << golpe;
        }
    }

    void comer(Comida comida){
        if(!vivo){
            cout << "Morto nao come";
            return;
        }
        this->fome -= comida.vnut;
        if(fome < 0)
            fome = 0;
    }

    void passarTempo(){
        fome += 1;
        if(fome > fomeMax)
            vivo = false;
    }

    void envelhecer(){
        if(!vivo){
            cout << "Morto nao envelhece" << endl;
            return;
        }
        idade += 1;
        if(idade > 5){
            vivo = false;
            cout << nome << "Morreeeeeeeeeu" << endl;
        }

    }

    void show(){
        cout << "Nome: " << this->nome
             << "\nFome: " << this->fome
             << "\nForca: " << this->forca
             << "\nVida: " << this->vida
             << "\nIdade: " << this->idade << endl;
    }
};

struct TamaFenix : public Tamagochi{
    TamaFenix(string nome, Tipo tipo):
        Tamagochi(nome, tipo){
    }

    void levarDano(int value){
        Tamagochi::levarDano(value);
        if(!this->vivo)
            if(rand() % 100 < 90){
                vivo = true;
                this->vida = 1;
                this->forca *= 1.5;
            }
    }

    void queimarCosmo(){
        forca *= 10;
    }
};


#include <cstdlib>
#include <ctime>

int main()
{    

    srand(time(NULL));
    Tamagochi * t1 = new TamaFenix("Bolsonaro", Unicornio);
    Tamagochi * t2 = new Tamagochi("MariaDoRosario", Borboleta);
    t2->vida += 30;
    t1->show();
    t2->show();

    while(t1->vivo && t2->vivo){
        if(rand() % 2 == 0)
            std::swap(t1, t2);
        t1->atacar(*t2);
        getchar();
    }
    if(t1->vivo)
        cout << t1->nome << " venceu" << endl;
    else
        cout << t2->nome << " venceu" << endl;


    return 0;
}












