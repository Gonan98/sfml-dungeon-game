#include "Jugador.h"
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
    
    Jugador* jugador = new Jugador(tJugador1, "Andre");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        jugador->dibujar(window);
        window.display();
    }
    return 0;
}