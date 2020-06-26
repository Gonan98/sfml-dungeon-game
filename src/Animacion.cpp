#include "Animacion.h"
#include <iostream>

Animacion::Animacion() {

}

Animacion::Animacion(int frames, int filas, int columnas, float velocidad) {
    this->filaArriba = filaArriba;
    this->filaAbajo = filaAbajo;
    this->filaDerecha = filaDerecha;
    this->filaIzquierda = filaIzquierda;
    this->framePosX = 0;
    this->framePosY = 0;
    this->frames = frames;
    this->filas = filas;
    this->columnas = columnas;
    this->velocidad = velocidad;

    rects = new IntRect*[filas];

    for (int i = 0; i < filas; i++) {
        rects[i] = new IntRect[columnas];
        for (int j = 0; j < columnas; j++) {
            rects[i][j] = IntRect(j*48,i*48,48,48);
            //std::cout << "(" << rects[i][j].left << ";" << rects[i][j].top << ")" << std::endl;
        }
    }
}

Animacion::Animacion(int frames, int filas, int columnas, float velocidad, int filaArriba, int filaAbajo, int filaDerecha, int filaIzquierda) {
    this->filaArriba = filaArriba;
    this->filaAbajo = filaAbajo;
    this->filaDerecha = filaDerecha;
    this->filaIzquierda = filaIzquierda;
    this->framePosX = 0;
    this->framePosY = 0;
    this->frames = frames;
    this->filas = filas;
    this->columnas = columnas;
    this->velocidad = velocidad;

    rects = new IntRect*[filas];

    for (int i = 0; i < filas; i++) {
        rects[i] = new IntRect[columnas];
        for (int j = 0; j < columnas; j++) {
            rects[i][j] = IntRect(j*48,i*48,48,48);
            //std::cout << "(" << rects[i][j].left << ";" << rects[i][j].top << ")" << std::endl;
        }
    }
}

Animacion::~Animacion() { 
    for (int i = 0; i < filas; i++)
        delete[] rects[i];
    delete[] rects;
}

int Animacion::getFrames() { return frames; }
float Animacion::getVelocidad() { return velocidad; }
IntRect** Animacion::getRects() { return rects; }
IntRect Animacion::rectActual() { return rects[(int)framePosY][(int)framePosX]; }

void Animacion::setFrames(int value) { frames = value; }
void Animacion::setVelocidad(float value) { velocidad = value; }
void Animacion::setRects(IntRect** values) { rects = values; }

void Animacion::update() {
    framePosX+=velocidad;
    if (framePosX >= columnas) {
        framePosX = 0;
        framePosY++;
        if (framePosY >= filas)
            framePosY = 0;
    }
}

void Animacion::update(Direccion dir) {
	switch(dir) {
		case Direccion::ARRIBA:
			framePosY = filaArriba;
			break;
		case Direccion::ABAJO:
			framePosY = filaAbajo;
			break;
		case Direccion::DERECHA:
			framePosY = filaDerecha;
			break;
		case Direccion::IZQUIERDA:
			framePosY = filaIzquierda;
			break;
		default:
            framePosY = filaDerecha;
			break;
	}
    framePosX += velocidad;
    if (framePosX >= columnas) framePosX = 0;
}