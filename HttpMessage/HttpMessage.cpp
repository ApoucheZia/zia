//
// Created by mart_- on 05/01/17.
//

#include "HttpMessage.hh"

apouche::HttpMessage::HttpMessage(IHttpHeader *iHttpHeader, IHttpBody *iHttpBody, const std::string &version)
  : _header (iHttpHeader)
  , _body (iHttpBody)
  , _version (version)
{
}

apouche::HttpMessage::~HttpMessage()
{
  delete _header;
  delete _body;
}

apouche::IHttpHeader *apouche::HttpMessage::getHeaders() {
    return _header;
}

const apouche::IHttpHeader *apouche::HttpMessage::getHeaders() const {
    return _header;
}

void apouche::HttpMessage::setHeaders(IHttpHeader *header) {
    delete _header;
    _header = header;
}

apouche::IHttpBody *apouche::HttpMessage::getBody() {
    return _body;
}

const apouche::IHttpBody *apouche::HttpMessage::getBody() const {
    return _body;
}

void apouche::HttpMessage::setBody(IHttpBody *body) {
    delete _body;
    _body = body;
}

const std::string &apouche::HttpMessage::getVersion() const {
    return _version;
}

void apouche::HttpMessage::setVersion(const std::string &version) {
    _version = version;
}
