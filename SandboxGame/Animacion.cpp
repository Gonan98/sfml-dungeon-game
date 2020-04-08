#include "Animacion.h"

Animacion::Animacion(){
	mov = Movimiento::NINGUNO;
	jFrame = iFrame = 0.0f;
	ancho = alto = 48;
	filaFrame = columnaFrame = 0;
	velocidad = 0.0f;
}

Animacion::Animacion(sf::Texture& t, int ancho, int alto, int filaFrame, int columnaFrame, float velocidad) {
	mov = Movimiento::NINGUNO;
	iFrame = 0;
	jFrame = 1;
	this->ancho = ancho;
	this->alto = alto;
	this->filaFrame = filaFrame;
	this->columnaFrame = columnaFrame;
	this->velocidad = velocidad;
	sprite.setTexture(t);
}
Animacion::~Animacion(){}

int Animacion::getAncho() { return ancho; }
int Animacion::getAlto() { return alto; }
float Animacion::getIFrame() { return iFrame; }
float Animacion::getJFrame() { return jFrame; }
float Animacion::getVelocidad() { return velocidad; }
int Animacion::getFilaFrame() { return filaFrame; }
int Animacion::getColumnaFrame() { return columnaFrame; }

void Animacion::setAncho(int value) { ancho = value; }
void Animacion::setAlto(int value) { alto = value; }
void Animacion::setIFrame(float value) { iFrame = value; }
void Animacion::setJFrame(float value) { jFrame = value; }
void Animacion::setVelocidad(float value) { velocidad = value; }
void Animacion::setFilaFrame(int value) { filaFrame = value; }
void Animacion::setColumnaFrame(int value) { columnaFrame = value; }

void Animacion::update_jugador() {
	switch (mov)
	{
	case Movimiento::NINGUNO:
		jFrame = 1;
		break;
	case Movimiento::ARRIBA:
		iFrame = 3;
		jFrame += velocidad;
		break;
	case Movimiento::ABAJO:
		iFrame = 0;
		jFrame += velocidad;
		break;
	case Movimiento::DERECHA:
		iFrame = 2;
		jFrame += velocidad;
		break;
	case Movimiento::IZQUIERDA:
		iFrame = 1;
		jFrame += velocidad;
		break;
	}
	if (jFrame+velocidad > columnaFrame)
		jFrame = 0;

	sprite.setTextureRect(sf::IntRect((int)jFrame * ancho, (int)iFrame * alto, ancho, alto));
}

void Animacion::update_enemigo() {
	switch (mov)
	{
	case Movimiento::NINGUNO:
		jFrame = 1;
		break;
	case Movimiento::ARRIBA:
		iFrame = 2;
		jFrame += velocidad;
		break;
	case Movimiento::ABAJO:
		iFrame = 0;
		jFrame += velocidad;
		break;
	case Movimiento::DERECHA:
		iFrame = 1;
		jFrame += velocidad;
		break;
	case Movimiento::IZQUIERDA:
		iFrame = 3;
		jFrame += velocidad;
		break;
	default:
		break;
	}
	if (jFrame + velocidad > columnaFrame)
		jFrame = 0;

	sprite.setTextureRect(sf::IntRect((int)jFrame * ancho, (int)iFrame * alto, ancho, alto));
}