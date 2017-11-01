#include <iostream>
#include "poo_aux.h"
#include "poo_controller.h"
#include "poo_repository.h"

#include "twitter.h"

using namespace std;


string HELP = R"(
help
users
addUser    _nome
seguir     _nome _outro
twittar    _nome _(mensagem com varias palavras)
like       _nome
seguidores _nome
seguidos   _nome
timeline   _nome
myTweets   _nome
unread     _nome
)";

class TwitterService : public Controller {
    Repository<User> repo;
    Repository<Tweet> r_tw;
    TweetGenerator twgen;

public:
    TwitterService():
        repo("usuario"), r_tw("tweet"),twgen(&r_tw)
    {
    }

    string process(string line) {
        auto ui = poo::split(line, ' ');
        auto cmd = ui[0];

        if(cmd == "help")
            return HELP;
        else if(cmd == "addUser")
            this->repo.add(ui[1], User(ui[1]));
        else if(cmd == "users")
            return "usuarios\n[" + poo::join(this->repo.keys(), " ") + "]";
        else if(cmd == "seguir")
            this->repo.get(ui[1])->seguir(this->repo.get(ui[2]));
        else if(cmd == "twittar"){
            auto texto = poo::join(poo::slice(ui, 2), " ");
            this->repo.get(ui[1])->twittar(twgen.create(ui[1], texto));
        }else if(cmd == "seguidores"){
            auto lista = this->repo.get(ui[1])->seguidores;
            return "[" + poo::pjoin(lista, " ") + "]";
        }else if(cmd == "seguidos"){
            auto lista = this->repo.get(ui[1])->seguidos;
            return "[" + poo::pjoin(lista, " ") + "]";
        }else if(cmd == "timeline"){
            auto lista = this->repo.get(ui[1])->timeline;
            return "timeline\n" + poo::pjoin(lista, "\n");
        }else if(cmd == "unread"){
            auto lista = this->repo.get(ui[1])->getUnread();
            return "unread\n" + poo::pjoin(lista, "\n");
        }else if(cmd == "myTweets"){
            auto lista = this->repo.get(ui[1])->myTweets;
            return "MyTweets\n" + poo::pjoin(lista, "\n");
        }else if(cmd == "like"){
            auto timeline = this->repo.get(ui[1])->getTimeline();
            for(auto tweet : timeline)
                if(tweet->idTw == poo::Int(ui[2]))
                    tweet->addLike(ui[1]);
        }
        else if(cmd == "fim")
            return "fim";
        else
            return "comando invalido";
        return "done";


    }
};

int main(){
    TwitterService c;
    c.commandLine();
    return 0;
}




