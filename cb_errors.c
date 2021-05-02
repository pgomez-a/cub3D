/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erros.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:40:05 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/04/26 11:41:19 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_spc_tab(int ct, char v, char **ln, t_elem *elems)
{
	if (v == 'R' && ((*ln)[ct + 1] == ' ' || (*ln)[ct + 1] == '\t'))
		cb_err_resolution(ln, elems);
	else if (v == 'N' && ((*ln)[ct + 2] == ' ' || (*ln)[ct + 2] == '\t'))
		cb_err_north(ln, elems);
	else if (v == 'S' && ((*ln)[ct + 2] == ' ' || (*ln)[ct + 2] == '\t'))
		cb_err_south(ln, elems);
	else if (v == 'W' && ((*ln)[ct + 2] == ' ' || (*ln)[ct + 2] == '\t'))
		cb_err_west(ln, elems);
	else if (v == 'E' && ((*ln)[ct + 2] == ' ' || (*ln)[ct + 2] == '\t'))
		cb_err_east(ln, elems);
	else if (v == 'P' && ((*ln)[ct + 1] == ' ' || (*ln)[ct + 1] == '\t'))
		cb_err_sprite(ln, elems);
	else if (v == 'F' && ((*ln)[ct + 1] == ' ' || (*ln)[ct + 1] == '\t'))
		cb_err_floor(ln, elems);
	else if (v == 'C' && ((*ln)[ct + 1] == ' ' || (*ln)[ct + 1] == '\t'))
		cb_err_ceiling(ln, elems);
	else
		ft_error("Error: Formato no valido de textura/resolucion\n");
}

static void	get_struct(char **ln, t_elem *elems)
{
	int	ct;

	ct = 0;
	while ((*ln)[ct] == ' ' || (*ln)[ct] == '\t')
		ct++;
	if ((*ln)[ct] == 'R')
		get_spc_tab(ct, 'R', ln, elems);
	else if ((*ln)[ct] == 'N' && (*ln)[ct + 1] == 'O')
		get_spc_tab(ct, 'N', ln, elems);
	else if ((*ln)[ct] == 'S' && (*ln)[ct + 1] == 'O')
		get_spc_tab(ct, 'S', ln, elems);
	else if ((*ln)[ct] == 'W' && (*ln)[ct + 1] == 'E')
		get_spc_tab(ct, 'W', ln, elems);
	else if ((*ln)[ct] == 'E' && (*ln)[ct + 1] == 'A')
		get_spc_tab(ct, 'E', ln, elems);
	else if ((*ln)[ct] == 'S')
		get_spc_tab(ct, 'P', ln, elems);
	else if ((*ln)[ct] == 'F')
		get_spc_tab(ct, 'F', ln, elems);
	else if ((*ln)[ct] == 'C')
		get_spc_tab(ct, 'C', ln, elems);
	else
		ft_error("Error: Formato no valido de textura/resolucion\n");
}

static int	manage_identifier(int reads, int count, char **line, t_elem *elems)
{
	if (reads == -1 || !(*line))
		return (-1);
	if (reads == 0 && count < 7)
		ft_error("Error: Formato no valido de .cub\n");
	if (**line == '\0')
		return (0);
	get_struct(line, elems);
	return (1);
}

void	cb_check_elements(const char *str, t_elem *elems)
{
	char	*line;
	int		count;
	int		reads;
	int		fd;

	count = 0;
	reads = 1;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_error("Error: Mapa no encontrado\n");
	while (count < 8 && reads == 1)
	{
		reads = get_next_line(fd, &line);
		reads = manage_identifier(reads, count, &line, elems);
		free(line);
		if (reads == -1)
			ft_error("Error: Identificador invalido\n");
		if (reads == 1)
			count++;
		reads = 1;
	}
	while (get_next_line(fd, &line) == 1)
		free(line);
	free(line);
	close(fd);
}
