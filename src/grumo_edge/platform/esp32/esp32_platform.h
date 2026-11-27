// esp32_platform.h
// Grumo Edge — ESP32 platform HAL implementation
//
// Provides concrete implementations of all HAL interfaces for ESP32.

#ifndef GRUMO_PLATFORM_ESP32_H
#define GRUMO_PLATFORM_ESP32_H

#include "grumo_edge/platform/hal.h"

namespace grumo {
namespace platform {
namespace esp32 {

// Initialize the ESP32 platform and register it as the active platform
void init();

// Get the ESP32 platform instance
hal::Platform& platform();

} // namespace esp32
} // namespace platform
} // namespace grumo

#endif // GRUMO_PLATFORM_ESP32_H
