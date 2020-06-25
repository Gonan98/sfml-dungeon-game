#include "Murcielago.h"

Murcielago::Murcielago() : Enemigo(){

}
Murcielago::Murcielago(Texture& t, Animacion* animacion, float x, float y) : Enemigo(t, animacion, x, y) {
    dx = dy = 10;
    damage = 2;
    vida = 5;
}
Murcielago::~Murcielago() {
    
}