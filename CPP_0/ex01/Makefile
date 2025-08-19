# ========================
# 📁 Makefile - ex01
# ========================

NAME    = PhoneBook
CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCDIR  = .
OBJDIR  = obj

SRC     = $(SRCDIR)/main.cpp \
          $(SRCDIR)/Contact.cpp \
          $(SRCDIR)/PhoneBook.cpp

OBJ     = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re