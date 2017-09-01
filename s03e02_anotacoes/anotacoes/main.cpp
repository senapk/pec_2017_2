#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Nota{
    string titulo;
    string texto;
public:
    Nota(string titulo = " ", string texto = " "){
        this->titulo = titulo;
        this->texto = texto;
    }

    string getTitulo(){
        return titulo;
    }
    string getTexto(){
        return texto;
    }

    void setTitulo(string titulo){
        this->titulo = titulo;
    }

    void setTexto(string texto){
        this->texto = texto;
    }

};

class Usuario{
    string username;
    string password;
    vector<Nota> notas;
public:
    Usuario (string username = "", string password = ""){
        this->username = username;
        this->password = password;
    }

    string getUsername(){
        return username;
    }

    bool updatePass(string  oldpass, string newpass){
        if(this->password == oldpass){
            this->password = newpass;
            return true;
        }
        return false;
    }

    bool addNota(Nota nota){
        for(auto elemento : notas){
            if(elemento.getTitulo() == nota.getTitulo())
                return false;
        }
        notas.push_back(nota);
        return true;
    }

    bool checkPassword(string password){
        return this->password == password;
    }

    string toString(){
        stringstream ss;
        ss << username << endl;
        for(auto nota : notas)
            ss << "[ " << nota.getTitulo() << "; " << nota.getTexto() << "]" << endl;
        return ss.str();
    }
};

class Sistema{
    vector<Usuario> usuarios;
public:
    Sistema(){
    }

    //não pode ter dois usernames iguais
    bool addUser(string username, string password){
        for(auto usuario : usuarios)
            if(usuario.getUsername() == username)
                return false;
        usuarios.push_back(Usuario(username, password));
        return true;
    }

    Usuario * getUser(string username, string password){
        for(auto& usuario : usuarios)
            if((usuario.getUsername() == username) && (usuario.checkPassword(password)))
                return &usuario;
        return nullptr;
    }
};

void commandLine(Sistema& sistema){
    string op = "";

    Usuario * usuario = nullptr;
    while(op != "fim"){
        cin >> op;
        if(op == "help"){
            cout << "addUser $username $password" << endl
                 << "updatePass $oldpass $newpass" << endl
                 << "addNote $titulo $textao" << endl
                 << "login $username $password" << endl
                 << "logout" << endl
                 << "show" << endl;
        }

        if(op == "addUser"){
            string name, pass;
            cin >> name >> pass;
            if(sistema.addUser(name, pass))
                cout << "sucesso" << endl;
            else
                cout << "username duplicado" << endl;
        }

        if(op == "login"){
            string name, pass;
            cin >> name >> pass;
            usuario = sistema.getUser(name, pass);
            if(usuario == nullptr)
                cout << "erro de login" << endl;
            else
                cout << "sucesso" << endl;
        }
        if(op == "show"){
            if(usuario == nullptr)
                cout << "ninguem logado" << endl;
            else
                cout << usuario->toString() << endl;
        }
        if(op == "logout"){
            usuario = nullptr;
        }
        if(op == "updatePass"){
            string old, newp;
            cin >> old >> newp;
            if(usuario == nullptr)
                cout << "ninguem logado" << endl;
            else{
                if(usuario->updatePass(old, newp))
                    cout << "ok" << endl;
                else
                    cout << "senha invalida" << endl;
            }
        }
        if(op == "addNote"){
            string titulo, texto;
            cin >> titulo;
            getline(cin, texto);
            if(usuario){
                if(usuario->addNota(Nota(titulo, texto)))
                    cout << "nota adicionada" << endl;
                else
                    cout << "titulo duplicado" << endl;
            }else{
                cout << "usuario nao logado" << endl;
            }
        }
    }
}


void initialize(Sistema &sistema){
    sistema.addUser("januario", "respeita");
    sistema.addUser("luiz", "luiz");
    Usuario * januario = sistema.getUser("januario", "respeita");
    januario->addNota(Nota("comprar", "baladeira de couro"));
    januario->addNota(Nota("vender", "baladeira pra ontem"));
    januario->addNota(Nota("chorar", "lagartixa que perdeu o rabo"));
    Usuario * luiz = sistema.getUser("luiz", "luiz");
    luiz->addNota(Nota("comprar", "estilingue"));
    luiz->addNota(Nota("vender", "estilingue com bolinhas"));
    luiz->addNota(Nota("rir", "i am bad!"));
}




int main()
{
    Sistema sistema;
    initialize(sistema);
    commandLine(sistema);
    return 0;
}
























