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
#include "Hud.h"
#include "Scene.h"
#include "Background.h"
#include "Player.h"

enum ObjectIds { PLAYER, MISSILE, ENEMY1, ENEMY2, ENEMY3};

// ------------------------------------------------------------------------------

enum SoundIds {THEME, START, FIRE, EXPLOSION, TAIL, GAMEOVER };

// ------------------------------------------------------------------------------

class SpaceBattle : public Game
{
private:
    Background* bg = nullptr;       // plano de fundo
    bool viewBBox  = false;         // visualiza��o das bbox
    Hud * hud      = nullptr;       // Hud
public:
   
    static Player * player;  
    static Audio  * audio;          // sistema de audio do jogo
    static Scene  * scene;          // gerenciador de cena do jogo
    
    static Image * enemy1;
    static Image * enemy2;
    static Image * enemy3;

    static bool viewHUD;            // visualiza��o do HUD

    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};

// ---------------------------------------------------------------------------------

#endif