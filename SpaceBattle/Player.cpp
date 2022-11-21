/**********************************************************************************
// Player (C�digo Fonte)
//
// Cria��o:     10 Out 2012
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define a classe jogador
//
**********************************************************************************/

#include "Player.h"
#include "Missile.h"
#include "SpaceBattle.h"
//#include "Hud.h"

Image* Player::missile = nullptr;

// -------------------------------------------------------------------------------

Player::Player()
{
    // inicializa controle
    gamepad   = new Controller();
    gamepadOn = gamepad->Initialize();

    // configura��o do objeto
    sprite  = new Sprite("Resources/ship.png");
    missile = new Image("Resources/Missile.png");
    speed.RotateTo(90.0f);
    speed.ScaleTo(0.0f);

    BBox(new Poly(vertex, 4));
    
    
    MoveTo(game->CenterX(), game->CenterY());
    type = PLAYER;
    // configura��o do emissor de part�culas
    Generator emitter;
    emitter.imgFile      = "Resources/particle_fire.png";    // arquivo de imagem
    emitter.angle        = 270.0f;                           // �ngulo base do emissor
    emitter.spread       = 45.0f;                            // espalhamento em graus
    emitter.lifetime     = 0.3f;                             // tempo de vida em segundos
    emitter.frequency    = 0.010f;                           // tempo entre gera��o de novas part�culas
    emitter.percentToDim = 0.6f;                             // desaparece ap�s 60% da vida
    emitter.minSpeed     = 50.0f;                            // velocidade m�nima das part�culas
    emitter.maxSpeed     = 100.0f;                           // velocidade m�xima das part�culas
    emitter.color.r      = 1.0f;                             // componente Red da part�cula 
    emitter.color.g      = 1.0f;                             // componente Green da part�cula 
    emitter.color.b      = 1.0f;                             // componente Blue da part�cula 
    emitter.color.a      = 1.0f;                             // transpar�ncia da part�cula

    // cria sistema de part�culas
    tail = new Particles(emitter);

    // diparo habilitado
    firingAngle = 0.0f;
    keysPressed = false;
    axisCtrl = true;
    keysCtrl = true;
    start = 0;
    timer.Start();
}

// -------------------------------------------------------------------------------

Player::~Player()
{
    delete sprite;
    delete missile;
    delete tail;
    delete gamepad;
}

// -------------------------------------------------------------------------------

bool Player::KeysTimed(bool pressed, float time)
{
    // se j� passou o tempo para o pr�ximo disparo
    if (keysCtrl)
    {
        // se h� qualquer seta pressionada
        if (pressed)
        {
            keysCtrl = false;
            start = timer.Stamp();
            return true;
        }
    }
    // sen�o aguarda o momento certo
    else if (timer.Elapsed(start, time))
    {
        keysCtrl = true;
    }

    // teclas n�o pressionadas ou tempo n�o atingido
    return false;
}

// -------------------------------------------------------------------------------

bool Player::AxisTimed(int axisX, int axisY, float time)
{
    // se j� passou o tempo para o pr�ximo disparo
    if (axisCtrl)
    {
        // a magnitude � a dist�ncia do eixo para o seu centro
        float magnitude = Point::Distance(Point(0, 0), Point(float(gamepad->Axis(axisX)), float(gamepad->Axis(axisY))));

        // se h� qualquer movimento no eixo
        if (magnitude > 0)
        {
            axisCtrl = false;
            start = timer.Stamp();
            return true;
        }
    }
    // sen�o aguarda o momento certo para testar
    else if (timer.Elapsed(start, time))
    {
        axisCtrl = true;
    }

    // eixo n�o acionado ou tempo n�o atingido
    return false;
}

// -------------------------------------------------------------------------------

void Player::Move(Vector&& v)
{
    // soma vetor movimento (v) ao vetor velocidade
    speed.Add(v);
    
    // limita velocidade m�xima
    if (speed.Magnitude() > 10.0f)
        speed.ScaleTo(10.0f);
    
    //fun��o faz com que a BBOX rotacione junto com o objeto. a adi��o do 90.0f para poder mantela no sentido correto da nave, speed.angle est� negativo para inverter o sentido do giro, e poder ficar de acordo com a nave
    RotateTo(-speed.Angle() + 90); 
}

// -------------------------------------------------------------------------------

