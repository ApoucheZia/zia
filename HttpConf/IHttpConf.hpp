#ifndef IHTTPCONF_HPP_
#define IHTTPCONF_HPP_

/*!
 * \file IHttpConf.hh
 * \brief Http interface for the server configuration
 * \author mart_-
 * \version 0.1
 */

#include <map>
#include <iostream>

/*! \namespace apouche
 *
 * namespace that contains all http component
 */
namespace apouche {
	/*! \interface IHttpConf
    * \brief interface that represent the server configuration
    *
    */
	class IHttpConf {
	public:
		/*!
            *  \brief Destructor
            *
            *  Destructor of class
            */
		virtual ~IHttpConf() {};
		/*!
            *  \brief Get all configuration
            *
            *  Getting server config
            *
            *  \param void
            *  \return std::map<std::string, std::string>, all the server config
            */
		virtual const	std::map<std::string, std::string> &getAllConf() const = 0;
		/*!
            *  \brief Set all configuration
            *
            *  Setting server config
            *
            *  \param map Content of the entire configuration
            *  \return void
            */
		virtual void	setAllConf(const std::map<std::string, std::string> &) = 0;
		/*!
            *  \brief Get value of a specific key
            *
            *  Get value of a specific key
            *
            *  \param key : the key of the configuration
            *  \return std::string, value of the key
            */
		virtual const	std::string &getConf(const std::string &key) const = 0;
		/*!
           *  \brief set value of a specific key
           *
           *  Set value of a specific key
           *
           *  \param key : the key of the configuration, value : data associated with the key
           *  \return void
           */
		virtual void	setConf(const std::string &, const std::string &)= 0;
		/*!
           *  \brief Remove a key and value from the map
           *
           *  Remove a pair key value from the map
           *
           *  \param key : the key of the configuration, the key and the value are deleted from the map
           *  \return void
           */
		virtual void	deleteConf(const std::string &)= 0;
		/*!
            *  \brief Check if a key is in the Header
            *
            *  Check if a key is in the Header
            *
            *  \param key : the header key of the http request or response, each key contains a value
            *  \return true if the key is in the header,
            * false if the key is not in the header
            */
        virtual const bool containsConf(const std::string &) const = 0;
		/*!
            *  \brief Update the configuration in the file
            *
            *  write the map in the specific file
            *
            *  \param void
            *  \return void
            */
		virtual void	update()= 0;
		/*!
            *  \brief load the config server in the map
            *
            *w  load the file in the map
            *
            *  \param void
            *  \return void
            */
		virtual void	load()= 0;
	};
}

#endif
