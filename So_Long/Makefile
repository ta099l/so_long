NAME = so_long

CC = cc
CFLAGS =-g -Wall -Wextra -Werror -I./includes

SRCDIR = srcs
OBJDIR = obj
LIBPATH = ft_lib/

LIB = -L./ft_lib -lft -lmlx -lX11 -lm -lXext

RM = rm -rf

SRCS = so_long.c reading_map.c error_handling.c clean_exit.c intialize.c convert_imgs.c flood_fill.c moving.c put_imgs.c

SRC  = $(addprefix $(SRCDIR)/, $(SRCS))

OBJ  = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBPATH)
	$(CC) $(CFLAGS) $^ $(LIB) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	make clean -C $(LIBPATH)
	$(RM) $(OBJDIR)

fclean: clean
	make fclean -C $(LIBPATH)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
