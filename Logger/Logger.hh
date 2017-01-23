//
// Created by mart_- on 05/01/17.
//

#ifndef ZIA_LOGGER_HH
#define ZIA_LOGGER_HH

/*!
 * \file Logger.hh
 * \brief Simple logger class
 * \author Julien Karst
 * \version 0.1
 */

#include <string>

/*! \namespace apouche
 *
 * namespace that contains all http component
 */
namespace apouche {
    /*! \class Logger
    * \brief class that represent a logger
    *
    */
    class Logger {
    public:
        /*!
        *  \brief Destructor
        *
        *  Destructor of Logger
        */
        virtual ~Logger() {};
        /*!
        *  \brief write the debug message
        *
        *  write a debug message in the output
        *
        *  \param std::string : message
        *  \return void
        */
        virtual void debug(const std::string &message);
        /*!
        *  \brief write the error message
        *
        *  write a error message in the output
        *
        *  \param std::string : message
        *  \return void
        */
        virtual void error(const std::string &message);
        /*!
        *  \brief write the fatal message
        *
        *  write a fatal message in the output
        *
        *  \param std::string : message
        *  \return void
        */
        virtual void fatal(const std::string &message);
        /*!
        *  \brief write the info message
        *
        *  write a info message in the output
        *
        *  \param std::string : message
        *  \return void
        */
        virtual void info(const std::string &message);
        /*!
        *  \brief write the warning message
        *
        *  write a warning message in the output
        *
        *  \param std::string : message
        *  \return void
        */
        virtual void warning(const std::string &message);
        /*!
        *  \brief write the message
        *
        *  write a message in the output
        *
        *  \param std::string : message
        *  \return void
        */
        virtual void write(const std::string &message);
    };

}

#endif //ZIA_LOGGER_HH
