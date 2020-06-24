#include "Orco.h"

Orco::Orco() : Enemigo(){

}
Orco::Orco(Texture& t, Animacion* animacion, float x, float y) : Enemigo(t, animacion, x, y) {
    dx = dy = 4;
    damage = 4;
    vida = 20;
}
Orco::~Orco() {
    
}