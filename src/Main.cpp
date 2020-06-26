#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Jugador.h"
#include "Mapa.h"
#include "ListaEnemigos.h"

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

    Jugador* jugador = new Jugador(tJugador1, aJugador, "Andre", 0, 0, 8 , 8);
    Arbol* arbol = new Arbol(tNaturaleza[0], 200, 200, 0, 0);
    Monte* monte = new Monte(tNaturaleza[1], 100, 400, 0, 0);
    Roca* roca = new Roca(tNaturaleza[2], 500, 500, 0, 0);
    Piedra* piedra = new Piedra(tNaturaleza[3], 700, 200, 0, 0);
    Mapa* mapa = new Mapa(tTerreno[0], tNaturaleza, tEnemigos);
    ListaEnemigos* enemies = new ListaEnemigos();

    for (int i = 0; i < 5; i++) {
        switch (rand()%4) {
        case 0:
            enemies->agregar(new Orco(tEnemigos[0], new Animacion(12, 4, 3, 0.2f, 2, 0, 1, 3), 600, 350));
            break;
        case 1:
            enemies->agregar(new Esqueleto(tEnemigos[1], new Animacion(12, 4, 3, 0.2f, 2, 0, 1, 3), 600, 350));
            break;
        case 2:
            enemies->agregar(new Murcielago(tEnemigos[2], new Animacion(12, 4, 3, 0.2f, 2, 0, 1, 3), 600, 350));
            break;
        case 3:
            enemies->agregar(new Espectro(tEnemigos[3], new Animacion(12, 4, 3, 0.2f, 2, 0, 1, 3), 600, 350));
            break;
        case 4:
            enemies->agregar(new Segador(tEnemigos[4], new Animacion(12, 4, 3, 0.2f, 2, 0, 1, 3), 600, 350));
            break;
        default:
            break;
        }
    }

    Clock clock;
    Direccion* direcciones = new Direccion[enemies->getTotal()];
    for (int i = 0; i < enemies->getTotal(); i++) {
        direcciones[i] = DERECHA;
    }
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
            for (int i = 0; i < enemies->getTotal(); i++) {
                direcciones[i] = Direccion(rand()%4);
            }
            clock.restart();
        }
        enemies->mover(direcciones);

        window.clear();

        mapa->dibujar(window);
        mapa->dibujarNaturalezaInferior(window);

        arbol->dibujarInferior(window);
        monte->dibujarInferior(window);
        roca->dibujarInferior(window);
        piedra->dibujarInferior(window);

        jugador->dibujar(window);

        enemies->dibujar(window);

        mapa->dibujarNaturalezaSuperior(window);
        arbol->dibujarSuperior(window);
        monte->dibujarSuperior(window);
        roca->dibujarSuperior(window);
        piedra->dibujarSuperior(window);

        window.display();
    }

    delete enemies;
    delete jugador;
    delete arbol;
    delete monte;
    delete roca;
    delete piedra;
    delete aJugador;
    delete[] tEnemigos;
    delete[] tNaturaleza;
    delete[] tTerreno;
    return 0;
}