/*
  ==============================================================================

    MQTTService.cpp
    Created: 3 Jan 2024 2:13:12pm
    Author:  antoni

  ==============================================================================
*/

#include "MQTTService.h"

//==============================================================================
MQTTService::MQTTService()
{
    this->mosq = nullptr;

    // must be called before any other mosquitto functions | NOT thread safe
    mosquitto_lib_init();
}

MQTTService::~MQTTService()
{
    // free memory associated with a mosquitto client instance
    if (this->mosq != nullptr)
    {
        mosquitto_destroy(mosq);
    }

    mosquitto_lib_cleanup();
    DBG("MQTTService destructor called");
}

//==============================================================================
void MQTTService::run()
{
    this->mosq = mosquitto_new(NULL, true, (void*) this);
    DBG("Created new mosquitto instance");

    mosquitto_int_option(mosq, MOSQ_OPT_PROTOCOL_VERSION, MQTT_PROTOCOL_V5);
    return;
}
