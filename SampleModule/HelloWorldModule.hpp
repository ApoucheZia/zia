//
// Created by Kevin Malot on 08/01/2017.
//

#ifndef ZIA_MYMODULE_HH
#define ZIA_MYMODULE_HH

#include "Module/AModule.hpp"


namespace apouche {

    /*
     *  HelloWorldModule.
     *  Test Module printing "Hello World"
     *  Inherits from AModule
     */
    class HelloWorldModule : public AModule {
    public:
        /*
         *  Default constructor.
         *  @param Logger* a pointer to a logger (default new apouche::Logger())
         */
        HelloWorldModule(apouche::Logger *log = new apouche::Logger()) : AModule("HelloWorldModule",
                                                                                 "Hello World !",
                                                                                 "1.0.1",
                                                                                 log){
        }

        /*
         * Default destructor
         */
        ~HelloWorldModule() {};

        /*
         * registerEvents function
         * @param EventHandler the EventHandler who will handle this module events
         */
        void registerEvents(EventHandler *_handler) {
            _logger->info(_name + " v" + _version + ": Event registering -> Request Informations printing");

            /* Bind de la méthode membre pour l'interpretation par l'événement*/
            auto function = std::bind(&HelloWorldModule::hello_world, this);
            /*Création de l'événement avec la fonction créée*/
            Event<> _event("HelloWorldEvent", Weight::HIGHEST, function);
            /*Ajout de l'événement dans la liste _voidEventList (définie dans EventHandler)*/
            _handler->_voidEventList.addEvent(_event);
        };

        /*
         * hello_world function
         * will be used as a module event to be called in the EventHandler
         */
        void hello_world() {
            _logger->debug(_name + " v" + _version + ": Hello World !");
        };
    };

    /*
     * Default extern "C" instanciation function
     * It will create a new HelloWorldModule after being builded in a .so or .dll
     * See dlopen / LoadLibrary for more details
     */
    extern "C" apouche::AModule *instantiate(){
        return new HelloWorldModule();
    }

    /*
     * Default extern "C" instanciation function with a Logger* as parameter
     * @param Logger* a pointer to a logger
     * It will create a new HelloWorldModule with its Logger after being builded in a .so or .dll
     * UseFull to send a new MyLogger.cpp extends Logger.cpp without compiling it in the module
     * For Example : QtLogger registering logs in a Qt Widget
     * See dlopen / LoadLibrary for more details
     */
    extern "C" apouche::AModule *instantiateWithLogger(apouche::Logger *log){
        return new HelloWorldModule(log);
    }
}

#endif //ZIA_MYMODULE_HH
