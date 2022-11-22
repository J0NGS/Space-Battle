/**********************************************************************************
// Explosion (Arquivo de Cabe�alho)
// 
// Cria��o:     21 Nov 2022
// Atualiza��o: 21 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Efeito de explos�o usando sistema de part�culas
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
    Particles * sparks1;                 // sistema de part�culas
public:
    Explosion(float pX, float pY);      // construtor
    ~Explosion();                       // destrutor

    int Size();                         // quantidade de part�culas
    void Update();                      // atualiza��o
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