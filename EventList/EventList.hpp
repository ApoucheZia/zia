//
// Created by Kevin Malot on 07/01/17.
//

#ifndef ZIA_EVENTLIST_HPP
#define ZIA_EVENTLIST_HPP

/*!
 * \file HttpBody.hh
 * \brief Http Object body, contains any type of data
 * \author Julien Karst
 * \version 0.1
 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <typeinfo>
#include "../Event/Event.hpp"

/*! \namespace apouche
 *
 * namespace that contains all http component
 */
namespace apouche {

    /*! \class EventList
    * \brief class that represent an EventList
    *
    */
    template <typename T, typename... Args>
    class EventList {
    protected:
        std::vector<Event<T, Args...>> _event;
    public:
        /*!
        *  \brief Constructor
        *
        *  Constructor of EventList
        */
        EventList() {};
        /*!
        *  \brief Destructor
        *
        *  Destructor of EventList
        */
        ~EventList() {};
        /*!
            *  \brief Get the Event
            *
            *  Get the Event from name
            *
            *  \param name : std::string
            *  \return Event<T, Args...>, Event
            */
        const Event<T, Args...> &getEvent(const std::string &name){
            for (typename std::vector<Event<T, Args...>>::iterator it = _event.begin() ; it != _event.end(); ++it)
                if ((*it).getName() == name)
                    return (*it);
            return NULL;
        }
        /*!
        *  \brief Get the next event
        *
        *  Get the next event in the EventList
        *
        *  \param void
        *  \return Event<T, Args...>, Event
        */
        const Event<T, Args...> &getNextEvent(){
            Event<T, Args...>e = *(_event.begin());
            for (typename std::vector<Event<T, Args...>>::iterator it = _event.begin() ; it != _event.end(); ++it) {
                if ((*it).getPriority() > e.getPriority())
                    e = *it;
            }
            typename std::vector<Event<void, Args...>>::iterator it = _event.begin();
            while ((*it).getName() != e.getName())
                ++it;
            return *it;
        }
        /*!
        *  \brief Put an Event
        *
        *  Put an Event in the EventList
        *
        *  \param event : Event<T, Args...>
        *  \return void
        */
        void addEvent(const Event<T, Args...> &event){
            _event.push_back(event);
        }
        /*!
        *  \brief Put and create an Event
        *
        *  Put and create an Event in the EventList
        *
        *  \param name : std::string, priority : apouche::Weight, function : std::function<T(Args...)>
        *  \return void
        */
        void addEvent(const std::string &name, const Weight &priority, const std::function<T(Args...)> &fct) {
            _event.push_back(Event<T, Args...>(name, priority, fct));
        }
        /*!
        *  \brief Check if a key is in the Header
        *
        *  Check if an Event is in EventList
        *
        *  \param key : the name of Event, each key contains a value
        *  \return true if the key is in the header,
        * false if the key is not in the header
        */
        bool containsEvent(const std::string &name) const {
            for (typename std::vector<Event<T, Args...>>::iterator it = _event.begin() ; it != _event.end(); ++it)
                if ((*it).getName() == name)
                    return true;
            return false;
        }
        /*!
        *  \brief Check if a key is in the Header
        *
        *  Check if an Event is in EventList
        *
        *  \param key : the Event, each key contains a value
        *  \return true if the key is in the header,
        * false if the key is not in the header
        */
        bool containsEvent(const Event<T, Args...> &e) const {
            for (typename std::vector<Event<T, Args...>>::iterator it = _event.begin() ; it != _event.end(); ++it)
                if ((*it).getName() == e.getName())
                    return true;
            return false;
        }
        /*!
        *  \brief Remove the Event
        *
        *  Remove the Event in the EventList
        *
        *  \param key : the name of Event
        *  \return void
        */
        void removeEvent(const std::string &name){
            for (typename std::vector<Event<T, Args...>>::iterator it = _event.begin() ; it != _event.end(); ++it)
                if ((*it).getName() == name)
                    _event.erase(it--);
        }
        /*!
        *  \brief Remove the Event
        *
        *  Remove the Event in the EventList
        *
        *  \param key : the Event
        *  \return void
        */
        void removeEvent (Event<T, Args...> &e){
            for (typename std::vector<Event<T, Args...>>::iterator it = _event.begin() ; it != _event.end(); ++it)
                if ((*it).getName() == e.getName())
                    _event.erase(it--);
        }
        /*!
        *  \brief Call the next Event
        *
        *  Call the next Event in the EventList
        *
        *  \param Args : Parameters of the function called
        *  \return The function
        */
        T callNextEvent(Args... args) {
            Event<T, Args...> event = getNextEvent();
            T ret = event.getFunction()(args...);
            removeEvent(event);
            return ret;
        }
        /*!
        *  \brief Call the all Event
        *
        *  Call the all Event in the EventList
        *
        *  \param Function : Callback function , Parameters of the function called
        *  \return void
        */
        void callAllEvent(const std::function<void(T)> &fct, Args... args){
            while (_event.size())
                fct(callNextEvent(args...));
        }
    };

