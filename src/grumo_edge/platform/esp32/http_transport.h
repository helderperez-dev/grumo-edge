// http_transport.h
// Grumo Edge — HTTP transport for ESP32
//
// Implements the Transport interface using HTTP POST for publishing
// and HTTP long-polling for receiving effects.
// Suitable for environments where MQTT is not available.

#ifndef GRUMO_PLATFORM_ESP32_HTTP_TRANSPORT_H
#define GRUMO_PLATFORM_ESP32_HTTP_TRANSPORT_H

#include "grumo_edge/core/transport.h"
#include <WiFiClient.h>
#include <HTTPClient.h>

namespace grumo
{
    namespace platform
    {
        namespace esp32
        {

            class HttpTransport : public edge::Transport
            {
            public:
                struct Config
                {
                    const char *base_url; // e.g. "http://192.168.1.100:8080"
                    const char *device_id;
                    const char *api_key;       // optional API key for auth
                    uint32_t poll_interval_ms; // how often to poll for effects (default 5000)
                    uint32_t timeout_ms;       // HTTP timeout (default 5000)
                };

                HttpTransport(const Config &config);

                // Transport interface
                bool begin() override;
                void end() override;
                bool connected() override;
                void loop() override;
                bool publish(const edge::EdgeMessage &msg) override;
                bool subscribe_effects() override;
                void on_effect(edge::EffectCallback callback, void *user_data = nullptr) override;
                edge::TransportKind kind() const override { return edge::TransportKind::HTTP; }

            private:
                Config _config;
                edge::EffectCallback _effect_callback;
                void *_effect_user_data;
                uint32_t _last_poll;
                bool _connected;

                bool post_message(const char *endpoint, const char *json, size_t len);
                void poll_effects();
            };

        } // namespace esp32
    } // namespace platform
} // namespace grumo

#endif // GRUMO_PLATFORM_ESP32_HTTP_TRANSPORT_H
