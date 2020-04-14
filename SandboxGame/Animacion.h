#pragma once
#include "SFML/Graphics.hpp"

enum class Movimiento { NINGUNO, ARRIBA, ABAJO, DERECHA, IZQUIERDA };
enum class TipoEntidad { GENERAL, JUGADOR, ENEMIGO};

class Animacion {
private:
	float iFrame;
	float jFrame;
	float velocidad;
	int ancho;
	int alto;
	int filaFrame;
	int columnaFrame;
	sf::IntRect** rects;
	Movimiento tipoMovimiento;
public:
	Animacion();
	Animacion(int ancho, int alto, int filaFrame, int columnaFrame, float velocidad);
	~Animacion();

	Movimiento getTipoMovimiento();
	int getAncho();
	int getAlto();
	float getIFrame();
	float getJFrame();
	float getVelocidad();
	int getFilaFrame();
	int getColumnaFrame();
	void setTipoMovimiento(Movimiento type);
	void setAncho(int value);
	void setAlto(int value);
	void setIFrame(float value);
	void setJFrame(float value);
	void setVelocidad(float value);
	void setFilaFrame(int value);
	void setColumnaFrame(int value);

	sf::IntRect update(TipoEntidad type);
};