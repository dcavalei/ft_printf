# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/25 17:05:20 by dcavalei          #+#    #+#              #
#    Updated: 2021/04/06 12:28:50 by dcavalei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= ft_printf.c ${shell find src -type f -name "*.c"}
HEADERS		= ${shell find includes -type f -name "*.h"}
OBJS		= ${SRC:.c=.o}
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
NAME		= libftprintf.a
LIB			= ar -rcs
RM			= rm -f
RED			= \033[0;31m
GREEN		= \033[0;32m
ORANGE		= \033[0;33m
BLUE		= \033[1;34m
YELLOW		= \033[1;33m
NC			= \033[0m

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${LIB} ${NAME} ${OBJS}

bonus:		all

clean:
			${RM} ${OBJS}
			
fclean:		clean
			${RM} ${NAME}

re:			fclean all

norm:
			@echo "\n${YELLOW}Checking norminette:${NC}\n"
			@norminette ${SRC} ${HEADERS} \
			| sed s/OK!/`printf "${GREEN}OK!${NC}"`/ \
			| sed s/KO!/`printf "${RED}KO!${NC}"`/

test:
			@cd 42TESTERS-PRINTF && bash runtest.sh && cd .. || echo "${RED}!!!TEST ATTEMPT FAILED!!!${NC}"
			@make -C printfTester || echo "${RED}!!!TEST ATTEMPT FAILED!!!${NC}"

ft:		test norm

.PHONY:		all clean fclean re
