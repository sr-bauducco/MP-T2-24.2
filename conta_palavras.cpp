/**
 * \file conta_palavras.cpp.cpp
 * \version 1.0
 * 
 * \brief Implementação das funções para contagem e ordenação das palavras do texto.
 *
 * \details Este arquivo contém a implementação das funções para:
 * - Ler o conteúdo de arquivos de texto.
 * - Contar palavras e suas frequências em um texto.
 * - Ordenar palavras por frequência ou ordem alfabética.
 * - Exibir resultados no console.
 *
 * \example
 * \code
 * std::string texto = lerArquivo("arquivo.txt");
 * auto palavras = ContaPalavras(texto);
 * \endcode
 *
 * \note Para garantir resultados precisos, o texto é normalizado removendo acentos
 * e convertendo para letras minúsculas.
 */

#include "conta_palavras.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <locale>
#include <codecvt>

// Implementações seguem...


/**
 * \brief Lê o conteúdo de um arquivo e retorna como uma string.
 * \param nome_do_arquivo Nome do arquivo a ser lido.
 * \return Retorna o conteúdo do arquivo como uma string.
 * \details Esta função tenta abrir o arquivo especificado:
 * Se o arquivo não puder ser aberto, uma exceção `std::runtime_error` é lançada. 
 * Caso contrário, o conteúdo do arquivo é lido e retornado como uma string.
 */
std::string lerArquivo(std::string nome_do_arquivo) {
  std::ifstream arquivo(nome_do_arquivo);
  if (!arquivo.is_open()) {
    throw std::runtime_error("Erro ao abrir o arquivo: " + nome_do_arquivo);
  }
  std::ostringstream buffer;
  buffer << arquivo.rdbuf();
  return buffer.str();
}

/**
 * \brief Separa as palavras de um texto e conta a frequência de cada uma.
 * \param texto Texto a ser processado.
 * \return Vetor de pares contendo palavras e suas respectivas frequências.
 * \details A função separa as palavras do texto com base em pontuação e espaços, 
 * contando a frequência de cada palavra e retornando um vetor com essas informações.
 */
std::vector<std::pair<std::string, int>> separarEContar(std::string texto) {
  std::vector<std::pair<std::string, int>> dicionario;
  std::string palavra_atual = "";
  for (char c : texto) {
    if (c == ' ' || c == '\n' || c == '.' || c == ',' || c == ':' ||
        c == ';' || c == '!' || c == '?' || c == '(' || c == ')' ||
        c == '=' || c == '*' || c == '#' || c == '&') {
      if (!palavra_atual.empty()) {
        bool encontrada = false;
        for (auto& par : dicionario) {
          if (par.first == palavra_atual) {
            par.second++;
            encontrada = true;
            break;
          }
        }
        if (!encontrada) {
          dicionario.push_back({palavra_atual, 1});
        }
        palavra_atual = "";
      }
    } else {
      palavra_atual += c;
    }
  }

  if (!palavra_atual.empty()) {
    bool encontrada = false;
    for (auto& par : dicionario) {
      if (par.first == palavra_atual) {
        par.second++;
        encontrada = true;
        break;
      }
    }
    if (!encontrada) {
      dicionario.push_back({palavra_atual, 1});
    }
  }

  return dicionario;
}

/**
 * \brief Converte uma string para letras minúsculas.
 * \param palavra String a ser convertida.
 * \return String com todas as letras em minúsculas.
 * \details Usa a função `tolower` para converter cada caractere.
 */
std::string lowerCase(std::string palavra) {
  std::string lower_palavra = "";
  for (size_t i = 0; i < palavra.size(); i++) {
    lower_palavra += tolower(palavra[i]);
  }
  return lower_palavra;
}

/**
 * \brief Remove acentos de uma palavra.
 * \param palavra String com possíveis caracteres acentuados.
 * \return String sem caracteres acentuados.
 */
