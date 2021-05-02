#include "cub3d.h"

void	cb_north_texture(t_data *dt)
{
	int	count;
	int	verif;

	count = ft_strlen(dt->nor.path) - 3;
	verif = ft_strncmp(dt->nor.path + count, "xpm", count);
	if (verif == 0)
		dt->nor.img = mlx_xpm_file_to_image(dt->mlx.mlx, dt->nor.path,
				&dt->nor.width, &dt->nor.height);
	else
		dt->nor.img = mlx_png_file_to_image(dt->mlx.mlx, dt->nor.path,
				&dt->nor.width, &dt->nor.height);
	dt->nor.addr = mlx_get_data_addr(dt->nor.img,
			&dt->nor.bpp, &dt->nor.length, &dt->nor.endian);
}

void	cb_south_texture(t_data *dt)
{
	int	count;
	int	verif;

	count = ft_strlen(dt->sou.path) - 3;
	verif = ft_strncmp(dt->sou.path + count, "xpm", 3);
	if (verif == 0)
		dt->sou.img = mlx_xpm_file_to_image(dt->mlx.mlx, dt->sou.path,
				&dt->sou.width, &dt->sou.height);
	else
		dt->sou.img = mlx_png_file_to_image(dt->mlx.mlx, dt->sou.path,
				&dt->sou.width, &dt->sou.height);
	dt->sou.addr = mlx_get_data_addr(dt->sou.img,
			&dt->sou.bpp, &dt->sou.length, &dt->sou.endian);
}

void	cb_east_texture(t_data *dt)
{
	int	count;
	int	verif;

	count = ft_strlen(dt->eas.path) - 3;
	verif = ft_strncmp(dt->eas.path + count, "xpm", 3);
	if (verif == 0)
		dt->eas.img = mlx_xpm_file_to_image(dt->mlx.mlx, dt->eas.path,
				&dt->eas.width, &dt->eas.height);
	else
		dt->eas.img = mlx_png_file_to_image(dt->mlx.mlx, dt->eas.path,
				&dt->eas.width, &dt->eas.height);
	dt->eas.addr = mlx_get_data_addr(dt->eas.img,
			&dt->eas.bpp, &dt->eas.length, &dt->eas.endian);
}

void	cb_west_texture(t_data *dt)
{
	int	count;
	int	verif;

	count = ft_strlen(dt->wes.path) - 3;
	verif = ft_strncmp(dt->wes.path + count, "xpm", 3);
	if (verif == 0)
		dt->wes.img = mlx_xpm_file_to_image(dt->mlx.mlx, dt->wes.path,
				&dt->wes.width, &dt->wes.height);
	else
		dt->wes.img = mlx_png_file_to_image(dt->mlx.mlx, dt->wes.path,
				&dt->wes.width, &dt->wes.height);
	dt->wes.addr = mlx_get_data_addr(dt->wes.img,
			&dt->wes.bpp, &dt->wes.length, &dt->wes.endian);
}

void	cb_sprite_texture(t_data *dt)
{
	int	count;
	int	verif;

	count = ft_strlen(dt->spr.path) - 3;
	verif = ft_strncmp(dt->spr.path + count, "xpm", 3);
	if (verif == 0)
		dt->spr.img = mlx_xpm_file_to_image(dt->mlx.mlx, dt->spr.path,
				&dt->spr.width, &dt->spr.height);
	else
		dt->spr.img = mlx_png_file_to_image(dt->mlx.mlx, dt->spr.path,
				&dt->spr.width, &dt->spr.height);
	dt->spr.addr = mlx_get_data_addr(dt->spr.img,
			&dt->spr.bpp, &dt->spr.length, &dt->spr.endian);
}
