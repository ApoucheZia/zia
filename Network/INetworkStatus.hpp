/**
 * @file INetworkStatus.hpp
 * @brief Defines the interface INetworkStatus
 * @author Quentin Gasparotto
 * @version 1.0
 */

#ifndef ZIA_INETWORKSTATUS_HPP
#define ZIA_INETWORKSTATUS_HPP

#include <vector>
#include "../HttpRequest/IHttpRequest.hh"
#include "IZiaConnection.hpp"

namespace apouche
{
    /**
     * @brief This interface propose a protocol to implement a NetworkStatus class that will be used
     * @brief   through the callback <_onNetworkIO> in the EventHandler. This will allow the module to tell the core
     * @brief   which requests he received and which connections he established in order to call the rights events
     */
    class INetworkStatus
    {
    public:
        /**
         * @brief Enum that define the mode of connection inside the Network Status
         * @enum CONNECT is the mode that tells a connection was freshly established in order to call <EventHandler::_afterConnect> callback
         * @enum REQUEST is the mode that tells a connection has requests to treat in order to call request treatment callbacks
         */
        enum Treatment
        {
            CONNECT,
            REQUEST
        };

    public:
        virtual ~INetworkStatus(){}

        /**
         * @brief Allow zia core to get the list of connections in function of the mode requested
         * @param mode The mode of connections to get
         * @return The internal reference on the list of connections
         */
        virtual std::vector<IZiaConnection *> const &getConnections(Treatment const &mode) const = 0;

        /**
         * @brief Allow a network module to add a new connection on a specific mode
         * @param connection The connection to add
         * @param mode The mode in which add the connection
         */
        virtual void addConnection(IZiaConnection *connection, Treatment const &mode) = 0;

        /**
         * @brief Clear connections
         */
        virtual void clear() = 0;
    };
}

#endif //ZIA_INETWORKSTATUS_HPP
