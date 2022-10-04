NAME1	= server
NAME2	= client
SRCS1	= server.c
SRCS2	= client.c
OBJS1	= server.o
OBJS2	= client.o
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@


all:$(NAME1) $(NAME2)

$(NAME1):$(OBJS1)
		$(CC) $(CFLAGS) -o $(NAME1) $(OBJS1)

$(NAME2):$(OBJS2)
		$(CC) $(CFLAGS) -o $(NAME2) $(OBJS2)

clean:
		$(RM) $(OBJS1)
		$(RM) $(OBJS2)

fclean :	clean
		$(RM) $(NAME1)
		$(RM) $(NAME2)

re		:fclean all

.PHONY: all clean fclean re

