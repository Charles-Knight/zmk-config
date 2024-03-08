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
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

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

    // Create Image

    lv_obj_t *img = lv_img_create(screen);
    lv_image_set_src(img, LV_SYMBOL_OK "Accept");
    lv_obj_align(img, LV_ALIGN_CENTER, 0, 0);

    // Create Simple Message Box
    // char * btns[] = {"Apply", "Close", ""};
    // lv_obj_t * mbox = lv_msgbox_create(screen, "Hello", "This is a message box", btns, true);
    // lv_obj_center(mbox);
    
    /*
    // Create Center Frame
    center_frame = lv_obj_create(screen);
    lv_obj_align(center_frame, LV_ALIGN_CENTER, 0, 0);
    lv_obj_center(center_frame);

    // Create don't label
    dont_label = lv_label_create(center_frame);
    lv_label_set_text(dont_label, "Don't");

    // Create panic label
    panic_label = lv_label_create(center_frame);
    lv_label_set_long_mode(panic_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_set_width(panic_label, 150);
    lv_label_set_text(panic_label, "This is some longer text");
    lv_obj_update_layout(dont_label); // otherwise proper height is not known
    lv_obj_set_y(panic_label, lv_obj_get_height(dont_label));

    // Set size of center frame
    lv_obj_set_size(center_frame, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    */

    return screen;
}
