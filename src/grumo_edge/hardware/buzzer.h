// buzzer.h
// Grumo Edge — Buzzer hardware abstraction
//
// Platform-independent buzzer using PWM for tone generation.

#ifndef GRUMO_HARDWARE_BUZZER_H
#define GRUMO_HARDWARE_BUZZER_H

#include "grumo_edge/platform/hal.h"
#include <cstdint>

namespace grumo
{
    namespace hardware
    {

        class BuzzerController
        {
        public:
            BuzzerController(hal::Pwm &pwm, uint8_t pwm_channel);

            void begin(uint8_t pin);

            // Play a tone at the given frequency (Hz) for duration_ms (0 = indefinite)
            void tone(uint32_t freq_hz, uint32_t duration_ms = 0);

            // Stop the tone
            void no_tone();

            // Play a short beep
            void beep(uint32_t freq_hz = 1000, uint32_t duration_ms = 100);

            bool is_playing() const;

        private:
            hal::Pwm &_pwm;
            uint8_t _pwm_channel;
            uint8_t _pin;
            bool _playing;
            uint32_t _tone_end_ms;
        };

    } // namespace hardware
} // namespace grumo

#endif // GRUMO_HARDWARE_BUZZER_H
