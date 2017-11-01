#include <iostream>
#include <list>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "sftext.h"
#include <ctime>
#include <cstdlib>

using namespace std;

float dist(double ax, double ay, double bx, double by){
    return std::sqrt((ax - bx)*(ax - bx) + (ay - by)*(ay - by));
}

struct Bola{
    char c;
    double x, y;
    double vx{0}, vy{0};
    int raio {20};
    Bola(){
        this->c = 'a' + (rand() % 26);
        y = 20;
        x = rand() % 700 + 50;
    }
    virtual ~Bola(){

    }

    virtual void atualizar(){
        x += vx;
        y += vy;
    }

    virtual void sofrerGravidade(){
        vy += 0.05;
    }

    virtual void kikar(){
        if((y + 2 * raio) > 600){
            y = 600 - 2 * raio;
            vy = -vy;
        }
    }
};

class BolaAlz: public Bola{
public:
    BolaAlz():
        Bola()
    {
    }
    void atualizar(){
        Bola::atualizar();
        if(rand() % 30 == 0)
            this->c = 'a' + (rand() % 26);
    }
};

class BolaParkison: public Bola{
public:
    BolaParkison():
        Bola()
    {
    }
    void atualizar(){
        x += vx + (rand() % 11 - 5.0);
        y += vy;
    }
};

int main()
{
    srand(time(NULL));
    vector<Bola*> bolas;

    sf::RenderWindow janela(sf::VideoMode(800, 600), "Janela");
    janela.setFramerateLimit(30);

    while(janela.isOpen()){
        sf::Event event;
        while(janela.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                janela.close();
            if(event.type == sf::Event::KeyPressed){
//                if((event.key.code >= sf::Keyboard::A) &&
//                   (event.key.code <= sf::Keyboard::Z)){
//                    char tecla = 'a' + (event.key.code - sf::Keyboard::A);
//                    cout << tecla << endl;
//                }
                if(event.key.code == sf::Keyboard::B){
                    bolas.push_back(new Bola());
                }
                if(event.key.code == sf::Keyboard::P){
                    bolas.push_back(new BolaParkison());
                }
                if(event.key.code == sf::Keyboard::A){
                    bolas.push_back(new BolaAlz());
                }
            }
        }

        for(Bola * bola: bolas){
            bola->sofrerGravidade();
            bola->kikar();
            bola->atualizar();
        }

        for(int i = 0; i < (int) bolas.size(); i++){
            for(int j = i + 1; j < (int) bolas.size(); j++){
                Bola * bi = bolas[i];
                Bola * bj = bolas[j];
                auto d = dist(bi->x, bi->y, bj->x, bj->y);
                if(d < (2 * bi->raio)){
                    swap(bi->vx, bj->vx);
                    swap(bi->vy, bj->vy);
                }

//                    auto forca = 2 * bi->raio - dist;
//                    auto vx = bi->x - bj->x;
//                    auto vy = bi->y - bj->y;
//                }
            }
        }


        janela.clear();        
        for(Bola * bola : bolas){
            sf::CircleShape cs(bola->raio);
            auto pos = sf::Vector2f(bola->x, bola->y);
            cs.setFillColor(sf::Color::White);
            cs.setPosition(pos);
            janela.draw(cs);
            janela.draw(sfText(pos + sf::Vector2f(bola->raio/2, bola->raio/2),
                               string(1, bola->c), sf::Color::Black, 20));
        }

        janela.display();
    }

    for(auto bola : bolas)
        delete bola;
    return 0;
}




