// "Copyright 2025 Joao Felipe Stein"
/**
 * \file  velha.cpp
 */
#include "velha.hpp"
/**
 * @brief Define os estados possiveis em um tabuleiro de jogo da velha.
 * * Essa enum eh usada como valores de retorno para a funcao
 * VerificaVelha.
 */
enum TIC_TAC_CONDITION {
    /** * O tabuleiro eh impossivel conforme as regras do jogo.
     * (Por exemplo : mais de um vencedor; quantidade incorreta de
     * X's comparados a quantidade de O's).
     */
    IMPOSSIBLE = -2,

    /** O jogo esta em progresso. */
    INDECISIVE = -1,

    /** O jogo terminou como um empate (Nao eh possivel fazer mais jogadas). */
    TIE,

    /** X ganhou o jogo. */
    X_WINNING,

    /** O ganhou o jogo. */
    O_WINNING
};

 /** 
 * @brief Verifica se existe algum movimento que ainda possa ser feito
 * no jogo.
 * @author Joao Felipe Stein
 * @param  retorna true caso seja possivel fazer uma jogada, e false
 * caso esse nao seja o caso.
 */ 
bool isMoveAvailable(int velha[3][3]) {
    for (int line = 0; line < 3; line++) {
        for (int column = 0; column < 3; column++) {
            if (velha[line][column] == 0) {
                return true;
            }
        }
    }
    return false;
}

/** 
 * @brief Checa todas as colunas de um tabuleiro 3x3, 
 * verificando se estao em condicao de vitoria.
 * @author Joao Felipe Stein
 * @param  Velha eh uma matriz 3x3 representando um tabuleiro de 
 * jogo da velha, winner eh um parametro que guarda quem foi vitorioso 
 * e wins guarda a quantidade de vitorias, caso haja mais de uma.
 */ 
void checkColumns(int velha[3][3], int &winner, int &wins) {
    for (int column = 0; column < 3; column++) {
        bool columnIsEqual = (velha[0][column] == velha[1][column])
                        && (velha[1][column] == velha[2][column]);

        if (velha[0][column] != 0 && columnIsEqual) {
             winner = velha[0][column];
            wins++;
        }
    }
}

/** 
 * @brief Checa todas as linhas de um tabuleiro 3x3, 
 * verificando se estao em condicao de vitoria.
 * @author Joao Felipe Stein
 * @param  Velha eh uma matriz 3x3 representando um tabuleiro de 
 * jogo da velha, winner eh um parametro que guarda quem foi vitorioso 
 * e wins guarda a quantidade de vitorias, caso haja mais de uma.
 */ 
void checkLines(int velha[3][3], int &winner, int &wins) {
    for (int line = 0; line < 3; line++) {
        bool lineIsEqual = (velha[line][0] == velha[line][1])
                        && (velha[line][1] == velha[line][2]);

        if (velha[line][0] != 0 && lineIsEqual) {
            winner = velha[line][0];
            wins++;
        }
    }
}

/** 
 * @brief Checa as duas diagonais de um tabuleiro 3x3, 
 * verificando se estao em condicao de vitoria.
 * @author Joao Felipe Stein
 * @param  Velha eh uma matriz 3x3 representando um tabuleiro de 
 * jogo da velha, winner eh um parametro que guarda quem foi vitorioso 
 * e wins guarda a quantidade de vitorias, caso haja mais de uma.
 */ 
void checkDiagonals(int velha[3][3], int &winner, int &wins) {
    bool diagonalIsEqual = (velha[0][0] == velha[1][1]) 
                           && (velha[1][1] == velha[2][2]);
    if (velha[0][0] != 0 && diagonalIsEqual) {
        winner = velha[0][0];
        wins++;
    }

    bool antiDiagonalIsEqual = (velha[0][2] == velha[1][1]) 
                               && (velha[1][1] == velha[2][0]);
    if (velha[0][2] != 0 && antiDiagonalIsEqual) {
        winner = velha[0][2];
        wins++;
    }
}

/** 
 * @brief Verifica a situacao de um jogo da velha 3x3. 
 * @author Joao Felipe Stein
 * @param  Velha eh uma matriz 3x3 descrevendo a situacao do tabuleiro.
 * @return Retorna 2 caso O esteja ganhando, 1 caso X esteja ganhando, 
 * 0 caso o resultado seja um empate, -1 caso o resultado seja
 * indecisivo e -2 caso o jogo seja impossivel.
 */ 
int VerificaVelha(int velha[3][3]) {
    int quantityX = 0;
    int quantityO = 0;
    for (int line = 0; line < 3; line++) {
        for (int column = 0; column < 3; column++) {
            if (velha[line][column] == 1) {
                quantityX++;
            }

            if (velha[line][column] == 2) {
                quantityO++;
            }
        }
    }

    if (quantityO > quantityX) {
        return IMPOSSIBLE;
    } else if (quantityX - quantityO > 1) {
        return IMPOSSIBLE;
    }

    int winner = INDECISIVE;
    int winsCounted = 0;

    checkColumns(velha, winner, winsCounted);

    checkLines(velha, winner, winsCounted);

    checkDiagonals(velha, winner, winsCounted);

    // Check for impossible wins
    if (winsCounted > 1) {
        return IMPOSSIBLE;
    } else if (winsCounted == 1) {
        if (winner == X_WINNING && quantityX == quantityO) {
            return IMPOSSIBLE;
        } else if (winner == O_WINNING && quantityX > quantityO) {
            return IMPOSSIBLE;
        } else {
            return winner;
        }
    }

    // Check for tie
    if (isMoveAvailable(velha)) {
        return INDECISIVE;
    } else {
        return TIE;
    }
}
