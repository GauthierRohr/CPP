NAME	=	ex01
COMP	=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCDIR	=	.
OBJDIR	=	obj

SRC		= 	$(SRCDIR)/ClapTrap.cpp \
			$(SRCDIR)/ScavTrap.cpp \
			$(SRCDIR)/main.cpp

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
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re