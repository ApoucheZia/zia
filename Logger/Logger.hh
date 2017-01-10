//
// Created by mart_- on 05/01/17.
//

#ifndef ZIA_LOGGER_HH
#define ZIA_LOGGER_HH

/*!
 * \file HttpHeader.hh
 * \brief Http Object Header, contains header of a request or response
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
        void debug(const std::string &message);
        /*!
        *  \brief write the error message
        *
        *  write a error message in the output
        *
        *  \param std::string : message
        *  \return void
        */
        void error(const std::string &message);
        /*!
        *  \brief write the fatal message
        *
        *  write a fatal message in the output
        *
        *  \param std::string : message
        *  \return void
        */
        void fatal(const std::string &message);
        /*!
        *  \brief write the info message
        *
        *  write a info message in the output
        *
        *  \param std::string : message
        *  \return void
        */
        void info(const std::string &message);
        /*!
        *  \brief write the warning message
        *
        *  write a warning message in the output
        *
        *  \param std::string : message
        *  \return void
        */
        void warning(const std::string &message);
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
