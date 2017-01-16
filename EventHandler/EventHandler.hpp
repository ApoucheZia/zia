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
#include "../EventList/EventList.hpp"
#include "../HttpConf/IHttpConf.hpp"
#include "../HttpResponse/HttpResponse.hh"
#include "../HttpRequest/HttpRequest.hh"

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
        EventList<void, int> _afterConnect;
        EventList<void, HttpRequest *> _requestReceived;
        EventList<void, HttpRequest *> _beforeParsingRequest;
        EventList<void, HttpRequest *> _afterParsingRequest;
        EventList<void, HttpRequest *> _beforeCreateResponse;
        EventList<void, HttpRequest *, HttpResponse *> _afterCreateResponse;
        EventList<bool, HttpResponse *, IHttpConf *> _beforeSendResponse;
        EventList<void, int> _afterSendResponse;
      EventList<void> _voidEventList;
    };
}

#endif //ZIA_EVENTHANDLER_HH
