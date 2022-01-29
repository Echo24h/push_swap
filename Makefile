

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gborne <gborne@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 17:10:18 by dalves-p          #+#    #+#              #
#    Updated: 2022/01/24 04:50:17 by gborne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CC			=	gcc
SRCS		=	srcs/main.c \
				srcs/sort.c \
				srcs/sort_small_stack.c \
				srcs/check.c \
				srcs/box.c \
				srcs/pile.c \
				srcs/functions.c \
				srcs/functions_command.c \

SRCS_BONUS	=

LIBFT		=	libft/libft.a
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
OBJS		=	$(SRCS:%.c=%.o)
OBJS_BONUS	=	$(SRCS_BONUS:%.c=%.o)


all:		$(NAME)

$(NAME):	$(OBJS)
			make -C libft
			$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -o $(NAME)

%o:			%.c
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

sanitize: 	$(OBJS)
			make -C libft
			$(CC) $(OBJS) $(LIBFT) -g -fsanitize=address $(CFLAGS) -o $(NAME)

bonus: 		$(OBJS_BONUS)
			make -C libft
			$(CC) $(OBJS_BONUS) $(LIBFT) $(CFLAGS) -o $(NAME)

clean:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
			$(RM) $(NAME)
			$(RM) *.out
			make fclean -C libft/

re:			fclean all

test3:		all
			./push_swap 8 5 6

test5:		all
			./push_swap 8 5 6 14 84

git:
	@git add .
	@git commit -m "$m"
	@git push
	@echo "Commit sent to github"
# Para chamar: make git m="meu commit"

.PHONY:		all clean fclean re test sanitize
