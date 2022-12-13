# TeoGraf TP3

Este biblioteca tem como principal funcao fornecer a possibilidade de encontrar o fluxo maximo de uma rede de fluxos e a alocacao de fludo de cada aresta.

Para tal eh necessario chamar o metodo construtor do grafo:

//builder_adjacency_list(std::string file_name, std::string type);
builder_adjacency_list("example.txt", "dw");

Assim podera chamar o metodo de encontrar fluxo maximo fonte-sumidouro:

//find_max_flow(int source, int target)
find_max_flow(1, 2)

ou de a alocacao de fludo de cada aresta:

//find_netflow(int source, int target, std::string write)
find_netflow(1, 2, "w");

o terceiro argumento eh usado para caso queira gravar no disco o fluxo buscado: "w" pra sim, qualquer outra string para nao

Por enquanto, caso queira alternar entre chamadas desses metodos cada interacao sera necessario reconstruir o grafo a partir do disco
