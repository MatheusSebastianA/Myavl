# Myavl
Trabalho de Algoritmos III
Aluno: Matheus Sebastian Alencar de Carvalho - GRR20220065

Objetivo:

   Esse trabalho tinha como objetivo a implementação de uma ávore do tipo AVL. Para essa implementação, foi criada, na linguagem C, uma biblioteca "lib_arvore_avl", a qual apresenta algumas funções fundamentais para a implementação da árvore. 


Implementação: 

  Para a implementação, duas structs foram utilizadas. A primeira para a árvore, que apresenta um ponteiro para a raiz e um inteiro para a altura total da árvore, que não é utilizada, mas pode ser utilizada para analisar se a altura está igual a altura do último nodo. A outra representa o nodo, com um inteiro para representar a chave, um inteiro para representar a altura desse nodo e 3 ponteiros: pai, filho da esquerda, filho da direita.
    
   A função de busca é feita recursivamente até encontrar um ponteiro nulo ou um nodo com mesma chave, a qual compara o valor da chave do nodo atual com a chave a ser inserida. Nessas comparações, existem quatro possibilidades:
    . Ponteiro passado é nulo: Base da recursividade;
    . Chave passada ser menor que a chave do nodo atual: Vai chamar a função busca recursivamente para o filho da esquerda do nodo atual;
    . Chave passada ser maior que a chave do nodo atual: Vai chamar a função busca recursivamente para o filho da direita do nodo atual;
    . Chave passada é igual a chave do nodo atual: Vai retornar o nodo que apresenta essa chave.
    
   A função imprime ordem é feita recursivamente, a qual utiliza das propriedades da árvore AVL para imprimir em ordem crescente os valores das chaves na árvore e o nivel dele na árovre. Como não foi necessário a utilização do nível de um nodo, para representar esse nivel na impressão a própria recursividade da impressão é suficiente para representar o nivel de cada nodo. Começando pela raiz, nivel 0, a função é chamada para o filho da esquerda até chegar na base, já que o nodo mais a esquerda da árvore representa o menor valor. Após chegar na base, sai da recursividade e printa o valor do nodo anterior à base e chama a função para o filho da direita.
   
   A função de inserção é feita recursivamente, a qual segue a mesma ideia da busca, só que se a chave não existe será criado um nodo como essa chave e o pai dele será o nodo da chamada da função, se a chave já existe apenas não insere esse valor novamente na árvore. Ao final de cada recursão é verificado se o nodo atual está com um fator de balanceamento maior que um ou menor que -1, se estiver entrará na função que balanceia a árvore.
   
   A função que balanceia a árvore apresenta quatro possibilidades:
   . O fator de balanceamento do nodo verificado é maior que 1 (está desbalanceado para a esquerda) e seu filho esquerdo tem balanceamento maior ou igual a 0 (não está "desbalanceado" para a direita): Faz uma rotação a direita desse nodo que está desbalanceado para a esquerda.
   . O fator de balanceamento do nodo verificado é maior que 1 (está desbalanceado para a esquerda) e seu filho esquerdo tem balanceamento menor que 0 (não está "desbalanceado" para a esquerda): Faz uma rotação a esquerda desse filho a esquerda que está "desbalanceado" para a direita e uma rotação a direita do nodo pai.
   . O fator de balanceamento do nodo verificado é menor que -1 (está desbalanceado para a direita) e seu filho esquerdo tem balanceamento menor ou igual a 0 (não está "desbalanceado" para a esquerda): Faz uma rotação a esquerda desse nodo que está desbalanceado para a direita.
   . O fator de balanceamento do nodo verificado é menor que -1 (está desbalanceado para a direita) e seu filho esquerdo tem balanceamento maior que 0 (não está "desbalanceado" para a direita): Faz uma rotação a direita desse filho a direita que está "desbalanceado" para a direita e uma rotação a direita do nodo pai.
    
