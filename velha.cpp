// "Copyright 2025 Joao Felipe Stein"
/**
 * \file  velha.cpp
 */
#include "velha.hpp"
/** 
 * @brief verifica situacao do jogo da velha  
 * @author Joao Felipe Stein 
 * @param  velha descreve o parametro
 * 
 *  Descrever o que a funcao faz
 */ 

 enum TIC_TAC_CONDITION {
	IMPOSSIBLE = -2,
	INDECISIVE = -1,
	TIE,
	X_WINNING,
	Y_WINNING
 };

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

/* 1 if X is winning, 2 if O is winning, 
0 if Tie, -1 if Indecisive, -2 if Impossible*/
int VerificaVelha(int velha[3][3]) {

	// Impossible
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

	if (quantityO == 0) {
		if (quantityX == 1) {
			return INDECISIVE;
		} else if (quantityX != 0) {
			return IMPOSSIBLE;
		}
	} else if (quantityX == 0) {
		return IMPOSSIBLE;
	}

	if (quantityO > quantityX) {
		return IMPOSSIBLE;
	} else if (quantityX - quantityO > 1) {
		return IMPOSSIBLE;
	}

	// Vertical
    for (int column = 0; column < 3; column++) {
		bool columnIsEqual = (velha[0][column] == velha[1][column]) 
						&& (velha[1][column] == velha[2][column]);

        if (velha[0][column] != 0 && columnIsEqual) {
         	return velha[0][column];
        }
    }

	// Horizontal
    for (int line = 0; line < 3; line++) {
		bool lineIsEqual = (velha[line][0] == velha[line][1]) 
						&& (velha[line][1] == velha[line][2]);

        if (velha[line][0] != 0 && lineIsEqual) {
			return velha[line][0];
        }
    }

	// Diagonals
	bool diagonalIsEqual = (velha[0][0] == velha[1][1]) && (velha[1][1] == velha[2][2]);
	if (velha[0][0] != 0 && diagonalIsEqual) {
		return velha[0][0];
	}

	bool antiDiagonalIsEqual = (velha[0][2] == velha[1][1]) && (velha[1][1] == velha[2][0]);
	if (velha[0][2] != 0 && antiDiagonalIsEqual) {
		return velha[0][2];
	}

	// Check for tie
	if (isMoveAvailable(velha)) {
		return INDECISIVE;
	} else {
		return TIE;
	}
}
