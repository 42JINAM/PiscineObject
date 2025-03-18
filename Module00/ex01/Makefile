# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinam <jinam@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 16:42:52 by jinam             #+#    #+#              #
#    Updated: 2025/03/11 16:53:17 by jinam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
TARGET = "ex01"
CC = g++
CC_FLAGS = -Wall -Wextra -Werror -std=c++98 -g3

SRCS = Graph \
	   Vector2 \
	   main \

OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRCS)))

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CC_FLAGS) -o $@ $(OBJS)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean:
	@$(MAKE) clean
	@rm -rf $(TARGET)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
