
#ifndef FILA_DUPLAMENTE_ENCADEADA_H
#define FILA_DUPLAMENTE_ENCADEADA_H





#include <string>
#include <iostream>

using namespace std;

struct Node { // Node co valores DEFAULT
     int key = -1;
     int data = -1;
     Node* next= nullptr;
     Node* prev = nullptr;
};

class fila_duplamente_encadeada {
public:
     Node* tail = nullptr; // ponteiros para o primeiro e último da fila
     Node* head = nullptr;
     int size;

     ////////////////////////////
     fila_duplamente_encadeada();
     ~fila_duplamente_encadeada();
     bool is_empty();
     void add_tail(int);
     void imprime();
     fila_duplamente_encadeada& remove();

};

inline fila_duplamente_encadeada::fila_duplamente_encadeada() {
     Node* tail = nullptr; // ponteiros para o primeiro e último da fila
     Node* head = nullptr;
     Node* currrent = nullptr; // ponteiro para o atual
     size = 0;
}

inline fila_duplamente_encadeada::~fila_duplamente_encadeada() {
     while (head != nullptr) { // Enquanto houver nós na lista
          Node* temp = head; // Armazena o nó atual
          head = head->next; // Move para o próximo nó
          delete temp;       // Deleta o nó atual
     }
}

void fila_duplamente_encadeada::add_tail(int d) {
    Node* new_node = new Node; // cria um novo nó
     new_node->data =d ; // passo a string e o ID
     new_node->key = size + 1;
     if(is_empty()) {
          head = new_node; // se for o 1° nó, tanto o tail quanto o head apontam para ele
          tail = new_node;
     } else {
          tail->next = new_node; // o (anteriormente) ultimo nó, tem seu next redefinido para o novo
          new_node->prev = tail; // o novo nó.prev aponta para o antigo tail
          tail = new_node; // tail agora aponta para o novo nó
          tail->next = nullptr; ////////////////////fffgfgf

     }
     size++;

}

fila_duplamente_encadeada& fila_duplamente_encadeada::remove() { // remove os elementos duplicados de uma fila
     Node* veloz = head; // ponteiro que percorrerá a lista várias vezes
     Node* lento = head; // ponteiro que percorrerá a lista uma vez

     while(lento != nullptr) { // lento define quais alvos ja foram encontrados, e onde o veloz é iniciado
          int alvo = lento->data; // armazenará o número que nao poderá ser repetido // é mudado toda vez que o lento avança um
          veloz = lento->next;
          while(veloz != nullptr) {// veloz percorre toda a lista em busca de achar inteiros iguais ao alvo
               if(alvo == veloz->data) { // se os números forem repitidos, o deleto
                    Node* deletar = veloz;
                    if(veloz->prev != nullptr) {
                         veloz->prev->next = veloz->next;
                    }
                    if(veloz->next != nullptr) {
                         veloz->next->prev = veloz->prev;
                    }
                    veloz = veloz->next;
                    delete deletar;
                    size--;
               }
               else
               veloz = veloz->next; // vou para próximo nó
          }
          lento = lento->next;
     }
     return *this;
}

inline bool fila_duplamente_encadeada::is_empty(){
     if(size==0)
          return true;
     return false;
}

inline void fila_duplamente_encadeada::imprime() {
     Node* atual = head; // ponteiro que percorrerá toda a lista
     while (atual != nullptr) {
          cout << atual->data << " "; // imprime os dados do nó atual
          atual = atual->next; // atual agora aponta para o próximo  nó
     }
     cout << endl;

}





#endif //FILA_DUPLAMENTE_ENCADEADA_H
