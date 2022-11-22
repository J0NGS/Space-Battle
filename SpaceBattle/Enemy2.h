/**********************************************************************************
// Magenta (Arquivo de Cabe�alho)
//
// Cria��o:     21 Nov 2022
// Atualiza��o: 21 Nov 2022
// Compilador:  Visual C++ 2022
//
// Descri��o:   inimigo com i.a. de persegui��o direta
//
**********************************************************************************/

#ifndef _SPACEBATTLE_ENEMY2_H_
#define _SPACEBATTLE_ENEMY2_H_

// ---------------------------------------------------------------------------------

#include "Object.h"    
#include "Types.h"
#include "Sprite.h"
#include "Vector.h"
#include "Player.h"

// ---------------------------------------------------------------------------------

class Enemy2 : public Object
{
private:
    Sprite* sprite;                            // sprite do objeto
    Player* player;                            // ponteiro para jogador
    Vector speed;                               // velocidade e dire��o
    Point vertex[4] =                   // pontos para criar poligano bbox 
    {
        //inicializa��o dos pontos da bbox    
           Point(-22, -40),
           Point(22, -40),
           Point(22,  40),
           Point(-22,  40)
    };
public:
    Enemy2(float pX, float pY, Player* p);    // construtor
    ~Enemy2();                                 // destrutor

    void OnCollision(Object* obj);             // resolu��o da colis�o
    void Update();                              // atualiza��o
    void Draw();                                // desenho
};

// ---------------------------------------------------------------------------------

inline void Enemy2::Draw()
{
    sprite->Draw(x, y, Layer::LOWER, scale, rotation);
}

// ---------------------------------------------------------------------------------


#endif