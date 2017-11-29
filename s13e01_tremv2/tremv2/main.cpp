#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#if 0
class Hero{
public:
    //virtual                  puro
    virtual void callPower() = 0;
};

//classe abstrata
class Animal{
protected:
    string nome;
public:
    Animal(string nome = ""){
        this->nome = nome;
    }
    string getNome(){
        return nome;
    }

//    virtual void grunir() = 0;//abstrato

    virtual void grunir(){ //ligacao tardia
        cout << this->nome + " faz ble" << endl;
    }

    string toString(){
        return nome;
    }
    friend void matar(Animal& animal);
};

class Dog : public Animal, public Hero{
public:
    Dog(string nome):
        Animal(nome)
    {}
    void grunir(){
        cout << "[" + this->getNome() + "] latindo:  Au au au" << endl;
    }
    string toString(){
        return "Dog " + Animal::toString();
    }
    virtual void callPower(){
        cout << "[" + this->getNome() + "] auuuuuuuuuuuuuuuu" << endl;
    }
};

class Cat : public Animal{
public:
    Cat(string nome):
        Animal(nome)
    {}
    void grunir(){
        cout << "[" + this->nome + "] miando:  miallll" << endl;
    }
    string toString(){
        return "Cat " + Animal::toString();
    }
    void auto_lamber_se_a_si_mesmo_mutuamente(){
        cout << this->nome + " esta tomando banho" << endl;
    }
};


void matar(Animal& animal){
    animal.nome += " RIP";
}

int main()
{

    Dog dog("Nick");
    Cat cat("Mimoso");
    dog.grunir();
    cat.grunir();
    cout << cat.toString() << " " << dog.toString() << endl;
    matar(dog);
    matar(cat);
    cout << cat.toString() << " " << dog.toString() << endl;

    Animal * mimi = &cat;
    cout << mimi->toString() << endl;
    mimi->grunir();


    vector<Animal*> animais;

    animais.push_back(new Cat("Xanin"));
    animais.push_back(new Cat("Valente"));
    animais.push_back(new Dog("Tangerina"));

    for(auto x : animais)
        x->grunir();

    Hero pegasus;
    pegasus.callPower();
    Animal * tang = animais.back();
    Dog * dtan = dynamic_cast<Dog*>(tang);
    dtan->callPower();

    Animal anim("Coiso");

    Dog * dchanin = dynamic_cast<Dog*> (animais.front());
    if(dchanin){
        dchanin->callPower();
    }else{
        cout << "Nao eh um cachorro" << endl;
    }
    return 0;
}


Pessoa
    nome
    toString
Aluno
    mat
    toString
Prof
    siape
    toString

vector<Pessoa*> sala;
imprimir a sala
#endif

class Pessoa{
protected:
    string nome;
public:
    Pessoa(string nome = ""){
        this->nome = nome;
    }

    virtual string toString(){
        return this->nome;
    }
    virtual ~Pessoa(){
    }
};

class Aluno : public Pessoa{
    string * matricula;
public:
    Aluno(string matricula = "", string nome = ""):
        Pessoa(nome)
    {
        this->matricula = new string(matricula);
    }
    string toString(){
        return "Aluno " + this->nome + " matricula " + *this->matricula;
    }
    ~Aluno(){
        delete matricula;
    }
};

class Professor : public Pessoa{
    string siap;
public:
    Professor(string siap = "", string nome= ""):
        Pessoa(nome)
    {
        this->siap = siap;
    }
    string toString(){
        return "Professor " + this->nome + " siap " + this->siap;
    }
};

int main(){

    vector<Pessoa*> sala;

    sala.push_back(new Aluno("1234","Joel"));
    sala.push_back(new Aluno("3231","Fernanda"));
    sala.push_back(new Professor("2222","david_Sena"));

    for(auto x : sala)
       cout << x->toString() << endl;

    while(!sala.empty()){
        delete sala.back();
        sala.pop_back();
    }

}

class Embarcavel{
    virtual string getId() = 0;
};


class Vagao{
    virtual bool embarcar(Embarcavel * emb) = 0;
    virtual bool desembarcar(string id) = 0;
    string toString() = 0;
};










