// encoder.h
// Grumo Edge — Rotary encoder hardware abstraction
//
// Platform-independent quadrature encoder using GPIO.
// Tracks position via interrupt-safe state machine.

#ifndef GRUMO_HARDWARE_ENCODER_H
#define GRUMO_HARDWARE_ENCODER_H

#include "grumo_edge/platform/hal.h"
#include <cstdint>

namespace grumo
{
    namespace hardware
    {

        typedef void (*EncoderCallback)(int32_t position, void *user_data);

        class EncoderController
        {
        public:
            EncoderController(hal::Gpio &gpio, uint8_t pin_a, uint8_t pin_b);

            void begin();

            // Call frequently from loop() to poll encoder state
            void loop();

            // Get current position (positive = CW, negative = CCW)
            int32_t position() const;

            // Reset position to zero
            void reset();

            // Set callback for position changes
            void on_change(EncoderCallback callback, void *user_data = nullptr);

        private:
            hal::Gpio &_gpio;
            uint8_t _pin_a;
            uint8_t _pin_b;
            int32_t _position;
            uint8_t _last_state;
            EncoderCallback _callback;
            void *_user_data;

            uint8_t read_state() const;
        };

    } // namespace hardware
} // namespace grumo

#endif // GRUMO_HARDWARE_ENCODER_H
