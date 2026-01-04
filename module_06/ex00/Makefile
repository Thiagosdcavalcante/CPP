RED                 = $(shell tput setaf 1)
GREEN               = $(shell tput setaf 2)
BLUE                = $(shell tput setaf 4)
RESET               = $(shell tput sgr0)

NAME                = convert
COMPILER            = c++
CFLAGS              = -Wall -Wextra -Werror -std=c++98

FILES               = main.cpp ScalarConverter.cpp
HEADERS             = ScalarConverter.hpp
OBJS                = $(FILES:%.cpp=%.o)

all:                $(NAME)

$(NAME):            $(OBJS)
					@$(COMPILER) $(CFLAGS) $(OBJS) -o $(NAME)
					@echo "$(GREEN)✨ $(NAME) compilado com sucesso!$(RESET)"

%.o:                %.cpp $(HEADERS)
					@$(COMPILER) $(CFLAGS) -c $< -o $@
					@echo "$(BLUE)✔ Compilado:$(RESET) $(notdir $<)"

clean:
					@rm -rf $(OBJS)
					@echo "$(RED)Cleaning:$(RESET) Arquivos objetos removidos."

fclean:             clean
					@rm -rf $(NAME)
					@echo "$(RED)Full Clean:$(RESET) Executável $(NAME) removido."

re:                 fclean all

.PHONY:             all clean fclean re