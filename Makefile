# Name of the library
NAME = fdf

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g -I.
RM = rm -f
INCLUDES = -I .

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Source files and corresponding object files
SRCS = main.c parse_map.c parse_map_utils.c

SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Rules
all: $(NAME)

# Link object files and libft to create the final executable
$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "Compiling fdf project"

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

# Clean object files from both fdf and libft
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Deleting libft objects"
	@rm -rf $(OBJ_DIR)
	@echo "Deleting fdf objects"


# Full clean: also remove the executable and libft objects
fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "Deleting libft.a"
	@rm -f $(NAME)
	@echo "Deleting fdf executable"

# Rebuild everything
re: fclean all

# PHONY prevents conflicts with files named like the targets
.PHONY: all clean fclean re
