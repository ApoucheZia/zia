//
// Created by Julien Karst on 05/01/2017.
//

#ifndef ZIA_FILELOGGER_HH
#define ZIA_FILELOGGER_HH

/*!
 * \file HttpHeader.hh
 * \brief Http Object Header, contains header of a request or response
 * \author Julien Karst
 * \version 0.1
 */

#include "Logger.hh"
#include <fstream>

/*! \namespace apouche
 *
 * namespace that contains all http component
 */
namespace apouche {
    /*! \class FileLogger
    * \brief class that represent a Filelogger
    *
    */
    class FileLogger: public Logger {
    protected:
        std::string _filename;
        std::fstream _file;
    public:
        /*!
        *  \brief Constructor
        *
        *  Constructor of FileLogger
        */
        FileLogger();
        /*!
        *  \brief Constructor
        *
        *  Constructor of FileLogger
        *  \param std::string : file name
        */
        FileLogger(const std::string &);
        /*!
        *  \brief Destructor
        *
        *  Destructor of FileLogger
        */
        ~FileLogger() {};
        /*!
        *  \brief clear the file
        *
        *  clear the file
        *
        *  \param void
        *  \return void
        */
        void clearFile();
        /*!
        *  \brief write the message
        *
        *  write a message in the end of file
        *
        *  \param std::string : message
        *  \return void
        */
        void write(const std::string &);
    };


}

#endif //ZIA_FILELOGGER_HH
