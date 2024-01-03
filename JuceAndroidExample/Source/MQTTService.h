/*
  ==============================================================================

    MQTTService.h
    Created: 3 Jan 2024 2:13:12pm
    Author:  antoni

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include <mosquitto.h>
#include <string>

class MQTTService
{
public:
    MQTTService();
    ~MQTTService();

    void run ();

private:
    struct mosquitto * mosq;
};
