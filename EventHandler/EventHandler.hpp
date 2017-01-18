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
#include "../HttpResponse/IHttpResponse.hh"
#include "../HttpConf/IHttpConf.hpp"
#include "../HttpRequest/IHttpRequest.hh"

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
        EventList<void, int, IHttpConf *> _afterConnect;
        EventList<void, IHttpRequest *, IHttpConf *> _requestReceived;
        EventList<void, IHttpRequest *, IHttpConf *> _beforeParsingRequest;
        EventList<void, IHttpRequest *, IHttpConf *> _afterParsingRequest;
        EventList<void, IHttpRequest *, IHttpConf *> _beforeCreateResponse;
        EventList<void, IHttpRequest *, IHttpResponse *, IHttpConf *> _afterCreateResponse;
        EventList<bool, IHttpResponse *, IHttpConf *> _beforeSendResponse;
        EventList<void, int> _afterSendResponse;
      EventList<void> _voidEventList;
    };
}

#endif //ZIA_EVENTHANDLER_HH
