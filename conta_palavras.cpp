#include "conta_palavras.h"
#include <fstream>
#include <sstream>
#include <algorithm>

ContaPalavras::ContaPalavras() {}

void ContaPalavras::processaArquivo(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        throw std::runtime_error("Erro ao abrir o arquivo");
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::istringstream stream(linha);
        std::string palavra;
        while (stream >> palavra) {
            // Remove caracteres não alfabéticos
            palavra.erase(std::remove_if(palavra.begin(), palavra.end(), [](char c) { return !std::isalnum(c); }), palavra.end());
            adicionaPalavra(palavra);
        }
    }
    arquivo.close();
}

void ContaPalavras::adicionaPalavra(const std::string& palavra) {
    if (!palavra.empty()) {
        palavras[palavra]++;
    }
}

std::map<std::string, int> ContaPalavras::getPalavrasOrdenadas() const {
    return palavras;
}
