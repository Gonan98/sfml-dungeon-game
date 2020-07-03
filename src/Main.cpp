#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Jugador.h"
#include "ListaMapas.h"

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

    Jugador* jugador = new Jugador(tJugador1, aJugador, "Andre", 48, 48, 6 , 6);
    ListaMapas* lista = new ListaMapas();
    lista->nuevoMapa(new Mapa(tTerreno[rand()%4], tNaturaleza, tEnemigos, tCofre));
    int n = lista->mapaActual()->getTotalNatural();

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

        if (clock.getElapsedTime().asSeconds() > 1) {
            if (Keyboard::isKeyPressed(Keyboard::N)) {
                lista->nuevoMapa(new Mapa(tTerreno[rand()%4], tNaturaleza, tEnemigos, tCofre));
                lista->mapaSiguiente();
                n = lista->mapaActual()->getTotalNatural();
            } else if (Keyboard::isKeyPressed(Keyboard::A)) {
                lista->mapaAnterior();
            } else if (Keyboard::isKeyPressed(Keyboard::S)) {
                lista->mapaSiguiente();
            }
            clock.restart();
        }

        for (int i = 0; i < n; i++) {
            Hitbox* a = jugador->getHitbox();
            Hitbox* b = lista->mapaActual()->getNaturalezas()->getNaturaleza(i)->getHitbox();
            if(b->colisiona(a)) {
                if (jugador->getDireccion() == DERECHA) {
                    jugador->mover(IZQUIERDA);
                } else if (jugador->getDireccion() == IZQUIERDA) {
                    jugador->mover(DERECHA);
                } 
                if (jugador->getDireccion() == ARRIBA) {
                    jugador->mover(ABAJO);
                } else if (jugador->getDireccion() == ABAJO) {
                    jugador->mover(ARRIBA);
                }
            }
        }

        if(Keyboard::isKeyPressed(Keyboard::Right)) {
            jugador->mover(DERECHA);
        }
        else if(Keyboard::isKeyPressed(Keyboard::Left)) {
            jugador->mover(IZQUIERDA);
        }
        if(Keyboard::isKeyPressed(Keyboard::Up)) {
            jugador->mover(ARRIBA);
        }
        else if(Keyboard::isKeyPressed(Keyboard::Down)) {
            jugador->mover(ABAJO);
        }
        
        lista->mapaActual()->colisionEnemigoDecoracion();
        lista->mapaActual()->moverEnemigos();

        window.clear();

        lista->mapaActual()->dibujar(window);
        lista->mapaActual()->dibujarNaturalezaInferior(window);

        lista->mapaActual()->dibujarCofres(window);
        lista->mapaActual()->dibujarEnemigos(window);
        jugador->dibujar(window);

        lista->mapaActual()->dibujarNaturalezaSuperior(window);

        window.display();
    }

    delete jugador;
    delete aJugador;
    delete[] tEnemigos;
    delete[] tNaturaleza;
    delete[] tTerreno;

    return 0;
}