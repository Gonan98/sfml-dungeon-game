#pragma once
#include "SFML/Graphics.hpp"

enum class Movimiento { NINGUNO, ARRIBA, ABAJO, DERECHA, IZQUIERDA };

class Animacion {
private:
	float iFrame;
	float jFrame;
	float velocidad;
	int ancho;
	int alto;
	int filaFrame;
	int columnaFrame;
public:
	Animacion();
	Animacion(sf::Texture& t, int ancho, int alto, int filaFrame, int columnaFrame, float velocidad);
	~Animacion();

	sf::Sprite sprite;
	Movimiento mov;
	int getAncho();
	int getAlto();
	float getIFrame();
	float getJFrame();
	float getVelocidad();
	int getFilaFrame();
	int getColumnaFrame();
	void setAncho(int value);
	void setAlto(int value);
	void setIFrame(float value);
	void setJFrame(float value);
	void setVelocidad(float value);
	void setFilaFrame(int value);
	void setColumnaFrame(int value);

	void update_jugador();
	void update_enemigo();
};