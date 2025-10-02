#ifndef noh_h
#define noh_h
#include <string>
using namespace std;

class Noh {
    private:
    string dado;
    Noh* esquerda;
    Noh* direita;

    public:
    Noh(string val, Noh* esq = nullptr, Noh* dir = nullptr);
    ~Noh();

    int avaliar();

    void gerarDot(std::ostream& out) const;
};

#endif
