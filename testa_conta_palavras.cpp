/**
 * \file testa_conta_palavras.cpp
 * \version 1.0
 * 
 * \brief Testes unitários para verificar a funcionalidade do contador de palavras.
 *
 * \details Este arquivo utiliza o framework Catch2 para realizar testes unitários
 * das funções implementadas no arquivo `conta_palavras.cpp`. Os testes cobrem:
 * - Leitura de arquivos.
 * - Separação e contagem de palavras.
 * - Normalização de texto (conversão para minúsculas e remoção de acentos).
 * - Ordenação alfabética e tratamento de palavras com acentuação ou caracteres especiais.
 *
 * \note Para compilar e executar os testes, é necessário incluir o framework Catch2.
 *
 * \example
 * \code
 * // Compile usando:
 * g++ -std=c++17 testa_conta_palavras.cpp -o testa_conta_palavras
 * // Execute o binário gerado para rodar os testes.
 * ./testa_conta_palavras
 * \endcode
 */

#define CATCH_CONFIG_NO_POSIX_SIGNALS
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "conta_palavras.hpp"
#include <string>

// Testes começam aqui

/**
 * \brief Testa a contagem de palavras em um texto vazio.
 * \details Verifica se o vetor de resultados está vazio ao processar um arquivo vazio.
 */
TEST_CASE("Teste 1: texto vazio") {
  std::string texto = lerArquivo("teste1.txt");
  auto resultado = ContaPalavras(texto);

  REQUIRE(resultado.size() == 0);
}

/**
 * \brief Testa a leitura de arquivos.
 * \details Verifica se a função `lerArquivo` lê corretamente o conteúdo de um arquivo.
 */
TEST_CASE("Teste 2: leitura de arquivo") {
  std::string texto = lerArquivo("teste2.txt");
  auto resultado = ContaPalavras(texto);

  REQUIRE(resultado.size() == 1);
}

/**
 * \brief Testa a separação de palavras.
 * \details Garante que as palavras são corretamente separadas e inseridas no vetor de resultados.
 */
TEST_CASE("Teste 3: separação de palavras") {
  std::string texto = lerArquivo("teste3.txt");
  auto resultado = ContaPalavras(texto);

  REQUIRE(resultado.size() == 2);
  REQUIRE(resultado[0].first == "texto");
  REQUIRE(resultado[1].first == "utilizado");
}

/**
 * \brief Testa a contagem de ocorrências das palavras.
 * \details Verifica se as palavras repetidas têm sua contagem corretamente incrementada.
 */
TEST_CASE("Teste 4: contagem de ocorrências das palavras") {
  std::string texto = lerArquivo("teste4.txt");
  auto resultado = ContaPalavras(texto);

  REQUIRE(resultado.size() == 3);
  REQUIRE(resultado[0].first == "texto");
  REQUIRE(resultado[0].second == 2);
  REQUIRE(resultado[1].first == "utilizado");
  REQUIRE(resultado[1].second == 1);
  REQUIRE(resultado[2].first == "validado");
  REQUIRE(resultado[2].second == 1);
}

/**
 * \brief Testa a separação de palavras com pontuação e caracteres especiais.
 * \details Garante que pontuações e caracteres especiais não interfiram na separação das palavras.
 */
TEST_CASE("Teste 5: separação com pontuação e caracteres especiais") {
  std::string texto = lerArquivo("teste5.txt");
  auto resultado = ContaPalavras(texto);

  REQUIRE(resultado.size() == 5);
  REQUIRE(resultado[0].first == "abra");
  REQUIRE(resultado[1].first == "ajuste");
  REQUIRE(resultado[2].first == "alinhe");
  REQUIRE(resultado[3].first == "texto");
  REQUIRE(resultado[4].first == "válido");
}

/**
 * \brief Testa a normalização para letras minúsculas.
 * \details Verifica se todas as palavras são convertidas para minúsculas.
 */
TEST_CASE("Teste 6: normalização das palavras para lowerCase") {
  std::string texto = lerArquivo("teste6.txt");
  std::string resultado = lowerCase(texto);
  REQUIRE(resultado == "envio para teste válido");
}

/**
 * \brief Testa a remoção de acentos.
 * \details Garante que caracteres acentuados são convertidos para suas versões sem acento.
 */
TEST_CASE("Teste 7: normalização das palavras com remoção de acento") {
  std::string texto = lerArquivo("teste7.txt");
  auto resultado = removerAcentos(texto);

  REQUIRE(resultado == "ha informacao logica no texto");
}

/**
 * \brief Testa a ordenação alfabética das palavras.
 * \details Garante que as palavras são ordenadas em ordem alfabética, ignorando maiúsculas e minúsculas.
 */
TEST_CASE("Teste 8: ordenação alfabética das palavras") {
  std::string texto = lerArquivo("teste8.txt");
  auto resultado = ContaPalavras(texto);

  REQUIRE(resultado.size() == 8);
  REQUIRE(resultado[0].first == "de");
  REQUIRE(resultado[1].first == "este");
  REQUIRE(resultado[2].first == "exemplo");
  REQUIRE(resultado[3].first == "ordenar");
  REQUIRE(resultado[4].first == "palavras");
  REQUIRE(resultado[5].first == "para");
  REQUIRE(resultado[6].first == "serve");
  REQUIRE(resultado[7].first == "teste");
}

/**
 * \brief Testa a ordenação considerando letras maiúsculas e minúsculas.
 * \details Verifica se a ordenação trata palavras com diferentes capitalizações de forma consistente.
 */
TEST_CASE("Teste 9: ordenação considerando letras minúsculas e maiúsculas") {
  std::string texto = lerArquivo("teste9.txt");
  auto resultado = ContaPalavras(texto);

  REQUIRE(resultado.size() == 7);
  REQUIRE(resultado[0].first == "Case");
  REQUIRE(resultado[1].first == "com");
  REQUIRE(resultado[2].first == "Esse");
  REQUIRE(resultado[3].first == "ordenar");
  REQUIRE(resultado[4].first == "para");
  REQUIRE(resultado[5].first == "serve");
  REQUIRE(resultado[6].first == "teste");
}

/**
 * \brief Testa a ordenação considerando palavras com acentuação.
 * \details Garante que palavras com acentos são tratadas corretamente durante a ordenação.
 */
TEST_CASE("Teste 10: ordenação considerando acentuação") {
  std::string texto = lerArquivo("teste10.txt");
  auto resultado = ContaPalavras(texto);

  REQUIRE(resultado.size() == 7);
  REQUIRE(resultado[0].first == "é");
  REQUIRE(resultado[0].second == 1);
  REQUIRE(resultado[1].first == "Este");
  REQUIRE(resultado[1].second == 1);
  REQUIRE(resultado[2].first == "o");
  REQUIRE(resultado[2].second == 1);
  REQUIRE(resultado[3].first == "que");
  REQUIRE(resultado[3].second == 1);
  REQUIRE(resultado[4].first == "será");
  REQUIRE(resultado[4].second == 1);
  REQUIRE(resultado[5].first == "texto");
  REQUIRE(resultado[5].second == 2);
  REQUIRE(resultado[6].first == "utilizado");
  REQUIRE(resultado[6].second == 1);
}
