# Name of the library
NAME		=	fdf

# Compiler and flags
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -Wunreachable-code -I.
DEBUG_FLAGS	=	-g  -fsanitize=address -fcolor-diagnostics -fansi-escape-codes
RM			=	rm -f
INCLUDES	=	-I .

# Directories
SRC_DIR		=	src
OBJ_DIR		=	obj
LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a
LIBFT_FLAGS	=	-L$(LIBFT_DIR) -lft
MLX42_DIR	=	./MLX42
MLX42		=	$(MLX42_DIR)/build/libmlx42.a
MLX42_FLAGS	=	-L$(MLX42_DIR)/build -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit -lglfw

# Source files and corresponding object files
SRCS		=	main.c parse_map.c parse_map_utils.c bresenham.c print_map.c error_handler.c \

SRCS		:=	$(addprefix $(SRC_DIR)/, $(SRCS))
OBJS		=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Rules
all: $(NAME)

# Link object files and libft to create the final executable
$(NAME): $(MLX42) $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAGS) $(MLX42_FLAGS)
	@echo "Compiling fdf project"

debug: $(MLX42) $(LIBFT) $(OBJS)
	@$(CC) $(DEBUG_FLAGS) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAGS) $(MLX42_FLAGS)
	@echo "Compiling fdf project with debug flags"

# Compile source files into object files in the obj/ folder
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Create the obj/ directory if it doesn't exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "Creating folder for object files"

# Build the libft library by calling its Makefile
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all
	@echo "Creating libft"

# Build the MLX42 library
$(MLX42):
	@echo "Compiling mlx42..."
	@git submodule update --init --recursive -q
	@if [ ! -d $(MLX42_DIR)/build ]; then mkdir -p $(MLX42_DIR)/build; fi
	@cd $(MLX42_DIR)/build && cmake .. && make -j4

# Clean object files from both fdf and libft
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Deleting libft objects"
	@$(MAKE) -C $(MLX42_DIR)/build clean
	@echo "Deleting MLX42 objects"
	@rm -rf $(OBJ_DIR)
	@echo "Deleting fdf objects"

# Full clean: also remove the executable and libft objects
fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "Deleting libft.a"
	@$(RM) $(NAME)
	@echo "Deleting fdf executable"

# Rebuild everything
re: fclean all

# Norm rule
norm:
	@echo "Norminette for libft, fdf.h and src:"
	@-norminette src libft fdf.h || true

# PHONY prevents conflicts with files named like the targets
.PHONY: all clean fclean re
