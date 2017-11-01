#ifndef TWITTER_H
#define TWITTER_H
#include <iostream>
#include <list>
#include "poo_aux.h"
#include "poo_repository.h"
using namespace std;

class Tweet {
public:
    int idTw;
    string username;
    string msg;
    list<string> likes;

    Tweet(int idTw = 0, string username = "", string msg = ""){
        this->idTw = idTw;
        this->username = username;
        this->msg = msg;
    }

    void addLike(string username){
        for(auto elem : likes)
            if(elem == username)
                return;
        likes.push_back(username);
    }

    friend ostream& operator<<(ostream& os, Tweet t){
        os << to_string(t.idTw) << " " << t.username << ": " << t.msg;
        if(t.likes.size() > 0)
            os << "{" << poo::join(t.likes, " ") << "}";
        return os;
    }
};

class User {
public:
    string username;
    list<User*> seguidores;
    list<User*> seguidos;
    list<Tweet*> myTweets;
    list<Tweet*> timeline;
    int unreadCount {0};

    User(string username = ""){
        this->username = username;
    }

    void seguir(User * user){
        for(auto elem : seguidos)
            if(elem->username == user->username)
                return;
        seguidos.push_back(user);
        user->seguidores.push_back(this);
    }

    void twittar(Tweet * tweet){
        myTweets.push_front(tweet);
        for(User * user : seguidores){
            user->unreadCount += 1;
            user->timeline.push_front(tweet);
        }
    }

    list<Tweet*> getUnread(){
        list<Tweet *> naoLidos;
        auto it = timeline.begin();
        for(int cont = 0; cont < unreadCount; cont++, it++)
            naoLidos.push_back(*it);
        unreadCount = 0;
        return naoLidos;
    }

    list<Tweet*> getTimeline(){
        unreadCount = 0;
        return timeline;
    }

    friend ostream& operator<<(ostream &os, User user){
        os << user.username;
        return os;
    }
};

class TweetGenerator{
public:
    Repository<Tweet> * r_tw;
    int nextId {0};
    TweetGenerator(Repository<Tweet> * r_tw = nullptr){
        this->r_tw = r_tw;
    }

    Tweet * create(string username, string msg){
        int id = nextId;
        nextId += 1;
        return r_tw->add(to_string(id), Tweet(id, username, msg));
    }
};

#endif // USER_H

