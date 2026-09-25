VERSION		= -std=c++98

NAME		= megaphone
BUILD_PATH	= .build/
#INC_PATH	= ./includes/

CPP_SRCS    :=	megaphone.cpp
OBJS 		:= 	$(patsubst %.cpp, $(BUILD_PATH)%.o, $(CPP_SRCS))

CXX			= c++ $(VERSION)
CXXFLAGS	= -Wall -Wextra -Werror
MAKE		= make --no-print-directory
RM			= rm -rf

all: $(NAME)

$(NAME): $(BUILD_PATH) $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(BUILD_PATH)%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_PATH):
	@mkdir -p $(BUILD_PATH)

clean:
	@$(RM) $(BUILD_PATH)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re