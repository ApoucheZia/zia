//
// Created by Kevin Malot on 08/01/2017.
//

#ifndef ZIA_PRINTINGMODULE_HH
#define ZIA_PRINTINGMODULE_HH

#include "Module/AModule.hpp"

namespace apouche {

    /*
    *  RequestInfoPrintingModule.
    *  Test Module printing all informations on a request send as parameter
    *  Inherits from AModule
    */
    class RequestInfoPrintingModule : public AModule {
    public:
        /*
        *  Default constructor.
        *  @param Logger* a pointer to a logger (default new apouche::Logger())
        */
        RequestInfoPrintingModule(apouche::Logger *log = new apouche::Logger()) : AModule("RequestInfoPrinting",
                                              "Print basic informations on a received request",
                                              "1.0.1", log) {
        }

        /*
        * Default destructor
        */
        ~RequestInfoPrintingModule() {};

        /*
        * registerEvents function
        * @param EventHandler the EventHandler who will handle this module events
        */
        void registerEvents(EventHandler *_handler) {
            _logger->info(_name + " v" + _version + ": Event registering -> Request Informations printing");

            auto function = std::bind(&RequestInfoPrintingModule::print_request_info, this, std::placeholders::_1, std::placeholders::_2);
            Event<void(IHttpRequest *, IHttpConf *)> _event("Print Request Informations", Weight::HIGH, function);

            _handler->_requestReceived.addEvent(_event);
        };

        /*
        * print_request_info function
        * will be used as a module event to be called in the EventHandler
        * @param IHttpRequest* the request to be printed
        * @param IHttpConf* the server configuration
        */
        void print_request_info(IHttpRequest *request, IHttpConf *conf) {

            _logger->debug(_name + " v" + _version + ": " + request->getRequestLine());

            std::map<std::string, std::string> headers = request->getHeaders()->getAllHeader();

            for (std::map<std::string, std::string>::iterator it = headers.begin(); it != headers.end(); ++it)
                _logger->debug(_name + " v" + _version + ": " + "Header : " + it->first + " : " + it->second);

            _logger->debug(_name + " v" + _version + ": " + "Body : " + request->getBody()->getBody());
        };
    };

    /*
     * Default extern "C" instanciation function
     * It will create a new RequestInfoPrintingModule after being builded in a .so or .dll
     * See dlopen / LoadLibrary for more details
     */
    extern "C" apouche::AModule *instantiate(){
        return new RequestInfoPrintingModule();
    }

    /*
     * Default extern "C" instanciation function with a Logger* as parameter
     * @param Logger* a pointer to a logger
     * It will create a new RequestInfoPrintingModule with its Logger after being builded in a .so or .dll
     * UseFull to send a new MyLogger.cpp extends Logger.cpp without compiling it in the module
     * For Example : QtLogger registering logs in a Qt Widget
     * See dlopen / LoadLibrary for more details
     */
    extern "C" apouche::AModule *instantiateWithLogger(apouche::Logger *log){
        return new RequestInfoPrintingModule(log);
    }
}

#endif //ZIA_MYMODULE_HH
