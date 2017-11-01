#ifndef POO_H
#define POO_H
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <list>

namespace poo {

//faz o cast de string para qualquer coisa
template <class T>
T cast(std::string palavra){
    T value;
    std::stringstream(palavra) >> value;
    return value;
}

inline int Int(std::string word){
    return cast<int>(word);
}

inline int Float(std::string word){
    return cast<float>(word);
}


//quebra o texto em um vetor de pedaços, utilizando o separador sep
//tal qual em python ou javascript
std::vector<std::string> split(const std::string& text, char sep = ' '){
    std::vector<std::string> saida;
    std::istringstream ss(text);
    std::string token;
    while(getline(ss, token, sep))
        saida.push_back(token);
    return saida;
}

//dá um tab no texto
//retorna o texto tabeado
//voce pode passar o tab em prefix ao inves do padrão de dois espacos
std::string tab(std::string data, std::string prefix = "  "){
    auto linhas = split(data, '\n');
    std::string saida = "";
    for(auto& line : linhas)
        saida += prefix + line + "\n";
    if(saida.size() > 0)
        saida.pop_back();//remove a ultima \n
    return saida;
}

//gera um novo vetor com as copias dos dados do vetor original
//para dentro do intervalo selecionado
//copia de _begin ate _end nao incluindo _end
template<class T>
std::vector<T> slice(std::vector<T>& vet, int vbegin = 0, int vend = -1){
    std::vector<T> new_vet;
    int size = vet.size();
    if(vend == -1)
        vend = size;
    for(int i = vbegin; i < vend; i++)
        new_vet.push_back(vet[i]);
    return new_vet;
}





//retorna os values de um map
template<class K, class T>
std::vector<T> map_values(std::map<K, T> &mapa){
    std::vector<T> vet;
    for(auto& par: mapa)
        vet.push_back(par.second);
    return vet;
}

//retorna as chaves de um map
template<class K, class T>
std::vector<K> map_keys(std::map<K, T> &mapa){
    std::vector<K> vet;
    for(auto& par: mapa)
        vet.push_back(par.first);
    return vet;
}

//usa a sobrecarga ostream<< para converter qualquer coisa
//que possua a sobrecarga para string
template <typename T>
std::string to_string(const T& value) {
  std::ostringstream os;
  os << value;
  return os.str();
}


//dado um vetor de ponteiros, retorna um vetor de inteiros
template<class T>
std::vector<T> to_values(std::vector<T*> v_ref){
    std::vector<T> vet;
    for(int i = 0; i < (int) v_ref.size(); i++)
        vet.push_back(*v_ref[i]);
    return vet;
}

//transforma de vetor para uma string
//utiliza a sobrecarga ostream<< para escrever cada objeto
//para string
template<class T>
std::string join(std::vector<T> vet, std::string separ){
    std::stringstream ss;
    for(int i = 0; i < (int) vet.size() - 1; i++)
        ss << vet[i] << separ;
    if(vet.size() > 0)
        ss << vet.back();
    return ss.str();
}

//sobrecarga do join que transforma gera as strings a partir
//dos um vetor de ponteiros
template<class T>
std::string pjoin(std::vector<T*> vet, std::string separ){
    return join(to_values<T>(vet), separ);
}

//versao para listas
template<class T>
std::string join(std::list<T> lista, std::string separ){
    return join(std::vector<T>(lista.begin(), lista.end()), separ);
}

//versao para listas
template<class T>
std::string pjoin(std::list<T*> lista, std::string separ){
    return pjoin(std::vector<T*>(lista.begin(), lista.end()), separ);
}

}

#endif // POO_H
