// relay.h
// Grumo Edge — Relay hardware abstraction
//
// Platform-independent relay controller using GPIO.

#ifndef GRUMO_HARDWARE_RELAY_H
#define GRUMO_HARDWARE_RELAY_H

#include "grumo_edge/platform/hal.h"
#include <cstdint>

namespace grumo
{
    namespace hardware
    {

        class RelayController
        {
        public:
            RelayController(hal::Gpio &gpio, uint8_t pin, bool active_high = true);

            void begin();
            void on();
            void off();
            void toggle();
            bool is_on() const;

        private:
            hal::Gpio &_gpio;
            uint8_t _pin;
            bool _active_high;
            bool _state;
        };

    } // namespace hardware
} // namespace grumo

#endif // GRUMO_HARDWARE_RELAY_H
