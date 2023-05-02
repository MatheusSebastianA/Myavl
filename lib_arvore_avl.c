#include <stdlib.h>
#include <stdio.h>
#include "lib_arvore_avl.h"

/*  Função que cria uma árvore AVL e inicializa os ponteiros e o tamanho do primeiro nodo (raiz)
    Retorna a árvore criada */
arvore* cria_arvore_avl(){
    arvore *avl;

    if(!(avl = malloc(sizeof(arvore))))
        return NULL;

    avl->raiz = NULL;
    avl->altura_arvore = 0;

    return avl;
}

/*  Função que cria um nodo vazio e inicia seus ponteiros como NULL 
    Retorna o nodo criado */
no* cria_no(int chave){
    no *nodo;

    if(!(nodo = malloc(sizeof(no))))
        return NULL;

    nodo->chave = chave;
    nodo->pai = NULL;
    nodo->dir = NULL;
    nodo->esq = NULL;
    nodo->altura_nodo = 0;

    return nodo;
}

/*  Função que verifica a altura do nodo atual 
    Retrona esse valor */
int altura_nodo(no *nodo){
    if (nodo == NULL)
        return -1;

    return nodo->altura_nodo;
}

int maior_valor(int a, int b){
    if(a > b)
        return a;

    return b;
}

/*  Função que calcula o valor de balanceamento de um nodo
    Retrona esse valor ou 0 se o ponteiro for nulo */
int fator_balanceamento_nodo(no *nodo){
    if(nodo == NULL)
        return 0;

    return (altura_nodo(nodo->esq) - altura_nodo(nodo->dir));
}

int precisa_balancear(no *nodo){
    if (fator_balanceamento_nodo(nodo) > 1 || fator_balanceamento_nodo(nodo) < -1)
        return 1;

    return 0;
}

/*  Função que procura uma chave passada na árvore
    Retorna qual é o nodo encontrado que apresenta aquela chave ou NULL caso não exite a chave procurada */
no* busca(no *nodo, int chave){
    if (nodo == NULL)
        return cria_no(chave); /* Significa que não foi encontrado nenhuma chave, então será criado um novo nodo */

    if (chave < nodo->chave) /* Verifica se o valor da chave procurada é menor que o valor da chave do nodo atual */
        return busca(nodo->esq, chave); /* Se for, então a busca será feita para o lado esquerdo desse nodo */

    else
        if (chave > nodo->chave) /* Verifica se o valor da chave procurada é maior que o valor da chave do nodo atual */
            return busca(nodo->dir, chave); /* Se for, então a busca será feita para o lado direito desse nodo */

    return nodo; /* Se chegar aqui é porque a chave procurada é igual a chave do nodo atual, e retorna esse nodo */


}

/*  Função que imprime os valores em ordem */
void imprime_ordem(no *nodo){
    if(nodo == NULL)
        return;

    imprime_ordem(nodo->esq);
    printf("%d ", nodo->chave);
    imprime_ordem(nodo->dir);

    return;
}

/*  Função que rotaciona um nodo passado para a esquerda
    Retorna o Y, que será a nova raiz */
no* rotaciona_esq(arvore *avl, no *x){
    no *y;

    y = x->dir; /* Y vira o filho da direita de x*/
    x->dir = y->esq; /* O filho da direita de x será tudo que está na esquerda do y (Filho da direita de x)  */

    if(y->esq != NULL) /* Verifica se Y não tem nenhum filho à esquerda */
        y->esq->pai = x; /* Se tiver, o pai dele se tornará x */

    y->pai = x->pai; /* Pai de X agora é Pai de y */

    if(x->pai == NULL) /* Verifica se X está na raiz */
        avl->raiz = y; /* Se estiver, então a raiz agora é o y */

    else{ /* Se X não está na raiz */
        if(x == x->pai->esq) /* Verifica se X é o filho da esquerda do pai dele */
            x->pai->esq = y; /* Se for, o filho da esquerda do pai de x recebe y, já que Y é menor que seu avô, mesmo que seja maior que x */

        else /* Se não for filho da esquerda, é porque y será maior que x e maior que o pai de x, logo será filho da direita de seu avô */
            x->pai->dir = y;
    }

    y->esq = x; /* O filho da esquerda de y é x, já que y é maior que x */
    x->pai = y; /* O ponteiro para o pai de x recebe y */

    x->altura_nodo = maior_valor(altura_nodo(x->esq), altura_nodo(x->dir)) + 1; /* A altura do nodo x é o maior valor entre a altura o filho da esquerda e o da direita somado a 1 */
    y->altura_nodo = maior_valor(altura_nodo(y->esq), altura_nodo(y->dir)) + 1; /* A altura do nodo y é o maior valor entre a altura o filho da esquerda e o da direita somado a 1 */
    
    return y; 
}

