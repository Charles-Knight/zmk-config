/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zmk/display/widgets/output_status.h>
#include <zmk/display/widgets/battery_status.h>
#include <zmk/display/widgets/layer_status.h>
#include <zmk/display/widgets/wpm_status.h>
#include <zmk/display/status_screen.h>
#include <lvgl.h>

#include <zephyr/logging/log.h>

LV_IMG_DECLARE(mountain);
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

// Create structs for ZMK Widgets.
#if IS_ENABLED(CONFIG_ZMK_WIDGET_BATTERY_STATUS)
static struct zmk_widget_battery_status battery_status_widget;
#endif

#if IS_ENABLED(CONFIG_ZMK_WIDGET_OUTPUT_STATUS)
static struct zmk_widget_output_status output_status_widget;
#endif

#if IS_ENABLED(CONFIG_ZMK_WIDGET_LAYER_STATUS)
static struct zmk_widget_layer_status layer_status_widget;
#endif

#if IS_ENABLED(CONFIG_ZMK_WIDGET_WPM_STATUS)
static struct zmk_widget_wpm_status wpm_status_widget;
#endif

lv_style_t global_style;

lv_obj_t *zmk_display_status_screen() {
    lv_obj_t *screen;
    lv_obj_t *dont_label;
    lv_obj_t *panic_label;
    lv_obj_t *center_frame;

    lv_style_init(&global_style);
    lv_style_set_text_font(&global_style, &lv_font_montserrat_26);
    lv_style_set_text_letter_space(&global_style, 1);
    lv_style_set_text_line_space(&global_style, 1);

    screen = lv_obj_create(NULL);
    lv_obj_add_style(screen, &global_style, LV_PART_MAIN);

// Battery Status Widget
#if IS_ENABLED(CONFIG_ZMK_WIDGET_BATTERY_STATUS)
    zmk_widget_battery_status_init(&battery_status_widget, screen);
    lv_obj_align(zmk_widget_battery_status_obj(&battery_status_widget), LV_ALIGN_TOP_RIGHT,
                 0, 0);
#endif

// Output Status Widget
#if IS_ENABLED(CONFIG_ZMK_WIDGET_OUTPUT_STATUS)
    zmk_widget_output_status_init(&output_status_widget, screen);
    lv_obj_align(zmk_widget_output_status_obj(&output_status_widget), LV_ALIGN_TOP_LEFT, 0,
                 0);
#endif

// Create Center Frame
center_frame = lv_obj_create(screen);
lv_obj_align(center_frame, LV_ALIGN_CENTER, 0, 0);
lv_obj_center(center_frame);


// Don't Panic Labels
// dont_label = lv_label_create(center_frame);
// lv_label_set_text(dont_label, "Don't");
// panic_label = lv_label_create(center_frame);
// lv_label_set_text(panic_label, "Panic");
// lv_obj_update_layout(dont_label); // otherwise proper height is not known
// lv_obj_set_y(panic_label, lv_obj_get_height(dont_label));

// Create image with custom image
lv_obj_t * img1 = lv_img_create(center_frame);
lv_img_set_src(img1, &mountain);
lv_obj_set_size(img1, 125, 75);
// lv_obj_align(img1, LV_ALIGN_CENTER, 0, 0);

// Create image with symbol and text
// lv_obj_t *img = lv_img_create(screen);
// lv_img_set_src(img, LV_SYMBOL_OK "Accept");
// lv_obj_align(img, LV_ALIGN_CENTER, 0, 0);

// Update size of Center Frame with Content
lv_obj_set_size(center_frame, LV_SIZE_CONTENT, LV_SIZE_CONTENT);


// Layer Status Widget
#if IS_ENABLED(CONFIG_ZMK_WIDGET_LAYER_STATUS)
    zmk_widget_layer_status_init(&layer_status_widget, screen);
    lv_obj_align(zmk_widget_layer_status_obj(&layer_status_widget), LV_ALIGN_BOTTOM_LEFT,
                 0, 0);
#endif

// WPM Widget
#if IS_ENABLED(CONFIG_ZMK_WIDGET_WPM_STATUS)
    zmk_widget_wpm_status_init(&wpm_status_widget, screen);
    lv_obj_align(zmk_widget_wpm_status_obj(&wpm_status_widget), LV_ALIGN_BOTTOM_RIGHT, -12, 0);
#endif

return screen;
}
