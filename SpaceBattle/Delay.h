/**********************************************************************************
// Delay (Arquivo de Cabeçalho)
//
// Criação:     19 Nov 2022
// Atualização: 19 Nov 2022
// Compilador:  Visual C++ 2019
//
// Descrição:   Passa as fases do jogo
//
**********************************************************************************/

#ifndef _SPACEBATTLE_DELAY_H_
#define _SPACEBATTLE_DELAY_H_

// --------------------------------------------------------------------------------

#include "Object.h"
#include "Sprite.h"
#include "Timer.h"
#include "Animation.h"

// --------------------------------------------------------------------------------

class Delay : public Object
{
private:
    Sprite* logo;           // logotipo do jogo
    Sprite* gameover;       // logotipo do jogo
    TileSet* tile;          // tileset da nave explodindo
    Animation* anim;        // animação da nave explodindo
    Timer timer;            // medidor de tempo

    bool notPlayed;         // intro não tocada ainda
    bool fase1;             // fase 1 completada
    bool fase2;             // fase 2 completada
    bool fase3;             // fase 3 completada
    bool fase4;             // fase 4 completada
    bool end;               // gameover

public:
    Delay();                // construtor
    ~Delay();               // destrutor

    void Update();          // atualização
    void Draw();            // desenho
};

// ------------------------------------------------------------------------------

#endif
