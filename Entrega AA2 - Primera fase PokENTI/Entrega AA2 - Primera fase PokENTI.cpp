// Entrega AA2 - Primera fase PokENTI.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Mapa.h"
#include <fstream>
#include <string>
#include <windows.h>

int main()
{
	bool gameState = true;
	char board[NUM_ROWS][NUM_COLUMNS];
	Symbols symbols = { '>', '<', '^', 'v', '-', 'P', 'X'};
	Mapa mapa = { 0, 0 };
	srand(time(NULL));
	//Read();
	initializeMapa(symbols, board, mapa);
	printMapa(symbols, board, mapa);
	while (gameState == true)
	{
        if (mapa.pokemonsCapturados == 1)
        {
            if (gameState <= 3)
            {
                mapa.gameState++;
                mapa.aparicionPokemon = true;
            }
            mapa.pokemonsCapturados = 0;
        }
        mapa.p_row = mapa.m_row + (NUM_ROWS_PRINT / 2);
        mapa.p_col = mapa.m_col + (NUM_COLUMNS_PRINT / 2);
            if (GetAsyncKeyState(VK_UP)) {
                //Tecla presionada
                if (board[mapa.p_row - 1][mapa.p_col] == symbols.empty) {
                    mapa.m_row--;
                }
                mapa.positionAsh = 0;
                std::system("cls");
                printMapa(symbols, board, mapa);
            }
            //Sleep(100);
            if (GetAsyncKeyState(VK_DOWN)) {
                //Tecla presionada
                if (board[mapa.p_row + 1][mapa.p_col] == symbols.empty) {
                    mapa.m_row++;
                }
                mapa.positionAsh = 1;
                std::system("cls");
                printMapa(symbols, board, mapa);
            }
            //Sleep(100);
            if (GetAsyncKeyState(VK_LEFT)) {
                //Tecla presionada
                if (board[mapa.p_row][mapa.p_col - 1] == symbols.empty) {
                    mapa.m_col--;
                }    
                mapa.positionAsh = 2;
                std::system("cls");
                printMapa(symbols, board, mapa);
            }
            //Sleep(100);
            if (GetAsyncKeyState(VK_RIGHT)) {
                //Tecla presionada
                if (board[mapa.p_row][mapa.p_col + 1] == symbols.empty) {
                    mapa.m_col++;
                }
                mapa.positionAsh = 3;
                std::system("cls");
                printMapa(symbols, board, mapa);
                
            }
            //Sleep(100);
            if (GetAsyncKeyState(VK_SPACE)) {
                //Tecla presionada
                switch (mapa.positionAsh)
                {
                case 0:
                    if (board[mapa.p_row - 1][mapa.p_col] == symbols.pokemon) {
                        board[mapa.p_row - 1][mapa.p_col] = symbols.empty;
                        mapa.pokemonsCapturados++;
                        std::system("cls");
                        printMapa(symbols, board, mapa);
                        std::cout << "hola";
                    }
                    break;
                case 1:
                    if (board[mapa.p_row + 1][mapa.p_col] == symbols.pokemon) {
                        board[mapa.p_row + 1][mapa.p_col] = symbols.empty;
                        mapa.pokemonsCapturados++;
                        std::system("cls");
                        printMapa(symbols, board, mapa);
                        std::cout << "hola";
                    }
                    break;
                case 2:
                    if (board[mapa.p_row][mapa.p_col-1] == symbols.pokemon) {
                        board[mapa.p_row][mapa.p_col-1] = symbols.empty;
                        mapa.pokemonsCapturados++;
                        std::system("cls");
                        printMapa(symbols, board, mapa);
                        std::cout << "hola";
                    }
                    break;
                case 3:
                    if (board[mapa.p_row][mapa.p_col + 1] == symbols.pokemon) {
                        board[mapa.p_row][mapa.p_col + 1] = symbols.empty;
                        mapa.pokemonsCapturados++;
                        std::system("cls");
                        printMapa(symbols, board, mapa);
                        std::cout << "hola";
                    }
                    break;
                }
            }
            //Sleep(100);
            if (GetAsyncKeyState(VK_ESCAPE)) {
                //Tecla presionada

            }
            //Sleep(100);
        
        Sleep(100);
	}
	
}

