//
// Created by mart_- on 07/01/17.
//

#ifndef ZIA_MODULE_HH
#define ZIA_MODULE_HH

/*!
 * \file HttpHeader.hh
 * \brief Http Object Header, contains header of a request or response
 * \author Kevin Malot
 * \version 0.1
 */

#include <string>
#include "EventHandler/EventHandler.hpp"
#include "Logger/Logger.hh"

/*! \namespace apouche
 *
 * namespace that contains all http component
 */

namespace apouche {
    /*! \class Abstract AModule
    * \brief class that represent a module abstraction
    *
    */
    class AModule {
    public:
        /*!
        *  \brief Destructor
        *
        *  Destructor of Module
        */
	virtual ~AModule() {
            _logger->info("Module '" + _name + "' (" + _desc + ") v" + _version + " Destroying ...");
        };
        /*!
        *  \brief Constructor
        *
        *  Constructor of Module
        */
        AModule(const std::string name, const std::string desc, const std::string version, apouche::Logger *log = new apouche::Logger())
            : _name(name), _desc(desc), _version(version), _logger(log){
            _logger->info("Module '" + _name + "' (" + _desc + ") v" + _version + " Registering ...");
        };
        /*!
            *  \brief Set the name
            *
            *  Set the name of module
            *
            *  \param name : std::string
            *  \return void
            */
        void    setName(const std::string &name){
            _name = name;
        }
        /*!
        *  \brief Get name
        *
        *  Get the name of module
        *
        *  \param void
        *  \return std::string, name of module
        */
        const   std::string &getName() const{
            return _name;
        };
        /*!
        *  \brief Set the description
        *
        *  Set the description of module
        *
        *  \param name : std::string
        *  \return void
        */
        void    setDesc(const std::string &desc){
            _desc = desc;
        };
        /*!
        *  \brief Get description
        *
        *  Get the description of module
        *
        *  \param void
        *  \return std::string, description of module
        */
        const   std::string &getDesc() const{
            return _desc;
        };
        /*!
        *  \brief Set the version
        *
        *  Set the version of module
        *
        *  \param name : std::string
        *  \return void
        */
        void    setVersion(const std::string &version){
            _version = version;
        };
        /*!
        *  \brief Get version
        *
        *  Get the version of description
        *
        *  \param void
        *  \return std::string, version of module
        */
        const   std::string &getVersion() const{
            return _version;
        };
        /*!
        *  \brief Register an events
        *
        *  Register an EventHandler
        *
        *  \param apouche::EventHandler *
        *  \return void
        */
        virtual void    registerEvents(EventHandler *) = 0;

    protected:
        std::string _name;
        std::string _desc;
        std::string _version;
        Logger      *_logger;
    };
}

#endif //ZIA_MODULE_HH
