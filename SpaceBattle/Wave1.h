/**********************************************************************************
// Wave1 (Arquivo de Cabeçalho)
//
// Criação:     21 Nov 2022
// Atualização: 21 Nov 2022
// Compilador:  Visual C++ 2022
//
// Descrição:   Cria uma onda de inimigos Magenta
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
    float pX, pY;       // posição dos inimigos 
    RandF posX;         // valor aleatório para posição X
    RandF posY;         // valor aleatório para posição Y
    RandF secs;         // valor aleatório de segundos
    Timer timer;        // medidor de tempo
    float delay;        // atraso para a próxima onda

public:
    Wave1();            // construtor
    ~Wave1();           // destrutor

    void Update();      // atualização
    void Draw();        // desenho
};

// ------------------------------------------------------------------------------

#endif
