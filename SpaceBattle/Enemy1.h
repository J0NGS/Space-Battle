/**********************************************************************************
// Enemy1 (Arquivo de Cabeçalho)
// 
// Criação:     21 Nov 2022
// Atualização: 21 Nov 2022
// Compilador:  Visual C++ 2022
//
// Descrição:   Inimigo 1 que usa a i.a. de movimento retilineo
//
**********************************************************************************/

#ifndef _SPACEBATTLE_ORANGE_H_
#define _SPACEBATTLE_ORANGE_H_

// ---------------------------------------------------------------------------------

#include "Object.h"    
#include "Types.h"
#include "Sprite.h"
#include "Vector.h"
#include "Player.h"

// ---------------------------------------------------------------------------------

class Enemy1 : public Object
{
private:
    Sprite * sprite;                        // sprite da nave
    Particles * tail;                       // calda da nave
    uint tailCount;                         // quantidade de partículas da calda
    Vector speed;                           // velocidade e direção    
    
public:
    Enemy1(float pX, float pY, float ang);  // construtor
    ~Enemy1();                              // destrutor
    
    void OnCollision(Object* obj);          // resolução da colisão
    void Update();                          // atualização
    void Draw();                            // desenho
}; 

// ---------------------------------------------------------------------------------


#endif