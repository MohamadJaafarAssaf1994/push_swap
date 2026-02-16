# **************************************************************************** #
#                                PUSH_SWAP                                    #
# **************************************************************************** #

NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS        = push_swap.c \
              push_swap_utils_1.c \
              push_swap_utils_2.c \
              push_swap_utils_3.c \
              push_swap_utils_4.c \
              push_swap_utils_5.c \
			  push_swap_utils_6.c \
			  push_swap_utils_7.c

OBJS        = $(SRCS:.c=.o)

INCLUDES    = -I. -I$(LIBFT_DIR)

# ---------------------------------------------------------------------------- #
#                                   RULES                                      #
# ---------------------------------------------------------------------------- #

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "push_swap compiled successfully ✅"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)
	@echo "Object files removed 🧹"

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)
	@echo "Executable removed 🗑"

re: fclean all

.PHONY: all clean fclean re
