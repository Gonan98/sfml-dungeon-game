#include "Animacion.h"

Animacion::Animacion(){
	movimiento = TipoMovimiento::NINGUNO;
	xFrame = yFrame = 0.0f;
	anchoFrame = altoFrame = 48;
	filas = columnas = 1;
	velocidad = 0.0f;
	rects = new sf::IntRect * [filas];
	for (int i = 0; i < filas; i++) {
		rects[i] = new sf::IntRect[columnas];
		for (int j = 0; j < columnas; j++)
			rects[i][j] = sf::IntRect(j * anchoFrame, i * altoFrame, anchoFrame, altoFrame);
	}
}

Animacion::Animacion(int anchoFrame, int altoFrame, int filas, int columnas, float velocidad) {
	movimiento = TipoMovimiento::NINGUNO;
	xFrame = 0;
	yFrame = 0;
	this->anchoFrame = anchoFrame;
	this->altoFrame = altoFrame;
	this->filas = filas;
	this->columnas = columnas;
	this->velocidad = velocidad;

	rects = new sf::IntRect*[this->filas];
	for (int i = 0; i < this->filas; i++) {
		rects[i] = new sf::IntRect[this->columnas];
		for (int j = 0; j < this->columnas; j++)
			rects[i][j] = sf::IntRect(j * anchoFrame, i * altoFrame, anchoFrame, altoFrame);
	}
}

Animacion::Animacion(int anchoFrame, int altoFrame, int xFrame, float yFrame, int filas, int columnas, float velocidad) {
	movimiento = TipoMovimiento::NINGUNO;
	this->xFrame = 0;
	this->yFrame = 0;
	this->anchoFrame = anchoFrame;
	this->altoFrame = altoFrame;
	this->filas = filas;
	this->columnas = columnas;
	this->velocidad = velocidad;

	rects = new sf::IntRect * [this->filas];
	for (int i = 0; i < this->filas; i++) {
		rects[i] = new sf::IntRect[this->columnas];
		for (int j = 0; j < this->columnas; j++)
			rects[i][j] = sf::IntRect((j + xFrame) * altoFrame, (i + yFrame) * anchoFrame, anchoFrame, altoFrame);
	}
}

Animacion::~Animacion() {
	for (int i = 0; i < filas; i++)
		delete[] rects[i];
	delete[] rects;
}

TipoMovimiento Animacion::getMovimiento() { return movimiento; }
int Animacion::getAnchoFrame() { return anchoFrame; }
int Animacion::getAltoFrame() { return altoFrame; }
float Animacion::getXFrame() { return xFrame; }
float Animacion::getYFrame() { return yFrame; }
float Animacion::getVelocidad() { return velocidad; }
int Animacion::getFilaFrame() { return filas; }
int Animacion::getColumnaFrame() { return columnas; }
sf::IntRect Animacion::frameActual() { return rects[(int)yFrame][(int)xFrame]; }

void Animacion::setMovimiento(TipoMovimiento type) { movimiento = type; }
void Animacion::setAnchoFrame(int value) { anchoFrame = value; }
void Animacion::setAltoFrame(int value) { altoFrame = value; }
void Animacion::setXFrame(float value) { xFrame = value; }
void Animacion::setYFrame(float value) { yFrame = value; }
void Animacion::setVelocidad(float value) { velocidad = value; }
void Animacion::setFilaFrame(int value) { filas = value; }
void Animacion::setColumnaFrame(int value) { columnas = value; }

sf::IntRect Animacion::update(TipoEntidad type) {
	if (type == TipoEntidad::JUGADOR) {
		switch (movimiento)
		{
		case TipoMovimiento::NINGUNO:
			xFrame = 1;
			break;
		case TipoMovimiento::ARRIBA:
			yFrame = 3;
			xFrame += velocidad;
			break;
		case TipoMovimiento::ABAJO:
			yFrame = 0;
			xFrame += velocidad;
			break;
		case TipoMovimiento::DERECHA:
			yFrame = 2;
			xFrame += velocidad;
			break;
		case TipoMovimiento::IZQUIERDA:
			yFrame = 1;
			xFrame += velocidad;
			break;
		}
	}
	else if (type == TipoEntidad::ENEMIGO) {
		switch (movimiento)
		{
		case TipoMovimiento::NINGUNO:
			xFrame = 1;
			break;
		case TipoMovimiento::ARRIBA:
			yFrame = 2;
			xFrame += velocidad;
			break;
		case TipoMovimiento::ABAJO:
			yFrame = 0;
			xFrame += velocidad;
			break;
		case TipoMovimiento::DERECHA:
			yFrame = 1;
			xFrame += velocidad;
			break;
		case TipoMovimiento::IZQUIERDA:
			yFrame = 3;
			xFrame += velocidad;
			break;
		default:
			break;
		}
	}

	if (xFrame + velocidad > columnas)
		xFrame = 0;

	return rects[(int)yFrame][(int)xFrame];
}

sf::IntRect Animacion::update() {
	
	xFrame += velocidad;
	if (xFrame + velocidad > columnas) {
		xFrame = 0;
		yFrame++;
		if (yFrame >= filas)
			yFrame = 0;
	}
	
	return rects[(int)yFrame][(int)xFrame];
}

bool Animacion::secuenciaFinalizada() {
	return xFrame == columnas - 1 && yFrame == filas - 1;
}