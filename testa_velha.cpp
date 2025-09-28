// "Copyright 2025 Joao Felipe Stein"
/**
 * \file testa_velha.cpp
 */

#include "velha.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// Vitorias na vertical

TEST_CASE("Vitoria Coluna 3", "[single-file]") {
    int teste1[3][3]= {   { 2, 0, 1 },
                          { 2, 0, 1 },
                          { 0, 2, 1 }
                      };
    REQUIRE(VerificaVelha(teste1) == 1);
}

TEST_CASE("Vitoria Coluna 2", "[single-file]") {
    int teste1[3][3]= {   { 1, 2, 0 },
                          { 0, 2, 1 },
                          { 0, 2, 1 }
                      };
    REQUIRE(VerificaVelha(teste1) == 2);
}

TEST_CASE("Vitoria Coluna 1", "[single-file]") {
    int teste1[3][3]= {   { 1, 2, 0 },
                          { 1, 0, 2 },
                          { 1, 2, 0 }
                      };
    REQUIRE(VerificaVelha(teste1) == 1);
}

// Vitorias na horizontal

TEST_CASE("Vitoria Linha 1", "[single-file]") {
    int teste1[3][3]= {   { 1, 1, 1 },
                          { 0, 0, 2 },
                          { 2, 2, 0 }
                      };
    REQUIRE(VerificaVelha(teste1) == 1);
}

TEST_CASE("Vitoria Linha 2", "[single-file]") {
    int teste1[3][3]= {   { 0, 0, 1 },
                          { 2, 2, 2 },
                          { 1, 1, 0 }
                      };
    REQUIRE(VerificaVelha(teste1) == 2);
}

TEST_CASE("Vitoria Linha 3", "[single-file]") {
    int teste1[3][3]= {   { 0, 0, 2 },
                          { 2, 0, 2 },
                          { 1, 1, 1 }
                      };
    REQUIRE(VerificaVelha(teste1) == 1);
}

// Vitorias na diagonal

TEST_CASE("Vitoria X Diagonal Esquerda-Direita", "[single-file]") {
    int teste1[3][3]= {   { 1, 0, 2 },
                          { 0, 1, 2 },
                          { 0, 2, 1 }
                      };
    REQUIRE(VerificaVelha(teste1) == 1);
}