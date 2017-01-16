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
        virtual apouche::StatusCode getStatus() const = 0;
        /*!
            *  \brief Set status code
            *
            *  Set the status code of the response
            *
            *  \param status code : apouche::StatusCode
            *  \return void
            */
        virtual void setStatus(apouche::StatusCode)= 0;
        /*!
            *  \brief Get status code description
            *
            *  Get the status code of the response
            *
            *  \param void
            *  \return std::string, description status code
            */
        virtual const std::string &getStatusDescription() const = 0;
        /*!
            *  \brief Get the description of the status code
            *
            *  Get the description of the status code
            *
            *  \param void
            *  \return std::string, the status of response
            */
        virtual const std::string getResponseLine() const = 0;
    };
}

#endif //ZIA_IHTTPRESPONSE_H
