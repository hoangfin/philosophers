NAME := philo

RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
RESET := \033[0m

BUILD_DIR := build

CC := cc
CFLAG := -Wall -Wextra -Werror -pthread -O3 -Iinclude

VPATH :=	src \
			src/philosopher \
			src/printer \
			src/routines \
			src/simulation \
			src/utils

SOURCES :=	main.c \
			\
			eat.c \
			ft_sleep.c \
			think.c \
			\
			monitor_routine.c \
			philo_routine.c \
			\
			destroy.c \
			init.c \
			lock.c \
			msleep.c \
			now.c \
			print.c \
			start.c \
			unlock.c \
			\
			ft_atol.c \
			validate.c

OBJECTS := $(SOURCES:%.c=$(BUILD_DIR)/%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(BUILD_DIR) $(OBJECTS)
	@$(CC) $(CFLAG) $(OBJECTS) -o $@
	@printf "$(YELLOW)$@$(RESET) created.\n"

$(BUILD_DIR):
	@mkdir -p $@
	@echo "Compiling ..."

$(BUILD_DIR)/%.o: %.c
	@$(CC) $(CFLAG) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR)

fclean:
	@rm -rf $(BUILD_DIR)
	@rm -f $(NAME)
	@printf "$(RED)$(NAME)$(RESET) deleted.\n"

re: fclean all
