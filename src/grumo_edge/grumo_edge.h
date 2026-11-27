// grumo_edge.h
// Grumo Edge — Single-include header for the entire SDK
//
// Usage:
//   #include <grumo_edge.h>

#ifndef GRUMO_EDGE_H
#define GRUMO_EDGE_H

// Core protocol
#include "grumo_edge/core/protocol.h"
#include "grumo_edge/core/transport.h"
#include "grumo_edge/core/capability_registry.h"
#include "grumo_edge/core/effect_dispatcher.h"
#include "grumo_edge/core/event_publisher.h"
#include "grumo_edge/core/device_state.h"
#include "grumo_edge/core/device_identity.h"
#include "grumo_edge/core/idempotency.h"
#include "grumo_edge/core/connection_manager.h"
#include "grumo_edge/core/device.h"

// Platform HAL
#include "grumo_edge/platform/hal.h"

// Hardware abstractions
#include "grumo_edge/hardware/led.h"
#include "grumo_edge/hardware/button.h"
#include "grumo_edge/hardware/motor.h"
#include "grumo_edge/hardware/servo.h"
#include "grumo_edge/hardware/relay.h"
#include "grumo_edge/hardware/buzzer.h"
#include "grumo_edge/hardware/encoder.h"
#include "grumo_edge/hardware/sensor.h"
#include "grumo_edge/hardware/temperature_sensor.h"

#endif // GRUMO_EDGE_H
