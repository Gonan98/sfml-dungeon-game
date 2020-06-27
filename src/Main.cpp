#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Jugador.h"
#include "Mapa.h"

using namespace sf;

int main() {
    srand((unsigned)time(0));
    RenderWindow window(VideoMode(1248, 720), "Sandbox Game");
    window.setFramerateLimit(30);

    Texture tJugador1;
    tJugador1.loadFromFile("resources/persona1.png");

    Texture* tTerreno = new Texture[4];
    tTerreno[0].loadFromFile("resources/grass.png");
    tTerreno[0].setRepeated(true);
    tTerreno[1].loadFromFile("resources/tierra.png");
    tTerreno[1].setRepeated(true);
    tTerreno[2].loadFromFile("resources/arena.png");
    tTerreno[2].setRepeated(true);
    tTerreno[3].loadFromFile("resources/adoquin.png");
    tTerreno[3].setRepeated(true);

    Texture* tNaturaleza = new Texture[4];
    tNaturaleza[0].loadFromFile("resources/arbol.png");
    tNaturaleza[1].loadFromFile("resources/monte.png");
    tNaturaleza[2].loadFromFile("resources/roca.png");
    tNaturaleza[3].loadFromFile("resources/piedra.png");

    Texture* tEnemigos = new Texture[5];
    tEnemigos[0].loadFromFile("resources/orco.png");
    tEnemigos[1].loadFromFile("resources/esqueleto.png");
    tEnemigos[2].loadFromFile("resources/murcielago.png");
    tEnemigos[3].loadFromFile("resources/espectro.png");
    tEnemigos[4].loadFromFile("resources/segador.png");

    Texture tCofre;
    tCofre.loadFromFile("resources/chests_sprite.png");
    
    Animacion* aJugador = new Animacion(12, 4, 3, 0.2f, 3, 0, 2, 1);

    Jugador* jugador = new Jugador(tJugador1, aJugador, "Andre", 48, 48, 8 , 8);
    Mapa* mapa = new Mapa(tTerreno[0], tNaturaleza, tEnemigos);
    Direccion* dir = new Direccion[mapa->getTotalEnemigos()];

    for (int i = 0; i < mapa->getTotalEnemigos(); i++) {
        dir[i] = Direccion(rand()%4);
    }
    
    Clock clock;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        if(Keyboard::isKeyPressed(Keyboard::Right))
            jugador->mover(DERECHA);
        else if(Keyboard::isKeyPressed(Keyboard::Left))
            jugador->mover(IZQUIERDA);
        if(Keyboard::isKeyPressed(Keyboard::Up))
            jugador->mover(ARRIBA);
        else if(Keyboard::isKeyPressed(Keyboard::Down))
            jugador->mover(ABAJO);

        if (clock.getElapsedTime().asSeconds() > 1) {
            mapa->cambiarDireccionEnemigos(dir);
            clock.restart();
        }
        
        mapa->moverEnemigos(dir);

        window.clear();

        mapa->dibujar(window);
        mapa->dibujarNaturalezaInferior(window);

        mapa->dibujarEnemigos(window);
        jugador->dibujar(window);

        mapa->dibujarNaturalezaSuperior(window);

        window.display();
    }

    delete jugador;
    delete aJugador;
    delete[] dir;
    delete mapa;
    delete[] tEnemigos;
    delete[] tNaturaleza;
    delete[] tTerreno;

    return 0;
}