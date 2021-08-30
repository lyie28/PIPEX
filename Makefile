# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 15:28:45 by lyie              #+#    #+#              #
#    Updated: 2021/08/26 11:56:29 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	str_functions.c\
      	tools_3.c\
	ft_split.c\
	get_next_line.c\
	main.c\
	tools_2.c\
	tools.c\
	functions.c\
	get_next_line_utils.c

SRCS_BONUS = ft_split_bonus.c\
	     get_next_line_bonus.c\
     	     hello_doc_bonus.c\
	     main_bonus.c\
	     tools_2_bonus.c\
	     tools_bonus.c\
	     functions_bonus.c\
	     get_next_line_utils_bonus.c\
	     str_functions_bonus.c\
	     tools_3_bonus.c

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
INCLUDES = pipex.h
INCLUDES_BONUS = pipex_bonus.h
NAME = pipex
NAME_BONUS = pipex_bonus
CC = clang
RM = rm -f
BONUS = pipex


CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

$(NAME)	: ${OBJS}
	${CC} ${CFLAGS} -I${INCLUDES} ${OBJS} -o ${NAME}

$(NAME_BONUS): ${OBJS_BONUS}
	 ${CC} ${CFLAGS} -I${INCLUDES_BONUS} ${OBJS_BONUS} -o ${NAME_BONUS}

bonus: $(NAME_BONUS)
clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	${RM} ${NAME} ${NAME_BONUS}

re: fclean all

.PHONY: all clean fclean re
