NAME	= cub3d
LIBFT	= libft
LIBMLX	= minilibx
X11		= /usr/X11
CC		= /usr/bin/gcc
SRCDIR	= srcs
INCDIR	= includes
CFLAGS	= -Wall -Wextra -Werror
IFLAGS	= -I$(INCDIR) -I$(LIBFT)/includes -I$(LIBMLX) -I$(X11)/include/X11
LFLAGS	= -L$(LIBFT) -L$(LIBMLX) -L$(X11)/lib -L. -lft -lmlx -lXext -lX11 -lz
FFLAGS	= -framework CoreFoundation -framework AppKit -framework OpenGL
SRCS	= $(addprefix $(SRCDIR)/, cub3d.c environment.c ray.c canvas.c color.c map.c vector.c settings.c hooks.c player.c error.c)
HDRS	= $(addprefix $(INCDIR)/, environment.h ray.h canvas.h color.h cell.h vector.h settings.h)

all:			libft $(NAME)

libft:
	make -C $(LIBFT) libft.a
libmlx:
	make -C $(LIBMLX) libmlx.a

$(LIBFT)/libft.a: libft
$(LIBMLX)/libmlx.a: libmlx

$(NAME):	 	$(HDRS) $(SRCS) $(LIBMLX)/libmlx.a $(LIBFT)/libft.a
	$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(FFLAGS) -o $@ $(SRCS)

clean:
	make -C $(LIBFT) $@
	make -C $(LIBMLX) $@
	/bin/rm -rf $(OBJDIR)

fclean: 		clean
	make -C $(LIBFT) $@
	make -C $(LIBMLX) clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: libft
