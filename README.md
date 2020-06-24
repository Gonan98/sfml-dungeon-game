# SFML-DUNGEON-GAME
Desarrollo de un juego en C++ y la libreria SFML

# Compilacion
Este proyecto debe compilarse con el compilador GNU (MingW para windows) y la libreria SFML.
Haga clic [aqui](https://sourceforge.net/projects/mingw-w64/files/) para ver las versiones del compilador.
Haga clic [aqui](https://www.sfml-dev.org/download/sfml/2.5.1/) para descargar la libreria SFML para el respectivo compilador.
Escoja la ultima version en el modo x86_64-posix-seh.
Deberá agregar el PATH la ruta al "bin"

## Comando
En una linea de comandos en el proyecto ejecute:
`g++ *.cpp -I<RutaDeSFML>/include -o ./bin/dungeon.exe -L/<RutaDeSFML>/lib -lsfml-graphics -lsfml-window -lsfml-system`
Este comando fue ejecutado usando el Git Bash.
Se creará un ejecutable dentro del directorio "bin" del proyecto y listo.
