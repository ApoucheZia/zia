//
// Created by Kevin Malot on 07/01/2017.
//

#ifndef ZIA_EVENT_HPP
#define ZIA_EVENT_HPP

#include "Enum.hh"
#include <functional>

/*!
 * \file Event.hpp
 * \brief Http Object body, contains any type of data
 * \author ExPl0siF
 * \version 0.1
 */

/*! \namespace apouche
 *
 * namespace that contains all http component
 */
namespace apouche {

  /*! \class Event
   * \brief class that represent an Event
   *
   */
    template <class T = void()>
    class Event {
    public:
        /*!
         *  \brief Constructor
         *
         *  Constructor of Event
         */
        Event(const std::string &name, const apouche::Weight &priority, const std::function<T> &function) :
                _name(name), _priority(priority), _function(function){

        }
        /*!
         *  \brief Destructor
         *
         *  Destructor of EventList
         */
        ~Event() {

        }
            /*!
             *  \brief Get the Name
             *
             *  Get the Event name
             *
             *  \param name : void
             *  \return std::string
             */
        const std::string &getName() const{
            return _name;
        }
        /*!
         *  \brief Set the Name
         *
         *  Set the Event name
         *
         *  \param name : std::string
         *  \return void
         */
        void setName(const std::string &n) {
            _name = n;
        }
        /*!
         *  \brief Get the Priority
         *
         *  Get the Priority
         *
         *  \param name : void
         *  \return Weight
         */
        const Weight &getPriority() const{
            return _priority;
        }
        /*!
         *  \brief Set the Priority
         *
         *  Set the Priority with Weight
         *
         *  \param name : Weight
         *  \return void
         */
        void setPriority(const apouche::Weight &p) {
            _priority = p;
        }
        /*!
         *  \brief Get the Function
         *
         *  Get the Function
         *
         *  \param name : void
         *  \return std::function<T(Args...)>
         */
        const std::function<T> &getFunction() const{
            return _function;
        }
        /*!
         *  \brief Set the Function
         *
         *  Set the Function with Template
         *
         *  \param name : std::function<T(Args...)>
         *  \return void
         */
        void setFunction(const std::function<T> &f) {
            _function = f;
        }

    protected:
        std::string _name;
        Weight _priority;
        std::function<T> _function;
    };
}

#endif //ZIA_EVENT_HH

