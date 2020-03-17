#include <stdio.h>
#include "feature.h"

extern const struct keyleds_feature __start_keyleds_features;
extern const struct keyleds_feature __stop_keyleds_features;

const struct keyleds_feature* get_feature_by_type(keyleds_feature_type type) {
    const struct keyleds_feature *f = &__start_keyleds_features;
    for (; f < &__stop_keyleds_features; ++f) {
        if (f->type == type) {
            return f;
        }
    }
    return NULL;
}

const struct keyleds_name_api* get_name_api() {
    const struct keyleds_feature *feature = get_feature_by_type(FEATURE_NAME);
    if (feature == NULL) return NULL;
    return (struct keyleds_name_api*)feature->api;
}

int main() {
    const struct keyleds_feature *f = &__start_keyleds_features;
    for (; f < &__stop_keyleds_features; ++f) {
        printf("%x, %s\n", f->id, f->name);
        switch (f->type) {
            case FEATURE_NAME:
                ((struct keyleds_name_api*)f->api)->get_name();
                break;
            case FEATURE_LEDS:
                ((struct keyleds_leds_api*)f->api)->set_leds();
                break;
            default:
                break;
        }
    }

    const struct keyleds_name_api *api = get_name_api();
    if (api != NULL) api->get_name();

    return 0;
}
