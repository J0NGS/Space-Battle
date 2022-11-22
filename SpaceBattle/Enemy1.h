/**********************************************************************************
// Orange (Arquivo de Cabeçalho)
// 
// Criação:     05 Ago 2019
// Atualização: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Objeto faz movimento retilíneo
//
**********************************************************************************/

#ifndef _BASICAI_ORANGE_H_
#define _BASICAI_ORANGE_H_

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