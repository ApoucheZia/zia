#include "EventHandler/EventHandler.hpp"
#include "SampleModule/HelloWorldModule.hpp"

int	main() {
  apouche::HelloWorldModule module;
  apouche::EventHandler *events = new apouche::EventHandler();
  module.registerEvents(events);
  events->_voidEventList.callAllEvent();
  return 0;
}
