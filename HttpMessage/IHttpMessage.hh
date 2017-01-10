//
// Created by mart_- on 05/01/17.
//

#ifndef ZIA_IHTTPMESSAGE_HH
#define ZIA_IHTTPMESSAGE_HH

/*!
 * \file IHttpMessage.hh
 * \brief Interface that represent an Http Object Message, that help you to create a HttpResponse or HttpRequest
 * \author Julien Karst
 * \version 0.1
 */

#include "../HttpHeader/IHttpHeader.hh"
#include "../HttpBody/IHttpBody.hh"

/*! \namespace apouche
 *
 * namespace that contains all http component
 */
namespace apouche {
    /*! \interface IHttpMessage
    * \brief Interface that represent an Http Message, common code of HttpRequest and HttpResponse
    *
    */
    class IHttpMessage {
    public:
        /*!
        *  \brief Destructor
        *
        *  Destructor of HttpMessage
        */
        virtual ~IHttpMessage() {};
        /*!
        *  \brief Get the IHttpHeader of your message, you can give you own implementation or use our implementation.
        *
        *  Get the IHttpHeader of your message, you can give you own implementation or use our implementation.
        *
        *  \return apouche::IHttpHeader : Your header of the request or response
        */
        virtual IHttpHeader *getHeaders()= 0;
        /*!
        *  \brief Set the IHttpHeader of your request or response
        *
        *  Set the IHttpHeader of your request or response
        *
        *  \param header : set the IHttpHeader of your request or response
        *  \return void
        */
        virtual void setHeaders(IHttpHeader *header)= 0;
        /*!
        *  \brief Get the IHttpBody of your message, you can give you own implementation or use our implementation.
        *
        *  Get the IHttpBody of your message, you can give you own implementation or use our implementation.
        *
        *  \return apouche::IHttpBody: Your body of the request or response
        */
        virtual IHttpBody *getBody()= 0;
        /*!
        *  \brief Set the IHttpBody of your request or response
        *
        *  Set the IHttpBody of your request or response
        *
        *  \param body : set the IHttpBody of your request or response
        *  \return void
        */
        virtual void setBody(IHttpBody *body)= 0;
        /*!
        *  \brief Get the http version of your message.
        *
        *  Get the http version of your message.
        *
        *  \return std::string: The http version used for your request or response
        */
        virtual const std::string &getVersion()= 0;
        /*!
        *  \brief Set the http version of your message.
        *
        *  Set the http version of your message.
        *
        *  \param version, The http version for your request or response
        */
        virtual void setVersion(const std::string &version)= 0;
    };
}

#endif //ZIA_IHTTPMESSAGE_HH
