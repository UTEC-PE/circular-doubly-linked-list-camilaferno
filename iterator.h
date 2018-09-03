#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T>
class Iterator {
    private:
        Node<T>* current;

    public:
        Iterator():current(nullptr){};
        Iterator(Node<T>* node): current(node){};

        Iterator<T> operator=(Iterator<T> node){
          current = node.current;

          return *this; //Returnea el iterador cambiado
        };

        bool operator!=(Iterator<T> cmp){
          if(current!=cmp.current){
            return true;
          }
          else{
            return false;
          }
        };

        Iterator<T> operator++(){
          current=current->next;

          return *this;
        };

        Iterator<T> operator--(){
          current =current->prev;

          return *this;
        };

        T operator*(){
          return current->data;
        };
};

#endif
