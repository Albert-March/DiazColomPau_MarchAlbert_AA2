#include "Mapa.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

void initializeMapa(Symbols& symbols, char board[NUM_ROWS][NUM_COLUMNS], Mapa& mapa)
{
    mapa.gameState = 0;
    int maxPokemon = 10;
    int pokemonPlaced = 0;

        for (int i = 0; i < NUM_ROWS; ++i)
        {
            for (int j = 0; j < NUM_COLUMNS; ++j)
            {
                if (i == 0 || i == NUM_ROWS / 2 || i == NUM_ROWS - 1 || j == 0 || j == NUM_COLUMNS / 2 || j == NUM_COLUMNS - 1)
                {
                    board[i][j] = symbols.pared;
                }
                else
                {
                    board[i][j] = symbols.empty;
                }
            }

        }
        while (pokemonPlaced < maxPokemon)
        {
            int row = rand() % NUM_ROWS/2;
            int column = rand() % NUM_COLUMNS/2;
            if (board[row][column] == symbols.empty)
            {
                board[row][column] = symbols.pokemon;
                pokemonPlaced++;
            }
        }

}

float* Read()
{
    int numRowsArray = 3;
    int numColsArray = 2;
    int valor;

    float** myArray2D;
    myArray2D = new float* [numRowsArray];
    for (int i = 0; i < numRowsArray; ++i) {
        myArray2D[i] = new float[numColsArray];
    }

    // Abrir el archivo
    std::ifstream archivo("config.txt");
    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo." << std::endl;
        //return 1;
    }



    for (int i = 0; i < numRowsArray; ++i) {
        for (int j = 0; j < numColsArray; ++j) {
            char coma;
            archivo >> valor >> coma; // Leemos el valor y la coma
            myArray2D[i][j] = valor;
        }
    }
    archivo.close();

    //return *myArray2D;


    std::cout << "Array:" << std::endl;
    for (int i = 0; i < numRowsArray; ++i) {
        for (int j = 0; j < numColsArray; ++j) {
            std::cout << myArray2D[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Liberar la memoria
    for (int i = 0; i < numRowsArray; ++i) {
        delete[] myArray2D[i];
    }
    delete[] myArray2D;

    return 0;
}


void printMapa(Symbols& symbols, char board[NUM_ROWS][NUM_COLUMNS], Mapa& mapa)
{
    int maxPokemon = 10;
    mapa.m_row;
    mapa.m_col;
    mapa.p_row = mapa.m_row + (NUM_ROWS_PRINT/2);
    mapa.p_col = mapa.m_col + (NUM_COLUMNS_PRINT/2);
    if (mapa.gameState == 1 && mapa.aparicionPokemon == true)
    {
            for (int i = 0; i < NUM_ROWS; ++i)
            {
                for (int j = 0; j < NUM_COLUMNS; ++j)
                {
                    if (i != 0 && i < NUM_ROWS / 2 && j == NUM_COLUMNS / 2)
                    {
                        board[i][j] = symbols.empty;
                    }
                }

            }
            for (int i = 0; i < maxPokemon; ++i)
            {
                int row = rand() % (NUM_ROWS / 2);
                int column = rand() % (NUM_COLUMNS / 2) + (NUM_COLUMNS / 2);
                if (board[row][column] == symbols.empty)
                {
                    board[row][column] = symbols.pokemon;
                }
                else
                    i--;
            }
            mapa.aparicionPokemon = false;
    }
    if (mapa.gameState == 2 && mapa.aparicionPokemon == true)
    {
        for (int i = 0; i < NUM_ROWS; ++i)
        {
            for (int j = 0; j < NUM_COLUMNS; ++j)
            {
                if (i == NUM_ROWS / 2 && j > NUM_COLUMNS / 2 && j != (NUM_COLUMNS-1))
                {
                    board[i][j] = symbols.empty;
                }
            }

        }
        for (int i = 0; i < maxPokemon; ++i)
        {
            int row = rand() % (NUM_ROWS / 2) + (NUM_ROWS / 2);
            int column = rand() % (NUM_COLUMNS / 2) + (NUM_COLUMNS / 2);
            if (board[row][column] == symbols.empty)
            {
                board[row][column] = symbols.pokemon;
            }
            else
                i--;
        }
        mapa.aparicionPokemon = false;
    }
    if (mapa.gameState == 3 && mapa.aparicionPokemon == true)
    {
        for (int i = 0; i < NUM_ROWS; ++i)
        {
            for (int j = 0; j < NUM_COLUMNS; ++j)
            {
                if (i != (NUM_ROWS-1) && i > NUM_ROWS / 2 && j == NUM_COLUMNS / 2)
                {
                    board[i][j] = symbols.empty;
                }
            }

        }
        for(int i =0; i < maxPokemon; ++i)
        {
            int row = rand() % (NUM_ROWS / 2) + (NUM_ROWS / 2);
            int column = rand() % (NUM_COLUMNS / 2);
            if (board[row][column] == symbols.empty)
            {
                board[row][column] = symbols.pokemon;
            }
            else
                i--;
        }
        mapa.aparicionPokemon = false;
    }
    for (int i = mapa.m_row; i < NUM_ROWS_PRINT + mapa.m_row; ++i)
    {
        for (int j = mapa.m_col; j < NUM_COLUMNS_PRINT + mapa.m_col; ++j)
        {
            
            if (i == mapa.p_row && j == mapa.p_col)
            {
                switch (mapa.positionAsh)
                {
                case 0:
                    std::cout << symbols.p_arriva << " ";
                    break;
                case 1:
                    std::cout << symbols.p_abajo << " ";
                    break;
                case 2:
                    std::cout << symbols.p_izquierda << " ";
                    break;
                case 3:
                    std::cout << symbols.p_derecha << " ";
                    break;
                }
            }
            else {
                switch (board[i][j])
                {
                case 'X':
                    std::cout << symbols.pared << " ";
                    break;
                case '-':
                    std::cout << symbols.empty << " ";
                    break;
                case 'P':
                    std::cout << symbols.pokemon << " ";
                    break;
                }
            }
                
        }
        std::cout << std::endl;
    }

}

