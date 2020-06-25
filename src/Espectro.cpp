#include "Espectro.h"

Espectro::Espectro() : Enemigo(){

}
Espectro::Espectro(Texture& t, Animacion* animacion, float x, float y) : Enemigo(t, animacion, x, y) {
    dx = dy = 8;
    damage = 5;
    vida = 8;
}
Espectro::~Espectro() {
    
}