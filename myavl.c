#include <stdio.h>
#include <stdlib.h>
#include "lib_arvore_avl.h"

int main(){
    int chave;
    char opcao;
    arvore *avl = cria_arvore_avl();

    while(!feof(stdin)){
        scanf(" %c %d", &opcao, &chave);

        if(opcao == 'i')
            avl->raiz = insere_avl(avl, avl->raiz, chave);
        
        else if(opcao == 'r')
            avl->raiz = remove_avl(avl, avl->raiz, chave);

        else{
            printf("Argumento %c passado não é válido\n", opcao);
            return 1;
        }

    }

    imprime_ordem(avl, avl->raiz, 0);
    destroi_arvore(avl->raiz);
    free(avl);

    return 0;
}
