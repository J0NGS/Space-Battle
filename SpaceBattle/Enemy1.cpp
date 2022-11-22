/**********************************************************************************
// Orange (Código Fonte)
// 
// Criação:     05 Ago 2019
// Atualização: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Objeto faz movimento retilíneo
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

    // configuração do emissor de partículas
    Generator emitter;
    emitter.imgFile      = "Resources/Player/particle_fire2.png";    // arquivo de imagem
    emitter.angle        = speed.Angle() + 180;                     // ângulo base do emissor
    emitter.spread       = 0;                                       // espalhamento em graus
    emitter.lifetime     = 0.1f;                                    // tempo de vida em segundos
    emitter.frequency    = 0.010f;                                  // tempo entre geração de novas partículas
    emitter.percentToDim = 0.8f;                                    // desaparece após 60% da vida
    emitter.minSpeed     = 100.0f;                                  // velocidade mínima das partículas
    emitter.maxSpeed     = 200.0f;                                  // velocidade máxima das partículas
    emitter.color.r      = 1.0f;                                    // componente Red da partícula 
    emitter.color.g      = 1.0;                                     // componente Green da partícula 
    emitter.color.b      = 1.0f;                                    // componente Blue da partícula 
    emitter.color.a      = 1.0f;                                    // transparência da partícula

    // cria sistema de partículas
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

    // ajusta ângulo do vetor na direção oposta
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