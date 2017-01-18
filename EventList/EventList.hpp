//
// Created by Kevin Malot on 07/01/17.
//

#ifndef ZIA_EVENTLIST_HPP
#define ZIA_EVENTLIST_HPP

/*!
 * \file EventList.hh
 * \brief Event List
 * \author Kevin Malot
 * \author Alexandre NICOLAIE
 * \author Clement Francois
 * \version 0.1
 */

#include <string>
#include <set>
#include <algorithm>
#include <iostream>
#include <typeinfo>
#include "../Event/Event.hpp"

/*! \namespace apouche
 *
 * namespace that contains all http component
 */
namespace apouche {

    /*
     *  Making void type compilates
     */
    template<typename T>
    struct Helper
    {
        typedef std::function<void(T)> callback;
    };

    template <>
    struct Helper<void>
    {
        typedef std::function<void()> callback;
    };

    /*! \class EventList
    * \brief class that represent an EventList
    *
    */
    template <typename T, typename... Args>
    class EventList {
    private:
        /*
        *  Sorting the set
        */
        struct EventCompare {
            bool operator()(const apouche::Event<T, Args...> &a, const apouche::Event<T, Args...> &b) {
                return a.getPriority() < b.getPriority();
            }
        };

    protected:
        std::multiset<Event<T, Args...>, EventCompare> _event;

    public:
        typedef typename Helper<T>::callback callback;
        typedef typename std::multiset<Event<T, Args...>>::iterator EventIterator;

        /*!
        *  \brief Constructor
        *
        *  Constructor of EventList
        */
        EventList(){
        };
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
        EventIterator getEvent(const std::string &name){
            return std::find_if(_event.begin(), _event.end(), [&name](Event<T, Args...> const &it) { return it.getName() == name; });
        }
        /*!
        *  \brief Get the next event
        *
        *  Get the next event in the EventList
        *
        *  \param void
        *  \return Event<T, Args...>, Event
        */
        EventIterator getNextEvent() const{
            return _event.begin();
        }
        /*!
        *  \brief Get the end of the eventList
        *
        *  Get the end of the EventList
        *
        *  \param void
        *  \return Iterator the end of the set
        */
        EventIterator getEnd() const{
            return _event.end();
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
            _event.insert(event);
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
            _event.insert(Event<T, Args...>(name, priority, fct));
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
            return std::find_if(_event.begin(), _event.end(), [&name](Event<T, Args...> const &it) { return it.getName() == name; }) != _event.end();
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
            return std::find(_event.begin(), _event.end(), e) != _event.end();
        }
        /*!
        *  \brief Remove the Event
        *
        *  Remove the Event in the EventList
        *
        *  \param key : the name of Event
        *  \return void
        */
        void removeEvent(const std::string &name) {
            _event.erase(std::remove_if(_event.begin(), _event.end(), [&name](Event<T, Args...> const &it) { return it.getName() == name; }), _event.end());
        }
        /*!
        *  \brief Remove the Event
        *
        *  Remove the Event in the EventList
        *
        *  \param key : the Event
        *  \return void
        */
        void removeEvent (Event<void, Args...> &e) {
            _event.erase(std::remove_if(_event.begin(), _event.end(), [const &e](Event<T, Args...> const &it) { return it.getName() == e.getName(); }), _event.end());
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
            auto &&it = getNextEvent();
            if (it == _event.end())
                throw; //Todo: add exception ici;
            return it->getFunction()(args...);
        }
        /*!
        *  \brief Call all the Events
        *
        *  Call the all Event in the EventList
        *
        *  \param Function : Callback function , Parameters of the function called
        *  \return void
        */
        void callAllEvent(const callback &fct, Args... args){
            for (auto &&it : _event) {
                fct(it.getFunction()(args...));
            }
            _event.clear();
        }
        /*!
        *  \brief Call all the Events
        *
        *  Call the all Event in the EventList without getting the return value (for Void Type)
        *
        *  \param Parameters of the function called
        *  \return void
        */
        void callAllEvent(Args... args){
            for (auto &&it : _event) {
                it.getFunction()(args...);
            }
            _event.clear();
        }
    };
}
#endif //ZIA_EVENTLIST_HPP
