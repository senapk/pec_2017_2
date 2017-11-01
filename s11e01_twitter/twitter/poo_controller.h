#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "poo_aux.h"
#include "iostream"
using namespace std;

class Controller{
public:
    virtual string process(string line){
        return line;
    }

    void commandLine() {
        std::cout << "Digite help, cmd ou fim:" << std::endl;
        string line = "";
        while(line != "fim"){
            std::getline(std::cin, line); //pega a linha

            if((line == "" ) || (line.substr(0, 2) == "  "))//se for resposta pula
                continue;
            std::cout << line << std::endl; //mostra
            if(line[0] == '#')//newline ou comentario
                continue;
            //executa o comando
            try {
                string resp = this->process(line);
                std::cout << poo::tab(resp) << std::endl;
            } catch(const std::string& e) {
                std::cout << poo::tab(e) << std::endl;
            }
        }
    }
};
#endif // CONTROLLER_H

