/**********************************************************************************
// Hud (Código Fonte)
//
// Criação:     02 Ago 2019
// Atualização: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Heads Up Display
//
**********************************************************************************/

#include "Hud.h"
#include "SpaceBattle.h"
//#include "BasicAI.h"

// ------------------------------------------------------------------------------

// inicializa contadores
 int Hud::life      = 100;                              // vida na tela
uint Hud::score     = 0;                                // score na tela
uint Hud::time      = 0;                                // tempo na tela
uint Hud::particles = 0;                                // particulas na tela
uint Hud::enemy1    = 0;                                // número de inimigos 1
uint Hud::enemy2    = 0;                                // número de inimigos 2
uint Hud::enemy3    = 0;                                // número de inimigos 3

// ------------------------------------------------------------------------------

Hud::Hud()
{

    // cria fonte para exibição de texto
    font = new Font("Resources/font.bmp");
    font->Spacing("Resources/font.dat");
       
    // inicializa contador de frames e tempo transcorrido
    frameCount = 0;
    totalTime = 0.0f;
    fps = 0;
}

// ------------------------------------------------------------------------------

Hud::~Hud()
{
    delete font;
    delete bold;
    delete infoBox;
}

// -------------------------------------------------------------------------------

void Hud::Update()
{

    // tempo acumulado dos frames
    totalTime += gameTime;

    // incrementa contador de frames
    frameCount++;

    // a cada 1000ms (1 segundo) atualiza indicador de FPS
    if (totalTime >= 1.0f)
    {
        fps = frameCount;
        frameCount = 0;
        totalTime -= 1.0f;
    }

}

// -------------------------------------------------------------------------------

void Hud::Draw()
{
    // desenha elementos da interface
    //infoBox->Draw(game->viewport.left + 140, game->viewport.top + 100, Layer::FRONT);

    // define cor do texto
    Color textColor{ 1.0f, 1.0f, 1.0f, 1.0f };

    // desenha texto
    text.str("");
    text << "Time - " << time ;
    font->Draw(40, 50, text.str(), textColor);

    text.str("");
    text << "Life - " << life << " %";
    font->Draw(945, 50, text.str(), textColor);

    text.str("");
    text << "Score - " << score;
    font->Draw(window->CenterX() - 70, window->CenterY() + window->CenterY() - 40, text.str(), textColor);
    
    if (SpaceBattle::player->Life() != life) {
        life = SpaceBattle::player->Life();
        text.str("");
        text << "Life - " << life << " %";
        font->Draw(window->CenterX() - 70, window->CenterY() - 200, text.str(), textColor);
    }



}

// -------------------------------------------------------------------------------
