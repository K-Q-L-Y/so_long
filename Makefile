# compilation
NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# source files
SRCDIR		= srcs
SRCS		:= $(shell find $(SRCDIR) -name '*.c')

# object filese
OBJDIR 		= objs
OBJDIRS		= $(sort $(dir $(OBJS)))
OBJS		= $(subst $(SRCDIR),$(OBJDIR),$(subst .c,.o,$(SRCS)))

# assets
ASSETS_DIR		= assets
XPM_DIR			= assets/xpm
IMAGE_SZIE		= 32x32
ASSETS_PATH_H	= headers/assets_path.h

# includes and headers
CWD			:= $(shell pwd)
INCLUDE_DIR	= includes
HEADER_DIR	= headers
HEADERS		:= $(shell find $(HEADER_DIR) -name '*.h') $(shell find $(INCLUDE_DIR) -name '*.h')
HEADERS_INC	= $(addprefix -I,$(sort $(dir $(HEADERS))))

IFLAGS		:= -I. $(HEADERS_INC)

# mlx library
UNAME_S		:= $(shell uname -s)
MLX_LINUX	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_MACOS	= -lmlx -framework OpenGL -framework AppKit
ifeq ($(UNAME_S), Darwin)
	MLX		= $(MLX_MACOS)
	MLX_CO	=
else
	MLX		= $(MLX_LINUX)
	MLX_CO	= $(MLX_LINUX)
endif

# libraries
LIBFT_DIR	= $(INCLUDE_DIR)/libft
LIBFT		= $(LIBFT_DIR)/libft.a

LIBS		= $(LIBFT)

# extras
RM			= rm -rf
UP			= \033[1A
FLUSH		= \033[2K

# build
$(NAME): $(LIBS) $(OBJDIRS) $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) $(LIBS) $(MLX) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(IFLAGS) $(MLX_CO) -c $< -o $@
	@echo "$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)"
# -I/usr/include -Imlx_linux -O3

$(OBJDIRS):
	@mkdir -p $@

$(LIBFT): $(LIBFT_DIR) $(shell find $(LIBFT_DIR) -name "*.c")
	make -C $(LIBFT_DIR) all

# commands
xpm:
	@echo "Deleting XPM files..."
	@$(RM) $(XPM_DIR)
	@echo "Creating XPM directory..."
	@mkdir -p $(XPM_DIR)
	@find $(ASSETS_DIR) -type f -name "*.png" | while read -r file; do \
		relative_path=$${file#$(ASSETS_DIR)/}; \
		dest_file=$(XPM_DIR)/$${relative_path%.png}.xpm; \
		mkdir -p $$(dirname $$dest_file); \
		convert $$file -resize $(IMAGE_SZIE) $$dest_file; \
		echo "Converted $$file to $$dest_file"; \
	done

path_h:
	@echo "#ifndef ASSETS_PATH_H" > $(ASSETS_PATH_H)
	@echo "# define ASSETS_PATH_H" >> $(ASSETS_PATH_H)
	@find assets/ -type f -name '*.xpm' -exec sh -c ' \
		FILE="{}"; \
		DEF_NAME=$$(echo "$$FILE" | tr "/" "_" | sed "s/\.xpm$$//" | awk "{print toupper(\$$0)}" | sed "s/ASSETS_SPRITES_//"  | sed "s/ASSETS__SPRITES_//"); \
		echo "# define PATH_$$DEF_NAME \"$$FILE\"" >> $(ASSETS_PATH_H); \
	' \;
	@echo "#endif" >> $(ASSETS_PATH_H)
	@cat $(ASSETS_PATH_H)

push:
	@read -p "Commit name: " commit_name; make fclean;	\
	cd $(CWD); git add .; git commit -m "$$commit_name"; git push;	\

all: $(NAME)

re: clean all

clean:
	@echo "Deleting object files..."
	@$(RM) $(OBJS)

fclean: clean
	@echo "Deleting executable $(NAME)..."
	@$(RM) $(NAME)