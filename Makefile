SRC = push_swap.c utils/ft_lstlast.c \
 utils/ft_lstadd_back.c utils/ft_atoi.c \
 utils/ft_lstnew.c utils/ft_isdigit.c utils/ft_lstadd_front.c utils/ft_split.c \
 utils/ft_strdup.c utils/ft_substr.c utils/ft_strlen.c printf/ft_printf.c\
 printf/ft_printf_functions.c utils/ft_lstsize.c instructions/algo.c instructions/instr2.c instructions/instr3.c instructions/instr1.c instructions/algoover5.c instructions/utils2.c

BONUS_SRC = bonus/checker.c bonus/get_next_line.c bonus/get_next_line_utils.c bonus/instr_bonus_1.c bonus/instr_bonus_2.c \
			utils/ft_lstlast.c \
			utils/ft_lstadd_back.c utils/ft_atoi.c \
			utils/ft_lstnew.c utils/ft_isdigit.c utils/ft_lstadd_front.c utils/ft_split.c \
			utils/ft_strdup.c utils/ft_substr.c utils/ft_strlen.c printf/ft_printf.c\
			printf/ft_printf_functions.c utils/ft_lstsize.c bonus/instr_bonus_3.c instructions/instr3.c

BONUS_OBJECTS = $(BONUS_SRC:.c=.o)

OBJFILES = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
BONUS_NAME = checker
all: $(NAME)

$(NAME): $(OBJFILES)
	cc  $(CFLAGS) $(OBJFILES) -o $(NAME)

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJECTS)
	cc $(CFLAGS) $(BONUS_OBJECTS) -o $(BONUS_NAME)

clean:
	rm -rf $(OBJFILES) $(BONUS_OBJECTS)


fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)
re:fclean all