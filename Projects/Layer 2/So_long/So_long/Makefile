
TARGET = $(BIN_DIR)/so_long

FILES = main.c					\
		errors.c				\
		checks.c				\
		checks2.c				\
		elements.c				\
		init.c					\
		utils.c					\
		close.c					\
		move.c					\
		map.c					\


LIBMLX	:= ./MLX42
LIBMLX_INC := $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm 



BIN_DIR = ./bin
LIBFT_DIR = ./libft
LIBFT_INC = $(LIBFT_DIR)/inc
LIBFT = $(LIBFT_DIR)/bin/libft.a

OBJS = $(addprefix $(OBJ_DIR)/,$(FILES:%.c=%.o))

INC_DIR = ./inc
OBJ_DIR = ./obj
SRC_DIR = ./src
INCLUDES = -I$(INC_DIR) -I$(LIBFT_INC) -I ./inc/pipex.h -I $(LIBMLX)/include
CFLAGS =  -Wunreachable-code  -g -Wall -Wextra -Werror
FRAMEWORK = -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"


$(TARGET): $(OBJS) $(LIBFT)
	mkdir -p $(BIN_DIR) 
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	gcc $(CFLAGS) $(LIBS) $(INCLUDES) $(FRAMEWORK) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	gcc $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

.PHONY: all clean fclean re run

all: $(TARGET) 

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

clean:
	@if [ -d $(OBJ_DIR) ]; then \
		rm -r $(OBJ_DIR); \
	fi
	$(MAKE) -C $(LIBFT_DIR) clean
		@if [ -d ./MLX42/build ]; then \
		$(MAKE) -C ./MLX42/build/ clean ; \
	fi
	

fclean: clean
	@if [ -d $(BIN_DIR) ]; then \
		rm -r $(BIN_DIR); \
	fi
	$(MAKE) -C $(LIBFT_DIR) fclean
	@if [ -d ./MLX42/build ]; then \
		rm -r ./MLX42/build ; \
	fi

re: fclean all