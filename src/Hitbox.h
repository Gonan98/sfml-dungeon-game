#ifndef _HITBOX_H_
#define _HITBOX_H_

#include <SFML/Graphics.hpp>

using namespace sf;

class Hitbox {
private:
    float x;
    float y;
    float w;
    float h;
    RectangleShape rectangle;
public:
    Hitbox();
    Hitbox(float x, float y, float w, float h);
    ~Hitbox();

    float getX();
    float getY();
    float getW();
    float getH();

    void setX(float value);
    void setY(float value);
    void setW(float value);
    void setH(float value);

    void dibujar(RenderWindow& w);
    void posicionar(float x, float y);
    bool colisiona(Hitbox* hbox);
};

#endif