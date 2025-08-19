NAME = megaphone
COMP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp
OBJDIR = obj
OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)

all : $(NAME)

#### 2ème étape ####
# Crée le binaire à partir des .o = l'exécutable
# Tu prends tous les .o et tu les LINKES ensemble → ça donne le binaire exécutable.
$(NAME) : $(OBJ)
	$(COMP) $(FLAGS) -o $(NAME) $(OBJ)

#### 1ère étape ####
# Compile chaque .cpp en .o dans le dossier obj/ :
# 	Transforme chaque fichier .cpp en fichier .o (objet).
# 	Ce .o contient du code machine partiel, pas encore exécutable.
# 	C'est rapide à recompiler si un seul .cpp change.
#
# -p : on le crée sans erreur s'il existe déjà
# -c : compile sans linker : .cpp → .o seulement
# $< : premier fichier de dépendance
# $@ : le nom de la cible (ex: obj/megaphone.o)
$(OBJDIR)/%.o: %.cpp
	mkdir -p $(OBJDIR)
	$(COMP) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

# Dans un Makefile, une règle a cette forme :
#
# target: dependencies
#	commands
#
###############################
# En écrivant $(NAME): $(SRC), ça dit à Make :
#
# “Je veux créer le fichier $(NAME), et il dépend des fichiers $(SRC).
# S’ils changent, je dois recompiler.” <<<<<<<<<<<<< IMPORTANT
###############################
# Si j'écris juste :
#
# $(NAME):
#	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRC)
#
# Make ne saura pas que le binaire dépend des .cpp.
# Du coup si je modifie megaphone.cpp, Make ne recompile pas car il ne voit aucune dépendance déclarée.