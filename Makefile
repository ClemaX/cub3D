NAME	= cub3D
LIBFT	= libft
LIBMLX	= minilibx
CC		= /usr/bin/gcc
SRCDIR	= srcs
OBJDIR	= objs
INCDIR	= includes
CFLAGS	= -Wall -Wextra -Werror
IFLAGS	= -I$(INCDIR) -I$(LIBFT)/includes -I$(LIBMLX)
LFLAGS	= -L$(LIBFT) -L$(LIBMLX) -L. -lft -lz -lmlx
FFLAGS	= -framework CoreFoundation -framework AppKit -framework OpenGL
SRCS	= $(addprefix $(SRCDIR)/, cub3d.c environment.c ray.c images.c canvas.c color.c map_read.c map.c cell.c vector.c vmath.c settings.c hooks.c error.c tick.c sprite.c sprite_utils.c)
OBJS	= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
HDRS	= $(addprefix $(INCDIR)/, environment.h ray.h canvas.h color.h vector.h vmath.h settings.h map.h)

# TODO: Cleanup files

all:			libft libmlx $(NAME)

libft:
	make -C $(LIBFT) libft.a
libmlx:
	make -C $(LIBMLX) NAME=libmlx.a

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
