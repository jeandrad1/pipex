# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 13:23:39 by jeandrad          #+#    #+#              #
#    Updated: 2024/07/27 13:23:42 by jeandrad         ###   ########.fr        #
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

# Source files prepended with directory and appended with .c
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

# Object directory for mandatory source files
OBJS_DIR = ./obs/

# Source files prepended with directory and appended with .o
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

# Ensure the object directory exists
$(OBJS_DIR):
    @mkdir -p $(OBJS_DIR)

# Compile rule
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
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

# Re rule
re: fclean all

.PHONY = all clean fclean re libft