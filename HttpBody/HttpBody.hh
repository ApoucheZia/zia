//
// Created by Julien Karst on 05/01/2017.
//

#ifndef ZIA_HTTPBODY_HH
#define ZIA_HTTPBODY_HH

/*!
 * \file HttpBody.hh
 * \brief Http Object body, contains any type of data
 * \author Julien Karst
 * \version 0.1
 */

#include "IHttpBody.hh"

/*! \namespace apouche
 *
 * namespace that contains all http component
 */
namespace apouche {
    /*! \class HttpBody
    * \brief class that represent an HttpBody of a request or response
    *
    */
    class HttpBody: public IHttpBody {
        public:
            /*!
            *  \brief Destructor
            *
            *  Destructor of HttpBody
            */
            ~HttpBody();
            /*!
            *  \brief get data of HttpBody
            *
            *  Get all data of the HttpBody
            *
            *  \return std::string data of the HttpBody,
            */
            const std::string &getBody();
            /*!
            *  \brief set data of HttpBody
            *
            *  Set all data of the HttpBody
            *
            *  \return void,
            */
            void setBody(const std::string &);
        private:
            std::string _body;  /*!< any type of data in the http body*/
    };
}

#endif //ZIA_HTTPBODY_HH
