NAME	 	= so_long
SRCSDIR		= ./srcs
SRCS 	 	= \
	$(SRCSDIR)/test.c\

OBJSDIR		= ./objs
OBJS 		= $(addprefix $(OBJSDIR)/, $(notdir $(SRCS:.c=.o)))


minilibx_DIR	= ./minilibx-linux
minilibx_A			= $(minilibx_DIR)/libmlx_Darwin.a
DEPENDS   		= $(OBJS:.o=.d)

LIBFT_DIR	= ./libft
LIBFT_A			= $(LIBFT_DIR)/libft.a
DEPENDS   		= $(OBJS:.o=.d)


CC 				= gcc
CFLAGS			= #-Werror -Wall -Wextra -MMD -MP
CFLAGS_MLX		= -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
DEGUB_CFLAGS	= -g3 -fsanitize=address
RM				= /bin/rm -f
INCLUDES 		= -I./includes

CFLAGS += $(CFLAGS_MLX)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) $(minilibx_A)
	$(CC) $(CFLAGS) -o $@  $(OBJS) $(INCLUDES) $(minilibx_A)


$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(OBJSDIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

$(minilibx_A):
	make -C $(minilibx_DIR)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

.PHONY:clean
clean:
	$(RM) $(OBJS)
	$(RM) $(LIBFT_OBJS)
	$(RM) $(DEPENDS)
	make -C $(minilibx_DIR) clean

.PHONY:fclean
fclean:clean
	$(RM) $(NAME)
#make -C $(LIBFT_DIR) fclean

.PHONY:re
re:fclean all

.PHONY:test
test:$(NAME)
	$(CC) $(CFLAGS) $^ -Imlx -L/usr/X11R6/lib -lXext -o $@

-include $(DEPENDS)
