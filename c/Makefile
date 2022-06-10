NAME		= pzem
SRCS		= $(addprefix srcs/, config.c main.c)
OBJS		= $(SRCS:.c=.o)
INCL		= -I includes
CC			= clang
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

%.o:		%.c
			$(CC) $(CFLAGS) $(INCL) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $^ -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re