NAME = libft.a
SRCS = 	ft_calloc.c \
		ft_memset.c \
		ft_split.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strjoin.c \
		ft_strrchr.c \
		ft_strdup.c \
		ft_free.c \
		ft_free_tab.c \
		ft_strcmp.c \
		ft_putstr_fd.c \
		get_next_line.c \
		get_next_line_utils.c \
		
OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
	@ar rc ${NAME} ${OBJS} 
.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	@${RM} ${OBJS} ${B_OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re 