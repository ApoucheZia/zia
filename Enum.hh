//
// Created by mart_- on 06/01/17.
//

#ifndef ZIA_ENUM_HH
#define ZIA_ENUM_HH

#include <string>

namespace apouche {

    enum Method {
        UndefinedRequestMethod = 0,
        Options,
        Get,
        Head,
        Post,
        Put,
        Delete,
        Trace,
        Connect
    };

    enum Weight {
        HIGHEST = 4,
        HIGH,
        NORMAL,
        LOW,
        LOWEST
    };

    enum StatusCode {

        UndefinedStatusCode          = 0,

        Continue                     = 100,
        SwitchingProtocols           = 101,

        OK                           = 200,
        Created                      = 201,
        Accepted                     = 202,
        NonAuthoritativeInformation  = 203,
        NoContent                    = 204,
        ResetContent                 = 205,
        PartialContent               = 206,

        MultipleChoices              = 300,
        MovedPermanently             = 301,
        Found                        = 302,
        SeeOther                     = 303,
        NotModified                  = 304,
        UseProxy                     = 305,
        TemporaryRedirect            = 307,

        BadRequest                   = 400,
        Unauthorized                 = 401,
        PaymentRequired              = 402,
        Forbidden                    = 403,
        NotFound                     = 404,
        MethodNotAllowed             = 405,
        NotAcceptable                = 406,
        ProxyAuthenticationRequired  = 407,
        RequestTimeOut               = 408,
        Conflict                     = 409,
        Gone                         = 410,
        LengthRequired               = 411,
        PreconditionFailed           = 412,
        RequestEntityTooLarge        = 413,
        RequestURITooLarge           = 414,
        UnsupportedMediaType         = 415,
        RequestedRangeNotSatisfiable = 416,
        ExpectationFailed            = 417,

        InternalServerError          = 500,
        NotImplemented               = 501,
        BadGateway                   = 502,
        ServiceUnavailable           = 503,
        GatewayTimeOut               = 504,
        HTTPVersionNotSupported      = 505
    };

    enum Category {
        Undefined             = 0,
        Informational         = 100,
        Success               = 200,
        Redirection           = 300,
        ClientError           = 400,
        ServerError           = 500
    };
}

#endif //ZIA_ENUM_HH
