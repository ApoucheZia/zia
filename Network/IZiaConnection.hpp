/**
 * @file IZiaConnection.hpp
 * @brief Defines the interface IZiaConnection
 * @author Quentin Gasparotto
 * @version 1.0
 */

#ifndef ZIA_IZIACONNECTION_HPP
#define ZIA_IZIACONNECTION_HPP

#include <vector>
#include "HttpResponse/IHttpResponse.hh"
#include "HttpRequest/IHttpRequest.hh"

namespace apouche
{
    /**
     * @brief Interface that encaplusate a Zia connection. In this protocol you are allowed to get the internal socket
     * @brief  to receive an http request or to send an http response
     */
    class IZiaConnection
    {
    public:
        virtual ~IZiaConnection(){}

        /**
         * @brief Type definition for clarity in the code
         */
        using NativeHandle = int;

        /**
         * @brief Allow any one to get the internal file descriptor of the socket
         * @return The native socket qualifier
         */
        virtual NativeHandle getNativeHandle() const = 0;

        /**
         * @brief Tells the connection to receive one or more requests an internally store it. Will clear the internal list before.
         * @return The number of requests, received or -1 if an error occured
         */
        virtual int ReceiveRequest() = 0;

        /**
         * @brief Allow core to send response to a connection
         * @param response The response to send
         * @return Tell if the sent succeds. Return of (send, write, or anything)
         */
        virtual int SendResponse(IHttpResponse *response) = 0;

        /**
         * @brief Allow core to get the list of requests the connection received
         * @return The internal list of requests freshly received
         */
        virtual std::vector<IHttpRequest *> const &getRequests() const = 0;

        /**
         * @brief Get the next request pending inside the Connection
         * @return A new HttpRequest
         */
        virtual IHttpRequest    *getNextRequest() = 0;
    };
}

#endif //ZIA_IZIACONNECTION_HPP
