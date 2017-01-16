//
// Created by mart_- on 05/01/17.
//

#ifndef ZIA_IHTTPREQUEST_HH
#define ZIA_IHTTPREQUEST_HH

/*!
 * \file IHttpRequest.hh
 * \brief Interface that represent an Http Object Request
 * \author Julien Karst
 * \version 0.1
 */

#include <string>
#include <map>
#include "../Enum.hh"
#include "../HttpHeader/IHttpHeader.hh"
#include "../HttpBody/IHttpBody.hh"
#include "../HttpMessage/IHttpMessage.hh"

/*! \namespace apouche
 *
 * namespace that contains all http component
 */
namespace apouche {
    /*! \interface IHttpRequest
    * \brief Interface that represent an Http Request
    *
    */
    class IHttpRequest: public IHttpMessage {
    public:
        /*!
        *  \brief Destructor
        *
        *  Destructor of HttpRequest
        */
        virtual ~IHttpRequest() {};
        /*!
        *  \brief Get the method of the header
        *
        *  Get the method of the header
        *
        *  \return apouche::Method : The type of the request, maybe post, get, etc...
        */
        virtual apouche::Method getMethod() const = 0;
        /*!
        *  \brief Set the method of the header
        *
        *  Set the method of the header
        *
        *  \param method : set the type of the request, maybe post, get, etc...
        */
        virtual void setMethod(apouche::Method)= 0;
        /*!
        *  \brief Get the uri
        *
        *  Get the uri
        *
        *  \return std::string : complete uri of the Header
        */
        virtual const std::string &getURI() const = 0;
        /*!
        *  \brief Set the uri of the header
        *
        *  Set the uri of the header
        *
        *  \param uri : set the uri of the request
        */
        virtual void setURI(const std::string &)= 0;
        /*!
        *  \brief Check if a get parameter is in the uri
        *
        *  Check if a get parameter is in the uri
        *
        *  \param key : a get parameter key in the uri
        *  \return bool : true if the key have a value
        */
        virtual bool containsUriParameters(const std::string &key) const = 0;
        /*!
        *  \brief Get all get parameters in the uri
        *
        *  Get all get parameters in the uri
        *
        *  \return std::map<std::string, std::string> : all get parameters in the uri
        */
        virtual const std::map<std::string, std::string> &getUriParameters() const = 0;
        /*!
        *  \brief Set all get parameters in the uri
        *
        *  Set all get parameters in the uri
        *
        *  \param map : all get parameters in the uri
        */
        virtual void setUriParameters(const std::map<std::string, std::string> &)= 0;
        /*!
        *  \brief Check if a get parameter is in the uri
        *
        *  Check if a get parameter is in the uri
        *
        *  \param key : a GET parameter key in the uri
        *  \return std::string : value of the key
        */
        virtual const std::string &getUriParameter(const std::string &key) const = 0;
        /*!
        *  \brief Set a get parameters in the uri
        *
        *  Set a get parameters in the uri
        *
        *  \param key : a GET parameter key in the uri
         * \param value : a GET parameters value in the uri
        */
        virtual void setUriParameter(const std::string &key, const std::string &value)= 0;
        /*!
        *  \brief Get the request line of your request
        *
        *  Get the request line of your request
        *
        *  \return std::string : the request line
        */
        virtual const std::string getRequestLine()= 0;
    };
}

#endif //ZIA_IHTTPREQUEST_HH
