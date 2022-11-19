/**********************************************************************************
// Missile (Arquivo de Cabeçalho)
//
// Criação:     19 Nov 2022
// Atualização: 19 Nov 2022
// Compilador:  Visual C++ 2022
//
// Descrição:   Define uma classe para um míssil
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
    static Player*& player;            // referência para o player
    Sprite* sprite;                    // sprite do míssil
    Vector speed;                      // velocidade do míssil    

public:
    Missile(float angle);               // construtor
    ~Missile();                         // destrutor

    Vector& Speed();                    // retona vetor velocidade
    void Update();                      // atualização
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