NAME := philo_bonus

RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
RESET := \033[0m

BUILD_DIR := build

CC := cc
CFLAG := -Wall -Wextra -Werror -pthread -O3 -Iinclude

VPATH :=	src \
			src/philosopher \
			src/simulation \
			src/utility

SOURCES :=	main_bonus.c \
			\
			acquire_locks_bonus.c \
			eat_bonus.c \
			ft_sleep_bonus.c \
			init_philo_bonus.c \
			philo_routine_bonus.c \
			print_bonus.c \
			release_locks_bonus.c \
			think_bonus.c \
			\
			destroy_bonus.c \
			get_sim_state_bonus.c \
			init_bonus.c \
			msleep_bonus.c \
			set_sim_state_bonus.c \
			start_bonus.c \
			\
			ft_atol_bonus.c \
			lock_bonus.c \
			now_bonus.c \
			unlock_bonus.c \
			validate_bonus.c

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
