# **************************************************************************** #
#                                PUSH_SWAP                                     #
# **************************************************************************** #

NAME        = push_swap
BONUS_NAME  = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

INCLUDES    = -I. -I$(LIBFT_DIR)

# ----------------------------- COMMON FILES --------------------------------- #

COMMON_SRCS = push_swap_utils_1.c \
              push_swap_utils_2.c \
              push_swap_utils_3.c \
              push_swap_utils_4.c \
              push_swap_utils_5.c \
              push_swap_utils_6.c \
              push_swap_utils_7.c \
			  push_swap_utils_8.c

COMMON_OBJS = $(COMMON_SRCS:.c=.o)

# ----------------------------- MANDATORY ------------------------------------ #

SRCS        = push_swap.c
OBJS        = $(SRCS:.c=.o)

# ------------------------------ BONUS --------------------------------------- #

BONUS_SRCS  = checker.c
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

# ---------------------------------------------------------------------------- #

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS) $(COMMON_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(COMMON_OBJS) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS) $(COMMON_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(COMMON_OBJS) $(LIBFT) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(BONUS_OBJS) $(COMMON_OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
