/**
 * \file testa_conta_palavras.cpp
 * \brief Testes unitários para verificar o contador de palavras usando Catch2.
 *
 */

#define CATCH_CONFIG_NO_POSIX_SIGNALS
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "conta_palavras.hpp"
#include <string>

TEST_CASE("Teste 1: texto vazio") {
  std::string texto = lerArquivo("teste1");
  auto resultado = ContaPalavras(texto);

  REQUIRE(resultado.size() == 0);
}

TEST_CASE("Teste 2: leitura de arquivo") {
  std::string texto = lerArquivo("teste2");
  auto resultado = ContaPalavras(texto);

  REQUIRE(resultado.size() == 1);
}

TEST_CASE("Teste 3: separação de palavras") {
  std::string texto = lerArquivo("teste3");
  auto resultado = ContaPalavras(texto);

  REQUIRE(resultado.size() == 2);
  REQUIRE(resultado[0].first == "texto");
  REQUIRE(resultado[1].first == "utilizado");
}

TEST_CASE("Teste 4: contagem de ocorrências das palavras") {
  std::string texto = lerArquivo("teste4");
  auto resultado = ContaPalavras(texto);

  REQUIRE(resultado.size() == 3);
  REQUIRE(resultado[0].first == "texto");
  REQUIRE(resultado[0].second == 2);
  REQUIRE(resultado[1].first == "utilizado");
  REQUIRE(resultado[1].second == 1);
  REQUIRE(resultado[2].first == "validado");
  REQUIRE(resultado[2].second == 1);
}

TEST_CASE("Teste 5: separação com pontuação e caracteres especiais") {
  std::string texto = lerArquivo("teste5");
  auto resultado = ContaPalavras(texto);

  REQUIRE(resultado.size() == 5);
  REQUIRE(resultado[0].first == "abra");
  REQUIRE(resultado[1].first == "ajuste");
  REQUIRE(resultado[2].first == "alinhe");
  REQUIRE(resultado[3].first == "texto");
  REQUIRE(resultado[4].first == "válido");
}

TEST_CASE("Teste 6: normalização das palavras para lowerCase") {
  std::string texto = lerArquivo("teste6");
  auto resultado = lowerCase(texto);

  REQUIRE(resultado == "envio para teste válido");
}

TEST_CASE("Teste 7: normalização das palavras com remoção de acento") {
  std::string texto = lerArquivo("teste7");
  auto resultado = removerAcentos(texto);

  REQUIRE(resultado == "ha informacao logica no texto");
}

TEST_CASE("Teste 8: ordenação alfabética das palavras") {
  std::string texto = lerArquivo("teste8");
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

TEST_CASE("Teste 9: ordenação considerando letras minúsculas e maiúsculas") {
  std::string texto = lerArquivo("teste9");
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

TEST_CASE("Teste 10: ordenação considerando acentuação") {
  std::string texto = lerArquivo("teste10");
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
