/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmelag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:46:23 by carmelag          #+#    #+#             */
/*   Updated: 2025/01/28 11:46:26 by carmelag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void flood_fill(char **map, int x, int y, t_game *game)
{
    if (x < 0 || y < 0 || x >= game->width || y >= game->height)  // Corregido a game->width y game->height
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

void check_path(t_game *game)  // Cambio aquí, el argumento ahora es un puntero a t_game
{
    char **map_copy;
    int x = 0;
    int y = 0;

    map_copy = copy_map(game->map, game->width, game->height);  // Corregido a game->width y game->height
    flood_fill(map_copy, game->x, game->y, game);  // Corregido a game (sin &)
    while (y < game->height)  // Corregido a game->height
    {
        x = 0;
        while (x < game->width)  // Corregido a game->width
        {
            if (game->map[y][x] == 'C' && map_copy[y][x] != 'F')
            {
                free_map(map_copy, game->height);
                write(2, "Error: No se puede acceder a todos los coleccionables.\n", 52);
                exit(1);
            }
            if (game->map[y][x] == 'E' && map_copy[y][x] != 'F')
            {
                free_map(map_copy, game->height);
                write(2, "Error: No se puede acceder a la salida.\n", 40);
                exit(1);
            }
            x++;
        }
        y++;
    }
    free_map(map_copy, game->height);
}

