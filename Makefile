##
## Makefile for  in /home/mart_-/Downloads/zia
## 
## Made by mart_-
## Login   <mart_-@epitech.net>
## 
## Started on  Tue Jan 10 10:01:27 2017 mart_-
## Last update Tue Jan 10 10:01:27 2017 mart_-
##

CXXFLAGS	+= -std=c++11

SRC=	HttpResponse/HttpResponse.cpp \
	HttpHeader/HttpHeader.cpp \
	HttpMessage/HttpMessage.cpp \
	Logger/Logger.cpp \
	Logger/FileLogger.cpp \
	HttpBody/HttpBody.cpp \
	HttpRequest/HttpRequest.cpp \
	main.cpp

OBJ=	$(SRC:.cpp=.o)

NAME=	apouche

all:	$(NAME)

$(NAME):$(OBJ)
	g++ -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
