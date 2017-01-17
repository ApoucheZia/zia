//
// Created by Julien Karst on 05/01/2017.
//

#ifndef ZIA_HTTPHEADER_HH
#define ZIA_HTTPHEADER_HH

/*!
 * \file HttpHeader.hh
 * \brief Http Object Header, contains header of a request or response
 * \author Julien Karst
 * \version 0.1
 */

#include "IHttpHeader.hh"

/*! \namespace apouche
 *
 * namespace that contains all http component
 */
namespace apouche {
    /*! \class HttpHeader
    * \brief class that represent an HttpHeader of a request or response
    *
    */
    class HttpHeader: public IHttpHeader {
        public:
            /*!
            *  \brief Destructor
            *
            *  Destructor of HttpHeader
            */
            ~HttpHeader();
            /*!
            *  \brief get map of the header
            *
            *  Get map of the header
            *
            *  \return std::map<std::string, std::string> data of the HttpHeader
            */
            const std::map<std::string, std::string> &getAllHeader() const override ;
            /*!
            *  \brief Set map of header object
            *
            *  Set the header
            *
            *  \param header : the header of the http request or response, in key, value format
            *  \return void
            */
            void setAllHeaders(const std::map<std::string, std::string> &) override;
            /*!
            *  \brief Get value of a specific key of the Header
            *
            *  Get value of a specific key of the Header
            *
            *  \param key : the header key of the http request or response, each key contains a value
            *  \return std::string, value of the key
            */
            const std::string &getHeader(const std::string &key) const override;
            /*!
            *  \brief set value of a specific key
            *
            *  Set value of a specific key
            *
            *  \param key : the header key of the http request or response each key contains a value
            *  \param value : data associated with the key
            *  \return void
            */
            void setHeader(const std::string &key, const std::string &value) override;
            /*!
            *  \brief Remove a key and value from the map
            *
            *  Remove a pair key value from the map
            *
            *  \param key : the header key of the http request or response, each key contains a value, the key and the value are deleted from the map
            *  \return void
            */
            void deleteHeader(const std::string &) override;
            /*!
            *  \brief Check if a key is in the Header
            *
            *  Check if a key is in the Header
            *
            *  \param key : the header key of the http request or response, each key contains a value
            *  \return true if the key is in the header,
            * false if the key is not in the header
            */
            bool containsHeader(const std::string &) const override;

        protected:
            std::map<std::string, std::string> _header;
    };
}

#endif //ZIA_HTTPHEADER_HH
