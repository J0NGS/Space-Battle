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
    bool viewBBox = false;          // visualização das bbox
    
public:
   
    static Player * player;  
    
    static Audio* audio;            // sistema de audio do jogo
    static Scene* scene;            // gerenciador de cena do jogo
    static bool viewHUD;            // visualização do HUD

    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização
};

// ---------------------------------------------------------------------------------

#endif