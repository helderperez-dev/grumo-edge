// capability_registry.h
// Grumo Edge — Capability registration and lookup
//
// Maps capability names (e.g. "led.control") to handler functions.
// Bounded array — no dynamic allocation.

#ifndef GRUMO_CORE_CAPABILITY_REGISTRY_H
#define GRUMO_CORE_CAPABILITY_REGISTRY_H

#include "grumo_edge/core/protocol.h"
#include <cstdint>
#include <cstddef>

#ifndef MAX_CAPABILITIES
#define MAX_CAPABILITIES 8
#endif

namespace grumo {
namespace edge {

// ---------------------------------------------------------------------------
// CapabilityHandler — processes an effect for a specific capability
// ---------------------------------------------------------------------------
// Returns true if the effect was handled successfully.
// The handler should populate result_doc with any response data.
typedef bool (*CapabilityHandler)(
    const EdgeMessage& effect,
    JsonObject result_doc,
    void* user_data
);

// ---------------------------------------------------------------------------
// CapabilityEntry
// ---------------------------------------------------------------------------
struct CapabilityEntry {
    char name[MAX_CAPABILITY_NAME_LEN];
    CapabilityHandler handler;
    void* user_data;
};

// ---------------------------------------------------------------------------
// CapabilityRegistry
// ---------------------------------------------------------------------------
class CapabilityRegistry {
public:
    CapabilityRegistry();

    // Register a capability handler. Returns true on success, false if full.
    bool register_capability(const char* name, CapabilityHandler handler, void* user_data = nullptr);

    // Look up a handler by capability name. Returns nullptr if not found.
    CapabilityHandler find(const char* name) const;

    // Look up user data for a capability. Returns nullptr if not found.
    void* find_user_data(const char* name) const;

    // Get the number of registered capabilities
    size_t count() const;

    // Get capability names as an array (for HELLO message)
    const char* const* names() const;

    // Check if a capability is registered
    bool has(const char* name) const;

private:
    CapabilityEntry _entries[MAX_CAPABILITIES];
    size_t _count;
    const char* _name_ptrs[MAX_CAPABILITIES + 1]; // null-terminated array for names()
};

} // namespace edge
} // namespace grumo

#endif // GRUMO_CORE_CAPABILITY_REGISTRY_H
