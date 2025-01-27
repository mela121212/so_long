#include "so_long.h"

static void flood_fill(char **map, int x, int y, t_game *game)
{
    if (x < 0 || y < 0 || x >= game->widthmap || y >= game->heightmap)
        return;
    if (map[y][x] != '0' && map[y][x] != 'C' && map[y][x] != 'E')
        return;
    map[y][x] = 'F';
    flood_fill(map, x + 1, y, game); 
    flood_fill(map, x - 1, y, game); 
    flood_fill(map, x, y + 1, game);
    flood_fill(map, x, y - 1, game);
}

static char **copy_map(char **original, int width, int height)
{
    char **copy;
    int y;

    copy = (char **)malloc(sizeof(char *) * height);
    if (!copy)
    {
        write(2, "Error: No se pudo asignar memoria para la copia del mapa.\n", 52);
        exit(1);
    }
    y = 0;
    while (y < height)
    {
        copy[y] = (char *)malloc(sizeof(char) * (width + 1));
        if (!copy[y])
        {
            free_map(copy, y); 
            write(2, "Error: No se pudo asignar memoria para una fila del mapa.\n", 58);
            exit(1);
        }
        strcpy(copy[y], original[y]);
        y++;
    }
    return (copy);
}

void check_path(t_game game)
{
    char **map_copy;
    int x = 0;
    int y = 0;

    map_copy = copy_map(game.map, game.widthmap, game.heightmap);
    flood_fill(map_copy, game.player_x, game.player_y, &game);
    while (y < game.heightmap)
    {
        x = 0;
        while (x < game.widthmap)
        {
            if (game.map[y][x] == 'C' && map_copy[y][x] != 'F')
            {
                free_map(map_copy, game.heightmap);
                write(2, "Error: No se puede acceder a todos los coleccionables.\n", 52);
                exit(1);
            }
            if (game.map[y][x] == 'E' && map_copy[y][x] != 'F')
            {
                free_map(map_copy, game.heightmap);
                write(2, "Error: No se puede acceder a la salida.\n", 40);
                exit(1);
            }
            x++;
        }
        y++;
    }
    free_map(map_copy, game.heightmap);
}

