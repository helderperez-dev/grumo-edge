// event_publisher.h
// Grumo Edge — Event publishing
//
// Validates and publishes EVENT messages through the transport.

#ifndef GRUMO_CORE_EVENT_PUBLISHER_H
#define GRUMO_CORE_EVENT_PUBLISHER_H

#include "grumo_edge/core/protocol.h"
#include "grumo_edge/core/transport.h"

namespace grumo {
namespace edge {

class EventPublisher {
public:
    EventPublisher(Transport& transport, const char* device_id);

    // Publish an event with optional payload
    bool publish(const char* event_name, JsonObjectConst payload = JsonObjectConst());

    // Set the device_id
    void set_device_id(const char* device_id);

private:
    Transport& _transport;
    char _device_id[MAX_DEVICE_ID_LEN];
};

} // namespace edge
} // namespace grumo

#endif // GRUMO_CORE_EVENT_PUBLISHER_H
