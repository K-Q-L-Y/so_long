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
ASSETS_DIR	= assets
XPM_DIR		= assets/xpm
IMAGE_SZIE	= 32x32

# includes and headers
CWD			:= $(shell pwd)
INCLUDE_DIR	= includes
HEADER_DIR	= headers
HEADERS		:= $(shell find $(HEADER_DIR) -name '*.h')
HEADERS_INC	= $(addprefix -I,$(sort $(dir $(HEADERS))))

IFLAGS		:= -I. $(HEADERS_INC)

# libraries
LIBFT_DIR	= $(INCLUDE_DIR)/libft
LIBFT		= $(LIBFT_DIR)/libft.a

LIBS		= $(LIBFT)

# mlx library
MLX_LINUX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_MACOS	= -lmlx -framework OpenGL -framework AppKit

ifeq ($(UNAME_S), Darwin)
	MLX		= $(MLX_MACOS)
	MLX_CO	=
else
	MLX		= $(MLX_LINUX)
	MLX_CO	= $(MLX_LINUX)
endif

# extras
RM			= rm -rf
UP			= \033[1A
FLUSH		= \033[2K

# build
$(NAME): $(OBJDIRS) $(OBJS) $(LIBS)
	$(CC) $(OBJS) $(LIBS) $(MLX) -o $(NAME)
	@echo "$(UP)$(FLUSH)$(UP)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) $(LIBS)
	$(CC) $(CFLAGS) $(IFLAGS) $(MLX_CO) -c $< -o $@
	@echo "$(UP)$(FLUSH)$(UP)"
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

all: $(NAME)

re: clean all

clean:
	@echo "Deleting object files..."
	@$(RM) $(OBJS)

fclean: clean
	@echo "Deleting executable $(NAME)..."
	@$(RM) $(NAME)