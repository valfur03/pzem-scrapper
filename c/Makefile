NAME		= pzem
SRCS		= $(addprefix srcs/, main.c)
OBJS		= $(SRCS:.c=.o)
INCL		= -Iincludes
LIBS		= -lmodbus
CC			= clang
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

%.o:		%.c
			$(CC) $(CFLAGS) $(INCL) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $^ -o $@ $(LIBS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re