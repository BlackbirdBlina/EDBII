#include "noh.hpp"
#include "soma.hpp"
#include "subtracao.hpp"
#include "multiplicacao.hpp"
#include "divisao.hpp"
#include <fstream>
using namespace std;

Noh::Noh(string val, Noh* esq, Noh* dir) : dado(val), esquerda(esq), direita(dir) {

}

Noh::~Noh() {
    delete esquerda;
    delete direita;
}

int Noh::avaliar() {
    if (dado == "+") {
        return soma(esquerda->avaliar(), direita->avaliar());
    } else if (dado == "-") {
        return subtracao(esquerda->avaliar(), direita->avaliar());
    } else if (dado == "*") {
        return multiplicacao(esquerda->avaliar(), direita->avaliar());
    } else if (dado == "/")
    {
        return divisao(esquerda->avaliar(), direita->avaliar());
    } else {
        // Se for um número, converte a string para inteiro e retorna
        return stoi(dado);
    }

}

void Noh::gerarDot(std::ostream& out) const {
    // Cria um identificador único usando o ponteiro
    out << "    node" << this << " [label=\"" << dado << "\"];\n";
    if (esquerda) {
        out << "    node" << this << " -> node" << esquerda << ";\n";
        esquerda->gerarDot(out);
    }
    if (direita) {
        out << "    node" << this << " -> node" << direita << ";\n";
        direita->gerarDot(out);
    }
}
