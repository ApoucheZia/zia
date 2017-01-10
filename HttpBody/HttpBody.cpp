//
// Created by Julien Karst on 05/01/2017.
//

#include "HttpBody.hh"

apouche::HttpBody::~HttpBody() {

}

const std::string &apouche::HttpBody::getBody() {
    return _body;
}

void apouche::HttpBody::setBody(const std::string &body) {
    _body = body;
}
