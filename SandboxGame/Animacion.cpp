#include "Animacion.h"

Animacion::Animacion(){
	tipoMovimiento = Movimiento::NINGUNO;
	jFrame = iFrame = 0.0f;
	ancho = alto = 48;
	filaFrame = columnaFrame = 0;
	velocidad = 0.0f;
	rects = new sf::IntRect * [filaFrame];
	for (int i = 0; i < filaFrame; i++) {
		rects[i] = new sf::IntRect[columnaFrame];
		for (int j = 0; j < columnaFrame; j++)
			rects[i][j] = sf::IntRect(j * ancho, i * alto, ancho, alto);
	}
}

Animacion::Animacion(int ancho, int alto, int filaFrame, int columnaFrame, float velocidad) {
	tipoMovimiento = Movimiento::NINGUNO;
	iFrame = 0;
	jFrame = 1;
	this->ancho = ancho;
	this->alto = alto;
	this->filaFrame = filaFrame;
	this->columnaFrame = columnaFrame;
	this->velocidad = velocidad;

	rects = new sf::IntRect*[filaFrame];
	for (int i = 0; i < filaFrame; i++) {
		rects[i] = new sf::IntRect[columnaFrame];
		for (int j = 0; j < columnaFrame; j++)
			rects[i][j] = sf::IntRect(j * ancho, i * alto, ancho, alto);
	}
}

Animacion::~Animacion() {
	for (int i = 0; i < filaFrame; i++)
		delete[] rects[i];
	delete[] rects;
}

Movimiento Animacion::getTipoMovimiento() { return tipoMovimiento; }
int Animacion::getAncho() { return ancho; }
int Animacion::getAlto() { return alto; }
float Animacion::getIFrame() { return iFrame; }
float Animacion::getJFrame() { return jFrame; }
float Animacion::getVelocidad() { return velocidad; }
int Animacion::getFilaFrame() { return filaFrame; }
int Animacion::getColumnaFrame() { return columnaFrame; }

void Animacion::setTipoMovimiento(Movimiento type) { tipoMovimiento = type; }
void Animacion::setAncho(int value) { ancho = value; }
void Animacion::setAlto(int value) { alto = value; }
void Animacion::setIFrame(float value) { iFrame = value; }
void Animacion::setJFrame(float value) { jFrame = value; }
void Animacion::setVelocidad(float value) { velocidad = value; }
void Animacion::setFilaFrame(int value) { filaFrame = value; }
void Animacion::setColumnaFrame(int value) { columnaFrame = value; }

sf::IntRect Animacion::update(TipoEntidad type) {
	if (type == TipoEntidad::GENERAL) {

	}
	else if (type == TipoEntidad::JUGADOR) {
		switch (tipoMovimiento)
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
		if (jFrame + velocidad > columnaFrame)
			jFrame = 0;
	}
	else if (type == TipoEntidad::ENEMIGO) {
		switch (tipoMovimiento)
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
	}

	return rects[(int)iFrame][(int)jFrame];
}