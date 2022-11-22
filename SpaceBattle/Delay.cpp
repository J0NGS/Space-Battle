/**********************************************************************************
// Delay (C�digo Fonte)
//
// Cria��o:     19 nOV 2022
// Atualiza��o: 19 nOV 2022
// Compilador:  Visual C++ 2022
//
// Descri��o:   Sincroniza uma a��o
//
**********************************************************************************/

#include "Delay.h"
#include "SpaceBattle.h"
#include "Wave0.h"
#include "Wave1.h"
//#include "WaveB.h"
//#include "WaveG.h"
//#include "Hud.h"

// ------------------------------------------------------------------------------

Delay::Delay()
{
    logo = new Sprite("Resources/Logo.png");
    gameover = new Sprite("Resources/Gameover.png");
    tile = new TileSet("Resources/player/PlayerExplosion.png", 256, 256, 11, 11);
    anim = new Animation(tile, 0.120f, false);
    timer.Start();

    notPlayed = true;
    fase1 = false;
    fase2 = false;
    fase3 = false;
    fase4 = false;
    end   = false;
}

// ------------------------------------------------------------------------------

Delay::~Delay()
{
    delete logo;
    delete tile;
    delete anim;
    delete gameover;
}

// -------------------------------------------------------------------------------

void Delay::Update()
{
    Hud::time = timer.Elapsed();

    if (notPlayed && timer.Elapsed(2.0f))
    {
        // toca �udio de introdu��o
        notPlayed = false;
    }

    if (!fase1 && timer.Elapsed(6.0f))
    {
        // para de tocar a m�sica de inicio
        SpaceBattle::audio->Stop(START);
        
        // toca m�sica do jogo
        
        SpaceBattle::audio->Play(THEME, true);
        SpaceBattle::scene->Add(new Wave0(), STATIC);
        SpaceBattle::viewHUD = true;
        fase1 = true;
    }

    if (!fase2 && timer.Elapsed(8.0f))
    {
        SpaceBattle::scene->Add(new Wave1(), STATIC);
        fase2 = true;
    }
    
    //if (!fase3 && timer.Elapsed(10.0f))
    //{
    //    BasicAI::scene->Add(new WaveB(), STATIC);
    //    fase3 = true;
    //}
    //
    //if (!fase4 && timer.Elapsed(15.0f))
    //{
    //    BasicAI::scene->Add(new WaveG(), STATIC);
    //    BasicAI::scene->Delete();
    //    fase4 = true;
    //}

    if (SpaceBattle::player->Life() <= 0) {
        SpaceBattle::scene->Remove(SpaceBattle::player, MOVING);
        anim->NextFrame();
        end = true;
        fase1 = true;
    }

    


}

// -------------------------------------------------------------------------------

void Delay::Draw()
{
    if (!fase1)
        logo->Draw(game->viewport.left + window->CenterX(), game->viewport.top + window->CenterY() - 150, Layer::FRONT);
    
    if (end == true){
        gameover->Draw(game->viewport.left + window->CenterX(), game->viewport.top + window->CenterY() - 150, Layer::FRONT);
        SpaceBattle::audio->Stop(START);
        SpaceBattle::audio->Stop(THEME);
    }
}

// -------------------------------------------------------------------------------
