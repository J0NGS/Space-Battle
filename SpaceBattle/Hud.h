/**********************************************************************************
// Hud (Arquivo de Cabe�alho)
//
// Cria��o:     19 Nov 2022
// Atualiza��o: 19 Nov 2022
// Compilador:  Visual C++ 2022
//
// Descri��o:   Display do jogador
//
**********************************************************************************/

#ifndef _SPACEBATTLE_HUD_H_
#define _SPACEBATTLE_HUD_H_

// --------------------------------------------------------------------------------

#include "Object.h"
#include "Sprite.h"
#include "Font.h"
#include <sstream>
using std::stringstream;

// --------------------------------------------------------------------------------

class Hud : public Object
{
private:
    Font* font = nullptr;              // fonte para exibi��o normal
    Font* bold = nullptr;              // fonte para exibi��o negrito
    Sprite* infoBox = nullptr;         // �rea de informa��es do jogo

    stringstream text;              // texto tempor�rio vida
    uint frameCount;                    // contador de quadros por segundo
    float totalTime;                    // tempo total transcorrido 
    uint fps;                           // valor para exibi��o do fps


public:
    static int   life;                // vida na hud
    static uint score;                // n�mero de inimigos laranja
    static uint time;                 // n�mero de inimigos rosa
    static uint particles;            // n�mero de particulas
    static uint enemy1;               // n�mero de inimigos rosa
    static uint enemy2;               // n�mero de inimigos rosa
    static uint enemy3;               // n�mero de inimigos rosa
    
    Hud();                              // construtor
    ~Hud();                             // destrutor

    void Update();                      // atualiza��o
    void Draw();                        // desenho
};

// ------------------------------------------------------------------------------

#endif

