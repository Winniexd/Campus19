NAME=bureaucrat
FLAGS= -Wall -Wextra -Werror -std=c++98 -g

SRC= Bureaucrat.cpp \
main.cpp \
Form.cpp \
ShrubberyCreationForm.cpp \
RobotomyRequestForm.cpp \
PresidentialPardonForm.cpp

OBJ=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f *_shrubbery

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all
