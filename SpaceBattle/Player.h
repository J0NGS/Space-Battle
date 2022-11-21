/**********************************************************************************
// Player (Arquivo de Cabeçalho)
//
// Criação:     18 Nov 202
// Atualização: 18 Nov 2022
// Compilador:  Visual C++ 2022
//
// Descrição:   Define a classe jogador
//
**********************************************************************************/

#ifndef _SPACEBATTLE_PLAYER_H_
#define _SPACEBATTLE_PLAYER_H_

// ---------------------------------------------------------------------------------

#include "Object.h"                     // objetos do jogo
#include "Sprite.h"                     // desenho de sprites
#include "Vector.h"                     // representação de vetores
#include "Particles.h"                  // sistema de partículas
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
    //inicialização dos pontos da bbox    
       Point(-38, -60),
       Point(38, -60),
       Point(38,  60),
       Point(-38,  60)                  
    };                       
    
    Controller* gamepad;                // leitura do controle
    bool gamepadOn;                     // controle está ligado

    Timer timer;                        // controla tempo dos disparos
    llong start;                        // marcação de início do disparo
    bool axisCtrl;                      // habilita leitura de disparos
    bool keysCtrl;                      // habilita disparos pelas setas
    bool keysPressed;                   // qualquer seta pressionada
    float firingAngle;                  // direção dos disparos

public:
   
    static Image* missile;              // imagem do míssil
    Vector speed;                       // velocidade e direção de movimento

    Player();                           // construtor
    ~Player();                          // destrutor

    bool AxisTimed(int axisX, int axisY, float time);
    bool KeysTimed(bool pressed, float time);

    void Move(Vector&& v);              // movimenta jogador
    void Update();                      // atualização
    void Draw();                        // desenho
};

// ---------------------------------------------------------------------------------
#endif