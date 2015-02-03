
.PHONY: clean fclean re

NAME =	test.exe

FLAGS =	-Wall -Wextra -Werror

CC = g++

SRC =	main.cpp \
		card.cpp \
		player.cpp \
		statistique.cpp \
		table.cpp

OBJ =	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ)  -o $(NAME)
	@rm -f $(OBJ)
	@echo Compilation OK

%.o: %.cpp
	@gcc -o $@ -c $< $(FLAGS)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
