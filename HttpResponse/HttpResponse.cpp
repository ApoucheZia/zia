//
// Created by Julien Karst on 05/01/2017.
//

#include "HttpResponse.hh"

apouche::HttpResponse::~HttpResponse() {

}

apouche::StatusCode apouche::HttpResponse::getStatus() const {
    return _status;
}

void apouche::HttpResponse::setStatus(apouche::StatusCode status) {
    _status = status;
}

const std::string apouche::HttpResponse::getResponseLine() const {
    return _status + " " + _message.at(_status);
}

apouche::IHttpHeader *apouche::HttpResponse::getHeaders() {
    return _header;
}

const apouche::IHttpHeader *apouche::HttpResponse::getHeaders() const {
    return _header;
}

void apouche::HttpResponse::setHeaders(IHttpHeader *header) {
    _header = header;
}

apouche::IHttpBody *apouche::HttpResponse::getBody() {
    return _body;
}

const apouche::IHttpBody *apouche::HttpResponse::getBody() const {
    return _body;
}

void apouche::HttpResponse::setBody(IHttpBody *body) {
    _body = body;
}

const std::string &apouche::HttpResponse::getVersion() const {
    return _version;
}

void apouche::HttpResponse::setVersion(const std::string &version) {
    _version = version;
}


apouche::HttpResponse::HttpResponse(apouche::IHttpHeader *header, apouche::IHttpBody *body, const std::string &version) {
    setHeaders(header);
    setBody(body);

    _message[apouche::StatusCode::UndefinedStatusCode] = "UndefinedStatusCode";

    _message[apouche::StatusCode::Continue] = "Continue";
    _message[apouche::StatusCode::SwitchingProtocols] = "SwitchingProtocols";

    _message[apouche::StatusCode::OK] = "OK";
    _message[apouche::StatusCode::Created] = "Created";
    _message[apouche::StatusCode::Accepted] = "Accepted";
    _message[apouche::StatusCode::NonAuthoritativeInformation] = "NonAuthoritativeInformation";
    _message[apouche::StatusCode::NoContent] = "NoContent";
    _message[apouche::StatusCode::ResetContent] = "ResetContent";
    _message[apouche::StatusCode::PartialContent] = "PartialContent";

    _message[apouche::StatusCode::MultipleChoices] = "MultipleChoices";
    _message[apouche::StatusCode::MovedPermanently] = "MovedPermanently";
    _message[apouche::StatusCode::Found] = "Found";
    _message[apouche::StatusCode::SeeOther] = "SeeOther";
    _message[apouche::StatusCode::NotModified] = "NotModified";
    _message[apouche::StatusCode::UseProxy] = "UseProxy";
    _message[apouche::StatusCode::TemporaryRedirect] = "TemporaryRedirect";

    _message[apouche::StatusCode::BadRequest] = "BadRequest";
    _message[apouche::StatusCode::Unauthorized] = "Unauthorized";
    _message[apouche::StatusCode::PaymentRequired] = "PaymentRequired";
    _message[apouche::StatusCode::Forbidden] = "Forbidden";
    _message[apouche::StatusCode::NotFound] = "NotFound";
    _message[apouche::StatusCode::MethodNotAllowed] = "MethodNotAllowed";
    _message[apouche::StatusCode::NotAcceptable] = "NotAcceptable";
    _message[apouche::StatusCode::ProxyAuthenticationRequired] = "ProxyAuthenticationRequired";
    _message[apouche::StatusCode::RequestTimeOut] = "RequestTimeOut";
    _message[apouche::StatusCode::Conflict] = "Conflict";
    _message[apouche::StatusCode::Gone] = "Gone";
    _message[apouche::StatusCode::LengthRequired] = "LengthRequired";
    _message[apouche::StatusCode::PreconditionFailed] = "PreconditionFailed";
    _message[StatusCode::RequestEntityTooLarge] = "RequestEntityTooLarge";
    _message[StatusCode::RequestURITooLarge] = "RequestURITooLarge";
    _message[StatusCode::UnsupportedMediaType] = "UnsupportedMediaType";
    _message[StatusCode::RequestedRangeNotSatisfiable] = "RequestedRangeNotSatisfiable";
    _message[StatusCode::ExpectationFailed] = "ExpectationFailed";

    _message[StatusCode::InternalServerError] = "InternalServerError";
    _message[StatusCode::NotImplemented] = "NotImplemented";
    _message[StatusCode::BadGateway] = "BadGateway";
    _message[StatusCode::ServiceUnavailable] = "ServiceUnavailable";
    _message[StatusCode::GatewayTimeOut] = "GatewayTimeOut";
    _message[StatusCode::HTTPVersionNotSupported] = "HTTPVersionNotSupported";
}

const std::string &apouche::HttpResponse::getStatusDescription() const {
    return _message.at(_status);
}
