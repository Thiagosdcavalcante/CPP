NAME = ex02
CC = c++
FLAGS = -Werror -Wall -Wextra -std=c++98

# ANSI colors for make output
CLR_HEADER := \033[1;36m
CLR_SUCCESS := \033[1;32m
CLR_ERROR := \033[1;31m
CLR_RESET := \033[0m

SRCS = main.cpp sources/Bureaucrat.cpp sources/AForm.cpp \
       sources/ShrubberyCreationForm.cpp sources/RobotomyRequestForm.cpp sources/PresidentialPardonForm.cpp

OBJS_DIR = objs
OBJS = $(SRCS:.cpp=.o)
OBJS := $(addprefix $(OBJS_DIR)/, $(notdir $(OBJS)))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CLR_HEADER)   Compilando ex02...$(CLR_RESET)"
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) || (echo "$(CLR_ERROR)   Build falhou$(CLR_RESET)"; exit 1)
	@echo "$(CLR_SUCCESS)   Pronto: $(NAME)$(CLR_RESET)"

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
