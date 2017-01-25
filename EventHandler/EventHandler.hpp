//
// Created by Kevin Malot on 07/01/17.
//

#ifndef ZIA_EVENTHANDLER_HH
#define ZIA_EVENTHANDLER_HH

/*!
 * \file HttpHeader.hh
 * \brief Http Object Header, contains header of a request or response
 * \author Kevin Malot
 * \version 0.1
 */

#include <map>
#include <functional>
#include <vector>
#include "EventList/EventList.hpp"
#include "HttpResponse/IHttpResponse.hh"
#include "HttpConf/IHttpConf.hpp"
#include "HttpRequest/IHttpRequest.hh"
#include "Network/INetworkStatus.hpp"
#include "Network/IZiaConnection.hpp"

/*! \namespace apouche
 *
 * namespace that contains all http component
 */
namespace apouche {
    /*! \class EventHandler
    * \brief class that represent an EventHandler
    *
    */
    class EventHandler {
    public:
        EventList<void(IHttpConf *, INetworkStatus *)> _onNetworkIO; // will handle network input/output operations
        EventList<void(IZiaConnection *, IHttpConf *)> _afterConnect;
        EventList<void(IHttpConf *)> _beforeParsingRequest;
        EventList<void(IHttpRequest *, IHttpConf *)> _afterParsingRequest;
        EventList<void(IHttpRequest *, IHttpConf *, IZiaConnection *)> _requestReceived;
        EventList<void(IHttpRequest *, IHttpConf *)> _beforeCreateResponse;
        EventList<void(IHttpRequest *, IHttpResponse *, IHttpConf *)> _afterCreateResponse;
        EventList<bool(IHttpResponse *, IHttpConf *)> _beforeSendResponse;
        EventList<void(IZiaConnection*)> _afterSendResponse;
        EventList<> _voidEventList;

        /*
         * Clear All EventLists
         */
        void clear() {
            _onNetworkIO.clear();
            _afterConnect.clear();
            _requestReceived.clear();
            _beforeParsingRequest.clear();
            _afterParsingRequest.clear();
            _beforeCreateResponse.clear();
            _afterCreateResponse.clear();
            _beforeSendResponse.clear();
            _afterSendResponse.clear();
            _voidEventList.clear();
        }
    };
}

#endif //ZIA_EVENTHANDLER_HH
