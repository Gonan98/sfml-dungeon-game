#include "Esqueleto.h"

Esqueleto::Esqueleto() : Enemigo(){

}
Esqueleto::Esqueleto(Texture& t, Animacion* animacion, float x, float y) : Enemigo(t, animacion, x, y) {
    dx = dy = 6;
    damage = 3;
    vida = 10;
}
Esqueleto::~Esqueleto() {
    
}