/*  Função que rotaciona um nodo passado para a direita
    Retorna o Y, que será a nova raiz */
no* rotaciona_dir(arvore *avl, no *x){
    no *y;

    y = x->esq; /* Y vira o filho da esquerda de x */
    x->esq = y->dir; /* O filho da esquerda de x será tudo que está na direita de y, já que sempre será menor que x*/

    if (y->dir != NULL)
        y->dir->pai = x;

    y->pai = x->pai;

    if(x->pai == NULL)
        avl->raiz = y;

    else{
        if(x == x->pai->esq)
            x->pai->esq = y;

        else    
            x->pai->dir = y;
    }

    y->dir = x; /* O filho da direita de y é x, já que y é menor que x */
    x->pai = y; /* O ponteiro para o pai de x recebe y */

    x->altura_nodo = maior_valor(altura_nodo(x->esq), altura_nodo(x->dir)) + 1; /* A altura do nodo x é o maior valor entre a altura o filho da esquerda e o da direita somado a 1 */
    y->altura_nodo = maior_valor(altura_nodo(y->esq), altura_nodo(y->dir)) + 1; /* A altura do nodo y é o maior valor entre a altura o filho da esquerda e o da direita somado a 1 */

    return y;
}

/*  Função que rotaciona se estiver no caso Zig-Zag direita-esquerda
    Retorna o Y, que será a nova raiz */
no* rotaciona_dir_esq(arvore *avl, no *x){
    x->dir = rotaciona_dir(avl, x->dir);
    return rotaciona_esq(avl, x);
}

/*  Função que rotaciona se estiver no caso Zig-Zag esquerda-direita
    Retorna o Y, que será a nova raiz */
no* rotaciona_esq_dir(arvore *avl, no *x){
    x->esq = rotaciona_esq(avl, x->dir);
    return rotaciona_dir(avl, x);
}

no* balancear_avl(arvore *avl, no *raiz){
    int fator_raiz = fator_balanceamento_nodo(raiz);

    if (fator_raiz > 1 && fator_balanceamento_nodo(raiz->esq) >= 0) /* Significa que está desbalanceada para a esquerda e seu filho não está desbalanceado para a direita*/
        rotaciona_dir(avl, raiz);

    if (fator_raiz < -1 && fator_balanceamento_nodo(raiz->dir) <= 0) /* Significa que está desbalanceada para a direita e seu filho está balanceado */
        rotaciona_esq(avl, raiz);

    if (fator_raiz > 1 && fator_balanceamento_nodo(raiz->esq) < 0) /* Significa que está desbalanceada para a esquerda e seu filho está desbalanceado para a direita*/
        rotaciona_esq_dir(avl, raiz);

    if (fator_raiz < -1 && fator_balanceamento_nodo(raiz->dir) > 0) /* Significa que está desbalanceada para a esquerda e seu filho está desbalanceado para a direita*/
        rotaciona_dir_esq(avl, raiz);

    return raiz;

}

/*  Função que insere a chave na raiz da árvore ou de alguma subárvore
    Retorna o nodo que foi adicionado */
no* inserir_avl(arvore *avl, no *raiz, int chave){
    if(raiz == NULL){
        raiz = cria_no(chave);
        return raiz;
    }

    if(raiz->chave > chave){
        raiz->esq = inserir_avl(avl, raiz->esq, chave);
        raiz->esq->pai = raiz;
    }
    else{
        if(raiz->chave < chave){
            raiz->dir = inserir_avl(avl, raiz->dir, chave);
            raiz->dir->pai = raiz;
        }
        else
            printf("O valor %d já existe e não será acionado à árvore\n", chave);
    }

    raiz->altura_nodo = maior_valor(altura_nodo(raiz->esq), altura_nodo(raiz->dir)) + 1;

    if(precisa_balancear(raiz))
        raiz = balancear_avl(avl, raiz);

    return raiz;
}

