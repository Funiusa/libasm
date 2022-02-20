SRCS =		ft_strlen.s ft_strcpy.s ft_strcmp.s ft_strdup.s ft_write.s ft_read.s

OBJ =		$(SRCS:%.s=%.o)

NAME =	libasm.a

%.o: %.s
	nasm -f macho64 $<

all:		$(NAME)


$(NAME):	$(OBJ)
			@ar -rc $(NAME) $(OBJ)
			@ranlib $(NAME)

run:	all
			@gcc main.c libasm.a -I libasm.h
			@./a.out

clean:
			@rm -f *.o
			@rm -f ./a.out
			@rm -f ./*txt

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re