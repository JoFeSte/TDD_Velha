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
    int teste2[3][3]= {   { 1, 2, 0 },
                          { 0, 2, 1 },
                          { 0, 2, 1 }
                      };
    REQUIRE(VerificaVelha(teste2) == 2);
}

TEST_CASE("Vitoria Coluna 1", "[single-file]") {
    int teste3[3][3]= {   { 1, 2, 0 },
                          { 1, 0, 2 },
                          { 1, 2, 0 }
                      };
    REQUIRE(VerificaVelha(teste3) == 1);
}

// Vitorias na horizontal

TEST_CASE("Vitoria Linha 1", "[single-file]") {
    int teste4[3][3]= {   { 1, 1, 1 },
                          { 0, 0, 2 },
                          { 2, 2, 0 }
                      };
    REQUIRE(VerificaVelha(teste4) == 1);
}

TEST_CASE("Vitoria Linha 2", "[single-file]") {
    int teste5[3][3]= {   { 0, 0, 1 },
                          { 2, 2, 2 },
                          { 1, 1, 0 }
                      };
    REQUIRE(VerificaVelha(teste5) == 2);
}

TEST_CASE("Vitoria Linha 3", "[single-file]") {
    int teste6[3][3]= {   { 0, 0, 2 },
                          { 2, 0, 2 },
                          { 1, 1, 1 }
                      };
    REQUIRE(VerificaVelha(teste6) == 1);
}

// Vitorias na diagonal

TEST_CASE("Vitoria X Diagonal Esquerda-Direita", "[single-file]") {
    int teste7[3][3]= {   { 1, 0, 2 },
                          { 0, 1, 2 },
                          { 0, 2, 1 }
                      };
    REQUIRE(VerificaVelha(teste7) == 1);
}

TEST_CASE("Vitoria X Diagonal Direita-Esquerda", "[single-file]") {
    int teste8[3][3]= {   { 2, 0, 1 },
                          { 0, 1, 2 },
                          { 1, 2, 0 }
                      };
    REQUIRE(VerificaVelha(teste8) == 1);
}

// Empate

TEST_CASE("Empate 1", "[single-file]") {
    int teste9[3][3]= {   { 1, 2, 1 },
                          { 2, 2, 1 },
                          { 1, 1, 2 }
                      };
    REQUIRE(VerificaVelha(teste9) == 0);
}

TEST_CASE("Empate 2", "[single-file]") {
    int teste10[3][3]= {  { 1, 2, 2 },
                          { 2, 1, 1 },
                          { 1, 1, 2 }
                      };
    REQUIRE(VerificaVelha(teste10) == 0);
}

TEST_CASE("Vitoria tabuleiro cheio X", "[single-file]") {
    int teste11[3][3]= {  { 1, 2, 2 },
                          { 2, 1, 1 },
                          { 1, 2, 1 }
                      };
    REQUIRE(VerificaVelha(teste11) == 1);
}

TEST_CASE("Vitoria tabuleiro cheio O", "[single-file]") {
    int teste12[3][3]= {  { 2, 1, 1 },
                          { 2, 2, 1 },
                          { 1, 1, 2 }
                      };
    REQUIRE(VerificaVelha(teste12) == 2);
}

// Impossivel

TEST_CASE("Nenhum X", "[single-file]") {
    int teste13[3][3]= {  { 0, 2, 2 },
                          { 0, 0, 2 },
                          { 2, 2, 0 }
                      };
    REQUIRE(VerificaVelha(teste13) == -2);
}

TEST_CASE("Nenhum O", "[single-file]") {
    int teste14[3][3]= {  { 0, 1, 1 },
                          { 0, 0, 1 },
                          { 1, 1, 1 }
                      };
    REQUIRE(VerificaVelha(teste14) == -2);
}

// Indeciso

TEST_CASE("Apenas um X", "[single-file]") {
    int teste15[3][3]= {  { 0, 1, 0 },
                          { 0, 0, 0 },
                          { 0, 0, 0 }
                      };
    REQUIRE(VerificaVelha(teste15) == -1);
}

TEST_CASE("Apenas zeros", "[single-file]") {
    int teste16[3][3]= {  { 0, 0, 0 },
                          { 0, 0, 0 },
                          { 0, 0, 0 }
                      };
    REQUIRE(VerificaVelha(teste16) == -1);
}
