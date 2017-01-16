//
// Created by Julien Karst on 05/01/2017.
//

#ifndef ZIA_HTTPRESPONSE_HH
#define ZIA_HTTPRESPONSE_HH

/*!
 * \file HttpResponse.hh
 * \brief Http Object response, contains any type of data
 * \author mart_-
 * \version 0.1
 */

#include "../Enum.hh"
#include "../HttpMessage/HttpMessage.hh"

/*! \namespace apouche
 *
 * namespace that contains all http component
 */
namespace apouche {
    /*! \class HttpResponse
    * \brief class that represent an HttpResponse of a response
    *
    */
    class HttpResponse: public HttpMessage {
    private:
        apouche::StatusCode _status;  /*!< apouche::StatusCode. status code */
        std::map<apouche::StatusCode, std::string> _message; /*!< std::map<apouche::StatusCode>. description of status code */
    public:
        /*!
            *  \brief Constructor
            *
            *  Constructor of HttpResponse
            *
            *  \param header : the header of the http response, the body of the http response, version http
            */
        HttpResponse(IHttpHeader *header, IHttpBody *body, const std::string &version);
        /*!
            *  \brief Destructor
            *
            *  Destructor of HttpResponse
            */
        ~HttpResponse();
        /*!
            *  \brief Get status code
            *
            *  Get the status code of the response
            *
            *  \param void
            *  \return apouche::StatusCode, status code
            */
        const apouche::StatusCode &getStatus();
        /*!
            *  \brief Set status code
            *
            *  Set the status code of the response
            *
            *  \param status code : apouche::StatusCode
            *  \return void
            */
        void setStatus(const apouche::StatusCode &);
        /*!
            *  \brief Get status code description
            *
            *  Get the status code of the response
            *
            *  \param void
            *  \return std::string, description status code
            */
        const std::string getStatusDescription();
        /*!
            *  \brief Get the description of the status code
            *
            *  Get the description of the status code
            *
            *  \param void
            *  \return std::string, the status of response
            */
        const std::string getResponseLine();
    };
}

#endif //ZIA_HTTPRESPONSE_HH
