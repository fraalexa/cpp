NAME        = a.out

SRC_PATH    = ./
BUILD_PATH  = .build/
INC_PATH    = ./includes/
CPP_SRCS    := main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJS        := $(patsubst %.cpp, $(BUILD_PATH)%.o, $(CPP_SRCS))

VERSION     = -std=c++98
CXX          = c++
CXXFLAGS      = $(VERSION) -Wall -Wextra -Werror
RM          = rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(BUILD_PATH)%.o: %.cpp | $(BUILD_PATH)
	$(CXX) $(CXXFLAGS) -I$(INC_PATH) -c $< -o $@

$(BUILD_PATH):
	mkdir -p $(BUILD_PATH)

clean:
	$(RM) $(BUILD_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all