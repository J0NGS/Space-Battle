/**********************************************************************************
// Player (Arquivo de Cabe�alho)
//
// Cria��o:     18 Nov 202
// Atualiza��o: 18 Nov 2022
// Compilador:  Visual C++ 2022
//
// Descri��o:   Define a classe jogador
//
**********************************************************************************/

#ifndef _SPACEBATTLE_PLAYER_H_
#define _SPACEBATTLE_PLAYER_H_

// ---------------------------------------------------------------------------------

#include "Object.h"                     // objetos do jogo
#include "Sprite.h"                     // desenho de sprites
#include "Vector.h"                     // representa��o de vetores
#include "Particles.h"                  // sistema de part�culas
#include "Controller.h"                 // entrada pelo controle
#include "Timer.h"                      // controle do tempo

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    Sprite* sprite;                     // sprite do objeto
    Particles* tail;                    // calda da turbina 
    Particles* tail2;                   // calda da turbina 
    Point vertex[4] =                   // pontos para criar poligano bbox 
    {                                         
    //inicializa��o dos pontos da bbox    
       Point(-38, -60),
       Point(38, -60),
       Point(38,  60),
       Point(-38,  60)                  
    };                       
    
    Controller* gamepad;                // leitura do controle
    bool gamepadOn;                     // controle est� ligado



    Timer timer;                        // controla tempo dos disparos
    llong start;                        // marca��o de in�cio do disparo
    bool axisCtrl;                      // habilita leitura de disparos
    bool keysCtrl;                      // habilita disparos pelas setas
    bool keysPressed;                   // qualquer seta pressionada
    float firingAngle;                  // dire��o dos disparos
    int life;                           // vida do jogador

public:
   
    static Image* missile;              // imagem do m�ssil
    Vector speed;                       // velocidade e dire��o de movimento

    Player();                           // construtor
    ~Player();                          // destrutor

    bool AxisTimed(int axisX, int axisY, float time);
    bool KeysTimed(bool pressed, float time);

    void Oncolission(Object* obj);      // tratamento de colis�o
    void Move(Vector&& v);              // movimenta jogador
    void Update();                      // atualiza��o
    void Draw();                        // desenho
    int  Life();                        // fun��o que retorna o valor da vida
    void  LifeReset();                        // fun��o que retorna o valor da vida
    void Damage(int dmg);               // fun��o para dar dano no player
};

inline int Player::Life() {
    return this->life;
}

inline void Player::LifeReset() {
    this->life = 100;
}
// ---------------------------------------------------------------------------------
#endif