#include "so_long.h"

int main(int argc, char **argv)
{
    t_game  game; //es la variable directa, NO un puntero (se usa . para acceder a las variables)

    if (argc != 2)
        return(0);
    ft_memset(&game, 0, sizeof(t_game));
    read_map(&game, *argv);
    check_map(game); //checkear errores
    check_path(game); //checkea si el oath se puede hacer
    game.mlxpointer = mlx_init(); //inicializa mlbx
    game.winpointer = mlx_new_window(game.mlxpointer, (game.widthmap * 40), (game.heightmap * 40), "solong"); //abre ventana (cada casilla del mapa es de 40x40 píxeles)
    load_images(&game);
    render(&game);

    // Registrar el manejador de eventos de teclas
    mlx_key_hook(game.winpointer, ft_press_key, &game);

    // Iniciar el bucle de eventos de mlx
    mlx_loop(game.mlxpointer);

    return(0);

}