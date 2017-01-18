//
// Created by Julien Karst on 05/01/2017.
//

#include <algorithm>
#include "HttpHeader.hh"

namespace
{
  bool stringCaseCompare(const std::string &a, const std::string &b) {
    return a.size() == b.size()
	   && std::equal(a.begin(), a.end(), b.begin(), [](char charA, char charB) -> bool
    {
      return std::tolower(charA) == std::tolower(charB);
    });
  }
}

apouche::HttpHeader::~HttpHeader() {

}

const std::map<std::string, std::string> &apouche::HttpHeader::getAllHeader() const {
    return _header;
}

void apouche::HttpHeader::setAllHeaders(const std::map<std::string, std::string> & header) {
    _header = header;
}

const std::string &apouche::HttpHeader::getHeader(const std::string & key) const {
    auto it = std::find_if(_header.begin(), _header.end(), [&key](std::pair<std::string, std::string> p) -> bool {
      return stringCaseCompare(key, p.first);
    });

    if (it == _header.end())
      throw std::out_of_range("at");

    return it->second;
}

void apouche::HttpHeader::setHeader(const std::string &key, const std::string &value) {
    deleteHeader(key);
    _header[key] = value;
}

void apouche::HttpHeader::deleteHeader(const std::string &key) {
    auto it = std::find_if(_header.begin(), _header.end(), [&key](std::pair<std::string, std::string> p) -> bool {
      return stringCaseCompare(key, p.first);
    });
    if (it != _header.end())
      _header.erase(it);
}

bool apouche::HttpHeader::containsHeader(const std::string &key) const {
    return std::find_if(_header.begin(), _header.end(), [&key](std::pair<std::string, std::string> p) -> bool {
      return stringCaseCompare(key, p.first);
    }) != _header.end();
}
