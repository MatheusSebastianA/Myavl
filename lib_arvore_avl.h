#ifndef lib_arvore_avl
#define lib_arvore_avl

struct nodo_avl{
    int chave;
    int altura_nodo;
    struct nodo_avl *esq, *dir, *pai;
};
typedef struct nodo_avl no;

struct arvore_avl{
    no *raiz;
    int altura_arvore;
};
typedef struct arvore_avl arvore;

arvore* cria_arvore_avl();

no* cria_no(int chave);

int altura_nodo(no *nodo);

int maior_valor(int x, int y);

no* busca(no *nodo, int chave);

void imprime_ordem(arvore *avl, no *nodo);

int fator_balanceamento_nodo(no *nodo);

int precisa_balancear(no *nodo);

no* rotaciona_esq(arvore *avl, no *x);

no* rotaciona_dir(arvore *avl, no *x);

no* rotaciona_dir_esq(arvore *avl, no *x);

no* rotaciona_esq_dir(arvore *avl, no *x);

no* balancear_avl(arvore *avl, no *raiz);

no* inserir_avl(arvore *avl, no *raiz, int chave);

no* remover_avl(arvore *avl, no *raiz, int chave);

#endif /* lib_arvore_avl.h*/
