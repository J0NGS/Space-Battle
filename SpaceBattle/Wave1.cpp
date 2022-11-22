/**********************************************************************************
// WaveM (Código Fonte)
//
// Criação:     06 Ago 2019
// Atualização: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Cria uma onda de inimigos Magenta
//
**********************************************************************************/

#include "Wave1.h"
#include "SpaceBattle.h"
#include "Enemy2.h"
#include "Hud.h"

// ------------------------------------------------------------------------------

Wave1::Wave1() : posX(50, window->Width() - 50), posY(50, game->Height() - 50), secs(2.0f, 4.0f)
{
    // posição dos inimigos
    pX = posX.Rand();
    pY = posY.Rand();

    // atraso para a próxima onda 
    delay = secs.Rand();
}

// ------------------------------------------------------------------------------

Wave1::~Wave1()
{

}

// -------------------------------------------------------------------------------

void Wave1::Update()
{
    // se passou o tempo de atraso
    if (timer.Elapsed(delay) && Hud::enemy2 < 5)
    {
        
        // adiciona novo inimigo
        SpaceBattle::scene->Add(new Enemy2(pX, pY, SpaceBattle::player), MOVING);

        // nova posição do inimigo
        pX = posX.Rand();
        pY = posY.Rand();

        // reinicia o timer
        timer.Start();
    }
}

// -------------------------------------------------------------------------------

void Wave1::Draw()
{

}

// -------------------------------------------------------------------------------
