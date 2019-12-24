NAME	= cub3d
LIBFT	= libft
LIBMLX	= minilibx
X11		= /usr/X11
CC		= /usr/bin/gcc
SRCDIR	= srcs
OBJDIR	= objs
INCDIR	= includes
CFLAGS	= -Wall -Wextra -Werror
IFLAGS	= -I$(INCDIR) -I$(LIBFT)/includes -I$(LIBMLX) -I$(X11)/include
LFLAGS	= -L$(LIBFT) -L$(LIBMLX) -L$(X11)/lib -L. -lft -lmlx -lXext -lX11 -lz
FFLAGS	= -framework CoreFoundation -framework AppKit -framework OpenGL
SRCS	= $(addprefix $(SRCDIR)/, cub3d.c environment.c ray.c canvas.c color.c map.c vector.c settings.c hooks.c player.c error.c tick.c)
OBJS	= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
HDRS	= $(addprefix $(INCDIR)/, environment.h ray.h canvas.h color.h vector.h settings.h)

all:			libft libmlx $(NAME)

libft:
	make -C $(LIBFT) libft.a
libmlx:
	make -C $(LIBMLX) libmlx.a

$(LIBFT)/libft.a: libft
$(LIBMLX)/libmlx.a: libmlx

$(NAME):		$(OBJDIR) $(OBJS) $(LIBFT)/libft.a $(LIBMLX)/libmlx.a
	$(CC) $(OBJS) $(CFLAGS) $(LFLAGS) $(FFLAGS) -o $@

$(OBJDIR):
	mkdir -p $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HDRS) Makefile
	$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

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
