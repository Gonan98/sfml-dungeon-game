#include "Mapa.h"

void Mapa::inicializar_matriz() {
	matrizMapa = new int* [FILA];
	for (int i = 0; i < FILA; i++) {
		matrizMapa[i] = new int[COLUMNA];
		for (int j = 0; j < COLUMNA; j++)
			matrizMapa[i][j] = 0;
	}
}

bool Mapa::regionVacia(int i, int j) {
	return matrizMapa[i][j] == 0 && matrizMapa[i][j + 1] == 0 && matrizMapa[i][j + 2] == 0
		&& matrizMapa[i + 1][j] == 0 && matrizMapa[i + 1][j + 1] == 0 && matrizMapa[i + 1][j + 2] == 0
		&& matrizMapa[i + 2][j] == 0 && matrizMapa[i + 2][j + 1] == 0 && matrizMapa[i + 2][j + 2] == 0;
}

void Mapa::colocar_enemigos(sf::Texture* tEnemigos) {
	for (int i = 0; i < 5;) {
		int posX = (rand() % (COLUMNA - 4) + 2) * CUADRO;
		int posY = (rand()%(FILA - 4) + 2) * CUADRO;
		if (matrizMapa[posY / CUADRO][posX / CUADRO] == 0) {
			int tipo = rand() % 5;
			Animacion* a = new Animacion(CUADRO, CUADRO, 4, 3, 0.40f);
			a->setMovimiento(TipoMovimiento(rand() % 4 + 1));
			enemigos.push_back(new Enemigo(a, tEnemigos[tipo], TipoEnemigo(tipo), posX, posY));
			i++;
		}
	}
}

void Mapa::colocar_decoracion(sf::Texture* naturales) {
	for (int i = 0; i < FILA; i++)
		for (int j = 0; j < COLUMNA; j++) {
			if (j == 0 || i == 0 || j == COLUMNA - 1 || i == FILA - 1) {
				matrizMapa[i][j] = 1;
				decoracion.push_back(new Naturaleza(naturales, TipoNatural::PIEDRA, j * CUADRO, i * CUADRO));
			}
			else if (i > 0 && i < FILA - 3 && j > 0 && j < COLUMNA - 3 && regionVacia(i, j)) {
				if (rand()%3 == 1) {
					TipoNatural tipo = TipoNatural(rand() % 4);
					decoracion.push_back(new Naturaleza(naturales, tipo, j * CUADRO, i * CUADRO));
					switch (tipo)
					{
					case TipoNatural::ARBOL:
						matrizMapa[i][j] = 2;
						matrizMapa[i + 1][j] = 2;
						matrizMapa[i + 2][j] = 1;
						break;
					case TipoNatural::MONTE:
						matrizMapa[i][j] = 2;
						matrizMapa[i][j+1] = 2;
						matrizMapa[i][j+2] = 2;
						matrizMapa[i+1][j] = 1;
						matrizMapa[i+1][j+1] = 1;
						matrizMapa[i+1][j+2] = 1;
						matrizMapa[i+2][j] = 1;
						matrizMapa[i+2][j+1] = 1;
						matrizMapa[i+2][j+2] = 1;
						break;
					case TipoNatural::ROCA:
						matrizMapa[i][j] = 2;
						matrizMapa[i][j+1] = 2;
						matrizMapa[i+1][j] = 1;
						matrizMapa[i+1][j+1] = 1;
						break;
					case TipoNatural::PIEDRA:
						matrizMapa[i][j] = 1;
					default:
						break;
					}
				}
			}
		}
}

void Mapa::colocar_cofres(sf::Texture &tCofre) {
	int cant = rand() % 4;
	for (int i = 0; i < cant;) {
		int posX = (rand() % (COLUMNA - 2) + 2) * CUADRO;
		int posY = (rand() % (FILA - 2) + 2) * CUADRO;
		if (matrizMapa[posY / CUADRO][posX / CUADRO] == 0) {
			//matrizMapa[posY / CUADRO][posX / CUADRO] = 1;
			Animacion* a = new Animacion(48, 48, 0, 4, 4, 3, 1.0f);
			cofres.push_back(new Cofre(a, tCofre, posX, posY+8, false));
			i++;
		}
	}
}

Mapa::Mapa(){
	inicializar_matriz();
}
Mapa::Mapa(sf::Texture* terrenos, sf::Texture* naturales, sf::Texture* tEnemigos, sf::Texture &tCofre, TipoTerreno tipo){
	switch (tipo)
	{
	case TipoTerreno::GRASS:
		sprite.setTexture(terrenos[0]);
		break;
	case TipoTerreno::TIERRA:
		sprite.setTexture(terrenos[1]);
		break;
	case TipoTerreno::ARENA:
		sprite.setTexture(terrenos[2]);
		break;
	case TipoTerreno::ADOQUIN:
		sprite.setTexture(terrenos[3]);
		break;
	default:
		sprite.setTexture(terrenos[0]);
		break;
	}
	sprite.setTextureRect(sf::IntRect(0, 0, 1280, 720));
	inicializar_matriz();
	colocar_decoracion(naturales);
	colocar_enemigos(tEnemigos);
	colocar_cofres(tCofre);
}
Mapa::~Mapa(){
	for (int i = 0; i < FILA; i++)
		delete[] matrizMapa[i];
	delete[] matrizMapa;
}

int** Mapa::getMatriz() { return matrizMapa; }
std::vector<Cofre*> Mapa::getCofres() { return cofres; }
std::vector<Enemigo*> Mapa::getEnemigos() { return enemigos; }

void Mapa::dibujar_fondo(sf::RenderWindow& w){
	w.draw(sprite);
}

void Mapa::dibujar_decoracion(sf::RenderWindow& w) {
	for (Naturaleza* n : decoracion)
		n->dibujar(w);
}

void Mapa::dibujar_enemigos(sf::RenderWindow& w) {
	for (Enemigo* e : enemigos)
		e->dibujar(w, matrizMapa);
}

void Mapa::dibujar_cofres(sf::RenderWindow& w) {
	for (Cofre* c : cofres)
		c->dibujar(w);
}