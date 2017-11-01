#include <iostream>
#include <vector>
using namespace std;

struct Transacao{
    string nome;
    int value;
    Transacao(string n, int v){
        nome = n;
        value = v;
    }
    friend ostream& operator<<(ostream& os, Transacao t){
        os << "nome:" << t.nome << " value:" << t.value;
        return os;
    }
};

class Observador{
public:
    virtual void notify(Transacao tr) = 0;
};

class Financas{
public:
    vector<Observador*> vobs;
    vector<Transacao> vt;

    Financas(){
    }
    void registrar(Observador *ob){
        vobs.push_back(ob);
    }
    void add(Transacao tr){
        vt.push_back(tr);
        for(auto obs : vobs)
            obs->notify(tr);
    }

    friend ostream& operator<<(ostream& os, Financas f){
        os << "Financas: " << endl;
        for(auto t : f.vt)
            os << "nome:" << t.nome << " value:" << t.value << endl;
        return os;
    }
};

class OlhaFulano : public Observador{
public:
    string nome;
    OlhaFulano(string fulano){
        nome = fulano;
    }

    void notify(Transacao tr){
        if(tr.nome == nome)
            cout << nome << " passou por aqui" << endl;
    }
};

class MaisQueTanto : public Observador{
public:
    int tanto;
    MaisQueTanto(int tanto){
        this->tanto = tanto;
    }

    void notify(Transacao tr){
        if(tr.value >= tanto)
            cout << "dinheiro " << tanto << " correndo frouxo" << endl;
    }
};

int main()
{
    Financas fn;
    OlhaFulano ooa("adolfo");
    OlhaFulano ooze("zeruela");
    fn.registrar(&ooa);
    fn.registrar(&ooze);

    MaisQueTanto m1200(1200);
    fn.registrar(&m1200);

    fn.add(Transacao("jose", 500));
    fn.add(Transacao("adolfo", 5));
    fn.add(Transacao("adolfo", 100));
    fn.add(Transacao("zeruela", 1400));

    return 0;
}







