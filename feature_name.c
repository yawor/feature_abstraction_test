#include <stdio.h>
#include "feature.h"

static void get_name() {
    printf("Called get_name in Name feature\n");
}

static struct keyleds_name_api api = {
        .get_name = &get_name,
};

static struct keyleds_feature __attribute__((section("keyleds_features"))) mod = {
        .id=0x0005,
        .name = "Name",
        .type = FEATURE_NAME,
        .api = &api,
};
