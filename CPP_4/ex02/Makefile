NAME	=	ex02
COMP	=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCDIR	=	.
OBJDIR	=	obj

SRC		= 	$(SRCDIR)/main.cpp \
			$(SRCDIR)/Animal.cpp \
			$(SRCDIR)/Cat.cpp \
			$(SRCDIR)/Dog.cpp \
			$(SRCDIR)/WrongAnimal.cpp \
			$(SRCDIR)/WrongCat.cpp \
			$(SRCDIR)/Brain.cpp

OBJ		=	$(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(COMP) $(FLAGS) -o $(NAME) $(OBJ)

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(COMP) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re