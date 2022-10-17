
SRCS 			= ${wildcard ./sources/*.c}

OBJS 			= ${SRCS:.c=.o}

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

INCLUDE         = -I ./includes

NAME			= rush-02

all:			${NAME}

.c.o:
				@$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

$(NAME):		$(OBJS)
				@${CC}  ${CFLAGS} ${INCLUDE} -o ${NAME} ${OBJS}
				@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
				@${RM} ${OBJS}
				@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@${RM} ${NAME}
				@echo "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

.PHONY:			all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
