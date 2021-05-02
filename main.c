/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:37:19 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/04/30 16:41:33 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *str)
{
	ft_printf("\033[0;31mError\n");
	ft_printf("%s", str);
	ft_printf("\n\n\033[0m");
	exit(0);
}

static void	init_rep_struct(t_elem *elems)
{
	elems->rep.re = 0;
	elems->rep.no = 0;
	elems->rep.so = 0;
	elems->rep.ea = 0;
	elems->rep.we = 0;
	elems->rep.sp = 0;
	elems->rep.fl = 0;
	elems->rep.cl = 0;
}

int	main(int argc, char *argv[])
{
	t_elem	elems;
	t_map	map;
	char	*tmp;
	int		verif;

	verif = -1;
	if (argc == 3)
		verif = ft_strncmp(argv[2], "--save", 7);
	if (argc == 2 || (argc == 3 && verif == 0))
	{
		tmp = ft_strnstr(argv[1], ".cub", ft_strlen(argv[1]));
		if (tmp && ft_strncmp(tmp, ".cub", ft_strlen(tmp)) == 0)
		{
			init_rep_struct(&elems);
			cb_check_elements(argv[1], &elems);
			cb_check_map(argv[1], &map);
			cb_create_map(argv[1], &map);
			cb_cub(verif, &elems, &map);
			exit(0);
		}
		ft_error("Error: Descripcion .cub no encontrada\n");
	}
	ft_error("Error: Numero de argumentos invalidos\n");
}
