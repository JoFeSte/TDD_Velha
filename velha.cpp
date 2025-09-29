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

int VerificaVelha(int velha[3][3]) {
    /*  Test 1 : Return win condition if 
        column 3 has the same number that isn't zero
    */

    /* 1 if X is winning, 2 if O is winning, 
    0 if Tie, -1 if Indecisive, -2 if Impossible*/
    int returnValue = -1;

    for (int column = 0; column < 3; column++) {
		bool columnIsEqual = (velha[0][column] == velha[1][column]) 
						&& (velha[1][column] == velha[2][column]);

        if (velha[0][column] != 0 && columnIsEqual) {
         	returnValue = velha[0][column];
        }
    }

    for (int line = 0; line < 3; line++) {
		bool lineIsEqual = (velha[line][0] == velha[line][1]) 
						&& (velha[line][1] == velha[line][2]);

        if (velha[line][0] != 0 && lineIsEqual) {
			returnValue = velha[line][0];
        }
    }

	bool diagonalIsEqual = (velha[0][0] == velha[1][1]) && (velha[1][1] == velha[2][2]);
	if (velha[0][0] != 0 && diagonalIsEqual)
	{
		returnValue = velha[0][0];
	}

	bool antiDiagonalIsEqual = (velha[0][2] == velha[1][1]) && (velha[1][1] == velha[2][0]);
	if (velha[0][2] != 0 && antiDiagonalIsEqual)
	{
		returnValue = velha[0][2];
	}

    return returnValue;
}


