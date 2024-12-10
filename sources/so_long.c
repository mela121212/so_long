#include "so_long.h"

main(int argc, char **argv)
{
    t_game  game; //es la variable directa, NO un puntero (se usa . para acceder a las variables)

    if (argc != 2)
        return(0);
    //inicializar con 0 todas las varibles de game con memsset;
    read_map(&game, *argv);
    //ERRORs
}