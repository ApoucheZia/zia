cmake_minimum_required(VERSION 3.0)
project(zia)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES
    Event/Event.hpp
    EventHandler/EventHandler.hpp
    EventList/EventList.hpp
    HttpBody/HttpBody.cpp
    HttpBody/HttpBody.hh
    HttpBody/IHttpBody.hh
    HttpConf/IHttpConf.hpp
    HttpHeader/HttpHeader.cpp
    HttpHeader/HttpHeader.hh
    HttpHeader/IHttpHeader.hh
    HttpMessage/HttpMessage.cpp
    HttpMessage/HttpMessage.hh
    HttpMessage/IHttpMessage.hh
    HttpRequest/HttpRequest.cpp
    HttpRequest/HttpRequest.hh
        HttpRequest/IHttpRequest.hh
    HttpResponse/HttpResponse.cpp
    HttpResponse/HttpResponse.hh
    HttpResponse/IHttpResponse.hh
    Logger/FileLogger.cpp
    Logger/FileLogger.hh
        Logger/Logger.cpp
    Logger/Logger.hh
    Module/AModule.hpp
    Network/INetworkStatus.hpp
    Network/IZiaConnection.hpp
    Enum.hh
    main.cpp)

add_executable(zia ${SOURCE_FILES})