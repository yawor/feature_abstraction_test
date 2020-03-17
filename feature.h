#ifndef LINKERTEST_FEATURE_H
#define LINKERTEST_FEATURE_H

#include <stdbool.h>
#include <stdint.h>

typedef enum {
    FEATURE_NAME,
    FEATURE_LEDS,
} keyleds_feature_type;

struct keyleds_feature {
    uint16_t id;
    char *name;
    keyleds_feature_type type;
    void *api;
};

struct keyleds_name_api {
    void (*get_name)();
};

struct keyleds_leds_api {
    void (*set_leds)();
};

#endif //LINKERTEST_FEATURE_H
