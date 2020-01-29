NAME = minishell
SRCS = read.c display_utilities.c arr_utils.c manipulate_env.c builtin_cmd.c\
		utility_funcs.c cd.c echo.c
LFT = Libft/libft.a
FLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME) : $(SRCS) $(LFT) 
	cc $(SRCS) $(LFT) $(FLAGS) -o minishell

clean: 
	make -C libft/ clean

fclean: clean
	rm -rf minishell
	make -C libft/ fclean

re:	fclean all
	make -C libft/ re

$(LFT):
	make -C libft/
