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
   
   A função de inserção é feita recursivamente, a qual segue a mesma ideia da busca, só que se a chave não existe será criado um nodo com essa chave e o pai dele será o nodo da chamada da função, se a chave já existe apenas não insere esse valor novamente na árvore. Ao final de cada recursão é verificado se o nodo atual está com um fator de balanceamento maior que um ou menor que -1, se estiver entrará na função que balanceia a árvore.
   
   O fator de balanceamente é feito por meio da subtração entre a altura do filho esquerdo e do filho direito, se for igual a 0 significa que tem a mesma quantidade de filhos em cada lado, se for > 0 tem mais filhos para a esquerda e se for < 0 tem mais filhos para a direita.
   
    A função que balanceia a árvore apresenta quatro possibilidades:
    . O fator de balanceamento do nodo verificado é maior que 1 (está desbalanceado para a esquerda) e seu filho esquerdo tem balanceamento maior ou igual a 0 (não tem mais filhos para a direita que para esquerda): Faz uma rotação a direita desse nodo que está desbalanceado para a esquerda.
    . O fator de balanceamento do nodo verificado é menor que -1 (está desbalanceado para a direita) e seu filho esquerdo tem balanceamento menor ou igual a 0 (não tem mais filhos para a esquerda que para direita): Faz uma rotação a esquerda desse nodo que está desbalanceado para a direita.
    . O fator de balanceamento do nodo verificado é maior que 1 (está desbalanceado para a esquerda) e seu filho esquerdo tem balanceamento menor que 0 (não tem mais filhos para a esquerda que para direita): Faz uma rotação a esquerda desse filho a esquerda que está "desbalanceado" para a direita e uma rotação a direita do nodo desbalanceado.
    . O fator de balanceamento do nodo verificado é menor que -1 (está desbalanceado para a direita) e seu filho esquerdo tem balanceamento maior que 0 (não tem mais filhos para a direita que para esquerda): Faz uma rotação a direita desse filho direito que está "desbalanceado" para a direita e uma rotação a esquerda do nodo desbalanceado.

  A função de remoção é feita recursivamente, a qual apresenta 3 possibilidades caso a chave exista para poder ser removida:
      
      . Nodo com a chave apresenta nenhum filho: Apenas libera esse nodo;
      . Nodo com a chave apresenta um filho: Troca o nodo pelo seu único filho e libera o nodo trocado; 
      . Nodo com a chave apresenta dois filhos: Pega a chave do seu antecessor e troca pela chave do nodo com a chave, libera o nodo que era seu antecessor
  Ao final de cada remoção é verificado a necessidade de rebalancear a árvore.
      
