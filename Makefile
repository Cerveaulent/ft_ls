# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/13 14:34:18 by eschnell     #+#   ##    ##    #+#        #
#    Updated: 2019/09/30 18:34:08 by ccantin     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME		= ft_ls
CC			= gcc
FLAGS		= -Wall -Wextra -Werror -g3 #-fsanitize=address
INCLUDES	= -Iincludes -Ilibft/includes
CFLAGS		= $(FLAGS) $(INCLUDES)
LIB			= libft/libft.a
SRCS		= src/free_handler.c \
			src/ls_colours.c \
			src/ls_loop.c \
			src/ls_print_l.c \
			src/ls_usergroup_id.c \
			src/ft_countdozen.c \
			src/ls_filedirs.c \
			src/ls_padding_l.c \
			src/ls_print_permissions.c \
			src/ft_strjoinfree.c \
			src/ls_filedirs_re.c \
			src/ls_populate.c \
			src/ls_print_sl.c\
			src/ls_checks.c \
			src/ls_get_sl.c \
			src/ls_prepare_l.c \
			src/ls_print_total.c \
			src/ls_cmp_fdir.c \
			src/ls_isdir.c \
			src/ls_print.c \
			src/ls_sweeper.c \
			src/main.c \
			src/opts.c
OBJS	:= $(patsubst %.c,%.o,$(SRCS)) 
INC 	=	includes/colours.h \
			includes/ft_ls.h

all: $(LIB) $(NAME)

$(NAME): $(OBJS)
		 $(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)

$(OBJS): %.o : %.c $(INC)

$(LIB): 
		@make -s -C libft/
clean:
		@rm -f src/*.o

fclean: clean
		@rm -f $(NAME) 
		@make -C libft/ fclean


re: fclean all
