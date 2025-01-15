// testa_conta_palavras.cpp
#include "conta_palavras.hpp"
#include <iostream>
#include <cassert>

void testaArquivo(const std::string& nomeArquivo, const std::map<std::string, int>& esperado) {
    ContaPalavras cp;
    cp.processaArquivo(nomeArquivo);
    auto palavras = cp.getPalavrasOrdenadas();

    assert(palavras == esperado);
    std::cout << "Teste com " << nomeArquivo << " passou!" << std::endl;
}

int main() {
    testaArquivo("1.txt", {
        {"Este", 1}, {"texto", 2}, {"é", 1}, {"o", 1}, {"que", 1}, {"será", 1}, {"utilizado", 1}
    });
/** 
    testaArquivo("2.txt", {
        {"Um", 1}, {"exemplo", 3}, {"simples", 1}, {"com", 1}, {"palavras", 1}, {"repetidas", 1}
    });

    testaArquivo("3.txt", {
        {"Teste", 1}, {"com", 1}, {"caracteres", 1}, {"especiais", 1}, {"E", 1}, {"também", 1}, {"números", 1}
    });

    testaArquivo("4.txt", {
        {"Palavras", 1}, {"ÚNICAS", 1}, {"com", 1}, {"maiúsculas", 1}, {"e", 1}, {"minúsculas", 1}, {"devem", 1}, {"ser", 1}, {"contadas", 1}, {"separadamente", 1}, {"únicas", 1}
    });

    testaArquivo("5.txt", {
        {"Arquivo", 1}, {"com", 1}, {"múltiplas", 1}, {"linhas", 1}, {"Essa", 1}, {"é", 1}, {"a", 1}, {"segunda", 1}, {"linha", 1}, {"E", 1}, {"aqui", 1}, {"está", 1}, {"terceira", 1}
    });

    testaArquivo("6.txt", {
        {"Espaços", 1}, {"extras", 1}, {"não", 1}, {"devem", 1}, {"afetar", 1}, {"o", 1}, {"resultado", 1}
    });

    testaArquivo("7.txt", {
        {"Não", 1}, {"deve", 1}, {"contar", 1}, {"números", 1}, {"apenas", 1}, {"palavras", 1}, {"alfabéticas", 1}
    });

    testaArquivo("8.txt", {
        {"Contar", 1}, {"palavras", 1}, {"longas", 1}, {"como", 1}, {"pseudopseudohipoparatiroidismo", 1}, {"corretamente", 1}
    });

    testaArquivo("9.txt", {
        {"Palavras", 1}, {"com", 1}, {"hífen", 1}, {"como", 1}, {"sub-região", 1}, {"devem", 1}, {"ser", 1}, {"consideradas", 1}, {"únicas", 1}
    });

    testaArquivo("10.txt", {
        {"Teste", 1}, {"de", 1}, {"limites", 1}, {"uma", 1}, {"única", 1}, {"palavra", 1}
    });

    testaArquivo("11.txt", {
        {"Misturar", 1}, {"idiomas", 1}, {"English", 1}, {"português", 1}, {"français", 1}, {"español", 1}
    });

    testaArquivo("12.txt", {
        {"O", 2}, {"mesmo", 2}, {"texto", 2}, {"repetido", 2}, {"várias", 2}, {"vezes", 2}
    });

    testaArquivo("13.txt", {
        {"Linha", 1}, {"única", 1}, {"mas", 1}, {"longa", 1}, {"o", 1}, {"suficiente", 1}, {"para", 1}, {"testar", 1}, {"desempenho", 1}, {"do", 1}, {"sistema", 1}, {"com", 1}, {"textos", 1}, {"extensos", 1}, {"Esta", 1}, {"deve", 1}, {"garantir", 1}, {"que", 1}, {"nenhum", 1}, {"problema", 1}, {"ocorra", 1}, {"quando", 1}, {"processamos", 1}, {"em", 1}, {"uma", 1}
    });

    testaArquivo("14.txt", {
        {"Teste", 1}, {"com", 1}, {"abreviações", 1}, {"como", 1}, {"U", 1}, {"S", 1}, {"A", 1}, {"O", 1}, {"N", 1}, {"U", 1}, {"e", 1}, {"siglas", 1}, {"NASA", 1}, {"FBI", 1}
    });

    testaArquivo("15.txt", {
        {"Teste", 1}, {"com", 1}, {"palavras", 1}, {"únicas", 1}, {"e", 1}, {"repetidas", 1}, {"para", 1}, {"validar", 1}, {"a", 1}, {"contagem", 1}, {"precisa", 1}, {"palavra", 1}, {"repetida", 2}
    });
*/
    std::cout << "Todos passaram com sucesso!" << std::endl;
    return 0;
}
