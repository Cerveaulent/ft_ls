# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/14 17:47:09 by eschnell     #+#   ##    ##    #+#        #
#    Updated: 2019/09/04 14:50:56 by eschnell    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME	= libft.a
DNAME	= libft.so
CC		= gcc
FLAGS	= -g -Wall -Werror -Wextra 
CFLAGS	= $(FLAGS) -Iincludes
subdirs := $(wildcard lib*/)
FILES	:= $(wildcard $(addsuffix *.c,$(subdirs)))
OBJS	:= $(patsubst %.c,%.o,$(FILES))

GREEN	= \033[32m
RED		= \033[31m
RESET	= \033[0m

all: $(NAME)

# This won't run if the .o files don't exist or are not modified
#so
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(shell find . -name "*.o")
	@ranlib $(NAME)
	@printf "✅$(GREEN)     LIBFT COMPILED$(RESET)\n"

so:
	@gcc -shared -fpic -o libft.so *.o -lc

$(OBJ): %.o : %.c

clean:
	@rm -f lib*/*.o
	@printf "🔴$(RED)     object files deleted$(RESET)\n"

fclean: clean
	@rm -f $(NAME) $(DNAME)
	@printf "🔴$(RED)     $(NAME) && $(DNAME) deleted$(RESET)\n"

re: fclean all

.PHONY: clean fclean all re
