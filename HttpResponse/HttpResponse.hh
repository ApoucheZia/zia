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

#include "IHttpResponse.hh"

/*! \namespace apouche
 *
 * namespace that contains all http component
 */
namespace apouche {
    /*! \class HttpResponse
    * \brief class that represent an HttpResponse of a response
    *
    */
    class HttpResponse: public IHttpResponse {
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
        /*!
        *  \brief Get the IHttpHeader of your response
        *
        *  Get the IHttpHeader of your response
        *
        *  \return apouche::IHttpHeader : Your header of the response
        */
        IHttpHeader *getHeaders();
        /*!
        *  \brief Set the IHttpHeader of your response
        *
        *  Set the IHttpHeader of your response
        *
        *  \param header : set the IHttpHeader of your response
        *  \return void
        */
        void setHeaders(IHttpHeader *header);
        /*!
        *  \brief Get the IHttpBody of your response, you can give you own implementation or use our implementation.
        *
        *  Get the IHttpBody of your response, you can give you own implementation or use our implementation.
        *
        *  \return apouche::IHttpBody: Your body of the response or response
        */
        IHttpBody *getBody();
        /*!
        *  \brief Set the IHttpBody of your response
        *
        *  Set the IHttpBody of your response
        *
        *  \param body : set the IHttpBody of your response
        *  \return void
        */
        void setBody(IHttpBody *body);
        /*!
        *  \brief Get the http version of your response.
        *
        *  Get the http version of your response.
        *
        *  \return std::string: The http version used for your response
        */
        const std::string &getVersion();
        /*!
        *  \brief Set the http version of your response.
        *
        *  Set the http version of your response.
        *
        *  \param version, The http version for your response
        */
        void setVersion(const std::string &version);
    private:
        IHttpHeader *_header; /*!< apouche::IHttpHeader. Http header of your Response */
        IHttpBody *_body; /*!< apouche::IHttpBody. Http body of your Response */
        std::string _version; /*!< std::string. Http version of your Response */
        apouche::StatusCode _status;  /*!< apouche::StatusCode. status code */
        std::map<apouche::StatusCode, std::string> _message; /*!< std::map<apouche::StatusCode>. description of status code */
    };
}

#endif //ZIA_HTTPRESPONSE_HH
