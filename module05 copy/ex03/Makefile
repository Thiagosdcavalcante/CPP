NAME = ex03
CC = c++
FLAGS = -Werror -Wall -Wextra -std=c++98

SRCS = main.cpp sources/Bureaucrat.cpp sources/AForm.cpp \
	sources/ShrubberyCreationForm.cpp sources/RobotomyRequestForm.cpp sources/PresidentialPardonForm.cpp \
	sources/Intern.cpp sources/tests.cpp

OBJS_DIR = objs
OBJS = $(SRCS:.cpp=.o)
OBJS := $(addprefix $(OBJS_DIR)/, $(notdir $(OBJS)))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "   Compilando ex03..."
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)
	@echo "   Pronto: $(NAME)"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR)/%.o: sources/%.cpp | $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)/*.o
	@rm -rf objs

fclean: clean
	@rm -f $(NAME)
	@echo "   Removendo arquivos de teste gerados..."
	@rm -f *_shrubbery || true

re: fclean all

.PHONY: all clean fclean re
