/**********************************************************************************
// WaveO (Arquivo de Cabe�alho)
//
// Cria��o:     21 Nob 2022
// Atualiza��o: 21 Nob 2022
// Compilador:  Visual C++ 2022
//
// Descri��o:   Cria uma onda de inimigos Enemy1
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
    int numX, numY;         // n�mero de inimigos que cabem na tela
    float posX, posY;       // posi��o dos inimigos 
    RandI position;         // valor aleat�rio para posi��o
    RandF delay;            // valor aleat�rio para tempo
    Timer timer;            // medidor de tempo
    float waveDelay;        // atraso para a pr�xima onda
    bool newWave;           // enviar nova onda

public:
    Wave0();                // construtor
    ~Wave0();               // destrutor

    void Update();          // atualiza��o
    void Draw();            // desenho
};

// ------------------------------------------------------------------------------

#endif
