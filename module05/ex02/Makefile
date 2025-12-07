
WHITE := \033[1;37m

NAME = ex01
CC = c++
FLAGS = -Werror -Wall -Wextra -std=c++98
MAKEFLAGS += --silent

SRCS = main.cpp tests.cpp sources/Bureaucrat.cpp sources/Form.cpp

OBJS_DIR = objs
OBJS = $(SRCS:.cpp=.o)
OBJS := $(addprefix $(OBJS_DIR)/, $(notdir $(OBJS)))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(WHITE)   Compilando arquivos... "
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)
	@echo "$(WHITE) Tudo pronto!"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR)/%.o: sources/%.cpp | $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR)/%.o: tests/%.cpp | $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)/*.o
	@rm -rf objs

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re