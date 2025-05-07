NAME = push_swap

SRCS = src/algorithm.c \
		src/errors.c \
		src/initialisation.c \
		src/ps_lst.c \
		src/main.c \
		src/op_push.c \
		src/op_rev_rotate.c \
		src/op_rotate.c \
		src/op_swap.c \
		src/push_swap_utils.c \

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

OBJS = $(SRCS:.c=.o)

LIBC = ar rcs

LIBR = ranlib

$(NAME) : $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -o $@ $(OBJS) ./libft/libft.a 

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I .

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)


fclean : clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re 


