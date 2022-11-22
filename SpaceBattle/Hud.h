/**********************************************************************************
// Hud (Arquivo de Cabeçalho)
//
// Criação:     02 Ago 2019
// Atualização: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Heads Up Display
//
**********************************************************************************/

#ifndef _BASICAI_HUD_H_
#define _BASICAI_HUD_H_

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
    Font* font = nullptr;              // fonte para exibição normal
    Font* bold = nullptr;              // fonte para exibição negrito
    Sprite* infoBox = nullptr;         // área de informações do jogo

    stringstream text;                  // texto temporário
    uint frameCount;                    // contador de quadros por segundo
    float totalTime;                    // tempo total transcorrido 
    uint fps;                           // valor para exibição do fps

public:
    static uint life;                 // número de mísseis na tela
    static uint score;                // número de inimigos laranja
    static uint time;                 // número de inimigos rosa
    static uint particles;            // número de particulas
    static uint enemy1;               // número de inimigos rosa
    static uint enemy2;               // número de inimigos rosa
    static uint enemy3;               // número de inimigos rosa
    
    Hud();                              // construtor
    ~Hud();                             // destrutor

    void Update();                      // atualização
    void Draw();                        // desenho
};

// ------------------------------------------------------------------------------

#endif

