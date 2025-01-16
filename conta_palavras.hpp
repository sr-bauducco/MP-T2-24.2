/**
 * \file conta_palavras.hpp.hpp
 * \version 1.0
 * 
 * \brief Declaração das funções para o contador de palavras.
 *
 * Este arquivo contém as declarações de funções que permitem:
 * - Ler o conteúdo de arquivos de texto.
 * - Contar palavras e suas frequências em um texto.
 * - Ordenar palavras por frequência.
 * - Exibir resultados no console.
 *
 * \details
 * Este código usa métodos como merge sort para ordenar os pares
 * (palavra, frequência) e inclui suporte a funções como remoção de acentos
 * e conversão para letras minúsculas, melhorando a precisão da contagem.
 *
 * \example
 * \code
 * std::string texto = lerArquivo("meuarquivo.txt");
 * auto palavras = ContaPalavras(texto);
 * ordenaPalavras(palavras);
 * printaResultado(palavras);
 * \endcode
 */
#ifndef CONTA_PALAVRAS_HPP_
#define CONTA_PALAVRAS_HPP_

#include <string>
#include <vector>
#include <utility>

/**
 * \brief Função principal que chama as auxiliares para contar e ordenar as palavras de um texto.
 * \param texto String contendo o texto de entrada.
 * \return Vetor de pares com as palavras e suas contagens.
 */
std::vector<std::pair<std::string, int>> ContaPalavras(std::string texto);

/**
 * \brief Lê o conteúdo de um arquivo e retorna como uma string.
 * \param nome_do_arquivo Nome do arquivo a ser lido.
 * \return Retorna o conteúdo do arquivo como uma string.
 */
std::string lerArquivo(std::string nome_do_arquivo);

/**
 * \brief Separa as palavras de um texto e conta a frequência de cada uma.
 * \param texto Texto a ser processado.
 * \return Vetor de pares contendo palavras e suas respectivas frequências.
 */
std::vector<std::pair<std::string, int>> separarEContar(std::string texto);

/**
 * \brief Converte uma string para letras minúsculas.
 * \param palavra String a ser convertida.
 * \return String com todas as letras em minúsculas.
 */
std::string lowerCase(std::string palavra);

/**
 * \brief Remove acentos de uma palavra.
 * \param palavra String com possíveis caracteres acentuados.
 * \return String sem caracteres acentuados.
 */
std::string removerAcentos(std::string palavra);

/**
 * \brief Função auxiliar do merge sort para mesclar dois subvetores.
 * \param vetor Vetor a ser ordenado.
 * \param inicio Índice inicial do primeiro subvetor.
 * \param meio Índice final do primeiro subvetor e início do segundo.
 * \param fim Índice final do segundo subvetor.
 * \return void
 */
void merge(std::vector<std::pair<std::string, int>>& vetor,
           int inicio, int meio, int fim);

/**
 * \brief Ordena um vetor de pares (palavra, contagem).
 * \param vetor Vetor a ser ordenado.
 * \param inicio Índice inicial do vetor.
 * \param fim Índice final do vetor.
 * \return void
 */
void mergeSort(std::vector<std::pair<std::string, int>>& vetor,
               int inicio, int fim);

/**
 * \brief Ordena o vetor de palavras e contagens.
 * \param palavras Vetor contendo pares de palavras e suas contagens.
 * \return void
 */
void ordenaPalavras(std::vector<std::pair<std::string, int>>& palavras);

/**
 * \brief Exibe as palavras e suas respectivas frequências no console.
 * \param palavras Um vetor de pares contendo as palavras e suas frequências.
 * \return void
 */
void printaResultado(std::vector<std::pair<std::string, int>> palavras);

#endif  // CONTA_PALAVRAS_HPP_
