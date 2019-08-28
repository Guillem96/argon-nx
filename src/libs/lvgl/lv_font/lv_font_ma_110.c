#include "libs/lvgl/lvgl.h"
#include "core/argon-resources.h"

/*******************************************************************************
 * Size: 110 px
 * Bpp: 4
 * Opts: 
 ******************************************************************************/

#ifndef LV_FONT_MA_110
#define LV_FONT_MA_110 1
#endif

#if LV_FONT_MA_110

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/
static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_h = 0, .box_w = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 452, .box_h = 0, .box_w = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 0, .adv_w = 444, .box_h = 78, .box_w = 10, .ofs_x = 9, .ofs_y = -1},
    {.bitmap_index = 390, .adv_w = 628, .box_h = 29, .box_w = 23, .ofs_x = 8, .ofs_y = 48},
    {.bitmap_index = 724, .adv_w = 1214, .box_h = 77, .box_w = 70, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 3419, .adv_w = 1072, .box_h = 105, .box_w = 57, .ofs_x = 5, .ofs_y = -14},
    {.bitmap_index = 6412, .adv_w = 1438, .box_h = 79, .box_w = 80, .ofs_x = 5, .ofs_y = -1},
    {.bitmap_index = 9572, .adv_w = 1153, .box_h = 79, .box_w = 66, .ofs_x = 5, .ofs_y = -1},
    {.bitmap_index = 12179, .adv_w = 341, .box_h = 29, .box_w = 6, .ofs_x = 8, .ofs_y = 48},
    {.bitmap_index = 12266, .adv_w = 565, .box_h = 104, .box_w = 18, .ofs_x = 12, .ofs_y = -22},
    {.bitmap_index = 13202, .adv_w = 567, .box_h = 104, .box_w = 19, .ofs_x = 5, .ofs_y = -22},
    {.bitmap_index = 14190, .adv_w = 660, .box_h = 40, .box_w = 37, .ofs_x = 2, .ofs_y = 42},
    {.bitmap_index = 14930, .adv_w = 1001, .box_h = 47, .box_w = 48, .ofs_x = 7, .ofs_y = 15},
    {.bitmap_index = 16058, .adv_w = 352, .box_h = 25, .box_w = 10, .ofs_x = 6, .ofs_y = -16},
    {.bitmap_index = 16183, .adv_w = 671, .box_h = 5, .box_w = 30, .ofs_x = 6, .ofs_y = 27},
    {.bitmap_index = 16258, .adv_w = 352, .box_h = 10, .box_w = 10, .ofs_x = 6, .ofs_y = -1},
    {.bitmap_index = 16308, .adv_w = 563, .box_h = 104, .box_w = 42, .ofs_x = -3, .ofs_y = -11},
    {.bitmap_index = 18492, .adv_w = 1158, .box_h = 79, .box_w = 61, .ofs_x = 6, .ofs_y = -1},
    {.bitmap_index = 20902, .adv_w = 621, .box_h = 77, .box_w = 26, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 21903, .adv_w = 991, .box_h = 78, .box_w = 56, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 24087, .adv_w = 982, .box_h = 78, .box_w = 55, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 26232, .adv_w = 1151, .box_h = 77, .box_w = 67, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 28812, .adv_w = 982, .box_h = 78, .box_w = 54, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 30918, .adv_w = 1060, .box_h = 79, .box_w = 57, .ofs_x = 6, .ofs_y = -1},
    {.bitmap_index = 33170, .adv_w = 1023, .box_h = 77, .box_w = 56, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 35326, .adv_w = 1112, .box_h = 79, .box_w = 59, .ofs_x = 5, .ofs_y = -1},
    {.bitmap_index = 37657, .adv_w = 1060, .box_h = 79, .box_w = 58, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 39948, .adv_w = 352, .box_h = 59, .box_w = 10, .ofs_x = 6, .ofs_y = -1},
    {.bitmap_index = 40243, .adv_w = 352, .box_h = 74, .box_w = 10, .ofs_x = 6, .ofs_y = -16},
    {.bitmap_index = 40613, .adv_w = 1001, .box_h = 45, .box_w = 47, .ofs_x = 8, .ofs_y = 16},
    {.bitmap_index = 41671, .adv_w = 1001, .box_h = 31, .box_w = 47, .ofs_x = 8, .ofs_y = 23},
    {.bitmap_index = 42400, .adv_w = 1001, .box_h = 43, .box_w = 47, .ofs_x = 8, .ofs_y = 17},
    {.bitmap_index = 43411, .adv_w = 989, .box_h = 79, .box_w = 52, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 45465, .adv_w = 1818, .box_h = 100, .box_w = 102, .ofs_x = 6, .ofs_y = -22},
    {.bitmap_index = 50565, .adv_w = 1412, .box_h = 78, .box_w = 64, .ofs_x = 12, .ofs_y = 0},
    {.bitmap_index = 53061, .adv_w = 1324, .box_h = 77, .box_w = 64, .ofs_x = 13, .ofs_y = 0},
    {.bitmap_index = 55525, .adv_w = 1260, .box_h = 79, .box_w = 68, .ofs_x = 6, .ofs_y = -1},
    {.bitmap_index = 58211, .adv_w = 1454, .box_h = 77, .box_w = 72, .ofs_x = 13, .ofs_y = 0},
    {.bitmap_index = 60983, .adv_w = 1102, .box_h = 79, .box_w = 61, .ofs_x = 6, .ofs_y = -1},
    {.bitmap_index = 63393, .adv_w = 1054, .box_h = 78, .box_w = 52, .ofs_x = 12, .ofs_y = 0},
    {.bitmap_index = 65421, .adv_w = 1360, .box_h = 79, .box_w = 68, .ofs_x = 6, .ofs_y = -1},
    {.bitmap_index = 68107, .adv_w = 1433, .box_h = 77, .box_w = 64, .ofs_x = 13, .ofs_y = 0},
    {.bitmap_index = 70571, .adv_w = 766, .box_h = 77, .box_w = 39, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 72073, .adv_w = 862, .box_h = 89, .box_w = 42, .ofs_x = 0, .ofs_y = -12},
    {.bitmap_index = 73942, .adv_w = 1237, .box_h = 77, .box_w = 64, .ofs_x = 13, .ofs_y = 0},
    {.bitmap_index = 76406, .adv_w = 1030, .box_h = 77, .box_w = 51, .ofs_x = 13, .ofs_y = 0},
    {.bitmap_index = 78370, .adv_w = 2156, .box_h = 78, .box_w = 109, .ofs_x = 13, .ofs_y = 0},
    {.bitmap_index = 82621, .adv_w = 1406, .box_h = 78, .box_w = 63, .ofs_x = 13, .ofs_y = 0},
    {.bitmap_index = 85078, .adv_w = 1475, .box_h = 79, .box_w = 80, .ofs_x = 6, .ofs_y = -1},
    {.bitmap_index = 88238, .adv_w = 1258, .box_h = 77, .box_w = 60, .ofs_x = 13, .ofs_y = 0},
    {.bitmap_index = 90548, .adv_w = 1475, .box_h = 93, .box_w = 81, .ofs_x = 6, .ofs_y = -15},
    {.bitmap_index = 94315, .adv_w = 1267, .box_h = 77, .box_w = 61, .ofs_x = 13, .ofs_y = 0},
    {.bitmap_index = 96664, .adv_w = 1072, .box_h = 79, .box_w = 57, .ofs_x = 5, .ofs_y = -1},
    {.bitmap_index = 98916, .adv_w = 1000, .box_h = 78, .box_w = 63, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 101373, .adv_w = 1399, .box_h = 78, .box_w = 62, .ofs_x = 12, .ofs_y = -1},
    {.bitmap_index = 103791, .adv_w = 1209, .box_h = 77, .box_w = 75, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 106679, .adv_w = 2116, .box_h = 78, .box_w = 108, .ofs_x = 12, .ofs_y = -1},
    {.bitmap_index = 110891, .adv_w = 1130, .box_h = 77, .box_w = 67, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 113471, .adv_w = 1387, .box_h = 89, .box_w = 62, .ofs_x = 12, .ofs_y = -12},
    {.bitmap_index = 116230, .adv_w = 1155, .box_h = 77, .box_w = 63, .ofs_x = 5, .ofs_y = 0},
    {.bitmap_index = 118656, .adv_w = 539, .box_h = 104, .box_w = 19, .ofs_x = 13, .ofs_y = -22},
    {.bitmap_index = 119644, .adv_w = 563, .box_h = 104, .box_w = 42, .ofs_x = -4, .ofs_y = -11},
    {.bitmap_index = 121828, .adv_w = 539, .box_h = 104, .box_w = 19, .ofs_x = 2, .ofs_y = -22},
    {.bitmap_index = 122816, .adv_w = 1003, .box_h = 47, .box_w = 43, .ofs_x = 10, .ofs_y = 15},
    {.bitmap_index = 123827, .adv_w = 880, .box_h = 4, .box_w = 55, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 123937, .adv_w = 1056, .box_h = 14, .box_w = 24, .ofs_x = 16, .ofs_y = 66},
    {.bitmap_index = 124105, .adv_w = 1188, .box_h = 59, .box_w = 58, .ofs_x = 5, .ofs_y = -1},
    {.bitmap_index = 125816, .adv_w = 1188, .box_h = 83, .box_w = 58, .ofs_x = 11, .ofs_y = -1},
    {.bitmap_index = 128223, .adv_w = 977, .box_h = 59, .box_w = 52, .ofs_x = 5, .ofs_y = -1},
    {.bitmap_index = 129757, .adv_w = 1188, .box_h = 83, .box_w = 58, .ofs_x = 5, .ofs_y = -1},
    {.bitmap_index = 132164, .adv_w = 1051, .box_h = 59, .box_w = 56, .ofs_x = 5, .ofs_y = -1},
    {.bitmap_index = 133816, .adv_w = 558, .box_h = 82, .box_w = 28, .ofs_x = 11, .ofs_y = 0},
    {.bitmap_index = 134964, .adv_w = 1200, .box_h = 80, .box_w = 59, .ofs_x = 5, .ofs_y = -22},
    {.bitmap_index = 137324, .adv_w = 1184, .box_h = 82, .box_w = 53, .ofs_x = 11, .ofs_y = 0},
    {.bitmap_index = 139497, .adv_w = 459, .box_h = 81, .box_w = 9, .ofs_x = 10, .ofs_y = 0},
    {.bitmap_index = 139862, .adv_w = 468, .box_h = 103, .box_w = 30, .ofs_x = -10, .ofs_y = -22},
    {.bitmap_index = 141407, .adv_w = 1035, .box_h = 82, .box_w = 53, .ofs_x = 11, .ofs_y = 0},
    {.bitmap_index = 143580, .adv_w = 524, .box_h = 83, .box_w = 23, .ofs_x = 11, .ofs_y = -1},
    {.bitmap_index = 144535, .adv_w = 1873, .box_h = 58, .box_w = 95, .ofs_x = 11, .ofs_y = 0},
    {.bitmap_index = 147290, .adv_w = 1184, .box_h = 58, .box_w = 52, .ofs_x = 11, .ofs_y = 0},
    {.bitmap_index = 148798, .adv_w = 1091, .box_h = 59, .box_w = 58, .ofs_x = 5, .ofs_y = -1},
    {.bitmap_index = 150509, .adv_w = 1188, .box_h = 80, .box_w = 58, .ofs_x = 11, .ofs_y = -22},
    {.bitmap_index = 152829, .adv_w = 1188, .box_h = 80, .box_w = 58, .ofs_x = 5, .ofs_y = -22},
    {.bitmap_index = 155149, .adv_w = 693, .box_h = 58, .box_w = 28, .ofs_x = 11, .ofs_y = 0},
    {.bitmap_index = 155961, .adv_w = 841, .box_h = 59, .box_w = 46, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 157318, .adv_w = 672, .box_h = 71, .box_w = 28, .ofs_x = 11, .ofs_y = -1},
    {.bitmap_index = 158312, .adv_w = 1177, .box_h = 59, .box_w = 51, .ofs_x = 11, .ofs_y = -1},
    {.bitmap_index = 159817, .adv_w = 929, .box_h = 58, .box_w = 58, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 161499, .adv_w = 1795, .box_h = 59, .box_w = 91, .ofs_x = 11, .ofs_y = -1},
    {.bitmap_index = 164184, .adv_w = 913, .box_h = 58, .box_w = 53, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 165721, .adv_w = 1177, .box_h = 80, .box_w = 51, .ofs_x = 11, .ofs_y = -22},
    {.bitmap_index = 167761, .adv_w = 903, .box_h = 58, .box_w = 46, .ofs_x = 5, .ofs_y = 0},
    {.bitmap_index = 169095, .adv_w = 563, .box_h = 104, .box_w = 27, .ofs_x = 6, .ofs_y = -22},
    {.bitmap_index = 170499, .adv_w = 512, .box_h = 104, .box_w = 6, .ofs_x = 13, .ofs_y = -22},
    {.bitmap_index = 170811, .adv_w = 563, .box_h = 104, .box_w = 27, .ofs_x = 2, .ofs_y = -22},
    {.bitmap_index = 172215, .adv_w = 1001, .box_h = 17, .box_w = 49, .ofs_x = 7, .ofs_y = 30},
    {.bitmap_index = 172632, .adv_w = 1760, .box_h = 111, .box_w = 110, .ofs_x = 0, .ofs_y = -14},
    {.bitmap_index = 178737, .adv_w = 1760, .box_h = 111, .box_w = 110, .ofs_x = 0, .ofs_y = -14}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const uint16_t unicode_list_1[] = {
    0x0, 0x61e
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY,
        .glyph_id_start = 1, .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0
    },
    {
        .range_start = 61749, .range_length = 1567, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY,
        .glyph_id_start = 96, .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 2
    }
};

/*-----------------
 *    KERNING
 *----------------*/




/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = (const uint8_t*)(ARGON_RES_ADDR + MONTSERRAT_ALT_110_KERN_CLASS_VALUE),
    .left_class_mapping  = (const uint8_t*)(ARGON_RES_ADDR + MONTSERRAT_ALT_110_KERN_LEFT_MAP),
    .right_class_mapping = (const uint8_t*)(ARGON_RES_ADDR + MONTSERRAT_ALT_110_KERN_RIGHT_MAP),
    .left_class_cnt      = 61,
    .right_class_cnt     = 48,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

/*Store all the custom data of the font*/
static lv_font_fmt_txt_dsc_t font_dsc = {
    .glyph_bitmap = (const uint8_t*)(ARGON_RES_ADDR + MONTSERRAT_ALT_110_GLYPH_BMP),
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .cmap_num = 2,
    .bpp = 4,

    .kern_scale = 33,
    .kern_dsc = &kern_classes,
    .kern_classes = 1
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
lv_font_t lv_font_montserrat_alternate_110 = {
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .line_height = 119,          /*The maximum line height required by the font*/
    .base_line = 22,             /*Baseline measured from the bottom of the line*/
};

#endif /*#if MONTSERRAT_ALTERNATE_110*/

