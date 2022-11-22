/**********************************************************************************
// WaveO (Arquivo de Cabeçalho)
//
// Criação:     21 Nob 2022
// Atualização: 21 Nob 2022
// Compilador:  Visual C++ 2022
//
// Descrição:   Cria uma onda de inimigos Enemy1
//
**********************************************************************************/

#ifndef _SPACECBATTLE_WAVEO_H_
#define _SPACECBATTLE_WAVEO_H_

// --------------------------------------------------------------------------------

#include "Object.h"
#include "Sprite.h"
#include "Timer.h"
#include "Random.h"

// --------------------------------------------------------------------------------

class Wave0 : public Object
{
private:
    int numX, numY;         // número de inimigos que cabem na tela
    float posX, posY;       // posição dos inimigos 
    RandI position;         // valor aleatório para posição
    RandF delay;            // valor aleatório para tempo
    Timer timer;            // medidor de tempo
    float waveDelay;        // atraso para a próxima onda
    bool newWave;           // enviar nova onda

public:
    Wave0();                // construtor
    ~Wave0();               // destrutor

    void Update();          // atualização
    void Draw();            // desenho
};

// ------------------------------------------------------------------------------

#endif
