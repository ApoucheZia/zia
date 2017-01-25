//
// Created by PC on 08/01/2017.
//

#ifndef ZIA_RESPONSE_MODULE_HH
#define ZIA_RESPONSE_MODULE_HH

#include "Module/AModule.hpp"

namespace apouche {

    /*
    *  ResponseRewritingModule.
    *  Test Module rewriting a response send as parameter
    *  Inherits from AModule
    */
    class ResponseRewritingModule : public AModule {
    public:
        /*
        *  Default constructor.
        *  @param Logger* a pointer to a logger (default new apouche::Logger())
        */
        ResponseRewritingModule(apouche::Logger *log = new apouche::Logger()) : AModule("ResponseRewriting",
                                            "Basic response rewriting",
                                            "1.0.0", log) {
        }

        /*
        * Default destructor
        */
        ~ResponseRewritingModule() {};

        /*
        * registerEvents function
        * @param EventHandler the EventHandler who will handle this module events
        */
        void registerEvents(EventHandler *_handler) {
            _logger->info(_name + " v" + _version + ": Event registering -> Response rewriting");

            auto function = std::bind(&ResponseRewritingModule::rewrite_response, this, std::placeholders::_1, std::placeholders::_2);
            Event<bool(IHttpResponse *, IHttpConf *)> _event("Response Rewriting", Weight::HIGH, function);
            _handler->_beforeSendResponse.addEvent(_event);
        };

        /*
        * rewrite_response function
        * will be used as a module event to be called in the EventHandler
        * @param IHttpResponse* the response to be rewritten
        * @param IHttpConf* the server configuration
        */
        bool rewrite_response(IHttpResponse *response, IHttpConf *conf) {
            if (conf->getConf("module.response.rewriting") == "true")
            {
                response->getBody()->setBody("Rewritten Body !");
                return true;
            }
            return false;
        };
    };

    /*
     * Default extern "C" instanciation function
     * It will create a new ResponseRewritingModule after being builded in a .so or .dll
     * See dlopen / LoadLibrary for more details
     */
    extern "C" apouche::AModule *instantiate(){
        return new ResponseRewritingModule();
    }

    /*
     * Default extern "C" instanciation function with a Logger* as parameter
     * @param Logger* a pointer to a logger
     * It will create a new ResponseRewritingModule with its Logger after being builded in a .so or .dll
     * UseFull to send a new MyLogger.cpp extends Logger.cpp without compiling it in the module
     * For Example : QtLogger registering logs in a Qt Widget
     * See dlopen / LoadLibrary for more details
     */
    extern "C" apouche::AModule *instantiateWithLogger(apouche::Logger *log){
        return new ResponseRewritingModule(log);
    }
}

#endif //ZIA_MYMODULE_HH
