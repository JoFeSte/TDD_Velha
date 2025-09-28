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

int VerificaVelha( int velha[3][3] )
{
	// Test 1 : Return win condition if column 3 has the same number that isn't zero

	/* 1 if X is winning, 2 if O is winning, 0 if Tie, -1 if Indecisive, -2 if Impossible*/
	int returnValue = -1;

	if (velha[0][2] != 0 && velha[0][2] == velha[1][2] && velha[1][2] == velha[2][2])
	{
		returnValue = velha[0][2];
	}

	if (velha[0][1] != 0 && velha[0][1] == velha[1][1] && velha[1][1] == velha[2][1])
	{
		returnValue = velha[0][1];
	}

	return returnValue;
}


