NAME	 	= so_long
SRCSDIR		= ./srcs
SRCS 	 	= \
	$(SRCSDIR)/main.c\
	$(SRCSDIR)/ft_malloc.c\
	$(SRCSDIR)/init_map.c\
	$(SRCSDIR)/init_window.c\
	$(SRCSDIR)/event_key_press.c\
	$(SRCSDIR)/main_loop.c\
	$(SRCSDIR)/get_next_line.c\
	$(SRCSDIR)/get_next_line_utils.c\
	$(SRCSDIR)/ft_mapjoin.c\
	$(SRCSDIR)/ft_mapdup.c\
	$(SRCSDIR)/move.c\

OBJSDIR		= ./objs
OBJS 		= $(addprefix $(OBJSDIR)/, $(notdir $(SRCS:.c=.o)))

LIBFT_DIR		= ./libft
LIBFT_A			= $(LIBFT_DIR)/libft.a
DEPENDS   		= $(OBJS:.o=.d)


CC 				= gcc
CFLAGS			= -Werror -Wall -Wextra -g
DEGUB_CFLAGS	= -fsanitize=address -O0
RM				= /bin/rm -f
INCLUDES 		= -I./includes

CFLAGS += $(CFLAGS_MLX) $(DEGUB_CFLAGS)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o  $@  $(OBJS) $(INCLUDES) -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

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
