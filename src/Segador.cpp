#include "Segador.h"

Segador::Segador() : Enemigo(){

}
Segador::Segador(Texture& t, Animacion* animacion, float x, float y) : Enemigo(t, animacion, x, y) {
    dx = dy = 6;
    damage = 5;
    vida = 15;
}
Segador::~Segador() {
    
}