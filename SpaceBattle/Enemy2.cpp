/**********************************************************************************
// Enemy2 (Código Fonte)
//
// Criação:     21 Nov 2022
// Atualização: 21 Nov 2022
// Compilador:  Visual C++ 2019
//
// Descrição:   inimigo com i.a. de perseguição direta
//
**********************************************************************************/

#include "SpaceBattle.h"
#include "Enemy2.h"
#include "Random.h" 
#include "Hud.h"
#include "Explosion.h"

// ---------------------------------------------------------------------------------

Enemy2::Enemy2(float pX, float pY, Player* p)
{
    player = p;
    sprite = new Sprite(SpaceBattle::enemy2);
    BBox(new Poly(vertex, 4));

    speed.RotateTo(0);
    speed.ScaleTo(2.0f);

    MoveTo(pX, pY);
    type = ENEMY2;
}

// ---------------------------------------------------------------------------------

Enemy2::~Enemy2()
{
    delete sprite;
}

// -------------------------------------------------------------------------------

void Enemy2::OnCollision(Object* obj)
{
    if (obj->Type() == MISSILE)
    {
        SpaceBattle::scene->Delete(obj, STATIC);
        SpaceBattle::scene->Delete(this, MOVING);
        SpaceBattle::scene->Add(new Explosion(x, y), STATIC);
        SpaceBattle::audio->Play(EXPLOSION);
    }
    
    if (obj->Type() == PLAYER)
    {
        SpaceBattle::player->Damage(15);
        SpaceBattle::scene->Delete(this, MOVING);
        SpaceBattle::scene->Add(new Explosion(x, y), STATIC);
        SpaceBattle::audio->Play(EXPLOSION);
        Hud::score += 5;
    }
}

// -------------------------------------------------------------------------------

void Enemy2::Update()
{
    // ajusta ângulo do vetor 
    speed.RotateTo(Line::Angle(Point(x, y), Point(player->X(), player->Y())));
    RotateTo(-speed.Angle() + 90);

    // movimenta objeto pelo seu vetor velocidade
    Translate(speed.XComponent() * 60.0f * gameTime, -speed.YComponent() * 60.0f * gameTime);
}

// -------------------------------------------------------------------------------