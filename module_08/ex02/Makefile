RED					= $(shell tput setaf 1)
GREEN				= $(shell tput setaf 2)
BLUE				= $(shell tput setaf 4)
RESET				= $(shell tput sgr0)

NAME				= mutatedAbomination
INCLUDES 			= -I
FILES				= $(wildcard *.cpp)
OBJS				= $(FILES:%.cpp=%.o)
COMPILER			= c++
CFLAGS				= -Wall -Wextra -Werror -std=c++98

all: 				$(NAME)

$(NAME):			$(OBJS)
					@$(COMPILER) $(CFLAGS) $(OBJS) -o $(NAME)
					@echo "$(BLUE)Compiled $(NAME) successfully$(RESET)"

%.o:				%.cpp
					@$(COMPILER) $(CFLAGS) -c $< -o $@
					@echo "$(GREEN)Compiled$(RESET) $(notdir $<)"

clean:
					@echo "$(RED)Removing$(RESET) $(NAME) objects"
					@rm -rf $(OBJS)

fclean: 			clean
					@echo "$(RED)Removing$(RESET) $(NAME)"
					@rm -rf $(NAME)

re:					fclean all

.PHONY: 			all clean fclean re