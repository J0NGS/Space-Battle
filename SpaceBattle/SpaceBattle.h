/**********************************************************************************
// GeoWars (Arquivo de Cabe�alho)
//
// Cria��o:     15/11/2022
// Atualiza��o: 15/11/2022
// Compilador:  Visual C++ 2022
//
// Descri��o:   Arquivo de cabe�alho do jogo space battle
//
**********************************************************************************/

#ifndef _SPACEBATTLE_H_
#define _SPACEBATTLE_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Audio.h"
#include "Scene.h"
#include "Background.h"
#include "Player.h"


// ------------------------------------------------------------------------------

enum ObjectIds { PLAYER, MISSILE };

// ------------------------------------------------------------------------------

enum SoundIds {THEME, START, FIRE, EXPLOSION };

// ------------------------------------------------------------------------------

class SpaceBattle : public Game
{
private:
    Background* bg = nullptr;       // plano de fundo
    //Hud * hud = nullptr
    bool viewBBox = false;          // visualiza��o das bbox
    
public:
   
    static Player * player;  
    
    static Audio* audio;            // sistema de audio do jogo
    static Scene* scene;            // gerenciador de cena do jogo
    static bool viewHUD;            // visualiza��o do HUD

    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};

// ---------------------------------------------------------------------------------

#endif