#include <stdio.h>
#include <stdlib.h>
#include "lib_arvore_avl.h"

int main(){
    arvore *avl;
    avl = cria_arvore_avl();


    avl->raiz = inserir_avl(avl, avl->raiz, 10);
    inserir_avl(avl, avl->raiz, 20);
    inserir_avl(avl, avl->raiz, 30);
    inserir_avl(avl, avl->raiz, 40);
    inserir_avl(avl, avl->raiz, 50);
    inserir_avl(avl, avl->raiz, 45);
    inserir_avl(avl, avl->raiz, 48);

    printf("A raiz agora é: %d\n", avl->raiz->chave);
    imprime_ordem(avl, avl->raiz);
    printf("\n");

    return 0;
}
