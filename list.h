#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* start;
        int nodes;

    public:
        List() : start(nullptr), nodes(0) {};//Constructor

        T front(){
          if(start==nullptr){throw "Lista Vacia";}
          else{
            return start -> data;
          }
        };

        T back(){
          if(start==nullptr){throw "Lista Vacia";}
          else{
            return start -> prev -> data;
          }
        };

        void push_front(T value){
          Node<T>* tmp = new Node<T>;
          tmp -> data = value;

          if(start==nullptr){
            start = tmp;
            start -> next = start;
            start -> prev = start;
          }
          else{
            tmp -> prev = start -> prev;
            start -> prev -> next = tmp;
            start -> prev = tmp;
            tmp -> next = start;
            start = tmp;
          }
          nodes++;
        };

        void push_back(T value){
          Node<T>* tmp = new Node<T>;
          tmp -> data = value;

          if(start==nullptr){
            start = tmp;
            start -> next = start;
            start -> prev = start;
            nodes = 1;
          }
          else{
            tmp -> prev = start -> prev;
            start -> prev -> next = tmp;
            start -> prev = tmp;
            tmp -> next = start;
            nodes +=1;
          }
        };

        void pop_front(){
          if(start==nullptr){
            throw "Empty list";
          }
          else{
            if(nodes==1){
              start=nullptr;
              delete start;
            }
            else{
              Node<T>* tmp = start->next;
              start -> prev -> next = start -> next;
              start -> next -> prev = start -> prev; // Punteros de los nodos adjacentes a start apuntan a each other
              start -> prev = nullptr;
              start -> next = nullptr;
              delete start;
              start = tmp;
            }
            nodes--;
          }
        };

        void pop_back(){
          if(start==nullptr){
            throw "Empty list";
          }
          else{
            if(start->next == start){
              start = nullptr;
              delete start;
            }
            else{
              Node<T>* tmp = start-> prev;

              start -> prev -> prev -> next = start;
              start -> prev = start -> prev -> prev;
              tmp -> next = nullptr;
              tmp -> prev = nullptr;
              delete tmp;
            }
            nodes--;
          }
        };

        T get(int position){
          if(start==nullptr || position < 0){ //si te piden la posicion 5 de una lista con 3 nodos te va a dar el start pq es circular
            throw "Wrong position or empty list";
          }
          else{
            Node<T>* tmp = start;
            for(int i=0; i<position; i++){
              tmp = tmp -> next;
            }
            return tmp -> data;
          }
        };

        void concat(List<T> &other);

        bool empty(){
          return !start;
        };

        int size(){
          return nodes;
        };

        void clear(){
          while (nodes) this->pop_front();
        };

        Iterator<T> begin(){
          Iterator<T>* itera = new Iterator<T>(start);
          return *itera;
        };
        Iterator<T> end(){
          Iterator<T>* itera = new Iterator<T>(start->prev);
          return *itera;
        };

        ~List(){ this->clear(); };
};

#endif
