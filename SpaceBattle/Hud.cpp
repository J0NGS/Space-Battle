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
//#include "BasicAI.h"

// ------------------------------------------------------------------------------

// inicializa contadores
uint Hud::life  = 100;
uint Hud::score = 0;
uint Hud::time  = 0;

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
    Color textColor{ 0.7f, 0.7f, 0.7f, 1.0f };

    // desenha texto
    text.str("");
    text << "Time - " << time ;
    font->Draw(40, 50, text.str(), textColor);

    text.str("");
    text << "Life - " << life << " %";
    font->Draw(945, 50, text.str(), textColor);

    text.str("");
    text << "Score - " << score;
    font->Draw(window->CenterX() - 70, 610, text.str(), textColor);


}

// -------------------------------------------------------------------------------
