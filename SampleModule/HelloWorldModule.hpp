//
// Created by Kevin Malot on 08/01/2017.
//

#ifndef ZIA_MYMODULE_HH
#define ZIA_MYMODULE_HH

#include "../Module/AModule.hpp"

namespace apouche {

    class HelloWorldModule : public AModule {
    public:
        HelloWorldModule() : AModule("HelloWorldModule",
                                              "Hello World !",
                                              "1.0.1") {
        }

        ~HelloWorldModule() {};

        void registerEvents(EventHandler *_handler) {
            _logger.info(_name + " v" + _version + ": Event registering -> Request Informations printing");

            /* Bind de la méthode membre pour l'interpretation par l'événement*/
            auto function = std::bind(&HelloWorldModule::hello_world, this);
            /*Création de l'événement avec la fonction créée*/
            Event<> _event("HelloWorldEvent", Weight::HIGHEST, function);
            /*Ajout de l'événement dans la liste _voidEventList (définie dans EventHandler)*/
            _handler->_voidEventList.addEvent(_event);
        };

        void hello_world() {
            _logger.debug(_name + " v" + _version + ": Hello World !");
        };
    };

    extern "C" apouche::AModule *instantiate(){
        return new HelloWorldModule();
    }
}

#endif //ZIA_MYMODULE_HH
