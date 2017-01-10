//
// Created by mart_- on 05/01/17.
//

#include "HttpMessage.hh"

apouche::HttpMessage::HttpMessage(IHttpHeader *iHttpHeader, IHttpBody *iHttpBody, const std::string &version) {
    _header = iHttpHeader;
    _body = iHttpBody;
    _version = version;
}

apouche::IHttpHeader *apouche::HttpMessage::getHeaders() {
    return _header;
}

void apouche::HttpMessage::setHeaders(IHttpHeader *header) {
    _header = header;
}

apouche::IHttpBody *apouche::HttpMessage::getBody() {
    return _body;
}

void apouche::HttpMessage::setBody(IHttpBody *body) {
    _body = body;
}

const std::string &apouche::HttpMessage::getVersion() {
    return _version;
}

void apouche::HttpMessage::setVersion(const std::string &version) {
    _version = version;
}