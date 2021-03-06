# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/19 15:14:41 by zminhas           #+#    #+#              #
#    Updated: 2021/02/19 17:12:21 by zminhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED			= $(shell tput -Txterm setaf 1)
GREEN		= $(shell tput -Txterm setaf 2)
YELLOW		= $(shell tput -Txterm setaf 3)
LIGHTPURPLE	= $(shell tput -Txterm setaf 4)
PURPLE		= $(shell tput -Txterm setaf 5)
BLUE		= $(shell tput -Txterm setaf 6)
WHITE		= $(shell tput -Txterm setaf 7)
RESET		= $(shell tput -Txterm sgr0)

SRCS	=	cub3d.c\
			srcs/ft_cub_display.c\
			srcs/ft_cub_get_info.c\
			srcs/ft_cub_key.c\
			srcs/ft_cub_map.c\
			srcs/ft_cub_move.c\
			srcs/ft_cub_rot.c\
			srcs/ft_cub_utils.c\
			gnl/get_next_line_utils.c\
			gnl/get_next_line.c

OBJS	=	${SRCS:.c=.o}			

NAME	=	cub3d.a

LIB_PATH	=	./libft

.c.o:
				@gcc -Wall -Wextra -Werror -c -I./ $< -o ${<:.c=.o}
				@echo "${LIGHTPURPLE}Compilation of :$<${RESET}"

$(NAME):		$(OBJS)
				@make -C $(LIB_PATH)
				@ar -rcs $(NAME) $(OBJS)
				@gcc -lmlx -framework OpenGL -framework AppKit $(NAME)
				@echo "${GREEN}cub3d.a created !${RESET}"

all:			$(NAME)

clean:			
				@rm -f $(OBJS)
				@make clean -C ${LIB_PATH}
				@echo "${YELLOW}Objects cleaned !${RESET}"

fclean:
				@rm -f ${OBJS}
				@rm -f ${NAME}
				@make fclean -C ${LIB_PATH}
				@echo "${RED}fclean done !${RESET}"

re:				fclean all

.PHONY:			all clean fclean re
