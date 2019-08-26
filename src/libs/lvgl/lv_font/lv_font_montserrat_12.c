#include "libs/lvgl/lvgl.h"
#include "core/argon-resources.h"

/*******************************************************************************
 * Size: 22 px
 * Bpp: 4
 * Opts:
 ******************************************************************************/

#ifndef LV_FONT_MONTSERRAT_12
#define LV_FONT_MONTSERRAT_12 1
#endif

#if LV_FONT_MONTSERRAT_12

/*-----------------
 *    BITMAPS
 *----------------*/
static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_h = 0, .box_w = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 53, .box_h = 0, .box_w = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 0, .adv_w = 57, .box_h = 9, .box_w = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 9, .adv_w = 72, .box_h = 4, .box_w = 3, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 15, .adv_w = 141, .box_h = 9, .box_w = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 56, .adv_w = 119, .box_h = 10, .box_w = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 91, .adv_w = 151, .box_h = 9, .box_w = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 132, .adv_w = 133, .box_h = 10, .box_w = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 172, .adv_w = 45, .box_h = 4, .box_w = 2, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 176, .adv_w = 64, .box_h = 11, .box_w = 4, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 198, .adv_w = 64, .box_h = 11, .box_w = 4, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 220, .adv_w = 83, .box_h = 5, .box_w = 5, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 233, .adv_w = 109, .box_h = 7, .box_w = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 258, .adv_w = 54, .box_h = 4, .box_w = 3, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 264, .adv_w = 91, .box_h = 3, .box_w = 5, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 272, .adv_w = 54, .box_h = 2, .box_w = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 275, .adv_w = 113, .box_h = 12, .box_w = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 317, .adv_w = 132, .box_h = 9, .box_w = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 353, .adv_w = 73, .box_h = 9, .box_w = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 371, .adv_w = 113, .box_h = 9, .box_w = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 403, .adv_w = 111, .box_h = 9, .box_w = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 435, .adv_w = 110, .box_h = 9, .box_w = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 467, .adv_w = 111, .box_h = 9, .box_w = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 499, .adv_w = 119, .box_h = 9, .box_w = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 531, .adv_w = 109, .box_h = 9, .box_w = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 563, .adv_w = 122, .box_h = 9, .box_w = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 595, .adv_w = 119, .box_h = 9, .box_w = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 627, .adv_w = 56, .box_h = 5, .box_w = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 635, .adv_w = 57, .box_h = 7, .box_w = 2, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 642, .adv_w = 114, .box_h = 7, .box_w = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 667, .adv_w = 120, .box_h = 4, .box_w = 7, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 681, .adv_w = 114, .box_h = 7, .box_w = 6, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 702, .adv_w = 98, .box_h = 9, .box_w = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 729, .adv_w = 174, .box_h = 10, .box_w = 11, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 784, .adv_w = 142, .box_h = 9, .box_w = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 825, .adv_w = 136, .box_h = 9, .box_w = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 857, .adv_w = 141, .box_h = 9, .box_w = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 898, .adv_w = 150, .box_h = 9, .box_w = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 934, .adv_w = 126, .box_h = 9, .box_w = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 966, .adv_w = 116, .box_h = 9, .box_w = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 993, .adv_w = 145, .box_h = 9, .box_w = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1034, .adv_w = 149, .box_h = 9, .box_w = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1070, .adv_w = 60, .box_h = 9, .box_w = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1079, .adv_w = 106, .box_h = 9, .box_w = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1106, .adv_w = 135, .box_h = 9, .box_w = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1142, .adv_w = 109, .box_h = 9, .box_w = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1169, .adv_w = 189, .box_h = 9, .box_w = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1214, .adv_w = 161, .box_h = 9, .box_w = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1250, .adv_w = 161, .box_h = 9, .box_w = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1295, .adv_w = 131, .box_h = 9, .box_w = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1327, .adv_w = 161, .box_h = 11, .box_w = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1382, .adv_w = 140, .box_h = 9, .box_w = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1418, .adv_w = 121, .box_h = 9, .box_w = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1450, .adv_w = 116, .box_h = 9, .box_w = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1482, .adv_w = 147, .box_h = 9, .box_w = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1518, .adv_w = 134, .box_h = 9, .box_w = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1559, .adv_w = 201, .box_h = 9, .box_w = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1618, .adv_w = 129, .box_h = 9, .box_w = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1654, .adv_w = 120, .box_h = 9, .box_w = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1690, .adv_w = 130, .box_h = 9, .box_w = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1726, .adv_w = 68, .box_h = 11, .box_w = 3, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1743, .adv_w = 100, .box_h = 9, .box_w = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1770, .adv_w = 68, .box_h = 11, .box_w = 4, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1792, .adv_w = 76, .box_h = 2, .box_w = 5, .ofs_x = 0, .ofs_y = 9},
    {.bitmap_index = 1797, .adv_w = 139, .box_h = 1, .box_w = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1801, .adv_w = 160, .box_h = 2, .box_w = 4, .ofs_x = 3, .ofs_y = 7},
    {.bitmap_index = 1805, .adv_w = 113, .box_h = 7, .box_w = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1830, .adv_w = 129, .box_h = 9, .box_w = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1862, .adv_w = 111, .box_h = 7, .box_w = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1887, .adv_w = 129, .box_h = 9, .box_w = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1919, .adv_w = 119, .box_h = 7, .box_w = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1944, .adv_w = 74, .box_h = 9, .box_w = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1967, .adv_w = 126, .box_h = 10, .box_w = 7, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 2002, .adv_w = 124, .box_h = 9, .box_w = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2029, .adv_w = 53, .box_h = 9, .box_w = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2043, .adv_w = 53, .box_h = 12, .box_w = 5, .ofs_x = -2, .ofs_y = -3},
    {.bitmap_index = 2073, .adv_w = 112, .box_h = 9, .box_w = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2100, .adv_w = 53, .box_h = 9, .box_w = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2109, .adv_w = 195, .box_h = 7, .box_w = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2148, .adv_w = 124, .box_h = 7, .box_w = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2169, .adv_w = 125, .box_h = 7, .box_w = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2197, .adv_w = 129, .box_h = 10, .box_w = 7, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 2232, .adv_w = 129, .box_h = 10, .box_w = 7, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 2267, .adv_w = 76, .box_h = 7, .box_w = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2281, .adv_w = 97, .box_h = 7, .box_w = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2302, .adv_w = 80, .box_h = 9, .box_w = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2325, .adv_w = 124, .box_h = 7, .box_w = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2346, .adv_w = 110, .box_h = 7, .box_w = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2371, .adv_w = 175, .box_h = 7, .box_w = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2410, .adv_w = 107, .box_h = 7, .box_w = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2435, .adv_w = 110, .box_h = 10, .box_w = 7, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 2470, .adv_w = 104, .box_h = 7, .box_w = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2491, .adv_w = 65, .box_h = 11, .box_w = 4, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 2513, .adv_w = 49, .box_h = 12, .box_w = 2, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 2525, .adv_w = 65, .box_h = 11, .box_w = 4, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 2547, .adv_w = 108, .box_h = 3, .box_w = 7, .ofs_x = 0, .ofs_y = 3}
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, 
        .range_length = 95, 
        .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY,
        .glyph_id_start = 1, 
        .unicode_list = NULL, 
        .glyph_id_ofs_list = NULL, 
        .list_length = 0
    }
};

/*-----------------
 *    KERNING
 *----------------*/

static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = (const uint8_t *)(ARGON_RES_ADDR + MONTSERRAT_12_KERN_PAIR_GLYPH),
    .values = (const int8_t *)(ARGON_RES_ADDR + MONTSERRAT_12_KERN_PAIR_VALUE),
    .pair_cnt = 764,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

/*Store all the custom data of the font*/
static lv_font_fmt_txt_dsc_t font_dsc = {
    .glyph_bitmap = (const uint8_t *)(ARGON_RES_ADDR + MONTSERRAT_12_GLYPH_BMP),
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .cmap_num = 1,
    .bpp = 4,

    .kern_scale = 16,
    .kern_dsc = &kern_pairs,
    .kern_classes = 0
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
lv_font_t lv_font_montserrat_12 = {
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .line_height = 14,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
};


#endif /*#if LV_FONT_MONTSERRAT_12*/
