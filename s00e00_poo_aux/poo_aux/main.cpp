#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <sstream>
#include <poo_aux.h>
using namespace std;

struct Ovo{
    string nome;
    Ovo(string n = ""){
        nome = n;
    }
    string toString(){
        return nome;
    }
    TO_OSTREAM(Ovo)
};


int main()
{
    vector<int> vet = {1, 2, 3, 4};
    vector<int*> pvet = {new int(1), new int(3), new int(4)};
    vector<string> vetc = {"hoje", "eh", "sabado"};

    int x = 5;
    string s("hoje");
    cout << x << endl;
    cout << s << endl;
    cout << "batata" << endl;
    cout << "" + Ovo("sergio") + 5 + 4.50 << endl;
    cout << vet << endl;
    cout << vetc << endl;
    cout << *pvet << endl;

    return 0;
}

