# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kandeol <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/23 15:57:17 by kandeol           #+#    #+#              #
#    Updated: 2018/03/16 15:13:41 by kandeol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = ./srcs/core/main.c\
	   ./srcs/core/reader.c\
	   ./srcs/core/draw.c\
	   ./srcs/rotation/calculation.c\
	   ./srcs/rotation/calcul_rot_2.c\
	   ./srcs/projection/projection.c\
	   ./srcs/zoom/zoom.c\
	   ./srcs/rotation/rotate.c\
	   ./srcs/translation/translation.c\
	   ./srcs/translation/calcul_trans.c\
	   ./srcs/projection/calcul_proj.c\
	   ./srcs/hud/hud.c\
	   ./srcs/core/free_map.c\
	   ./srcs/core/check.c\
	   ./srcs/core/deal_key.c

OBJS = $(SRCS:.c=.o)

INCLUDE = -I include

FLAGS = #-Wall -Wextra -Werror

LIBMLX = ./minilibx_macos/

LIBFT = ./libft/

LIB = -L./minilibx_macos/ -lmlx\
		-L./libft/ -lft

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBMLX)
	@make -C $(LIBFT)
	gcc -g $(LIB) $^ -o $@ $(INCLUDE) -framework OpenGl -framework AppKit

clean:
	@make clean -C $(LIBFT)
	@rm -f $(OBJS)

fclean: clean
	@make clean -C $(LIBMLX)
	@make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

%.o: %.c
	@gcc -c $< -o $@ $(FLAGS) $(INCLUDE)

.PHONY: all clean fclean re

#######################

fsanit: $(OBJS)
	@make -C $(LIBMLX)
	@make -C $(LIBFT)
	gcc -g -fsanitize=address $(LIB) $^ -o $@ $(INCLUDE) -framework OpenGl -framework AppKit
