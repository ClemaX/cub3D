NAME	=	cub3D
LIBFT	=	libft
LIBMLX	=	minilibx
CC		=	/usr/bin/gcc
SRCDIR	=	srcs
OBJDIR	=	objs
INCDIR	=	includes
CFLAGS	=	-Wall -Wextra -Werror
IFLAGS	=	-I$(INCDIR) -I$(LIBFT)/includes -I$(LIBMLX)
LFLAGS	=	-L$(LIBFT) -L$(LIBMLX) -L. -lft -lz -lmlx
FFLAGS	=	-framework CoreFoundation -framework AppKit -framework OpenGL
SRCS	=	$(addprefix $(SRCDIR)/,				\
			cub3d.c ray.c vector.c				\
			$(addprefix environment/,			\
			env_error.c env_settings.c env.c)	\
			$(addprefix hooks/,					\
			hooks.c input.c tick.c)				\
			$(addprefix images/,				\
			canvas.c color.c images.c)			\
			$(addprefix map/,					\
			cell.c map_read.c map.c)			\
			$(addprefix sprites/,				\
			sprite_utils.c sprite.c))
OBJDS	=	$(addprefix $(OBJDIR)/, environment hooks images map sprites)
OBJS	=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
HDRS	=	$(addprefix $(INCDIR)/, canvas.h color.h environment.h hooks.h map.h ray.h settings.h sprite.h tick.h vector.h)

all:				libft libmlx $(NAME)

bonus:				all

libft:
	make -C $(LIBFT) libft.a
libmlx:
	make -C $(LIBMLX) NAME=libmlx.a

$(LIBFT)/libft.a: 	libft

$(LIBMLX)/libmlx.a:	libmlx

$(NAME):		$(OBJDS) $(OBJS) $(LIBFT)/libft.a $(LIBMLX)/libmlx.a
	$(CC) $(OBJS) $(CFLAGS) $(LFLAGS) $(FFLAGS) -o $@

$(OBJDS):
	mkdir -p $@
	echo $(SRCS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HDRS) Makefile
	$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

clean:
	make -C $(LIBFT) $@
	make -C $(LIBMLX) $@
	/bin/rm -rf $(OBJDIR)

fclean: 			clean
	make -C $(LIBFT) $@
	make -C $(LIBMLX) clean
	/bin/rm -f $(NAME)

re:					fclean all

.PHONY: 			libft
