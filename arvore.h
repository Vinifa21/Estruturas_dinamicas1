//
// Created by azaza on 14/03/2025.
//

#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>
using namespace std;
struct Node {
    int key;
    Node* p; // aponta para o pai
    Node* left;
    Node* right;
};

class arvore {
public:
    Node* root;
    int size;

    arvore() {
        size = 0;
        root = nullptr;
    } // construtor

    // na main, sempre chamar r como root do obj
    void insere(int k, Node* current){  // nao funfa pra elementos repitidos
        // para arvores de busca, // current ponteiro que andará pela árvore
        if (root == nullptr) { // se for o primeiro nó
            Node* temp = new Node;
            root = temp;
            temp->key = k;
            temp->p = nullptr;
            temp->left = nullptr;
            temp->right = nullptr;
            size++;
        }
        else{// se não for o primreiro nó... - só entra em um caso desses por vez
            if(k < current->key && current->left == nullptr){ // se o valor for menor q o current, e current for nó folha, dou add left
                Node* temp = new Node; // crio novo node
                current->left = temp; // temp agr está atrelado com à árvore

                temp->p = current;
                temp->left = nullptr;
                temp->right = nullptr;

                temp->key = k;
                size++;
            }

            else if( k > current->key && current->right == nullptr) { // dou add right

                Node* temp = new Node; // crio novo node
                current->right = temp; // temp agr está atrelado com à árvore

                temp->p = current;
                temp->left = nullptr;
                temp->right = nullptr;

                temp->key = k;
                size++;
            }

            else if( k < current->key && current->left != nullptr) { // chamo recursivamente a funcao dnv, agr com current = seu filho à esquerda
                insere(k, current->left);

            }

            else if( k > current->key && current->right != nullptr) { // current = seu filho à direita
                insere(k, current->right);

            }

        }
    }


    // começa do elemento mais à esq, e vai percorrendo a arvore do esq-baixo subindo e acabando no dir-baixo
    void percorre_inorder(Node* r){ // r é o root para essa funcao (caso eu queira usar uma subarvore, por ex)
        // já imprime na volta (cout pode ser substituido por coletar o valo, por ex)
        if (r != nullptr) {
            percorre_inorder(r->left);
            std::cout << r->key <<", ";
            percorre_inorder(r->right);
        }
        // else, não faz nada (chegou nos nós-folhas)
    }

    //imprime todos os mais de baixo da sub_arvore primeiro
    void percorre_postorder(Node* r) {
        if (r != nullptr) {
            percorre_postorder(r->left);
            percorre_postorder(r->right);
            std::cout << r->key << std::endl;
        }
        else
            std::cout << "arvore vazia";

    }
    // começo do root, vou pegando todos à esq, na volta éga à dir, dps de pegar todos da subtree à esq, começa a dir
    void percorre_preorder(Node* r) {
        if (r != nullptr) {
            std::cout << r->key << std::endl;
            percorre_postorder(r->left);
            percorre_postorder(r->right);
        }
        else
            std::cout << "arvore vazia";

    }

    // Retorna a altura de certo nó. altura = o número de arestas no caminho descendente mais longo do nó v até uma folha
    // FUNCAO UTILIZADA NO EXERCICIO 3
    int altura(Node* node) {
            // Caso base: se o nó for nulo, a altura é -1 (árvore vazia)
            if (node == nullptr) {
                return -1;
            }

            // Calcula a altura dos filhos esquerdo e direito
            int alturaEsquerda = altura(node->left);
            int alturaDireita = altura(node->right);

            // A altura do nó atual é o maior valor entre as alturas dos filhos + 1
            return max(alturaEsquerda, alturaDireita) + 1;
        }

    // profundidade = o número de arestas no caminho da raiz de T até o nó v
    int profundidade(Node* r, Node* T) {
        int contador = 0;
        //caso base --> nó é o root depth = 0
        if( T == r) {
            return 0;
        }
        else {
            contador = contador + profundidade(r, T->p) + 1;
            return contador;
        }

    }
    // diametro = maior distancia entre 2 folhas (soma da altura dir + altura esquerda)
    int diametro(Node* r) {
        // +2 é o camino do root->left até o root->right
        return 2 + altura(r->right) + altura(r->left);
    }

};


#endif //ARVORE_H
