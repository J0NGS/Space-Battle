/**********************************************************************************
// GeoWars (Arquivo de Cabeçalho)
//
// Criação:     15/11/2022
// Atualização: 15/11/2022
// Compilador:  Visual C++ 2022
//
// Descrição:   Arquivo de cabeçalho do jogo space battle
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

// ------------------------------------------------------------------------------

enum EnemysIds {ENEMY1, ENEMY2, ENEMY3};

// ------------------------------------------------------------------------------

enum ObjectIds { PLAYER, MISSILE };

// ------------------------------------------------------------------------------

enum SoundIds {THEME, START, FIRE, EXPLOSION };

// ------------------------------------------------------------------------------

class SpaceBattle : public Game
{
private:
    Background* bg = nullptr;       // plano de fundo
    bool viewBBox  = false;         // visualização das bbox
    Hud * hud      = nullptr;       // Hud
public:
   
    static Player * player;  
    static Audio  * audio;          // sistema de audio do jogo
    static Scene  * scene;          // gerenciador de cena do jogo
    
    static Image * enemy1;
    static Image * enemy2;
    static Image * enemy3;

    static bool viewHUD;            // visualização do HUD

    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização
};

// ---------------------------------------------------------------------------------

#endif