    template <typename... Args>
    class EventList<void, Args...> {
    protected:
        std::vector<Event<void, Args...>> _event;
    public:
        /*!
        *  \brief Constructor
        *
        *  Constructor of EventList
        */
        EventList() {};
        /*!
        *  \brief Destructor
        *
        *  Destructor of EventList
        */
        ~EventList() {};
        /*!
        *  \brief Get the Event
        *
        *  Get the Event from name
        *
        *  \param name : std::string
        *  \return Event<void, Args...>, Event
        */
        const Event<void, Args...> &getEvent(const std::string &name){
            for (typename std::vector<Event<void, Args...>>::iterator it = _event.begin() ; it != _event.end(); ++it)
                if ((*it).getName() == name)
                    return (*it);
            return NULL;
        }
        /*!
        *  \brief Get the next event
        *
        *  Get the next event in the EventList
        *
        *  \param void
        *  \return Event<void, Args...>, Event
        */
        const Event<void, Args...> &getNextEvent(){
            Event<void, Args...>e = *(_event.begin());
            for (typename std::vector<Event<void, Args...>>::iterator it = _event.begin() ; it != _event.end(); ++it) {
                if ((*it).getPriority() > e.getPriority())
                    e = *it;
            }
            typename std::vector<Event<void, Args...>>::iterator it = _event.begin();
            while ((*it).getName() != e.getName())
                ++it;
            return *it;
        }
        /*!
        *  \brief Put an Event
        *
        *  Put an Event in the EventList
        *
        *  \param event : Event<void, Args...>
        *  \return void
        */
        void addEvent(const Event<void, Args...> &event){
            _event.push_back(event);
        }
        /*!
        *  \brief Put and create an Event
        *
        *  Put and create an Event in the EventList
        *
        *  \param name : std::string, priority : apouche::Weight, function : std::function<T(Args...)>
        *  \return void
        */
        void addEvent(const std::string &name, const Weight &priority, const std::function<void(Args...)> &fct) {
            _event.push_back(Event<void, Args...>(name, priority, fct));
        }
        /*!
        *  \brief Check if a key is in the Header
        *
        *  Check if an Event is in EventList
        *
        *  \param key : the Event, each key contains a value
        *  \return true if the key is in the header,
        * false if the key is not in the header
        */
        bool containsEvent(const std::string &name) const {
            for (typename std::vector<Event<void, Args...>>::iterator it = _event.begin() ; it != _event.end(); ++it)
                if ((*it).getName() == name)
                    return true;
            return false;
        }
        /*!
        *  \brief Check if a key is in the Header
        *
        *  Check if an Event is in EventList
        *
        *  \param key : the Event, each key contains a value
        *  \return true if the key is in the header,
        * false if the key is not in the header
        */
        bool containsEvent(const Event<void, Args...> &e) const {
            for (typename std::vector<Event<void, Args...>>::iterator it = _event.begin() ; it != _event.end(); ++it)
                if ((*it).getName() == e.getName())
                    return true;
            return false;
        }
        /*!
        *  \brief Remove the Event
        *
        *  Remove the Event in the EventList
        *
        *  \param key : the name of Event
        *  \return void
        */
        void removeEvent(const std::string &name){
            for (typename std::vector<Event<void, Args...>>::iterator it = _event.begin() ; it != _event.end(); ++it)
                if ((*it).getName() == name)
                    _event.erase(it--);
        }
        /*!
        *  \brief Remove the Event
        *
        *  Remove the Event in the EventList
        *
        *  \param key : the Event
        *  \return void
        */
        void removeEvent (Event<void, Args...> &e){
            for (typename std::vector<Event<void, Args...>>::iterator it = _event.begin() ; it != _event.end(); ++it)
                if ((*it).getName() == e.getName())
                    _event.erase(it--);
        }
        /*!
        *  \brief Call the next Event
        *
        *  Call the next Event in the EventList
        *
        *  \param Args : Parameters of the function called
        *  \return The function
        */
        void callNextEvent(Args... args) {
            Event<void, Args...> event = getNextEvent();
            event.getFunction()(args...);
            removeEvent(event);
        }
        /*!
        *  \brief Call the all Event
        *
        *  Call the all Event in the EventList
        *
        *  \param Function : Callback function , Parameters of the function called
        *  \return void
        */
        void callAllEvent(Args... args){
            while (_event.size())
                callNextEvent(args...);
        }
    };
}
#endif //ZIA_EVENTLIST_HPP
