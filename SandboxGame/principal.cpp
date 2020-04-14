#include "Controller.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace sf;

int main()
{
    srand((unsigned)time(0));
    RenderWindow window(VideoMode(1248, 720), "Sandbox Game");
    window.setFramerateLimit(30);

    Texture tJugador1;
    tJugador1.loadFromFile("recursos/persona1.png");

    Texture* tTerreno = new Texture[4];
    tTerreno[0].loadFromFile("recursos/grass.png");
    tTerreno[0].setRepeated(true);
    tTerreno[1].loadFromFile("recursos/tierra.png");
    tTerreno[1].setRepeated(true);
    tTerreno[2].loadFromFile("recursos/arena.png");
    tTerreno[2].setRepeated(true);
    tTerreno[3].loadFromFile("recursos/adoquin.png");
    tTerreno[3].setRepeated(true);

    Texture* tNaturaleza = new Texture[4];
    tNaturaleza[0].loadFromFile("recursos/arbol.png");
    tNaturaleza[1].loadFromFile("recursos/monte.png");
    tNaturaleza[2].loadFromFile("recursos/roca.png");
    tNaturaleza[3].loadFromFile("recursos/piedra.png");

    Texture* tEnemigos = new Texture[5];
    tEnemigos[0].loadFromFile("recursos/orco.png");
    tEnemigos[1].loadFromFile("recursos/esqueleto.png");
    tEnemigos[2].loadFromFile("recursos/murcielago.png");
    tEnemigos[3].loadFromFile("recursos/espectro.png");
    tEnemigos[4].loadFromFile("recursos/segador.png");

    Controller* juego = new Controller(tJugador1, tTerreno, tEnemigos, tNaturaleza);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.key.code == sf::Keyboard::C) {
                juego->mapa_anterior();
            }
            if (event.key.code == sf::Keyboard::V) {
                juego->mapa_siguiente();
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Up))
            juego->getJugador1()->getAnimacion()->setTipoMovimiento(Movimiento::ARRIBA);
        else if (Keyboard::isKeyPressed(Keyboard::Down))
            juego->getJugador1()->getAnimacion()->setTipoMovimiento(Movimiento::ABAJO);
        else if (Keyboard::isKeyPressed(Keyboard::Right))
            juego->getJugador1()->getAnimacion()->setTipoMovimiento(Movimiento::DERECHA);
        else if (Keyboard::isKeyPressed(Keyboard::Left))
            juego->getJugador1()->getAnimacion()->setTipoMovimiento(Movimiento::IZQUIERDA);
        else
            juego->getJugador1()->getAnimacion()->setTipoMovimiento(Movimiento::NINGUNO);

        if (Keyboard::isKeyPressed(Keyboard::Z)) {
            juego->agregar_mapa(TipoTerreno(rand() % 4));
            std::cout << "Agregar mapa\n";
        }

        juego->dibujar_todo(window);
        window.display();
    }

    return 0;
}