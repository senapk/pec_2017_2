#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


//int main()
//{
//    cout << "Digite a palavra magica para entrar na caverna: " << endl;
//    string palavra;
//    ifstream ifs("../erros/palavra_errada.txt");
//    ifs >> palavra;
//    ofstream erros("../erros/erros.txt");
//    if(palavra == "abre_te_sesamo")
//        cout << "Voce ganhou o tesouro" << endl;
//    else{
//        cout << "sistema indisponivel no momento, tente mais tarde" << endl;
//        erros << "tem um ze doidin tentando acessar o sistema" << endl;
//    }
//    return 0;
//}


#include <vector>
enum FLAG_SAIDA {SUCESSO = 1, NUMERO_INVALIDO = 100, ID_JA_EXISTE = 200};

namespace contatos_com_flags {
class Fone {
public:
    string id;
    string num;
    static bool validade(string num){
        return (num.find("#") == string::npos);
    }
};

class Contato {
public:
    vector<Fone> fones;

    FLAG_SAIDA addFone(Fone fone){
        if(!fone.validade(fone.num))
            return NUMERO_INVALIDO;
        for(auto elem : fones)
            if(elem.id == fone.id)
                return ID_JA_EXISTE;
        fones.push_back(fone);
        return SUCESSO;
    }
};

int main(){
    Contato cont;
    cont.addFone(Fone{"oi", "322"});
    FLAG_SAIDA fs = cont.addFone(Fone{"oi", "322"});
    if(fs == SUCESSO)
        cout << "Sucesso" << endl;
    else
        cout << "erro: " << static_cast<int>(fs);
    cout << endl;
    return 0;
}
}//namespace erros_em_c

namespace retornando_erros_por_parametro {
float dividir(int num, int den, FLAG_SAIDA& fs){
    if(den == 0){
        fs = ID_JA_EXISTE;
        return 0;
    }
    fs = SUCESSO;
    return (float)num / den;
}

int main(){
    cout << "digite dois numeros inteiros" << endl;
    int num = 0, den = 0;
    cin >> num >> den;
    FLAG_SAIDA deu_certo = SUCESSO;
    float result = dividir(num, den, deu_certo);
    if(deu_certo)
        cout << result << endl;
    else
        cout << "deu mal" << endl;
    return 0;
}
}//namespace retornando_erros_por_parametro

namespace retornando_erros_por_excessao {
float dividir(int num, int den){
    if(den == 0)
        throw "divisao por zero";
    return (float)num / den;
}

int main(){
    cout << "digite dois numeros inteiros" << endl;
    int num = 0, den = 0;
    cin >> num >> den;
    try{
        cout << dividir(num, den);
    }catch(const char* str){
        cout << str << endl;
    }
    return 0;
}
}//namespace retornando_erros_por_parametro


namespace contatos_com_excessoes {
class Fone {
public:
    string id;
    string num;
    static bool validade(string num){
        return (num.find("#") == string::npos);
    }
};

class Contato {
public:
    vector<Fone> fones;

    void addFone(Fone fone){
        if(!fone.validade(fone.num))
            throw "telefone com numero invalido";
        for(auto elem : fones)
            if(elem.id == fone.id)
                throw "id ja existe";
        fones.push_back(fone);
    }
};

int main(){
    Contato cont;
    try{
        cont.addFone(Fone{"oi", "322#"});
    }catch(const char* msg){
        (void) msg;
    }

    try {
        cont.addFone(Fone{"oi", "3#22"});
        cout << "sucesso" << endl;
    }catch(const char* msg) {
        cout << msg << endl;
    }

    return 0;
}
}//namespace erros_em_c

int main(){
    contatos_com_excessoes::main();
    return 0;
}














