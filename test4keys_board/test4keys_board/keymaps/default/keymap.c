// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "display_images/shiheart.qgf.h"
#include QMK_KEYBOARD_H
#include <qp.h>
#include <spi_master.h>

#define TFT_CS_PIN    A2   // Chip Select
#define TFT_DC_PIN    A4   // Data/Command
#define TFT_RST_PIN   A3   // Reset
#define LCD_SPI_DIVISOR 2


static painter_device_t display;


void keyboard_post_init_user(void) {
    display = qp_ili9341_spi_make_device(
        240,       // width
        320,       // height
        TFT_CS_PIN,    // chip select pin
        TFT_DC_PIN,    // data/command pin
        TFT_RST_PIN,   // reset pin
        LCD_SPI_DIVISOR,   // SPI speed divisor
        0   // SPI mode 
    );

    qp_init(display, QP_ROTATION_0);
    painter_image_handle_t qp_load_image_mem(const void *buffer);
    qp_drawimage(display, 0, 0, &shiheart);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_UP,   KC_DOWN,  
        KC_LEFT,   KC_RIGHT
    )
};
