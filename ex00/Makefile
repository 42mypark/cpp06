NAME=convert
CXXFLAGS= -Werror -Wextra -Wall

SRCS =	main.cpp\
				Parser.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $@ $(OBJS)

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<


clean:
	rm -f *.o

fclean:
	$(MAKE) clean
	rm $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re