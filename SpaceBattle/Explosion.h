/**********************************************************************************
// Explosion (Arquivo de Cabeçalho)
// 
// Criação:     21 Nov 2022
// Atualização: 21 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Efeito de explosão usando sistema de partículas
//
**********************************************************************************/

#ifndef _SPACEBATTLE_EXPLOSION_H_
#define _SPACEBATTLE_EXPLOSION_H_

// ---------------------------------------------------------------------------------

#include "Object.h"    
#include "Types.h"
#include "Particles.h"

// ---------------------------------------------------------------------------------

class Explosion : public Object
{
private:
    Particles * sparks1;                 // sistema de partículas
public:
    Explosion(float pX, float pY);      // construtor
    ~Explosion();                       // destrutor

    int Size();                         // quantidade de partículas
    void Update();                      // atualização
    void Draw();                        // desenho
}; 

// ---------------------------------------------------------------------------------

inline int Explosion::Size()
{ return sparks1->Size(); }

inline void Explosion::Draw()
{
    sparks1->Draw(Layer::LOWER, 1.0f);
}
// ---------------------------------------------------------------------------------


#endif