void Player::Update()
{
    // magnitude do vetor acelera��o
    float accel = 40.0f * gameTime;

    // -----------------
    // Controle
    // -----------------

    if (gamepadOn)
    {
        // atualiza estado das teclas e eixos do controle
        gamepad->UpdateState();

        // constr�i vetor com base na posi��o do anal�gico esquerdo
        float ang = Line::Angle(Point(0, 0), Point(gamepad->Axis(AxisX) / 25.0f, gamepad->Axis(AxisY) / 25.0f));
        float mag = Point::Distance(Point(0, 0), Point(gamepad->Axis(AxisX) / 25.0f, gamepad->Axis(AxisY) / 25.0f));

        // nenhuma dire��o selecionada
        if (mag == 0)
        {
            // se a velocidade estiver muita baixa
            if (speed.Magnitude() < 0.1)
            {
                // pare de se movimentar imediatamente
                speed.ScaleTo(0.0f);
            }
            else
            {
                // some um vetor no sentido contr�rio para frear
                Move(Vector(speed.Angle() + 180.0f, 5.0f * gameTime));
            }
        }
        else
        {
            // movimente-se para a nova dire��o
            Move(Vector(ang, mag * gameTime));
            //Rotate(ang);
        }

        // dispara m�ssil com o anal�gico direito
        if (AxisTimed(AxisRX, AxisRY, 0.150f))
        {
            float ang = Line::Angle(Point(0, 0), Point(float(gamepad->Axis(AxisRX)), float(gamepad->Axis(AxisRY))));
            //SpaceBattle::audio->Play(FIRE);
            SpaceBattle::scene->Add(new Missile(ang), STATIC);
        }
    }

    // -----------------
    // Teclado
    // -----------------

    else
    {
        // controla movimenta��o do jogador
        if (window->KeyDown('D') && window->KeyDown('W')) {
            Move(Vector(45.0f, accel));
            //Rotate(45.0f );
        }
        else if (window->KeyDown('A') && window->KeyDown('W')){
            Move(Vector(135.0f, accel));
            //Rotate(135.0f *2);
        }
        else if (window->KeyDown('A') && window->KeyDown('S')){
            Move(Vector(225.0f, accel));                      
            //Rotate(225.0f * 2);
        }
        else if (window->KeyDown('D') && window->KeyDown('S')){
            Move(Vector(315.0f, accel));
            //Rotate(315.0f * 2);

        }
        else if (window->KeyDown('D')){
            Move(Vector(0.0f, accel));
            //RotateTo(0.0f - 90);

        }
        else if (window->KeyDown('A')){
            Move(Vector(180.0f, accel));
            //RotateTo(180.0f - 90);

        }
        else if (window->KeyDown('W')){
            Move(Vector(90.0f, accel));
            //RotateTo(90.0f - 90);

        }
        else if (window->KeyDown('S')) {
            Move(Vector(270.0f, accel));
            //RotateTo(270.0f - 90);
        }
        else
            // se nenhuma tecla est� pressionada comece a frear
            if (speed.Magnitude() > 0.1f)
                Move(Vector(speed.Angle() + 180.0f, 5.0f * gameTime));
            else
                // velocidade muita baixa, n�o use soma vetorial, apenas pare
                speed.ScaleTo(0.0f);

        // controla dire��o dos disparos
        if (window->KeyDown(VK_RIGHT) && window->KeyDown(VK_UP)) {
            keysPressed = true;
            firingAngle = 45.0f;
        }
        else if (window->KeyDown(VK_LEFT) && window->KeyDown(VK_UP)) {
            keysPressed = true;
            firingAngle = 135.0f;
        }
        else if (window->KeyDown(VK_LEFT) && window->KeyDown(VK_DOWN)) {
            keysPressed = true;
            firingAngle = 225.0f;
        }
        else if (window->KeyDown(VK_RIGHT) && window->KeyDown(VK_DOWN)) {
            keysPressed = true;
            firingAngle = 315.0f;
        }
        else if (window->KeyDown(VK_RIGHT)) {
            keysPressed = true;
            firingAngle = 0.0f;
        }
        else if (window->KeyDown(VK_LEFT)) {
            keysPressed = true;
            firingAngle = 180.0f;
        }
        else if (window->KeyDown(VK_UP)) {
            keysPressed = true;
            firingAngle = 90.0f;
        }
        else if (window->KeyDown(VK_DOWN)) {
            keysPressed = true;
            firingAngle = 270.0f;
        }
        else
        {
            keysPressed = false;
        }

        // dispara m�ssil
        if (KeysTimed(keysPressed, 0.300f))
        {
            //SpaceBattle::audio->Play(FIRE);
            SpaceBattle::scene->Add(new Missile(firingAngle), STATIC);
        }
    }

    // movimenta objeto pelo seu vetor velocidade
    Translate(speed.XComponent() * 50.0f * gameTime, -speed.YComponent() * 50.0f * gameTime);

    // atualiza calda do jogador
    tail->Config().angle = speed.Angle() + 180;
    tail->Generate(x - 10 * cos(speed.Radians()), y + 10 * sin(speed.Radians()));
    tail->Update(gameTime);


    // restringe a �rea do jogo
    if (x < 50)
        MoveTo(50, y);
    if (y < 50)
        MoveTo(x, 50);
    if (x > game->Width() - 50)
        MoveTo(game->Width() - 50, y);
    if (y > game->Height() - 50)
        MoveTo(x, game->Height() - 50);
}

// ---------------------------------------------------------------------------------

void Player::Draw()
{
    sprite->Draw(x, y, Layer::MIDDLE, 1.0f, -speed.Angle() + 90.0f);
    tail->Draw(Layer::LOWER, 1.0f);
}

// -------------------------------------------------------------------------------
