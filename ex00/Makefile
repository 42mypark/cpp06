NAME=convert
CXXFLAGS= -Werror -Wextra -Wall

SRCS = test.cpp
OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CXX) -o $@ $(OBJS)

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

fclean:
	rm *.o
	rm $(NAME)
