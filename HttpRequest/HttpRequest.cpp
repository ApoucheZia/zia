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
    return _mapMethodFromEnum[_method] + " " + _URI + " " + getVersion();
}

void apouche::HttpRequest::setUriParameters(const std::map<std::string, std::string> &uriParameters) {
    _uriParameters = uriParameters;
}

apouche::IHttpHeader *apouche::HttpRequest::getHeaders() {
    return _header;
}

void apouche::HttpRequest::setHeaders(IHttpHeader *header) {
    _header = header;
}

apouche::IHttpBody *apouche::HttpRequest::getBody() {
    return _body;
}

void apouche::HttpRequest::setBody(IHttpBody *body) {
    _body = body;
}

const std::string &apouche::HttpRequest::getVersion() {
    return _version;
}

void apouche::HttpRequest::setVersion(const std::string &version) {
    _version = version;
}

apouche::HttpRequest::HttpRequest(const std::string &message, apouche::IHttpBody *body, apouche::IHttpHeader *header) {
    setHeaders(header);
    setBody(body);

    _mapMethodFromEnum[Method::Post] = "POST";
    _mapMethodFromEnum[Method::Get] = "GET";
    _mapMethodFromEnum[Method::Options] = "OPTIONS";
    _mapMethodFromEnum[Method::Head] = "HEAD";
    _mapMethodFromEnum[Method::Put] = "PUT";
    _mapMethodFromEnum[Method::Delete] = "DELETE";
    _mapMethodFromEnum[Method::Trace] = "TRACE";
    _mapMethodFromEnum[Method::Connect] = "CONNECT";
    _mapMethodFromEnum[Method::UndefinedRequestMethod] = "Undefined";

    _mapMethodFromName["GET"] = Method::Get;
    _mapMethodFromName["POST"] = Method::Post;
    _mapMethodFromName["OPTIONS"] = Method::Options;
    _mapMethodFromName["HEAD"] = Method::Head;
    _mapMethodFromName["PUT"] = Method::Put;
    _mapMethodFromName["DELETE"] = Method::Delete;
    _mapMethodFromName["TRACE"] = Method::Trace;
    _mapMethodFromName["CONNECT"] = Method::Connect;
    _mapMethodFromName["UNDEFINED"] = Method::UndefinedRequestMethod;

    std::istringstream ss(message);
    std::string token;

    std::getline(ss, token, ' ');

    setMethod(_mapMethodFromName[token]);

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