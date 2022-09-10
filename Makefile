# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 14:22:14 by asokolov          #+#    #+#              #
#    Updated: 2022/06/17 01:04:09 by asokolov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

BONUS = pipex_bonus

CFLAGS = -Wall -Wextra -Werror

CC = gcc

MA_SRC =	main.c                      \
			utils.c                     \
			open_files.c                \
			path.c                      \
			errors.c                    \
			main_process.c

BO_SRC =	main_bonus.c                \
			utils_bonus.c               \
			open_files_bonus.c          \
			path_bonus.c                \
			errors_bonus.c              \
			main_process_bonus.c

LB_SRC =	ft_strjoin.c                \
			ft_strlen.c                 \
			ft_strnstr.c                \
			ft_substr.c                 \
			ft_strncmp.c                \
			ft_split.c                  \
			ft_calloc.c                 \
			ft_memset.c                 \
			ft_memmove.c                \
			ft_memcpy.c                 \
			ft_putstr_fd.c

GL_SRC =	get_next_line.c             \
			get_next_line_utils.c

MA_OBJS = $(MA_SRC:.c=.o)
LB_OBJS = $(LB_SRC:.c=.o)
BO_OBJS = $(BO_SRC:.c=.o)
GL_OBJS = $(GL_SRC:.c=.o)

MA_DEPENDENCES = $(MA_OBJS:.o=.d)
LB_DEPENDENCES = $(LB_OBJS:.o=.d)
BO_DEPENDENCES = $(BO_OBJS:.o=.d)
GL_DEPENDENCES = $(GL_OBJS:.o=.d)

MA_PATH = mandatory_pipex/
LB_PATH = libft/
BO_PATH = bonus_pipex/
GL_PATH = get_next_line/

$(NAME): 	$(addprefix $(MA_PATH), $(MA_OBJS)) $(addprefix $(LB_PATH), $(LB_OBJS))
			$(CC) $(CFLAGS) -o $@ $^

$(BONUS): 	$(addprefix $(BO_PATH), $(BO_OBJS)) $(addprefix $(LB_PATH), $(LB_OBJS)) $(addprefix $(GL_PATH), $(GL_OBJS))
			$(CC) $(CFLAGS) -o ${BONUS} $^
			
all: $(NAME)

bonus: $(BONUS)

clean: 
	rm -f	$(addprefix $(MA_PATH), $(MA_OBJS)) \
			$(addprefix $(LB_PATH), $(LB_OBJS)) \
			$(addprefix $(BO_PATH), $(BO_OBJS)) \
			$(addprefix $(GL_PATH), $(GL_OBJS)) \
			$(addprefix $(MA_PATH), $(MA_DEPENDENCES)) \
			$(addprefix $(LB_PATH), $(LB_DEPENDENCES)) \
			$(addprefix $(BO_PATH), $(BO_DEPENDENCES)) \
			$(addprefix $(GL_PATH), $(GL_DEPENDENCES))

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

rebonus: fclean bonus

.PHONY: all bonus clean fclean re rebonus
