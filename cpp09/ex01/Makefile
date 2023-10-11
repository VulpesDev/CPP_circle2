CC = c++

CFLAGS = 

NAME = RPN

SRC = main.cpp RPN.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

.cpp.o:
	$(CC) $(CFLAGS) -g3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	-rm -f $(OBJ)

fclean: clean
	-rm -f $(NAME)

re: fclean all