# Notação polonesa reversa (ou pós-fixada)

## Descrição da atividade, elaborada pelo Prof. Dr. André Campos

### Implemente uma árvore binária para representar uma expressão aritmética a partir de uma notação polonesa reversa (ou pós-fixada), na qual os operadores vêm logo depois dos operandos (ex: "1 2 + 3 *) é equivalente a operação (1 + 2) × 3.

* Os nós da árvore devem ser capazes de representar tanto operadores aritméticos (*, /, + e -) quanto valores inteiros (ex: 3, 45 ...).

* Os elementos da expressão são processados da esquerda pra direita, usando uma pilha como estrutura auxiliar.

* Sempre que um valor numérico for processado, um nó folha da árvore é criado contendo o valor numérico, e este nó é adicionado na pilha.

* Sempre que um operador aritmético for processado, dois itens do topo da pilha devem ser retirados, um nó da árvore é criado contendo o operador e tendo esses itens como filho. Por fim, o nó recém criado deve ser adicionado de volta na pilha.

* Ao final do processo, o topo da pilha conterá a árvore com a expressão.
