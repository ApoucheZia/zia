//
// Created by mart_- on 05/01/17.
//

#ifndef ZIA_HTTPMESSAGE_HH
#define ZIA_HTTPMESSAGE_HH

/*!
 * \file HttpMessage.hh
 * \brief class that represent an IHttpMessage , that help you to create a HttpResponse or HttpRequest
 * \author Julien Karst
 * \version 0.1
 */


#include "../HttpBody/IHttpBody.hh"
#include "../HttpHeader/IHttpHeader.hh"
#include "IHttpMessage.hh"

/*! \namespace apouche
 *
 * namespace that contains all http component
 */
namespace apouche {
    /*! \class HttpMessage
    * \brief Class that represent an HttpMessage, common code of HttpRequest and HttpResponse
    *
    */
    class HttpMessage: public IHttpMessage {
    protected:
        IHttpHeader *_header;
        IHttpBody *_body;
        std::string _version;
    public:
        /*!
        *  \brief Constructor
        *
        *  Create your class with your own implementation of IHttpHeader and IHttpBody, you can also give our implementation
        *
        *  \param header: an implementation of IHttpHeader, body: an implementation of IHttpBody, version: http version of your message
        */
        HttpMessage(IHttpHeader *, IHttpBody *, const std::string &);
        /*!
        *  \brief Constructor
        */
        HttpMessage(){};
        /*!
        *  \brief Destructor
        *
        *  Destructor of HttpMessage
        */
        ~HttpMessage(){};
        /*!
        *  \brief Get the IHttpHeader of your message, you can give you own implementation or use our implementation.
        *
        *  Get the IHttpHeader of your message, you can give you own implementation or use our implementation.
        *
        *  \return apouche::IHttpHeader : Your header of the request or response
        */
        IHttpHeader *getHeaders();
        /*!
        *  \brief Set the IHttpHeader of your request or response
        *
        *  Set the IHttpHeader of your request or response
        *
        *  \param header : set the IHttpHeader of your request or response
        *  \return void
        */
        void setHeaders(IHttpHeader *header);
        /*!
        *  \brief Get the IHttpBody of your message, you can give you own implementation or use our implementation.
        *
        *  Get the IHttpBody of your message, you can give you own implementation or use our implementation.
        *
        *  \return apouche::IHttpBody: Your body of the request or response
        */
        IHttpBody *getBody();
        /*!
        *  \brief Set the IHttpBody of your request or response
        *
        *  Set the IHttpBody of your request or response
        *
        *  \param body : set the IHttpBody of your request or response
        *  \return void
        */
        void setBody(IHttpBody *body);
        /*!
        *  \brief Get the http version of your message.
        *
        *  Get the http version of your message.
        *
        *  \return std::string: The http version used for your request or response
        */
        const std::string &getVersion();
        /*!
        *  \brief Set the http version of your message.
        *
        *  Set the http version of your message.
        *
        *  \param version, The http version for your request or response
        */
        void setVersion(const std::string &version);
    };
}

#endif //ZIA_HTTPMESSAGE_HH
