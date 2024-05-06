#pragma once
#include <iostream>
#define NUM_ROWS 21
#define NUM_COLUMNS 41
#define NUM_ROWS_PRINT 11
#define NUM_COLUMNS_PRINT 11

struct Symbols
{
    char p_derecha;
    char p_izquierda;
    char p_arriva;
    char p_abajo;
    char empty;
    char pokemon;
    char pared;
};

struct Mapa
{
    int m_row; //Map
    int m_col;
    int p_row; //Player
    int p_col;
    int positionAsh;
    int gameState;
    int pokemonsCapturados;
    bool aparicionPokemon;

};

	float* Read();

    void initializeMapa(Symbols& symbols, char board[NUM_ROWS][NUM_COLUMNS], Mapa& mapa);
    void printMapa(Symbols& symbols, char board[NUM_ROWS][NUM_COLUMNS], Mapa& mapa);