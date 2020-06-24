#ifndef _ANIMACION_H_
#define _ANIMACION_H_

#include "SFML/Graphics.hpp"

using namespace sf;

enum Direccion { ARRIBA, ABAJO, DERECHA, IZQUIERDA };

class Animacion {
private:
    int filaArriba;
    int filaAbajo;
    int filaDerecha;
    int filaIzquierda;
    int filas;
    int columnas;
    float framePosX;
    float framePosY;
    int frames;
    float velocidad;
    IntRect** rects;
public:
    Animacion();
    Animacion(int frames, int filas, int columnas, float velocidad);
    Animacion(int frames, int filas, int columnas, float velocidad, int filaArriba, int filaAbajo, int filaDerecha, int filaIzquierda);
    ~Animacion();

    int getFrames();
    float getVelocidad();
    IntRect** getRects();
    IntRect rectActual();

    void setFrames(int value);
    void setVelocidad(float value);
    void setRects(IntRect** values);

    void update();
    void update(Direccion dir);
};

#endif