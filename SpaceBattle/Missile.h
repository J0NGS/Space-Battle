/**********************************************************************************
// Missile (Arquivo de Cabe�alho)
//
// Cria��o:     19 Nov 2022
// Atualiza��o: 19 Nov 2022
// Compilador:  Visual C++ 2022
//
// Descri��o:   Define uma classe para um m�ssil
//
**********************************************************************************/

#ifndef _SPACEBATTLE_MISSILE_H_
#define _SPACEBATTLE_MISSILE_H_

// --------------------------------------------------------------------------------

#include "Vector.h"
#include "Object.h"
#include "Sprite.h"
#include "Player.h" 

// --------------------------------------------------------------------------------

class Missile : public Object
{
private:
    static Player*& player;            // refer�ncia para o player
    Sprite* sprite;                    // sprite do m�ssil
    Vector speed;                      // velocidade do m�ssil    

public:
    Missile(float angle);               // construtor
    ~Missile();                         // destrutor

    Vector& Speed();                    // retona vetor velocidade
    void Update();                      // atualiza��o
    void Draw();                        // desenho
};

// ------------------------------------------------------------------------------

inline Vector& Missile::Speed()
{
    return speed;
}

inline void Missile::Draw()
{
    sprite->Draw(x, y, Layer::UPPER, scale, rotation);
}

// ------------------------------------------------------------------------------

#endif