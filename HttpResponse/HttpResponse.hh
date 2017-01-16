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
        apouche::StatusCode getStatus() const override;
        /*!
            *  \brief Set status code
            *
            *  Set the status code of the response
            *
            *  \param status code : apouche::StatusCode
            *  \return void
            */
        void setStatus(apouche::StatusCode) override;
        /*!
            *  \brief Get status code description
            *
            *  Get the status code of the response
            *
            *  \param void
            *  \return std::string, description status code
            */
        const std::string &getStatusDescription() const override;
        /*!
            *  \brief Get the description of the status code
            *
            *  Get the description of the status code
            *
            *  \param void
            *  \return std::string, the status of response
            */
        const std::string getResponseLine() const override;
        /*!
        *  \brief Get the IHttpHeader of your response
        *
        *  Get the IHttpHeader of your response
        *
        *  \return apouche::IHttpHeader : Your header of the response
        */
        IHttpHeader *getHeaders() override;
        /*!
         * \brief Constant version of getHeaders()
         * @return apouche::IHttpHeader: Your header of the request or response
         */
        const IHttpHeader *getHeaders() const override;
        /*!
        *  \brief Set the IHttpHeader of your response
        *
        *  Set the IHttpHeader of your response
        *
        *  \param header : set the IHttpHeader of your response
        *  \return void
        */
        void setHeaders(IHttpHeader *header) override;
        /*!
        *  \brief Get the IHttpBody of your response, you can give you own implementation or use our implementation.
        *
        *  Get the IHttpBody of your response, you can give you own implementation or use our implementation.
        *
        *  \return apouche::IHttpBody: Your body of the response or response
        */
        IHttpBody *getBody() override;
        /*!
         * \brief Constant version of getBody()
         * @return apouche::IHttpBody: Your body of the request or response
         */
        const IHttpBody *getBody() const override;
        /*!
        *  \brief Set the IHttpBody of your response
        *
        *  Set the IHttpBody of your response
        *
        *  \param body : set the IHttpBody of your response
        *  \return void
        */
        void setBody(IHttpBody *body) override;
        /*!
        *  \brief Get the http version of your response.
        *
        *  Get the http version of your response.
        *
        *  \return std::string: The http version used for your response
        */
        const std::string &getVersion() const override;
        /*!
        *  \brief Set the http version of your response.
        *
        *  Set the http version of your response.
        *
        *  \param version, The http version for your response
        */
        void setVersion(const std::string &version) override;
    private:
        IHttpHeader *_header; /*!< apouche::IHttpHeader. Http header of your Response */
        IHttpBody *_body; /*!< apouche::IHttpBody. Http body of your Response */
        std::string _version; /*!< std::string. Http version of your Response */
        apouche::StatusCode _status;  /*!< apouche::StatusCode. status code */
        static const std::map<apouche::StatusCode, std::string> _message; /*!< std::map<apouche::StatusCode>. description of status code */
    };
}

#endif //ZIA_HTTPRESPONSE_HH
