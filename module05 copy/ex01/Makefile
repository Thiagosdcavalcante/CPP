WHITE := \033[1;37m
RED := \033[1;31m
GREEN := \033[1;32m
YELLOW := \033[1;33m
CYAN := \033[1;36m
RESET := \033[0m

NAME = ex01A
CC = c++
FLAGS = -Werror -Wall -Wextra -std=c++98
MAKEFLAGS += --silent

SRCS = main.cpp sources/Bureaucrat.cpp sources/Form.cpp sources/tests.cpp

OBJS_DIR = objs
OBJS = $(SRCS:.cpp=.o)
OBJS := $(addprefix $(OBJS_DIR)/, $(notdir $(OBJS)))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)   Compilando arquivos...$(RESET)"
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)   Tudo pronto!$(RESET)"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR)/%.o: sources/%.cpp | $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)   Limpando objetos...$(RESET)"
	@rm -rf $(OBJS_DIR)/*.o
	@rm -rf objs

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
