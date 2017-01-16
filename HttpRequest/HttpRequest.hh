//
// Created by mart_- on 05/01/17.
//

#ifndef ZIA_HTTPREQUEST_HH
#define ZIA_HTTPREQUEST_HH

/*!
 * \file HttpRequest.hh
 * \brief Http Object Request, representation of a request
 * \author Julien Karst
 * \version 0.1
 */

#include "../HttpMessage/HttpMessage.hh"
#include "../Enum.hh"

/*! \namespace apouche
 *
 * namespace that contains all http component
 */
namespace apouche {
    /*! \class HttpRequest
    * \brief class that represent an HttpRequest
    *
    */
    class HttpRequest: public HttpMessage {
    private:
        apouche::Method _method; /*!< apouche::Method. Type of method, may be post, get, etc */
        std::string _URI; /*!< std::string. complete uri */
        std::map<std::string, std::string> _uriParameters; /*!< std::map <std::string,  std::string>. get parameters in the uri */
        static const std::map<apouche::Method, std::string> _mapMethodFromEnum; /*!< std::map <apouche::Method,  std::string>. get std::string from apouche::Method */
        static const std::map<std::string, apouche::Method> _mapMethodFromName; /*!< std::map <std::string, apouche::Method>. get apouche::Method from std::string */
    public:
        /*!
        *  \brief Construct an HttpRequest
        *
        *  Create an HttpRequest
        *
        *  \param message : the message recieved from the server, body : an implementation of IHttpBody, header : an implementation of IHttpHeader
        */

        HttpRequest(const std::string &message, apouche::IHttpBody *, apouche::IHttpHeader *);

        /*!
        *  \brief Destructor
        *
        *  Destructor of HttpRequest
        */
        ~HttpRequest();

        /*!
        *  \brief Get the method of the header
        *
        *  Get the method of the header
        *
        *  \return apouche::Method : The type of the request, maybe post, get, etc...
        */
        const apouche::Method &getMethod();

        /*!
        *  \brief Set the method of the header
        *
        *  Set the method of the header
        *
        *  \param method : set the type of the request, maybe post, get, etc...
        *  \return void
        */
        void setMethod(const apouche::Method &);

        /*!
        *  \brief Get the uri
        *
        *  Get the uri
        *
        *  \return std::string : complete uri of the Header
        */
        const std::string &getURI();

        /*!
        *  \brief Set the uri of the header
        *
        *  Set the uri of the header
        *
        *  \param uri : set the uri of the request
        */
        void setURI(const std::string &);

        /*!
        *  \brief Check if a get parameter is in the uri
        *
        *  Check if a get parameter is in the uri
        *
        *  \param key : a get parameter key in the uri
        *  \return bool : true if the key have a value
        */
        const bool containsUriParameters(const std::string &);

        /*!
        *  \brief Get all get parameters in the uri
        *
        *  Get all get parameters in the uri
        *
        *  \return std::map<std::string, std::string> : all get parameters in the uri
        */
        std::map<std::string, std::string> getUriParameters();

        /*!
        *  \brief Set all get parameters in the uri
        *
        *  Set all get parameters in the uri
        *
        *  \param map : all get parameters in the uri
        */
        void setUriParameters(const std::map<std::string, std::string> &);

        /*!
        *  \brief Check if a get parameter is in the uri
        *
        *  Check if a get parameter is in the uri
        *
        *  \param key : a get parameter key in the uri
        *  \return std::string : value of the key
        */
        const std::string &getUriParameter(const std::string &);

        /*!
        *  \brief Set a get parameters in the uri
        *
        *  Set a get parameters in the uri
        *
        *  \param key : a get parameter key in the uri, value : a get parameters value in the uri
        */
        void setUriParameter(const std::string &, const std::string &);

        /*!
        *  \brief Get the request line of your request
        *
        *  Get the request line of your request
        *
        *  \return std::string : the request line
        */
        const std::string getRequestLine();
    };
}

#endif //ZIA_HTTPREQUEST_HH
