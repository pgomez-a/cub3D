/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 09:19:53 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/04/13 12:13:56 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ext_look_color(int tot, int count, char *color)
{
	int	del;

	if (color[count] == '\0')
		ft_error("Error: Formato RGB invalido\n");
	if ((color[count] < '0' || color[count] > '9'))
		ft_error("Error: Formato RGB invalido\n");
	count = 0;
	del = 0;
	while (color[count])
	{
		if (color[count] == ',')
			count++;
		if ((color[count] < '0' || color[count] > '9')
			&& (color[count] != ',' && del < 2)
			&& color[count] != ' ' && color[count] != '\t')
			ft_error("Error: Los colores no pueden tener letras\n");
		count++;
	}
	tot++;
	return (0);
}

static void	final_color(int count, char *str)
{
	while (str[count] == ' ' || str[count] == '\t')
		count++;
	if (str[count] != '\0')
		ft_error("Error: Solo se necesita un color\n");
}

void	cb_look_path(char *path)
{
	char	*tmp;
	int		fd;

	tmp = path;
	path = ft_strtrim(path, " \t");
	fd = open(path, O_RDONLY);
	free(tmp);
	if (fd < 0)
	{
		close(fd);
		ft_error("Error: Ruta de textura no encontrada\n");
	}
	tmp = ft_strnstr(path + ft_strlen(path) - 4, ".xpm", ft_strlen(path));
	if (!tmp || ft_strncmp(tmp, ".xpm", ft_strlen(tmp)) != 0)
	{
		tmp = ft_strnstr(path + ft_strlen(path) - 4, ".png", ft_strlen(path));
		if (!tmp || ft_strncmp(tmp, ".png", ft_strlen(tmp)) != 0)
			ft_error("Error: Extensión de textura invalida\n");
	}
	free(path);
	close(fd);
}

int	cb_look_color(int *red, int *green, char *color)
{
	int	tot;
	int	count;
	int	value;

	tot = 0;
	count = 0;
	while (tot < 3)
	{
		value = ext_look_color(tot, count, color);
		while (color[count] >= '0' && color[count] <= '9')
			value = (value * 10) + (color[count++] - '0');
		if ((tot < 2 && color[count] != ','))
			ft_error("Error: Color invalido\n");
		if (value < 0 || value > 255)
			ft_error("Error: Color fuera de parámetros\n");
		if (tot == 0)
			(*red) = value;
		else if (tot == 1)
			(*green) = value;
		count++;
		tot++;
	}
	count--;
	final_color(count, color);
	return (value);
}
