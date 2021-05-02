/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_err_colres.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 09:18:33 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/04/28 14:13:54 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	copy_res(int time, int ct, char **str, char **ln)
{
	char	*tmpOne;
	char	*tmpTwo;

	(*str) = ft_strdup("");
	if ((*ln)[ct] == 'R')
		ct++;
	while ((*ln)[ct] == ' ' || (*ln)[ct] == '\t')
		ct++;
	while ((*ln)[ct] != ' ' && (*ln)[ct] != '\t' && (*ln)[ct] != '\0')
	{
		if ((*ln)[ct] < '0' || (*ln)[ct] > '9')
			ft_error("Error: Resolucion con letras\n");
		tmpOne = (*str);
		tmpTwo = ft_charstr((*ln)[ct++]);
		(*str) = ft_strjoin(*str, tmpTwo);
		free(tmpOne);
		free(tmpTwo);
	}
	while (((*ln)[ct] == ' ' || (*ln)[ct] == '\t')
		&& (*ln)[ct] != '\0')
		ct++;
	if (((*ln)[ct] == '\0' && time == 1)
		|| ((*ln)[ct] != '\0' && time == 2))
		ft_error("Error: Resolución necesita 2 valores\n");
	return (ct);
}

void	cb_copy_path(int count, char **str, char **line)
{
	char	*tmpOne;
	char	*tmpTwo;

	(*str) = ft_strdup("");
	while (((*line)[count] != ' ' || (*line)[count] != '\t')
		&& (*line)[count] != '\0')
	{
		tmpOne = (*str);
		tmpTwo = ft_charstr((*line)[count++]);
		(*str) = ft_strjoin(*str, tmpTwo);
		free(tmpOne);
		free(tmpTwo);
	}
	while ((*line)[count] != '\0')
	{
		if ((*line)[count] != ' ' && (*line)[count] != '\t')
			ft_error("Error: Elemento con formato incorrecto\n");
		count++;
	}
}

void	cb_err_resolution(char **line, t_elem *elems)
{
	char	*str;
	int		count;

	if (elems->rep.re == 1)
		ft_error("Error: Resolucion repetida\n");
	elems->rep.re = 1;
	count = 1;
	while (((*line)[count] == ' ' || (*line)[count] == '\t')
		&& (*line)[count] != '\0')
		count++;
	if ((*line)[count] == '\0')
		ft_error("Error: Resolucion Incorrecta\n");
	count = copy_res(1, count, &str, line);
	elems->res.x_axis = ft_atoi(str);
	free(str);
	count = copy_res(2, count, &str, line);
	elems->res.y_axis = ft_atoi(str);
	free(str);
	str = NULL;
	if (elems->res.x_axis <= 0 || elems->res.y_axis <= 0)
		ft_error("Error: Resolucion invalida\n");
}

void	cb_err_floor(char **line, t_elem *elems)
{
	char	*str;
	int		count;
	int		red;
	int		green;

	if (elems->rep.fl == 1)
		ft_error("Error: Textura Suelo repetida\n");
	elems->rep.fl = 1;
	count = 0;
	while ((*line)[count] == ' ' || (*line)[count] == '\t')
		count++;
	count += 1;
	while (((*line)[count] == ' ' || (*line)[count] == '\t')
		&& (*line)[count] != '\0')
		count++;
	if ((*line)[count] == '\0')
		ft_error("Error: Textura Suelo sin ruta\n");
	cb_copy_path(count, &str, line);
	elems->color.floor = str;
	elems->color.fl_blue = cb_look_color(&red, &green, str);
	elems->color.fl_green = green;
	elems->color.fl_red = red;
}

void	cb_err_ceiling(char **line, t_elem *elems)
{
	char	*str;
	int		count;
	int		red;
	int		green;

	if (elems->rep.cl == 1)
		ft_error("Error: Textura Techo repetida\n");
	elems->rep.cl = 1;
	count = 0;
	while ((*line)[count] == ' ' || (*line)[count] == '\t')
		count++;
	count += 1;
	while (((*line)[count] == ' ' || (*line)[count] == '\t')
		&& (*line)[count] != '\0')
		count++;
	if ((*line)[count] == '\0')
		ft_error("Error: Textura Techo sin ruta\n");
	cb_copy_path(count, &str, line);
	elems->color.ceiling = str;
	elems->color.cl_blue = cb_look_color(&red, &green, str);
	elems->color.cl_green = green;
	elems->color.cl_red = red;
}
