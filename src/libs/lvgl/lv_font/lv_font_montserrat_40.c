#include "libs/lvgl/lvgl.h"
#include "core/argon-resources.h"


#ifndef LV_FONT_MONTSERRAT_40
#define LV_FONT_MONTSERRAT_40 1
#endif

#if LV_FONT_MONTSERRAT_40

/*-----------------
 *    BITMAPS
 *----------------*/
static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_h = 0, .box_w = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 175, .box_h = 0, .box_w = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 0, .adv_w = 189, .box_h = 30, .box_w = 6, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 90, .adv_w = 239, .box_h = 10, .box_w = 9, .ofs_x = 3, .ofs_y = 18},
    {.bitmap_index = 135, .adv_w = 470, .box_h = 29, .box_w = 27, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 527, .adv_w = 396, .box_h = 34, .box_w = 22, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 901, .adv_w = 503, .box_h = 30, .box_w = 29, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1336, .adv_w = 444, .box_h = 30, .box_w = 25, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 1711, .adv_w = 148, .box_h = 10, .box_w = 4, .ofs_x = 3, .ofs_y = 18},
    {.bitmap_index = 1731, .adv_w = 212, .box_h = 37, .box_w = 10, .ofs_x = 2, .ofs_y = -6},
    {.bitmap_index = 1916, .adv_w = 212, .box_h = 37, .box_w = 11, .ofs_x = 1, .ofs_y = -6},
    {.bitmap_index = 2120, .adv_w = 276, .box_h = 13, .box_w = 13, .ofs_x = 2, .ofs_y = 15},
    {.bitmap_index = 2205, .adv_w = 364, .box_h = 19, .box_w = 19, .ofs_x = 2, .ofs_y = 6},
    {.bitmap_index = 2386, .adv_w = 180, .box_h = 11, .box_w = 7, .ofs_x = 2, .ofs_y = -5},
    {.bitmap_index = 2425, .adv_w = 305, .box_h = 6, .box_w = 15, .ofs_x = 2, .ofs_y = 9},
    {.bitmap_index = 2470, .adv_w = 179, .box_h = 7, .box_w = 7, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 2495, .adv_w = 376, .box_h = 38, .box_w = 22, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 2913, .adv_w = 440, .box_h = 30, .box_w = 24, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 3273, .adv_w = 244, .box_h = 28, .box_w = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3427, .adv_w = 377, .box_h = 29, .box_w = 20, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 3717, .adv_w = 370, .box_h = 29, .box_w = 20, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 4007, .adv_w = 366, .box_h = 28, .box_w = 21, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 4301, .adv_w = 371, .box_h = 29, .box_w = 20, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 4591, .adv_w = 397, .box_h = 30, .box_w = 21, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 4906, .adv_w = 362, .box_h = 28, .box_w = 21, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 5200, .adv_w = 407, .box_h = 30, .box_w = 22, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 5530, .adv_w = 396, .box_h = 30, .box_w = 21, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 5845, .adv_w = 188, .box_h = 17, .box_w = 6, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 5896, .adv_w = 189, .box_h = 21, .box_w = 6, .ofs_x = 3, .ofs_y = -5},
    {.bitmap_index = 5959, .adv_w = 379, .box_h = 23, .box_w = 20, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 6189, .adv_w = 399, .box_h = 12, .box_w = 21, .ofs_x = 2, .ofs_y = 9},
    {.bitmap_index = 6315, .adv_w = 379, .box_h = 23, .box_w = 19, .ofs_x = 3, .ofs_y = 4},
    {.bitmap_index = 6534, .adv_w = 325, .box_h = 30, .box_w = 18, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 6804, .adv_w = 579, .box_h = 32, .box_w = 33, .ofs_x = 2, .ofs_y = -5},
    {.bitmap_index = 7332, .adv_w = 475, .box_h = 28, .box_w = 30, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 7752, .adv_w = 452, .box_h = 28, .box_w = 23, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 8074, .adv_w = 471, .box_h = 30, .box_w = 26, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 8464, .adv_w = 500, .box_h = 28, .box_w = 25, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 8814, .adv_w = 419, .box_h = 28, .box_w = 20, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 9094, .adv_w = 387, .box_h = 28, .box_w = 19, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 9360, .adv_w = 484, .box_h = 30, .box_w = 26, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 9750, .adv_w = 497, .box_h = 28, .box_w = 24, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 10086, .adv_w = 200, .box_h = 28, .box_w = 6, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 10170, .adv_w = 353, .box_h = 29, .box_w = 18, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 10431, .adv_w = 451, .box_h = 28, .box_w = 24, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 10767, .adv_w = 362, .box_h = 28, .box_w = 19, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 11033, .adv_w = 629, .box_h = 28, .box_w = 32, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 11481, .adv_w = 535, .box_h = 28, .box_w = 26, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 11845, .adv_w = 538, .box_h = 30, .box_w = 30, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 12295, .adv_w = 438, .box_h = 28, .box_w = 22, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 12603, .adv_w = 538, .box_h = 35, .box_w = 32, .ofs_x = 2, .ofs_y = -6},
    {.bitmap_index = 13163, .adv_w = 466, .box_h = 28, .box_w = 24, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 13499, .adv_w = 403, .box_h = 30, .box_w = 23, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 13844, .adv_w = 387, .box_h = 28, .box_w = 22, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 14152, .adv_w = 492, .box_h = 29, .box_w = 25, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 14515, .adv_w = 448, .box_h = 28, .box_w = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 14907, .adv_w = 671, .box_h = 28, .box_w = 42, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 15495, .adv_w = 431, .box_h = 28, .box_w = 27, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 15873, .adv_w = 399, .box_h = 28, .box_w = 27, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 16251, .adv_w = 432, .box_h = 28, .box_w = 23, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 16573, .adv_w = 227, .box_h = 37, .box_w = 10, .ofs_x = 3, .ofs_y = -6},
    {.bitmap_index = 16758, .adv_w = 334, .box_h = 31, .box_w = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 17053, .adv_w = 227, .box_h = 37, .box_w = 10, .ofs_x = 1, .ofs_y = -6},
    {.bitmap_index = 17238, .adv_w = 252, .box_h = 7, .box_w = 14, .ofs_x = 1, .ofs_y = 29},
    {.bitmap_index = 17287, .adv_w = 462, .box_h = 3, .box_w = 24, .ofs_x = 2, .ofs_y = -6},
    {.bitmap_index = 17323, .adv_w = 533, .box_h = 6, .box_w = 10, .ofs_x = 12, .ofs_y = 24},
    {.bitmap_index = 17353, .adv_w = 376, .box_h = 23, .box_w = 20, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 17583, .adv_w = 430, .box_h = 31, .box_w = 22, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 17924, .adv_w = 369, .box_h = 23, .box_w = 21, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 18166, .adv_w = 430, .box_h = 31, .box_w = 22, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 18507, .adv_w = 396, .box_h = 23, .box_w = 21, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 18749, .adv_w = 247, .box_h = 31, .box_w = 16, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 18997, .adv_w = 419, .box_h = 31, .box_w = 21, .ofs_x = 2, .ofs_y = -9},
    {.bitmap_index = 19323, .adv_w = 413, .box_h = 30, .box_w = 20, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 19623, .adv_w = 175, .box_h = 31, .box_w = 7, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 19732, .adv_w = 175, .box_h = 40, .box_w = 14, .ofs_x = -5, .ofs_y = -9},
    {.bitmap_index = 20012, .adv_w = 372, .box_h = 30, .box_w = 20, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 20312, .adv_w = 175, .box_h = 30, .box_w = 5, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 20387, .adv_w = 649, .box_h = 22, .box_w = 35, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 20772, .adv_w = 413, .box_h = 22, .box_w = 20, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 20992, .adv_w = 417, .box_h = 23, .box_w = 24, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 21268, .adv_w = 430, .box_h = 30, .box_w = 22, .ofs_x = 3, .ofs_y = -8},
    {.bitmap_index = 21598, .adv_w = 430, .box_h = 30, .box_w = 22, .ofs_x = 2, .ofs_y = -8},
    {.bitmap_index = 21928, .adv_w = 254, .box_h = 22, .box_w = 12, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 22060, .adv_w = 324, .box_h = 23, .box_w = 18, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 22267, .adv_w = 268, .box_h = 29, .box_w = 16, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 22499, .adv_w = 413, .box_h = 23, .box_w = 20, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 22729, .adv_w = 366, .box_h = 22, .box_w = 23, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 22982, .adv_w = 584, .box_h = 22, .box_w = 36, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 23378, .adv_w = 357, .box_h = 22, .box_w = 22, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 23620, .adv_w = 367, .box_h = 31, .box_w = 23, .ofs_x = 0, .ofs_y = -9},
    {.bitmap_index = 23977, .adv_w = 346, .box_h = 22, .box_w = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 24186, .adv_w = 215, .box_h = 37, .box_w = 11, .ofs_x = 1, .ofs_y = -6},
    {.bitmap_index = 24390, .adv_w = 164, .box_h = 39, .box_w = 4, .ofs_x = 3, .ofs_y = -7},
    {.bitmap_index = 24468, .adv_w = 215, .box_h = 37, .box_w = 10, .ofs_x = 2, .ofs_y = -6},
    {.bitmap_index = 24653, .adv_w = 362, .box_h = 7, .box_w = 19, .ofs_x = 2, .ofs_y = 12},
    {.bitmap_index = 24720, .adv_w = 549, .box_h = 38, .box_w = 35, .ofs_x = 0, .ofs_y = -6},
    {.bitmap_index = 25385, .adv_w = 686, .box_h = 38, .box_w = 43, .ofs_x = 0, .ofs_y = -6},
    {.bitmap_index = 26202, .adv_w = 640, .box_h = 32, .box_w = 40, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 26842, .adv_w = 640, .box_h = 27, .box_w = 36, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 27328, .adv_w = 503, .box_h = 27, .box_w = 27, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 27693, .adv_w = 549, .box_h = 38, .box_w = 35, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 28358, .adv_w = 549, .box_h = 35, .box_w = 35, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 28971, .adv_w = 503, .box_h = 35, .box_w = 32, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 29531, .adv_w = 594, .box_h = 29, .box_w = 37, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 30068, .adv_w = 594, .box_h = 35, .box_w = 38, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 30733, .adv_w = 549, .box_h = 29, .box_w = 35, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 31241, .adv_w = 549, .box_h = 35, .box_w = 35, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 31854, .adv_w = 274, .box_h = 28, .box_w = 18, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 32106, .adv_w = 411, .box_h = 28, .box_w = 26, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 32470, .adv_w = 594, .box_h = 33, .box_w = 38, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 33097, .adv_w = 686, .box_h = 35, .box_w = 43, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 33850, .adv_w = 549, .box_h = 34, .box_w = 34, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 34428, .adv_w = 366, .box_h = 35, .box_w = 23, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 34831, .adv_w = 503, .box_h = 35, .box_w = 32, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 35391, .adv_w = 549, .box_h = 35, .box_w = 35, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 36004, .adv_w = 549, .box_h = 35, .box_w = 35, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 36617, .adv_w = 366, .box_h = 35, .box_w = 23, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 37020, .adv_w = 549, .box_h = 29, .box_w = 35, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 37528, .adv_w = 457, .box_h = 37, .box_w = 24, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 37972, .adv_w = 457, .box_h = 37, .box_w = 24, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 38416, .adv_w = 503, .box_h = 32, .box_w = 32, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 38928, .adv_w = 503, .box_h = 9, .box_w = 32, .ofs_x = 0, .ofs_y = 11},
    {.bitmap_index = 39072, .adv_w = 640, .box_h = 38, .box_w = 40, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 39832, .adv_w = 640, .box_h = 37, .box_w = 40, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 40572, .adv_w = 640, .box_h = 24, .box_w = 36, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 41004, .adv_w = 640, .box_h = 24, .box_w = 36, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 41436, .adv_w = 686, .box_h = 26, .box_w = 43, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 41995, .adv_w = 594, .box_h = 32, .box_w = 38, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 42603, .adv_w = 594, .box_h = 36, .box_w = 38, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 43287, .adv_w = 503, .box_h = 32, .box_w = 32, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 43799, .adv_w = 640, .box_h = 32, .box_w = 40, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 44439, .adv_w = 640, .box_h = 41, .box_w = 40, .ofs_x = 0, .ofs_y = -6},
    {.bitmap_index = 45259, .adv_w = 549, .box_h = 35, .box_w = 35, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 45872, .adv_w = 320, .box_h = 38, .box_w = 20, .ofs_x = 0, .ofs_y = -6},
    {.bitmap_index = 46252, .adv_w = 640, .box_h = 41, .box_w = 38, .ofs_x = 1, .ofs_y = -6},
    {.bitmap_index = 47031, .adv_w = 686, .box_h = 26, .box_w = 43, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 47590, .adv_w = 503, .box_h = 32, .box_w = 32, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 48102, .adv_w = 549, .box_h = 41, .box_w = 35, .ofs_x = 0, .ofs_y = -6},
    {.bitmap_index = 48820, .adv_w = 731, .box_h = 32, .box_w = 44, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 49524, .adv_w = 823, .box_h = 29, .box_w = 52, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 50278, .adv_w = 823, .box_h = 29, .box_w = 52, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 51032, .adv_w = 823, .box_h = 29, .box_w = 52, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 51786, .adv_w = 823, .box_h = 29, .box_w = 52, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 52540, .adv_w = 823, .box_h = 29, .box_w = 52, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 53294, .adv_w = 549, .box_h = 41, .box_w = 30, .ofs_x = 2, .ofs_y = -6}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0x7, 0xa, 0xb, 0xc, 0x10, 0x12, 0x13,
    0x14, 0x18, 0x1b, 0x20, 0x25, 0x26, 0x27, 0x3d,
    0x3f, 0x47, 0x4a, 0x4b, 0x4c, 0x50, 0x51, 0x52,
    0x53, 0x66, 0x67, 0x70, 0x73, 0x76, 0x77, 0x78,
    0x7a, 0x92, 0x94, 0xc3, 0xc4, 0xc6, 0xe6, 0xf2,
    0x11b, 0x123, 0x15a, 0x1ea, 0x23f, 0x240, 0x241, 0x242,
    0x243, 0x292
};
/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY,
        .glyph_id_start = 1, .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0
    },
    {
        .range_start = 61441, .range_length = 659, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY,
        .glyph_id_start = 96, .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 50
    }
};
/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = (const uint8_t *)(ARGON_RES_ADDR + MONTSERRAT_40_KERN_PAIR_GLYPH),
    .values = (const int8_t *)(ARGON_RES_ADDR + MONTSERRAT_40_KERN_PAIR_VALUE),
    .pair_cnt = 764,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

/*Store all the custom data of the font*/
static lv_font_fmt_txt_dsc_t font_dsc = {
    .glyph_bitmap = (const uint8_t *)(ARGON_RES_ADDR + MONTSERRAT_40_GLYPH_BMP),
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .cmap_num = 2,
    .bpp = 4,

    .kern_scale = 24,
    .kern_dsc = &kern_pairs,
    .kern_classes = 0
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
lv_font_t lv_font_montserrat_40 = {
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .line_height = 45,          /*The maximum line height required by the font*/
    .base_line = 9,             /*Baseline measured from the bottom of the line*/
};


#endif /*#if MONTSERRAT_40*/

