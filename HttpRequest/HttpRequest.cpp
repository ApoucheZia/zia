//
// Created by mart_- on 05/01/17.
//

#include <sstream>
#include <iostream>
#include "HttpRequest.hh"

apouche::HttpRequest::~HttpRequest() {
  delete _header;
  delete _body;
}

apouche::Method apouche::HttpRequest::getMethod() const {
    return _method;
}

void apouche::HttpRequest::setMethod(apouche::Method method) {
    _method = method;
}

const std::string &apouche::HttpRequest::getURI() const {
    return _URI;
}

void apouche::HttpRequest::setURI(const std::string &URI) {
    _URI = URI;
}

bool apouche::HttpRequest::containsUriParameters(const std::string &key) const {
    return !(_uriParameters.find(key) == _uriParameters.end());
}

const std::map<std::string, std::string> &apouche::HttpRequest::getUriParameters() const {
    return _uriParameters;
}

const std::string &apouche::HttpRequest::getUriParameter(const std::string &key) const {
    return _uriParameters.at(key);
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

apouche::IHttpHeader *apouche::HttpRequest::getHeaders() {
    return _header;
}

const apouche::IHttpHeader *apouche::HttpRequest::getHeaders() const {
    return _header;
}

void apouche::HttpRequest::setHeaders(IHttpHeader *header) {
    delete _header;
    _header = header;
}

apouche::IHttpBody *apouche::HttpRequest::getBody() {
    return _body;
}

const apouche::IHttpBody *apouche::HttpRequest::getBody() const {
  return _body;
}

void apouche::HttpRequest::setBody(IHttpBody *body) {
    delete _body;
    _body = body;
}

const std::string &apouche::HttpRequest::getVersion() const {
    return _version;
}

void apouche::HttpRequest::setVersion(const std::string &version) {
    _version = version;
}

apouche::HttpRequest::HttpRequest(const std::string &message, apouche::IHttpBody *body, apouche::IHttpHeader *header)
  : _header (header)
  , _body (body)
{
    std::istringstream ss(message);
    std::string token;

    std::getline(ss, token, ' ');

    setMethod(_mapMethodFromName.at(token));

    std::getline(ss, token, ' ');
    setURI(token);

    // Get URI parameters
    size_t pos = token.find("?");
    std::string value = token.substr(pos + 1, token.size());

    std::istringstream sss(value);
    while(std::getline(sss, token, '&')) {
        if (token.empty())
            break;
        pos = token.find('=');
        std::string key = token.substr(0, pos);
        std::string value = token.substr(pos + 1, token.size());
        _uriParameters[key] = value;
    }

    std::getline(ss, token, '\n');
    setVersion(token.substr(0, token.size() - 1));

    apouche::IHttpHeader *iHttpHeader = getHeaders();
    std::map<std::string, std::string> map;

    while(std::getline(ss, token, '\n')) {
        if (token.empty())
            break;
        pos = token.find(": ");
        std::string key = token.substr(0, pos);
        std::string value = token.substr(pos + 2, token.size() - pos - 3);
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
