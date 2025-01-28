/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmelag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:46:14 by carmelag          #+#    #+#             */
/*   Updated: 2025/01/28 11:46:16 by carmelag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_map_rectangular(t_complete *game)
{
    int width;
    int i = 1;

    if (!game->map || !game->map[0])
        return(0);  // Mapa vacío
    while (game->map[i])
    {
        if (ft_strlen(game->map[i]) != game->width)  // Compara la longitud con la primera linea del mapa
            return(0);  // No es rectangular
        i++;
    }
    return(1);  // Es rectangular
}

int is_map_enclosed(t_complete *game)
{
    int i;

    if (!game->map || !game->map[0] || game->height < 1 || game->width < 1)
        return(0);
    i = 0;
    while (i < game->width)
    {
        if ((game->map[0][i] != '1') || (game->map[game->height - 1][i] != '1')) // Revisar la primera línea y última linea
            return(0);
        i++;
    }
    i = 0;
    while (i < game->height)
    {
        if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1') // Revisar las columnas de los bordes
            return(0);
        i++;
    }
    return(1); // El mapa está completamente encerrado
}

int count_elements(t_game *game, char element)
{
    int count = 0;
    int i = 0, j;

    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == element)
                count++;
            j++;
        }
        i++;
    }
    return count;
}

int validate_map_elements(t_game *game)
{
    int exits = count_elements(game, 'E');
    int starts = count_elements(game, 'P');
    int collectibles = count_elements(game, 'C');

    if (exits != 1)
    {
        printf("Error: Debe haber exactamente un 'E'.\n");
        return(0);
    }
    if (starts != 1)
    {
        printf("Error: Debe haber exactamente un 'P'.\n");
        return(0);
    }
    if (collectibles < 1)
    {
        printf("Error: Debe haber al menos un 'C'.\n");
        return(0);
    }
    return(1);  // Todo está correcto
}

int check_map(t_game *game)
{
    if (!is_map_rectangular(game))
    {
        printf("Error: El mapa no es rectangular.\n");
        return(0);
    }
    if (!is_map_enclosed(game))
    {
        printf("Error: El mapa no está rodeado por paredes.\n");
        return(0);
    }
    if (!validate_map_elements(game))
        return(0);
    if (!is_map_fully_accessible(game))
        return(0);
    return(1);
}
