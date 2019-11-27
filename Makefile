NAME	= libftprintf.a
LIBFT	= libft
LIBMLX	= minilibx
X11		= /usr/X11
CC		= /usr/bin/gcc
SRCDIR	= srcs
INCDIR	= includes
CFLAGS	= -Wall -Wextra -Werror
IFLAGS	= -I$(INCDIR) -I$(LIBFT) -I$(LIBMLX) -I$(X11)/include/X11
LFLAGS	= -L$(LIBFT) -L$(LIBMLX) -L$(X11)/lib -lft -lmlx -lXext -lX11 -lz
FFLAGS	= -framework CoreFoundation -framework AppKit -framework OpenGL
SRCS	= $(addprefix $(SRCDIR)/, main.c cub.c get_next_line.c get_next_line_utils.c)
HDRS	= $(addprefix $(INCDIR)/, cub3d.h environment.h cub.h color.h get_next_line.h)

all:			libft $(NAME)

libft:
	make -C $(LIBFT) libft.a
libmlx:
	make -C $(LIBMLX) libmlx.a

$(LIBFT)/libft.a: libft
$(LIBMLX)/libmlx.a: libmlx

$(NAME):	 	$(SRCS) $(LIBMLX)/libmlx.a $(LIBFT)/libft.a
	$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(FFLAGS) -o $@ $(SRCS)

clean:
	make -C $(LIBFT) $@
	make -C $(LIBMLX) $@
	/bin/rm -rf $(OBJDIR)

fclean: 		clean
	make -C $(LIBFT) $@
	make -C $(LIBMLX) $@
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: libft
