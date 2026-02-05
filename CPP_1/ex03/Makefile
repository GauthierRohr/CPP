NAME	=	ex03
COMP	=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCDIR	=	.
OBJDIR	=	obj

SRC		=	$(SRCDIR)/main.cpp \
			$(SRCDIR)/Weapon.cpp \
			$(SRCDIR)/HumanA.cpp \
			$(SRCDIR)/HumanB.cpp

OBJ		=	$(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(COMP) $(FLAGS) -o $(NAME) $(OBJ)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(COMP) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re