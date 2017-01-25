SRC= HelloWorldModule.hpp \
	../Module/AModule.hpp \
	../Logger/Logger.cpp

NAME= HelloWorldModule.so

all:
	g++ -shared -std=c++11 -fpic -x c++ $(SRC) -o $(NAME)
	cp $(NAME) ../libs/$(NAME)

clean:
	rm -f $(NAME)

fclean:	clean
	rm -f ../libs/$(NAME)

re:	fclean all
