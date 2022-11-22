/**********************************************************************************
// Orange (C�digo Fonte)
// 
// Cria��o:     05 Ago 2019
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Objeto faz movimento retil�neo
//
**********************************************************************************/

#include "SpaceBattle.h"
#include "Hud.h"
#include "Enemy1.h"
#include "Explosion.h"
#include "Random.h" 

// ---------------------------------------------------------------------------------

Enemy1::Enemy1(float pX, float pY, float ang)
{
    sprite = new Sprite(SpaceBattle::enemy1);

    // ajusta o vetor velocidade
    speed.RotateTo(ang);
    speed.ScaleTo(400);
    RotateTo(-speed.Angle() + 90);
    BBox(new Circle(20.0f));
    MoveTo(pX, pY);
    type = ENEMY1;

    // configura��o do emissor de part�culas
    Generator emitter;
    emitter.imgFile      = "Resources/Player/particle_fire2.png";    // arquivo de imagem
    emitter.angle        = speed.Angle() + 180;                     // �ngulo base do emissor
    emitter.spread       = 0;                                       // espalhamento em graus
    emitter.lifetime     = 0.1f;                                    // tempo de vida em segundos
    emitter.frequency    = 0.010f;                                  // tempo entre gera��o de novas part�culas
    emitter.percentToDim = 0.8f;                                    // desaparece ap�s 60% da vida
    emitter.minSpeed     = 100.0f;                                  // velocidade m�nima das part�culas
    emitter.maxSpeed     = 200.0f;                                  // velocidade m�xima das part�culas
    emitter.color.r      = 1.0f;                                    // componente Red da part�cula 
    emitter.color.g      = 1.0;                                     // componente Green da part�cula 
    emitter.color.b      = 1.0f;                                    // componente Blue da part�cula 
    emitter.color.a      = 1.0f;                                    // transpar�ncia da part�cula

    // cria sistema de part�culas
    tail = new Particles(emitter);
    tailCount = 0;

    // incrementa contagem
    ++Hud::enemy1;
}

// ---------------------------------------------------------------------------------

Enemy1::~Enemy1()
{
    delete sprite;
    delete tail;

    // decrementa contagem
    //Hud::particles -= tailCount;
    --Hud::enemy1;
}

// -------------------------------------------------------------------------------

void Enemy1::OnCollision(Object * obj)
{
    if (obj->Type() == MISSILE)
    {
        SpaceBattle::scene->Delete(obj, STATIC);
        SpaceBattle::scene->Delete(this, MOVING);
        SpaceBattle::scene->Add(new Explosion(x, y), STATIC);
        //SpaceBattle::audio->Play(EXPLODE);
    }
}

// -------------------------------------------------------------------------------

void Enemy1::Update()
{
    // movimenta objeto pelo seu vetor velocidade
    Translate(speed.XComponent() * gameTime, -speed.YComponent() * gameTime);

    // ajusta �ngulo do vetor na dire��o oposta
    if (x < 50 || y < 50 || x > game->Width() - 50 || y > game->Height() - 50)
    {
        Rotate(180);
        speed.Rotate(180);        
        Translate(speed.XComponent() * gameTime, -speed.YComponent() * gameTime);
    }

    // atualiza calda da nave
    tail->Config().angle = speed.Angle();
    tail->Generate(x - 10 * cos(speed.Radians()), y + 10 * sin(speed.Radians()));
    tail->Update(gameTime);

    //Hud::particles -= tailCount;
    tailCount = tail->Size();
    //Hud::particles += tailCount;
}

// ---------------------------------------------------------------------------------

void Enemy1::Draw()
{
    sprite->Draw(x, y, Layer::LOWER, scale, rotation);
    tail->Draw(Layer::LOWER, 1.0f);
}

// -------------------------------------------------------------------------------