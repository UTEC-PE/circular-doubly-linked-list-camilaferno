#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;

    void killSelf(){
      if(next){
        next -> killSelf();
      }
      delete this;
    };

    //No se hace
    void print_next(){
    };
};

#endif
