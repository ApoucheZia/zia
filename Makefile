SRC= Event/Event.hpp \
    EventHandler/EventHandler.hpp \
    EventList/EventList.hpp \
    HttpBody/HttpBody.cpp \
    HttpConf/IHttpConf.hpp \
    HttpHeader/HttpHeader.cpp \
    HttpMessage/HttpMessage.cpp \
    HttpRequest/HttpRequest.cpp \
    HttpResponse/HttpResponse.cpp \
    Logger/FileLogger.cpp \
    Logger/Logger.cpp \
    Module/AModule.hpp \
    Network/INetworkStatus.hpp \
    Network/IZiaConnection.hpp \

NAME= apouche.so

all:
	g++ -shared -std=c++11 -fpic -x c++ $(SRC) -o $(NAME) -I .
	
clean:
	rm -f $(NAME)

fclean:	clean
	rm -f ../libs/$(NAME)

re:	fclean all
