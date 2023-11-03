NAME_CLIENT = client
NAME_SERVER = server

CFLAGS = -Wall -Werror -Wextra
PRINTF_PATH = ./ft_printf
PRINTF = $(PRINTF_PATH)/libftprintf.a
CLIENT = client.a
SERVER = server.a

CC = gcc

CLEAN = rm -rf

SRC_SERVER = server.c
SRC_CLIENT = client.c

OBJS_CLIENT := $(SRC_CLIENT:.c=.o)
OBJS_SERVER := $(SRC_SERVER:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS_CLIENT) $(PRINTF) -o $(NAME_CLIENT)

$(OBJS_CLIENT): %.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME_SERVER): $(OBJS_SERVER) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS_SERVER) $(PRINTF) -o $(NAME_SERVER)

$(OBJS_SERVER): %.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF):
	@make -s -C $(PRINTF_PATH)

clean:
	@$(CLEAN) $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	@$(CLEAN) $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re
