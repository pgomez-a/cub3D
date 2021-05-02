# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/02 10:19:24 by pgomez-a          #+#    #+#              #
#    Updated: 2021/05/02 10:19:26 by pgomez-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:	all clean fclean re

NAME	= cub3D

SRCS	= main.c			\
		  cb_errors.c		\
		  cb_err_txts.c		\
		  cb_err_colres.c	\
		  cb_err_map.c		\
		  cb_err_imap.c		\
		  cb_read_map.c 	\
		  cb_map_body.c 	\
		  cb_cub.c 			\
		  cb_save.c			\
		  cb_findspr.c		\
		  cb_renderframe.c	\
		  cb_textures.c		\
		  cb_texel.c		\
		  cb_sprites.c		\
		  cb_setdir.c 		\
		  cb_keypress.c 	\
		  cb_change_move.c	\
		  cb_change_rot.c	\
		  err_utils.c		\
		  utils.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

LIBS	= -L./libft/ -lft -L. -lmlx

FRAMES	= -framework OpenGl -framework AppKit

MLX		= libmlx.dylib

$(NAME):	$(OBJS)
	make -C ./libft/
	make -C ./mlx/
	cp ./mlx/$(MLX) .
	$(CC) $(CFLAGS) $(LIBS) $(FRAMES) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
	make clean -C ./libft/
	make clean -C ./mlx/
	rm -f $(OBJS)

fclean:		clean
	make fclean -C ./libft/
	rm -f $(NAME) $(MLX)

re:			fclean $(NAME)
