#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Jugador.h"
#include "Orco.h"
#include "Segador.h"
#include "Espectro.h"
#include "Murcielago.h"
#include "Esqueleto.h"
#include "Arbol.h"
#include "Monte.h"
#include "Roca.h"
#include "Piedra.h"
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
    Animacion* animacionOrco = new Animacion(12, 4, 3, 0.2f, 2, 0, 1, 3);
    Animacion* animacionEsqueleto = new Animacion(12, 4, 3, 0.2f, 2, 0, 1, 3);
    Animacion* animacionSegador = new Animacion(12, 4, 3, 0.2f, 2, 0, 1, 3);
    Animacion* animacionMurcielago = new Animacion(12, 4, 3, 0.2f, 2, 0, 1, 3);
    Animacion* animacionEspectro = new Animacion(12, 4, 3, 0.2f, 2, 0, 1, 3);

    Jugador* jugador = new Jugador(tJugador1, aJugador, "Andre", 0, 0, 8 , 8);
    Orco* orco = new Orco(tEnemigos[0], animacionOrco, 600, 350);
    Esqueleto* esqueleto = new Esqueleto(tEnemigos[1], animacionEsqueleto, 600, 350);
    Murcielago* murcielago = new Murcielago(tEnemigos[2], animacionMurcielago, 600, 350);
    Espectro* espectro = new Espectro(tEnemigos[3], animacionEspectro, 600, 350);
    Segador* segador = new Segador(tEnemigos[4], animacionSegador, 600, 350);
    Arbol* arbol = new Arbol(tNaturaleza[0], 200, 200, 0, 0);
    Monte* monte = new Monte(tNaturaleza[1], 100, 400, 0, 0);
    Roca* roca = new Roca(tNaturaleza[2], 500, 500, 0, 0);
    Piedra* piedra = new Piedra(tNaturaleza[3], 700, 200, 0, 0);
    Mapa* mapa = new Mapa(tTerreno[0]);

    Clock clock;
    Direccion* direcciones = new Direccion[5];
    direcciones[0] = DERECHA;
    direcciones[1] = DERECHA;
    direcciones[2] = DERECHA;
    direcciones[3] = DERECHA;
    direcciones[4] = DERECHA;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        if(Keyboard::isKeyPressed(Keyboard::Up))
            jugador->mover(ARRIBA);
        else if(Keyboard::isKeyPressed(Keyboard::Down))
            jugador->mover(ABAJO);
        else if(Keyboard::isKeyPressed(Keyboard::Right))
            jugador->mover(DERECHA);
        else if(Keyboard::isKeyPressed(Keyboard::Left))
            jugador->mover(IZQUIERDA);

        if (clock.getElapsedTime().asSeconds() > 1) {
            direcciones[0] = Direccion(rand()%4);
            direcciones[1] = Direccion(rand()%4);
            direcciones[2] = Direccion(rand()%4);
            direcciones[3] = Direccion(rand()%4);
            direcciones[4] = Direccion(rand()%4);
            clock.restart();
        }

        orco->mover(direcciones[0]);
        esqueleto->mover(direcciones[1]);
        murcielago->mover(direcciones[2]);
        espectro->mover(direcciones[3]);
        segador->mover(direcciones[4]);

        window.clear();
        mapa->dibujar(window);
        arbol->dibujarInferior(window);
        monte->dibujarInferior(window);
        roca->dibujarInferior(window);
        piedra->dibujarInferior(window);
        jugador->dibujar(window);
        orco->dibujar(window);
        esqueleto->dibujar(window);
        murcielago->dibujar(window);
        espectro->dibujar(window);
        segador->dibujar(window);
        arbol->dibujarSuperior(window);
        monte->dibujarSuperior(window);
        roca->dibujarSuperior(window);
        piedra->dibujarSuperior(window);
        window.display();
    }

    delete jugador;
    delete orco;
    delete esqueleto;
    delete segador;
    delete murcielago;
    delete espectro;
    delete arbol;
    delete monte;
    delete roca;
    delete piedra;
    delete aJugador;
    delete animacionOrco;
    delete animacionEsqueleto;
    delete animacionSegador;
    delete animacionMurcielago;
    delete animacionEspectro;
    delete[] tEnemigos;
    delete[] tNaturaleza;
    delete[] tTerreno;
    return 0;
}