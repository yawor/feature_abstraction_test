#include <stdio.h>
#include "feature.h"

static void set_leds() {
    printf("Called set_leds in LEDs v2 feature\n");
}

static struct keyleds_leds_api api = {
        .set_leds = &set_leds,
};

static struct keyleds_feature __attribute__((section("keyleds_features"))) mod = {
        .id=0x8081,
        .name = "LEDs v2",
        .type = FEATURE_LEDS,
        .api = &api,
};
