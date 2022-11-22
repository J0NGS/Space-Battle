/**********************************************************************************
// Explosion (C�digo Fonte)
// 
// Cria��o:     17 Mar 2013
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Efeito de explos�o usando sistema de part�culas
//
**********************************************************************************/

#include "SpaceBattle.h"
#include "Explosion.h"
#include "Random.h"
#include "Hud.h"

// ---------------------------------------------------------------------------------

Explosion::Explosion(float pX, float pY)
{
    // n�mero aleat�rio entre 0 e 1
    RandF color{ 0, 1 };

    // configura emissor de part�culas
    Generator explosion;
    explosion.imgFile       = "Resources/Player/particle_fire.png";    // arquivo de imagem
    explosion.angle         = 0.0f;                     // dire��o da explos�o
    explosion.spread        = 360.0;                   // espalhamento em graus
    explosion.lifetime      = 0.50f;                    // tempo de vida em segundos
    explosion.frequency     = 0.000f;                   // tempo entre gera��o de novas part�culas
    explosion.percentToDim  = 0.5f;                     // desaparece ap�s 60% da vida
    explosion.minSpeed      = 25.0f;                    // velocidade m�nima das part�culas
    explosion.maxSpeed      = 250.0f;                   // velocidade m�xima das part�culas
    explosion.color.r       = 1.0f;                     // cor da part�cula entre 0 e 1
    explosion.color.g       = 1.0f;                     // cor da part�cula entre 0 e 1
    explosion.color.b       = 1.0f;                     // cor da part�cula entre 0 e 1
    explosion.color.a       = 1.0f;                     // transpar�ncia da part�cula

    // configura emissor de part�culas
    Generator explosion2;
    explosion.imgFile       = "Resources/Player/particle_fire2.png";    // arquivo de imagem
    explosion.angle         = 0.0f;                     // dire��o da explos�o
    explosion.spread        = 360.0;                    // espalhamento em graus
    explosion.lifetime      = 0.50f;                    // tempo de vida em segundos
    explosion.frequency     = 0.000f;                   // tempo entre gera��o de novas part�culas
    explosion.percentToDim  = 0.5f;                     // desaparece ap�s 60% da vida
    explosion.minSpeed      = 25.0f;                    // velocidade m�nima das part�culas
    explosion.maxSpeed      = 250.0f;                   // velocidade m�xima das part�culas
    explosion.color.r       = 1.0f;                     // cor da part�cula entre 0 e 1
    explosion.color.g       = 1.0f;                     // cor da part�cula entre 0 e 1
    explosion.color.b       = 1.0f;                     // cor da part�cula entre 0 e 1
    explosion.color.a       = 1.0f;                     // transpar�ncia da part�cula

    // cria sistema de part�culas
    sparks1 = new Particles(explosion);
    
    // gera 50 part�culas na posi��o indicada
    sparks1->Generate(pX, pY, 100);
    type = EXPLOSION;
    
    // ---------------------------------------------------

    // cria sistema de part�culas
    sparks2 = new Particles(explosion);
    // gera 50 part�culas na posi��o indicada
    sparks2->Generate(pX, pY, 100);
    type = EXPLOSION;


    // incrementa contagem de part�culas
    Hud::particles += 50;
}

// ---------------------------------------------------------------------------------

Explosion::~Explosion()
{
    delete sparks1;
    delete sparks2;
    // decrementa contagem de part�culas
    Hud::particles -= 50;
}

// -------------------------------------------------------------------------------

void Explosion::Update()
{
    // atualiza posi��o de cada part�cula
    sparks1->Update(gameTime);
    sparks2->Update(gameTime);

    // remove da cena quando todas as part�culas est�o inativas
    if (sparks1->Inactive())
        SpaceBattle::scene->Delete();
    if (sparks2->Inactive())
        SpaceBattle::scene->Delete();
}

// -------------------------------------------------------------------------------