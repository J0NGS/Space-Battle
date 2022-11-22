/**********************************************************************************
// Wave1 (Arquivo de Cabe�alho)
//
// Cria��o:     21 Nov 2022
// Atualiza��o: 21 Nov 2022
// Compilador:  Visual C++ 2022
//
// Descri��o:   Cria uma onda de inimigos Magenta
//
**********************************************************************************/

#ifndef _SPACEBATTLE_WAVE1_H_
#define _SPACEBATTLE_WAVE1_H_

// --------------------------------------------------------------------------------

#include "Object.h"
#include "Timer.h"
#include "Random.h"

// --------------------------------------------------------------------------------

class Wave1 : public Object
{
private:
    float pX, pY;       // posi��o dos inimigos 
    RandF posX;         // valor aleat�rio para posi��o X
    RandF posY;         // valor aleat�rio para posi��o Y
    RandF secs;         // valor aleat�rio de segundos
    Timer timer;        // medidor de tempo
    float delay;        // atraso para a pr�xima onda

public:
    Wave1();            // construtor
    ~Wave1();           // destrutor

    void Update();      // atualiza��o
    void Draw();        // desenho
};

// ------------------------------------------------------------------------------

#endif
