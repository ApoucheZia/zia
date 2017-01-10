//
// Created by Julien Karst on 05/01/2017.
//

#include "HttpRequest.hh"
#include "../HttpHeader/HttpHeader.hh"
#include "../HttpBody/HttpBody.hh"

void HttpRequestTest() {
    apouche::HttpRequest *request;

    apouche::IHttpHeader *header = new apouche::HttpHeader();
    apouche::IHttpBody *body = new apouche::HttpBody();

    request = new apouche::HttpRequest("POST /cgi-bin/process.cgi?param1=7&param2=seven HTTP/1.1\n"
    "User-Agent: Mozilla/4.0 (compatible; MSIE5.01; Windows NT)\n"
    "Host: www.tutorialspoint.com\n"
    "Content-Type: application/x-www-form-urlencoded\n"
    "Content-Length: length\n"
    "Accept-Language: en-us\n"
    "Accept-Encoding: gzip, deflate\n"
    "Connection: Keep-Alive\n"
    "\n"
    "licenseID=string&content=string&/paramsXML=string\n", body, header);
}