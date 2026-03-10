// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "kirbyrun2.qgf.h"
#include QMK_KEYBOARD_H
#include <qp.h>
#include <spi_master.h>

#define TFT_CS_PIN    A2   // Chip Select
#define TFT_DC_PIN    A4   // Data/Command
#define TFT_RST_PIN   A3   // Reset
#define LCD_SPI_DIVISOR 16


static painter_device_t display;
static painter_image_handle_t kirbyrun2;
static deferred_token kirbyanim;


void keyboard_post_init_user(void) {
    display = qp_ili9341_make_spi_device(
        240,       // width
        320,       // height
        TFT_CS_PIN,    // chip select pin
        TFT_DC_PIN,    // data/command pin
        TFT_RST_PIN,   // reset pin
        LCD_SPI_DIVISOR,   // SPI speed divisor
        0   // SPI mode 
    );
    

    qp_init(display, QP_ROTATION_0);
    qp_clear(display);
    //start of add

    kirbyrun2 = qp_load_image_mem(gfx_kirbyrun2);
    if (kirbyrun2 != NULL) {
        kirbyanim = qp_animate(display, ((240 - kirbyrun2->width)/2), ((320 - kirbyrun2->height)/2), kirbyrun2);
    }
    qp_flush(display);
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_UP,   KC_DOWN,  
        KC_LEFT,   KC_RIGHT
    )
};
