//
// Created by mart_- on 05/01/17.
//

#include "HttpRequest.hh"
#include <sstream>
#include <iostream>

apouche::HttpRequest::~HttpRequest() {

}

const apouche::Method &apouche::HttpRequest::getMethod() {
    return _method;
}

void apouche::HttpRequest::setMethod(const apouche::Method &method) {
    _method = method;
}

const std::string &apouche::HttpRequest::getURI() {
    return _URI;
}

void apouche::HttpRequest::setURI(const std::string &URI) {
    _URI = URI;
}

const bool apouche::HttpRequest::containsUriParameters(const std::string &key) {
    return !(_uriParameters.find(key) == _uriParameters.end());
}

std::map<std::string, std::string> apouche::HttpRequest::getUriParameters() {
    return _uriParameters;
}

const std::string &apouche::HttpRequest::getUriParameter(const std::string &key) {
    return _uriParameters[key];
}

void apouche::HttpRequest::setUriParameter(const std::string &key, const std::string &value) {
    _uriParameters[key] = value;
}

const std::string apouche::HttpRequest::getRequestLine() {
    return _mapMethodFromEnum.at(_method) + " " + _URI + " " + getVersion();
}

void apouche::HttpRequest::setUriParameters(const std::map<std::string, std::string> &uriParameters) {
    _uriParameters = uriParameters;
}

apouche::HttpRequest::HttpRequest(const std::string &message, apouche::IHttpBody *body, apouche::IHttpHeader *header) {
    setHeaders(header);
    setBody(body);

    std::istringstream ss(message);
    std::string token;

    std::getline(ss, token, ' ');

    setMethod(_mapMethodFromName.at(token));

    std::getline(ss, token, ' ');
    setURI(token);

    // Get URI parameters
    unsigned long start = token.find("?");
    std::string value = token.substr(start + 1, token.size());

    std::istringstream sss(value);
    while(std::getline(sss, token, '&')) {
        if (token.empty())
            break;
        unsigned long pos = token.find('=');
        std::string key = token.substr(0, pos);
        std::string value = token.substr(pos + 1, token.size());
        _uriParameters[key] = value;
    }

    std::getline(ss, token, '\n');
    setVersion(token);


    apouche::IHttpHeader *iHttpHeader = getHeaders();
    std::map<std::string, std::string> map;

    while(std::getline(ss, token, '\n')) {
        if (token.empty())
            break;
        unsigned long pos = token.find(": ");
        std::string key = token.substr(0, pos);
        std::string value = token.substr(pos + 2, token.size());
        map[key] = value;
    }
    iHttpHeader->setAllHeaders(map);

    apouche::IHttpBody *iHttpBody = getBody();
    std::getline(ss, token);
    iHttpBody->setBody(token);
}

const std::map <apouche::Method,  std::string> apouche::HttpRequest::_mapMethodFromEnum = {
    {Method::Post, "POST"},
    {Method::Get, "GET"},
    {Method::Options, "OPTIONS"},
    {Method::Head, "HEAD"},
    {Method::Put, "PUT"},
    {Method::Delete, "DELETE"},
    {Method::Trace, "TRACE"},
    {Method::Connect, "CONNECT"},
    {Method::UndefinedRequestMethod, "UNDEFINED"}
};

const std::map <std::string, apouche::Method> apouche::HttpRequest::_mapMethodFromName = {
    {"GET", Method::Get},
    {"POST", Method::Post},
    {"OPTIONS", Method::Options},
    {"HEAD", Method::Head},
    {"PUT", Method::Put},
    {"DELETE", Method::Delete},
    {"TRACE", Method::Trace},
    {"CONNECT", Method::Connect},
    {"UNDEFINED", Method::UndefinedRequestMethod},
};
