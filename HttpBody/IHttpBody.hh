//
// Created by mart_- on 05/01/17.
//

#ifndef ZIA_IHTTPBODY_HH
#define ZIA_IHTTPBODY_HH

/*!
 * \file IHttpBody.hh
 * \brief Interface for Http Object body, should contains any type of data
 * \author Pierre Jean Martins
 * \version 0.1
 */

#include <string>

/*! \namespace apouche
 *
 * namespace that contains all http component
 */
namespace apouche {
    /*! \interface IHttpBody
    * \brief Interface that represent an HttpBody of a request or response
    *
    */
    class IHttpBody {
        public:
            /*!
            *  \brief Virtual Destructor
            *
            *  Virtual Destructor of IHttpBody
            */
            virtual ~IHttpBody() {};
            /*!
            *  \brief get data of HttpBody
            *
            *  Get all data of the HttpBody
            *
            *  \return std::string data of the HttpBody,
            */
            virtual const std::string &getBody() const = 0;
            /*!
            *  \brief set data of HttpBody
            *
            *  Set all data of the HttpBody
            *
            *  \return void,
            */
            virtual void setBody(const std::string &)= 0;
    };
}

#endif //ZIA_IHTTPBODY_HH
