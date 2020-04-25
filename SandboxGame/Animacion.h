#pragma once
#include "SFML/Graphics.hpp"

enum class TipoMovimiento { NINGUNO, ARRIBA, ABAJO, DERECHA, IZQUIERDA };
enum class TipoEntidad { GENERAL, JUGADOR, ENEMIGO };

class Animacion {
private:
	float xFrame;
	float yFrame;
	float velocidad;
	int anchoFrame;
	int altoFrame;
	int filas;
	int columnas;
	sf::IntRect** rects;
	TipoMovimiento movimiento;
public:
	Animacion();
	Animacion(int anchoFrame, int altoFrame, int filas, int columnas, float velocidad);
	Animacion(int anchoFrame, int altoFrame, int xFrame, float yFrame, int filas, int columnas, float velocidad);
	~Animacion();

	TipoMovimiento getMovimiento();
	int getAnchoFrame();
	int getAltoFrame();
	float getXFrame();
	float getYFrame();
	float getVelocidad();
	int getFilaFrame();
	int getColumnaFrame();
	sf::IntRect frameActual();
	void setMovimiento(TipoMovimiento type);
	void setAnchoFrame(int value);
	void setAltoFrame(int value);
	void setXFrame(float value);
	void setYFrame(float value);
	void setVelocidad(float value);
	void setFilaFrame(int value);
	void setColumnaFrame(int value);

	bool secuenciaFinalizada();

	sf::IntRect update(TipoEntidad type);
	sf::IntRect update();
};