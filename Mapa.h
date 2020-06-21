#ifndef _MAPA_H_
#define _MAPA_H_

#define FILA 15
#define COLUMNA 26
#define CUADRO 48

enum TipoTerreno {GRASS, TIERRA, ARENA, ADOQUIN};

class Mapa {
private:
	int dificultad;
public:
	Mapa();
	~Mapa();
};

#endif