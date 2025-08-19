NAME	=	Zombie
COMP	=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCDIR	=	.
OBJDIR	=	obj

SRC		=	$(SRCDIR)/main.cpp \
			$(SRCDIR)/newZombie.cpp \
			$(SRCDIR)/randomChump.cpp \
			$(SRCDIR)/Zombie.cpp \

OBJ		= 	$(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(COMP) $(FLAGS) -o $(NAME) $(OBJ)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(COMP) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm $(NAME)

re: fclean all
