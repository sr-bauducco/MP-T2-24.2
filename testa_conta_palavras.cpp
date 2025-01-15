#include "conta_palavras.h"
#include <iostream>
#include <cassert>

void testaProcessaArquivo() {
    ContaPalavras cp;
    cp.processaArquivo("teste.txt");

    auto palavras = cp.getPalavrasOrdenadas();

    assert(palavras["este"] == 1);
    assert(palavras["texto"] == 2);
    assert(palavras["que"] == 1);
    assert(palavras["sera"] == 1);
    assert(palavras["utilizado"] == 1);
    assert(palavras["o"] == 1);
    std::cout << "TestaProcessaArquivo passou!" << std::endl;
}

void testaAdicionaPalavra() {
    ContaPalavras cp;
    cp.processaArquivo("teste.txt");

    auto palavras = cp.getPalavrasOrdenadas();

    assert(!palavras.empty());
    std::cout << "TestaAdicionaPalavra passou!" << std::endl;
}

int main() {
    testaProcessaArquivo();
    testaAdicionaPalavra();

    std::cout << "Todos os testes passaram!" << std::endl;
    return 0;
}
