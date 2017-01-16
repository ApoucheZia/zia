//
// Created by mart_- on 05/01/17.
//

#ifndef ZIA_IHTTPHEADER_HH
#define ZIA_IHTTPHEADER_HH

/*!
 * \file IHttpHeader.hh
 * \brief Http Object Header, contains header of a request or response
 * \author Pierre jean martin
 * \version 0.1
 */

#include <map>
#include <string>

/*! \namespace apouche
 *
 * namespace that contains all http component
 */
namespace apouche {
    /*! \interface IHttpHeader
    * \brief Interface that represent an Http header of a request or response
    *
    */
    class IHttpHeader {
    public:
        /*!
        *  \brief Virtual Destructor
        *
        *  Virtual Destructor of IHttpHeader
        */
        virtual ~IHttpHeader() {};
        /*!
        *  \brief Set map of header object
        *
        *  Set the header
        *
        *  \param header : the header of the http request or response, in key, value format
        *  \return void
        */
        virtual const std::map<std::string, std::string> &getAllHeader() const = 0;
        /*!
        *  \brief Set map of header object
        *
        *  Set the header
        *
        *  \param header : the header of the http request or response, in key, value format
        *  \return void
        */
        virtual void setAllHeaders(const std::map<std::string, std::string> &)= 0;
        /*!
        *  \brief Get value of a specific key of the Header
        *
        *  Get value of a specific key of the Header
        *
        *  \param key : the header key of the http request or response, each key contains a value
        *  \return std::string, value of the key
        */
        virtual const std::string &getHeader(const std::string &key) const= 0;
        /*!
        *  \brief set value of a specific key
        *
        *  Set value of a specific key
        *
        *  \param key : the header key of the http request or response each key contains a value
        *  \param value : data associated with the key
        *  \return void
        */
        virtual void setHeader(const std::string &key, const std::string &value)= 0;
        /*!
        *  \brief Remove a key and value from the map
        *
        *  Remove a pair key value from the map
        *
        *  \param key : the header key of the http request or response, each key contains a value, the key and the value are deleted from the map
        *  \return void
        */
        virtual void deleteHeader(const std::string &)= 0;
        /*!
        *  \brief Check if a key is in the Header
        *
        *  Check if a key is in the Header
        *
        *  \param key : the header key of the http request or response, each key contains a value
        *  \return true if the key is in the header,
        * false if the key is not in the header
        */
        virtual bool containsHeader(const std::string &) const = 0;
    };
}

#endif //ZIA_IHTTPHEADER_HH
