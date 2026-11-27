// led.h
// Grumo Edge — LED hardware abstraction
//
// Platform-independent LED controller using the HAL GPIO interface.

#ifndef GRUMO_HARDWARE_LED_H
#define GRUMO_HARDWARE_LED_H

#include "grumo_edge/platform/hal.h"
#include <cstdint>

namespace grumo {
namespace hardware {

class LedController {
public:
    LedController(hal::Gpio& gpio, uint8_t pin);

    void begin();
    void on();
    void off();
    void toggle();
    bool is_on() const;

private:
    hal::Gpio& _gpio;
    uint8_t _pin;
    bool _state;
};

} // namespace hardware
} // namespace grumo

#endif // GRUMO_HARDWARE_LED_H
