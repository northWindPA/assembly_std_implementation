NAME	=	libasm.a

SRC		=	ft_strlen.s ft_write.s ft_read.s ft_strcpy.s ft_strdup.s ft_strcmp.s

OBJ		=	$(SRC:.s=.o)

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

%.o		:	%.s
	nasm -f macho64 $< -o $@

$(NAME)	:	$(OBJ)
			ar rcs $(NAME) $(OBJ)

all		:	$(NAME)

test	:	all
			$(CC) $(FLAGS) ./main.c $(NAME) -o compfile

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)
			rm -f compfile

re		:	fclean all

.PHONY	:	all clean fclean re