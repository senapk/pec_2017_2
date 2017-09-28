#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
T read(){
    T t;
    cin >> t;
    return t;
}

class Segredo{
    int nivel;
    string texto;
public:
    static const int minNivel {1};
    static const int maxNivel {10};
    static constexpr const char * defaultTexto = "Escreva seu segredo";

    Segredo(int nivel = Segredo::minNivel,
            string texto = Segredo::defaultTexto)
    {
        setNivel(nivel);
        setTexto(texto);
    }

    void setNivel(int value){
        if(value < Segredo::minNivel || value > Segredo::maxNivel)
            nivel = Segredo::minNivel;
        else
            nivel = value;
    }

    int getNivel(){
        return nivel;
    }

    string getTexto(){
        return texto;
    }

    void setTexto(string texto){
        if(texto == "")
            this->texto = Segredo::defaultTexto;
        else
            this->texto = texto;
    }

    friend ostream& operator<<(ostream &os, Segredo segredo){
        os << "[Nivel: " << segredo.nivel << " Texto: " << segredo.texto << "]";
        return os;
    }
};

class Usuario{
    string username;
    string password;
    Segredo segredo;
public:
    Usuario(string username, string password):
        username(username), password(password)
    {
    }

    bool operator< (Usuario other){
        return username < other.username;
    }

    bool matchPassword(string password){
        return this->password == password;
    }
    string getName(){
        return username;
    }
    friend ostream& operator<<(ostream &os, Usuario usuario){
        os << "username: " << usuario.username
           << " password: " << usuario.password
           << " segredo: " << usuario.segredo;
        return os;
    }
    Segredo getSegredo(){
        return segredo;
    }
    void setSegredo(Segredo segredo){
        this->segredo = segredo;
    }
};

class Sistema {
    vector<Usuario> usuarios;
public:
    static constexpr const char * adminUser = "admin";
    static constexpr const char * adminPass = "admin";
    Sistema(){
        usuarios.push_back(Usuario(Sistema::adminUser, Sistema::adminPass));
    }

    vector<Usuario> getUsers(){
        std::sort(usuarios.begin(), usuarios.end());
        return usuarios;
    }

    bool addUser(Usuario usuario){
        for(auto elem : usuarios)
            if(elem.getName() == usuario.getName())
                return false;
        usuarios.push_back(usuario);
        return true;
    }

    bool rmUser(string username){
        for(int i = 0; i < (int) usuarios.size(); i++){
            if(usuarios[i].getName() == username){
                usuarios.erase(usuarios.begin() + i);
                return true;
            }
        }
        return false;
    }

    Usuario * login(string username, string password){
        for(auto& elem : usuarios)
            if(elem.getName() == username)
                if(elem.matchPassword(password))
                    return &elem;
        return nullptr;
    }
};

bool compNivel(Usuario a, Usuario b){
    return !(a.getSegredo().getNivel() < b.getSegredo().getNivel());
}

class Controller {
    Usuario * usuario;
    Sistema sistema;
public:
    Controller(){
        usuario = nullptr;
        sistema.addUser(Usuario("david", "sena"));
        sistema.login("david", "sena")->setSegredo(Segredo(10, "Comi fruta E doce"));
        sistema.addUser(Usuario("ana", "amora"));
        sistema.login("ana", "amora")->setSegredo(Segredo(5, "comi o danone da geladeira"));
        sistema.addUser(Usuario("julia", "sena"));
        sistema.login("julia", "sena")->setSegredo(Segredo(2, "ponho o dedo no nariz"));
    }
    void commandLine(){
        string ui;
        while(ui != "fim"){
            cout << "Digite comando ou help: ";
            if(usuario)
                cout << usuario->getName() << ":";
            cin >> ui;

            if(ui == "help"){
                cout << "showUsers" << endl;
                cout << "addUser _usuario _password" << endl;
                cout << "login _usuario _passowrd" << endl;
                cout << "rmAccount _passowrd" << endl;
                cout << "show" << endl
                     << "logout" << endl;

            }
            else if(ui == "showUsers"){
                auto users = sistema.getUsers();
                for(auto elem : users)
                    cout << elem.getName() << endl;
            }
            else if(ui == "addUser"){
                auto user = read<string>();
                sistema.addUser(Usuario(user, read<string>()));
            }
            else if(ui == "login"){
                auto user = read<string>();
                usuario = sistema.login(user, read<string>());
            }
            else if(usuario == nullptr){
                cout << "voce precisa estar logado" << endl;
            }//daqui pra baixo sei que usuario eh diferente de nullptr
            else if(ui == "logout"){
                usuario = nullptr;
            }
            else if(ui == "rmAccount"){
                if(usuario->matchPassword(read<string>())){
                    sistema.rmUser(usuario->getName());
                    usuario = nullptr;
                }

            }
            else if(ui == "show"){
                cout << (*usuario) << endl;
            }
            else if(ui == "showAll"){
                if(usuario->getName() != Sistema::adminUser){
                    cout << "usuario sem permissao" << endl;
                    continue;
                }

                auto users = sistema.getUsers();
                sort(users.begin(), users.end(), compNivel);
                for(auto elem : users)
                    cout << elem << endl;

            }
        }

    }
};

int main()
{
    Controller controller;
    controller.commandLine();
}
