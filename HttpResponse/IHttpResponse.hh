//
// Created by Julien Karst on 05/01/2017.
//

#ifndef ZIA_IHTTPRESPONSE_H
#define ZIA_IHTTPRESPONSE_H

/*!
 * \file IHttpResponse.hh
 * \brief Interface of Http Object response
 * \author Julien Karst
 * \version 0.1
 */


#include <string>
#include "../Enum.hh"
#include "../HttpHeader/IHttpHeader.hh"
#include "../HttpBody/IHttpBody.hh"
#include "../HttpMessage/IHttpMessage.hh"

/*! \namespace apouche
 *
 * namespace that contains all http component
 */
namespace apouche {
    /*! \interface IHttpResponse
    * \brief Interface that represent an Http Response
    *
    */
    class IHttpResponse: public IHttpMessage {
        public:
        /*!
        *  \brief Destructor
        *
        *  Destructor of HttpResponse
        */
        virtual ~IHttpResponse() {};
        /*!
            *  \brief Get status code
            *
            *  Get the status code of the response
            *
            *  \param void
            *  \return apouche::StatusCode, status code
            */
        virtual const apouche::StatusCode &getStatus()= 0;
        /*!
            *  \brief Set status code
            *
            *  Set the status code of the response
            *
            *  \param status code : apouche::StatusCode
            *  \return void
            */
        virtual void setStatus(const apouche::StatusCode &)= 0;
        /*!
            *  \brief Get status code description
            *
            *  Get the status code of the response
            *
            *  \param void
            *  \return std::string, description status code
            */
        virtual const std::string getStatusDescription()= 0;
        /*!
            *  \brief Get the description of the status code
            *
            *  Get the description of the status code
            *
            *  \param void
            *  \return std::string, the status of response
            */
        virtual const std::string getResponseLine()= 0;
        /*!
        *  \brief Get the IHttpHeader of your response
        *
        *  Get the IHttpHeader of your response
        *
        *  \return apouche::IHttpHeader : Your header of the response
        */
        virtual IHttpHeader *getHeaders()= 0;
        /*!
        *  \brief Set the IHttpHeader of your response
        *
        *  Set the IHttpHeader of your response
        *
        *  \param header : set the IHttpHeader of your response
        *  \return void
        */
        virtual void setHeaders(IHttpHeader *header)= 0;
        /*!
        *  \brief Get the IHttpBody of your response, you can give you own implementation or use our implementation.
        *
        *  Get the IHttpBody of your response, you can give you own implementation or use our implementation.
        *
        *  \return apouche::IHttpBody: Your body of the response or response
        */
        virtual IHttpBody *getBody()= 0;
        /*!
        *  \brief Set the IHttpBody of your response
        *
        *  Set the IHttpBody of your response
        *
        *  \param body : set the IHttpBody of your response
        *  \return void
        */
        virtual void setBody(IHttpBody *body)= 0;
        /*!
        *  \brief Get the http version of your response.
        *
        *  Get the http version of your response.
        *
        *  \return std::string: The http version used for your response
        */
        virtual const std::string &getVersion()= 0;
        /*!
        *  \brief Set the http version of your response.
        *
        *  Set the http version of your response.
        *
        *  \param version, The http version for your response
        */
        virtual void setVersion(const std::string &version)= 0;
    };
}

#endif //ZIA_IHTTPRESPONSE_H
