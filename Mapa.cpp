#include "Mapa.h"

Mapa::Mapa(Texture& t) {
	sprite.setTexture(t);
	sprite.setTextureRect(IntRect(0,0,COLUMNA*CUADRO,FILA*CUADRO));
}

Mapa::~Mapa() {

}

void Mapa::dibujar(RenderWindow& w) {
	w.draw(sprite);
}