#include "divisao.hpp"
#include "multiplicacao.hpp"
#include "noh.hpp"
#include "soma.hpp"
#include "subtracao.hpp"
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {

    if (argc != 2) {
        cerr << "Uso: " << argv[0] << " \"<expressao em pos-fixa>\"" << endl;
        return 1;
    }
    // (iss) input string stream - fluxo de string de entrada transformando em array de strings
    istringstream iss(argv[1]);
    vector<string> words;
    string word;
    stack<Noh*> pilhaNohs;

    // (>>) Extrai palavras do fluxo iss, a partir do delimitador "espaço" e as armazena no vetor words
    while (iss >> word) {
        words.push_back(word);
    }

    for (const string &word : words) {
        if (word == "+") {
            Noh* direita = pilhaNohs.top();
            pilhaNohs.pop();
            Noh* esquerda = pilhaNohs.top();
            pilhaNohs.pop();
            Noh* operadorSoma = new Noh("+", esquerda, direita);
            pilhaNohs.push(operadorSoma);
        } else if (word == "-") {
            Noh* direita = pilhaNohs.top();
            pilhaNohs.pop();
            Noh* esquerda = pilhaNohs.top();
            pilhaNohs.pop();
            Noh* operadorSubtracao = new Noh("-", esquerda, direita);
            pilhaNohs.push(operadorSubtracao);
        } else if (word == "*") {
            Noh* direita = pilhaNohs.top();
            pilhaNohs.pop();
            Noh* esquerda = pilhaNohs.top();
            pilhaNohs.pop();
            Noh* operadorMultiplicacao = new Noh("*", esquerda, direita);
            pilhaNohs.push(operadorMultiplicacao);
        } else if (word == "/") {
            Noh* direita = pilhaNohs.top();
            pilhaNohs.pop();
            Noh* esquerda = pilhaNohs.top();
            pilhaNohs.pop();
            Noh* operadorDivisao = new Noh("/", esquerda, direita);
            pilhaNohs.push(operadorDivisao);
        } else {
            // Se for um número, cria um nó e empilha
            int numero = stoi(word);
            Noh* numeroNoh = new Noh(to_string(numero));
            pilhaNohs.push(numeroNoh);
        }
    }

    Noh* raiz = pilhaNohs.top();
    pilhaNohs.pop();

    // Gerando arquivo .dot
    ofstream dotfile("arvore.dot");
    dotfile << "digraph Arvore {\n";
    raiz->gerarDot(dotfile);
    dotfile << "}\n";
    dotfile.close();

    cout << raiz->avaliar() << endl;
    delete raiz;

    return 0;
}


