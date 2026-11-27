// led.cpp
// Grumo Edge — LED controller implementation

#include "grumo_edge/hardware/led.h"

namespace grumo {
namespace hardware {

LedController::LedController(hal::Gpio& gpio, uint8_t pin)
    : _gpio(gpio)
    , _pin(pin)
    , _state(false)
{
}

void LedController::begin() {
    _gpio.pinMode(_pin, hal::Gpio::Mode::Output);
    off();
}

void LedController::on() {
    _gpio.digitalWrite(_pin, hal::Gpio::Level::High);
    _state = true;
}

void LedController::off() {
    _gpio.digitalWrite(_pin, hal::Gpio::Level::Low);
    _state = false;
}

void LedController::toggle() {
    if (_state) off();
    else on();
}

bool LedController::is_on() const {
    return _state;
}

} // namespace hardware
} // namespace grumo
