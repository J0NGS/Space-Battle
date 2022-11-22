/**********************************************************************************
// WaveO (C�digo Fonte)
//
// Cria��o:     06 Ago 2019
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Cria uma onda de inimigos Orange
//
**********************************************************************************/

#include "Wave0.h"
#include "SpaceBattle.h"
#include "Enemy1.h"
#include "Hud.h"

// ------------------------------------------------------------------------------

Wave0::Wave0() : position(0,3), delay (1.0f, 5.0f)
{
    // n�mero de inimigos na horizontal (X) e na vertical (Y)
    numX = 8;
    numY = 8;
    
    // posi��o dos inimigos
    posX = 0;
    posY = 0;

    // n�o enviar nova onda agora
    newWave = false;
    waveDelay = delay.Rand();
}

// ------------------------------------------------------------------------------

Wave0::~Wave0()
{

}

// -------------------------------------------------------------------------------

void Wave0::Update()
{
    // nova onda foi solicitada
    if (newWave)
    {
        // se passou o tempo de atraso da solicita��o
        if (timer.Elapsed(waveDelay))
        {
            // toca som de nova onda
            //SpaceBattle::audio->Play(ORANGE);

            // origem da onda � aleat�ria
            switch (position.Rand())
            {
            case 0:
                // lado esquerdo da tela
                posY = 100;
                for (int i = 0; i < numY; ++i)
                {
                    SpaceBattle::scene->Add(new Enemy1(50, posY, 0), MOVING);
                    posY += 50;
                }
                break;
            case 1:
                // lado superior da tela
                posX = 100;
                for (int i = 0; i < numX; ++i)
                {
                    SpaceBattle::scene->Add(new Enemy1(posX, 50, 270), MOVING);
                    posX += 50;
                }
                break;
            case 2:
                // lado direito da tela
                posY = game->Height() - 100;
                for (int i = 0; i < numY; ++i)
                {
                    SpaceBattle::scene->Add(new Enemy1(game->Width() - 50, posY, 180), MOVING);
                    posY -= 50;
                }
                break;
            case 3:
                // lado inferior da tela
                posX = game->Width() - 100;
                for (int i = 0; i < numX; ++i)
                {
                    SpaceBattle::scene->Add(new Enemy1(posX, game->Height() - 50, 90), MOVING);
                    posX -= 50;
                }
                break;
            }

            // onda enviada
            newWave = false;
        }
    }
    else
    {
        // solicita nova onda se existirem poucos inimigos
        if (Hud::enemy1 < 10)
        {
            waveDelay = delay.Rand();
            timer.Start();
            newWave = true;
        }
    }
}

// -------------------------------------------------------------------------------

void Wave0::Draw()
{
    
}

// -------------------------------------------------------------------------------
