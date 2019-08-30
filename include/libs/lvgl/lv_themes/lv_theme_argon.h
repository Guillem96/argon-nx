/**
 * @file lv_theme_argon.h
 *
 */

#ifndef LV_THEME_ARGON_H
#define LV_THEME_ARGON_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#ifdef LV_CONF_INCLUDE_SIMPLE
#include "lv_conf.h"
#else
#include "../lv_conf.h"
#endif

#if LV_USE_THEME_ARGON

/*********************
 *      DEFINES
 *********************/
#define GRAD_1 LV_COLOR_MAKE(0xD3, 0x83, 0x12)
#define GRAD_2 LV_COLOR_MAKE(0xA8, 0x32, 0x79)

#define GUN_METAL           lv_color_hex(0x293132)
#define ARGON_ORANGE        lv_color_hex(0xEB8258)
#define ONYX                lv_color_hex(0x3A2E39)
#define ARGON_PINK          lv_color_hex(0xB74F6F)
#define ARGON_DARK_ORANGE   lv_color_hex(0xAD6A5A)

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Initialize the argon theme
 * @param hue [0..360] hue value from HSV color space to define the theme's base color
 * @param font pointer to a font (NULL to use the default)
 * @return pointer to the initialized theme
 */
lv_theme_t * lv_theme_argon_init(uint16_t hue, lv_font_t * font);

/**
 * Get a pointer to the theme
 * @return pointer to the theme
 */
lv_theme_t * lv_theme_get_argon(void);

/**********************
 *      MACROS
 **********************/

#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_THEME_ARGON_H*/
