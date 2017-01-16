//
// Created by Julien Karst on 05/01/2017.
//

#include "HttpHeader.hh"


apouche::HttpHeader::~HttpHeader() {

}

const std::map<std::string, std::string> &apouche::HttpHeader::getAllHeader() const {
    return _header;
}

void apouche::HttpHeader::setAllHeaders(const std::map<std::string, std::string> & header) {
    _header = header;
}

const std::string &apouche::HttpHeader::getHeader(const std::string & key) const {
    return _header.at(key);
}

void apouche::HttpHeader::setHeader(const std::string &key, const std::string &value) {
    _header[key] = value;
}

void apouche::HttpHeader::deleteHeader(const std::string &key) {
    _header.erase(key);
}

bool apouche::HttpHeader::containsHeader(const std::string &key) const {
    return !(_header.find(key) == _header.end());
}
