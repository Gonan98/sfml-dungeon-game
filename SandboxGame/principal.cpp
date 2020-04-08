#include "Jugador.h"
#include "Mapa.h"
#include "Naturaleza.h"

using namespace sf;

int main()
{
    
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

    Animacion* aJugador = new Animacion(tJugador1, 48, 48, 4, 3, 0.40f);
    Jugador* j1 = new Jugador(aJugador, 48, 48, 20, 0, "Andre");
    Mapa* mapa1 = new Mapa(tTerreno, tNaturaleza, tEnemigos, TipoTerreno::GRASS);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Up))
            aJugador->mov = Movimiento::ARRIBA;
        else if (Keyboard::isKeyPressed(Keyboard::Down))
            aJugador->mov = Movimiento::ABAJO;
        else if (Keyboard::isKeyPressed(Keyboard::Right))
            aJugador->mov = Movimiento::DERECHA;
        else if (Keyboard::isKeyPressed(Keyboard::Left))
            aJugador->mov = Movimiento::IZQUIERDA;
        else
            aJugador->mov = Movimiento::NINGUNO;

        mapa1->dibujar_fondo(window);
        mapa1->dibujar_enemigos(window);
        j1->dibujar(window, mapa1->getMatriz());
        mapa1->dibujar_decoracion(window);
        window.display();
    }

    return 0;
}