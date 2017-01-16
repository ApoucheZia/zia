#include "EventHandler/EventHandler.hpp"
#include "SampleModule/HelloWorldModule.hpp"
#include "HttpHeader/HttpHeader.hh"
#include "HttpBody/HttpBody.hh"

int	main() {
  apouche::HelloWorldModule module;
  apouche::EventHandler *events = new apouche::EventHandler();
  module.registerEvents(events);
  events->_voidEventList.callAllEvent();
  return 0;
}
