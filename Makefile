# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 13:23:39 by jeandrad          #+#    #+#              #
#    Updated: 2024/07/27 16:05:00 by jeandrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 13:23:39 by jeandrad          #+#    #+#              #
#    Updated: 2024/07/27 13:27:24 by jeandrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name: pipex
NAME = pipex

# Compiler
CC = clang

# Compiler flags
FLAGS = -Wall -Werror -Wextra -g -Iinclude 

# Source files for libft
LIBFT_PATH = ./libft

# Compiled libft
LIBFT = $(LIBFT_PATH)/libft.a

# Source files for mandatory
FILES =	pipex\
        init\
        parse\
        exec\
        exit_error\
        free\
        
# Source directory
SRCS_DIR = ./src/

# Object directory
OBJ_DIR = ./obj/

# Object directory
$(shell mkdir -p obj)

# Source files prepended with directory and appended with .c
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

# Object files prepended with directory and appended with .o
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

# Compile rule
$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@$(CC) $(FLAGS) -c $< -o $@

# Build rule for mandatory
$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "PIPEX created"

# Build rule for libft
$(LIBFT):
	@make -C $(LIBFT_PATH) all

# Build rule for mandatory
all: $(NAME)

# Clean rule
clean: 
	@rm -f $(OBJS)
	@make -C $(LIBFT_PATH) clean
	@echo "ALL clean"

# Fclean rule
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@echo "ALL fclean"
	@$(shell rm -rf obj)

# Re rule
re: fclean all

.PHONY = all clean fclean re libft