std::string removerAcentos(std::string palavra) {
  std::vector<std::pair<std::string, std::string>> tabelaAcentos = {
        {"á", "a"}, {"à", "a"}, {"â", "a"}, {"ã", "a"}, {"ä", "a"},
        {"é", "e"}, {"è", "e"}, {"ê", "e"}, {"ë", "e"},
        {"í", "i"}, {"ì", "i"}, {"î", "i"}, {"ï", "i"},
        {"ó", "o"}, {"ò", "o"}, {"ô", "o"}, {"õ", "o"}, {"ö", "o"},
        {"ú", "u"}, {"ù", "u"}, {"û", "u"}, {"ü", "u"},
        {"ç", "c"}, {"ñ", "n"}
  };

  std::string palavra_sem_acento;

  std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
  auto utf32Texto = converter.from_bytes(palavra);
  for (char32_t c : utf32Texto) {
    std::string utf8Char = converter.to_bytes(c);
    bool substituido = false;
    for (const auto& par : tabelaAcentos) {
      if (utf8Char == par.first) {
        palavra_sem_acento += par.second;
        substituido = true;
        break;
      }
    }
    if (!substituido) {
      palavra_sem_acento += utf8Char;
    }
  }

  return palavra_sem_acento;
}

/**
 * \brief Função auxiliar do merge sort para mesclar dois subvetores.
 * \param vetor Vetor a ser ordenado.
 * \param inicio Índice inicial do primeiro subvetor.
 * \param meio Índice final do primeiro subvetor e início do segundo.
 * \param fim Índice final do segundo subvetor.
 * \return void
 * \details Mescla dois subvetores ordenados em um único vetor ordenado.
 */
void merge(std::vector<std::pair<std::string, int>>& vetor,
          int inicio, int meio, int fim) {
  std::vector<std::pair<std::string, int>> temp(fim - inicio + 1);
  int i = inicio, j = meio + 1, k = 0;

  while (i <= meio && j <= fim) {
    std::string a = removerAcentos(lowerCase(vetor[i].first));
    std::string b = removerAcentos(lowerCase(vetor[j].first));
    if (a <= b) {
      temp[k++] = vetor[i++];
    } else {
      temp[k++] = vetor[j++];
    }
  }

  while (i <= meio) temp[k++] = vetor[i++];
  while (j <= fim) temp[k++] = vetor[j++];

  for (k = 0; k < temp.size(); k++) vetor[inicio + k] = temp[k];
}

/**
 * \brief Ordena um vetor de pares (palavra, contagem).
 * \param vetor Vetor a ser ordenado.
 * \param inicio Índice inicial do vetor.
 * \param fim Índice final do vetor.
 * \return void
 * \details Divide o vetor em partes menores e usa a função merge para ordenar.
 */
void mergeSort(std::vector<std::pair<std::string, int>>& vetor,
              int inicio, int fim) {
  if (inicio < fim) {
    int meio = (inicio + fim) / 2;
    mergeSort(vetor, inicio, meio);
    mergeSort(vetor, meio + 1, fim);
    merge(vetor, inicio, meio, fim);
  }
}

/**
 * \brief Ordena o vetor de palavras e contagens.
 * \param palavras Vetor contendo pares de palavras e suas contagens.
 * \return void
 * \details Usa merge sort para ordenar as palavras em ordem alfabética.
 */
void ordenaPalavras(std::vector<std::pair<std::string, int>>& palavras) {
  mergeSort(palavras, 0, palavras.size()-1);
}

/**
 * \brief Exibe as palavras e suas respectivas frequências no console.
 * \param palavras Um vetor de pares contendo as palavras e suas frequências.
 * \details A função percorre o vetor de pares e imprime cada palavra seguida de sua frequência.
 * \return void
 */
void printaResultado(std::vector<std::pair<std::string, int>> palavras) {
  for (auto par : palavras) {
    std::cout << par.first << ": " << par.second << std::endl;
  }
  std::cout << std::endl;
}

/**
 * \brief Função principal que chama as auxiliares para contar e ordenar as palavras de um texto.
 * \param texto String contendo o texto de entrada.
 * \return Vetor de pares com as palavras e suas contagens.
 * \details Separa, conta as palavras e ordena, considerando case e acentuação, e printa o resultado.
 */
std::vector<std::pair<std::string, int>> ContaPalavras(std::string texto) {
  std::vector<std::pair<std::string, int>> palavras;
  palavras = separarEContar(texto);
  ordenaPalavras(palavras);
  printaResultado(palavras);
  return palavras;
}
