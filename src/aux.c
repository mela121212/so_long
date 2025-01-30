/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmelag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:46:03 by carmelag          #+#    #+#             */
/*   Updated: 2025/01/28 11:46:06 by carmelag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char *p;

	p = (char *)b;
	while (len > 0)
	{
		*p = c;
		p++;
		len--;
	}
	return (b);
}

void ft_putstr_fd(char *str, int fd)
{
    if (!str)
        return;
    write(fd, str, ft_strlen(str));
}

void ft_putendl_fd(char *str, int fd)
{
    if (!str)
        return;
    ft_putstr_fd(str, fd);
    write(fd, "\n", 1);
}

/*int	ft_strlen(const char *s)
{
	size_t	i; //un size_t o un int??

	i = 0;
	while ((s[i] != '\0') || (s[i] != '\n'))
		i++;
	return (i);
}*/

void free_map(char **map, int height)
{
    int y = 0;

    while (y < height)
    {
        free(map[y]);
        y++;
    }
    free(map);
}
