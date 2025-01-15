#ifndef CONTA_PALAVRAS_H
#define CONTA_PALAVRAS_H

#include <map>
#include <string>
#include <vector>

class ContaPalavras {
public:
    ContaPalavras();
    void processaArquivo(const std::string& nomeArquivo);
    std::map<std::string, int> getPalavrasOrdenadas() const;

private:
    std::map<std::string, int> palavras;
    void adicionaPalavra(const std::string& palavra);
};

#endif // CONTA_PALAVRAS_H
