cmake_minimum_required(VERSION 3.0)
project(zia)

set(CMAKE_CXX_STANDARD 11)

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
    HttpRequest/HttpRequestTest.cpp
        HttpResponse/HttpResponse.cpp
    HttpResponse/HttpResponse.hh
        Logger/FileLogger.cpp
    Logger/FileLogger.hh
    Logger/FileLoggerTest.cpp
    Logger/Logger.cpp
    Logger/Logger.hh
    Module/AModule.hpp
    SampleModule/RequestInfoPrintingModule.hpp
    SampleModule/ResponseRewritingModule.hpp
    Enum.hh
    main.cpp
    README.md
        )

add_executable(zia ${SOURCE_FILES})