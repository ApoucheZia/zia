//
// Created by Kevin Malot on 08/01/2017.
//

#ifndef ZIA_PRINTINGMODULE_HH
#define ZIA_PRINTINGMODULE_HH

#include "../Module/AModule.hpp"

namespace apouche {

    class RequestInfoPrintingModule : public AModule {
    public:
        RequestInfoPrintingModule() : AModule("RequestInfoPrinting",
                                              "Print basic informations on a received request",
                                              "1.0.1") {
        }

        ~RequestInfoPrintingModule() {};

        void registerEvents(EventHandler *_handler) {
            _logger.info(_name + " v" + _version + ": Event registering -> Request Informations printing");

            auto function = std::bind(&RequestInfoPrintingModule::print_request_info, this, std::placeholders::_1);
            Event<void, HttpRequest *> _event("Print Request Informations", Weight::HIGH, function);

            _handler->_requestReceived.addEvent(_event);
        };

        void print_request_info(HttpRequest *request) {

            _logger.debug(_name + " v" + _version + ": " + request->getRequestLine());

            std::map<std::string, std::string> headers = request->getHeaders()->getAllHeader();

            for (std::map<std::string, std::string>::iterator it = headers.begin(); it != headers.end(); ++it)
                _logger.debug(_name + " v" + _version + ": " + "Header : " + it->first + " : " + it->second);

            _logger.debug(_name + " v" + _version + ": " + "Body : " + request->getBody()->getBody());
        };

        AModule *instantiate() const{
            return new RequestInfoPrintingModule();
        }
    };
    extern "C" apouche::AModule *instantiate(){
        return new RequestInfoPrintingModule();
    }
}

#endif //ZIA_MYMODULE_HH
