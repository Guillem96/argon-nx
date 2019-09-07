#include "libs/lvgl/lvgl.h"
#include "core/argon-resources.h"


#ifndef LV_FONT_MA_20
#define LV_FONT_MA_20 1
#endif

#if LV_FONT_MA_20

/*-----------------
 *    BITMAPS
 *----------------*/
static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_h = 0, .box_w = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 88, .box_h = 0, .box_w = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 0, .adv_w = 94, .box_h = 16, .box_w = 4, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 32, .adv_w = 120, .box_h = 5, .box_w = 5, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 45, .adv_w = 235, .box_h = 15, .box_w = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 143, .adv_w = 198, .box_h = 18, .box_w = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 251, .adv_w = 252, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 363, .adv_w = 222, .box_h = 16, .box_w = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 467, .adv_w = 74, .box_h = 5, .box_w = 3, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 475, .adv_w = 106, .box_h = 19, .box_w = 5, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 523, .adv_w = 106, .box_h = 19, .box_w = 6, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 580, .adv_w = 138, .box_h = 7, .box_w = 7, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 605, .adv_w = 182, .box_h = 10, .box_w = 10, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 655, .adv_w = 90, .box_h = 5, .box_w = 4, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 665, .adv_w = 152, .box_h = 3, .box_w = 8, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 677, .adv_w = 90, .box_h = 4, .box_w = 4, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 685, .adv_w = 188, .box_h = 20, .box_w = 12, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 805, .adv_w = 220, .box_h = 14, .box_w = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 889, .adv_w = 122, .box_h = 12, .box_w = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 925, .adv_w = 188, .box_h = 13, .box_w = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 990, .adv_w = 185, .box_h = 15, .box_w = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1073, .adv_w = 183, .box_h = 14, .box_w = 11, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1150, .adv_w = 185, .box_h = 15, .box_w = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1225, .adv_w = 198, .box_h = 16, .box_w = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1313, .adv_w = 181, .box_h = 14, .box_w = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1383, .adv_w = 204, .box_h = 16, .box_w = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1471, .adv_w = 198, .box_h = 16, .box_w = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1559, .adv_w = 94, .box_h = 9, .box_w = 4, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1577, .adv_w = 95, .box_h = 10, .box_w = 4, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1597, .adv_w = 189, .box_h = 12, .box_w = 10, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 1657, .adv_w = 200, .box_h = 6, .box_w = 11, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 1690, .adv_w = 189, .box_h = 12, .box_w = 10, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 1750, .adv_w = 163, .box_h = 15, .box_w = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1818, .adv_w = 289, .box_h = 17, .box_w = 17, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1963, .adv_w = 245, .box_h = 15, .box_w = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2061, .adv_w = 226, .box_h = 14, .box_w = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2138, .adv_w = 236, .box_h = 16, .box_w = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 2242, .adv_w = 250, .box_h = 14, .box_w = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2333, .adv_w = 186, .box_h = 16, .box_w = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 2413, .adv_w = 186, .box_h = 15, .box_w = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2496, .adv_w = 244, .box_h = 16, .box_w = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 2600, .adv_w = 249, .box_h = 14, .box_w = 12, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2684, .adv_w = 155, .box_h = 15, .box_w = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 2744, .adv_w = 182, .box_h = 17, .box_w = 10, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 2829, .adv_w = 225, .box_h = 14, .box_w = 12, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2913, .adv_w = 181, .box_h = 14, .box_w = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2983, .adv_w = 345, .box_h = 15, .box_w = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 3118, .adv_w = 249, .box_h = 15, .box_w = 12, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 3208, .adv_w = 269, .box_h = 16, .box_w = 15, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 3328, .adv_w = 219, .box_h = 14, .box_w = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 3405, .adv_w = 269, .box_h = 18, .box_w = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 3540, .adv_w = 233, .box_h = 14, .box_w = 12, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 3624, .adv_w = 202, .box_h = 16, .box_w = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 3720, .adv_w = 216, .box_h = 15, .box_w = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3818, .adv_w = 249, .box_h = 15, .box_w = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 3916, .adv_w = 224, .box_h = 14, .box_w = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 4014, .adv_w = 335, .box_h = 15, .box_w = 19, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 4157, .adv_w = 217, .box_h = 14, .box_w = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 4248, .adv_w = 232, .box_h = 17, .box_w = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 4350, .adv_w = 216, .box_h = 14, .box_w = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 4434, .adv_w = 114, .box_h = 19, .box_w = 6, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 4491, .adv_w = 167, .box_h = 16, .box_w = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 4571, .adv_w = 114, .box_h = 19, .box_w = 6, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 4628, .adv_w = 126, .box_h = 4, .box_w = 8, .ofs_x = 0, .ofs_y = 14},
    {.bitmap_index = 4644, .adv_w = 231, .box_h = 2, .box_w = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 4656, .adv_w = 267, .box_h = 3, .box_w = 5, .ofs_x = 6, .ofs_y = 12},
    {.bitmap_index = 4664, .adv_w = 215, .box_h = 12, .box_w = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 4730, .adv_w = 215, .box_h = 16, .box_w = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 4826, .adv_w = 184, .box_h = 12, .box_w = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 4886, .adv_w = 215, .box_h = 16, .box_w = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 4974, .adv_w = 196, .box_h = 12, .box_w = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 5040, .adv_w = 118, .box_h = 15, .box_w = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 5100, .adv_w = 209, .box_h = 16, .box_w = 11, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 5188, .adv_w = 207, .box_h = 15, .box_w = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 5271, .adv_w = 88, .box_h = 16, .box_w = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 5303, .adv_w = 88, .box_h = 21, .box_w = 7, .ofs_x = -3, .ofs_y = -5},
    {.bitmap_index = 5377, .adv_w = 186, .box_h = 15, .box_w = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 5460, .adv_w = 110, .box_h = 15, .box_w = 6, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 5505, .adv_w = 324, .box_h = 11, .box_w = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 5604, .adv_w = 207, .box_h = 11, .box_w = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 5665, .adv_w = 209, .box_h = 12, .box_w = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 5731, .adv_w = 215, .box_h = 15, .box_w = 12, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 5821, .adv_w = 215, .box_h = 15, .box_w = 11, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 5904, .adv_w = 127, .box_h = 11, .box_w = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 5943, .adv_w = 162, .box_h = 12, .box_w = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 6003, .adv_w = 124, .box_h = 15, .box_w = 7, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 6056, .adv_w = 207, .box_h = 12, .box_w = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 6122, .adv_w = 183, .box_h = 11, .box_w = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 6188, .adv_w = 292, .box_h = 11, .box_w = 18, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 6287, .adv_w = 179, .box_h = 11, .box_w = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 6348, .adv_w = 206, .box_h = 16, .box_w = 11, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 6436, .adv_w = 173, .box_h = 11, .box_w = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 6486, .adv_w = 108, .box_h = 19, .box_w = 6, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 6543, .adv_w = 82, .box_h = 20, .box_w = 3, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 6573, .adv_w = 108, .box_h = 19, .box_w = 5, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 6621, .adv_w = 184, .box_h = 5, .box_w = 10, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 6646, .adv_w = 274, .box_h = 19, .box_w = 18, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 6817, .adv_w = 343, .box_h = 19, .box_w = 22, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 7026, .adv_w = 320, .box_h = 16, .box_w = 20, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 7186, .adv_w = 320, .box_h = 14, .box_w = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 7312, .adv_w = 251, .box_h = 14, .box_w = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 7410, .adv_w = 274, .box_h = 20, .box_w = 18, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 7590, .adv_w = 274, .box_h = 18, .box_w = 18, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 7752, .adv_w = 251, .box_h = 18, .box_w = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 7896, .adv_w = 297, .box_h = 15, .box_w = 19, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 8039, .adv_w = 297, .box_h = 18, .box_w = 19, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 8210, .adv_w = 274, .box_h = 15, .box_w = 18, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 8345, .adv_w = 274, .box_h = 18, .box_w = 18, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 8507, .adv_w = 137, .box_h = 14, .box_w = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 8570, .adv_w = 206, .box_h = 14, .box_w = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 8661, .adv_w = 297, .box_h = 16, .box_w = 19, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 8813, .adv_w = 343, .box_h = 18, .box_w = 22, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 9011, .adv_w = 274, .box_h = 18, .box_w = 17, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 9164, .adv_w = 183, .box_h = 18, .box_w = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 9272, .adv_w = 251, .box_h = 18, .box_w = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 9416, .adv_w = 274, .box_h = 18, .box_w = 18, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 9578, .adv_w = 274, .box_h = 18, .box_w = 18, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 9740, .adv_w = 183, .box_h = 18, .box_w = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 9848, .adv_w = 275, .box_h = 15, .box_w = 18, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 9983, .adv_w = 229, .box_h = 18, .box_w = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 10100, .adv_w = 229, .box_h = 19, .box_w = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 10214, .adv_w = 251, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 10342, .adv_w = 251, .box_h = 5, .box_w = 16, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 10382, .adv_w = 320, .box_h = 19, .box_w = 20, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 10572, .adv_w = 320, .box_h = 18, .box_w = 20, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 10752, .adv_w = 320, .box_h = 12, .box_w = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 10860, .adv_w = 320, .box_h = 13, .box_w = 18, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 10977, .adv_w = 343, .box_h = 13, .box_w = 22, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 11120, .adv_w = 297, .box_h = 16, .box_w = 19, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 11272, .adv_w = 297, .box_h = 19, .box_w = 19, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 11453, .adv_w = 251, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 11581, .adv_w = 320, .box_h = 17, .box_w = 20, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 11751, .adv_w = 320, .box_h = 21, .box_w = 20, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 11961, .adv_w = 274, .box_h = 18, .box_w = 18, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 12123, .adv_w = 160, .box_h = 19, .box_w = 10, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 12218, .adv_w = 320, .box_h = 20, .box_w = 20, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 12418, .adv_w = 343, .box_h = 13, .box_w = 22, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 12561, .adv_w = 251, .box_h = 17, .box_w = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 12697, .adv_w = 274, .box_h = 21, .box_w = 18, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 12886, .adv_w = 366, .box_h = 16, .box_w = 23, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 13070, .adv_w = 411, .box_h = 15, .box_w = 26, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 13265, .adv_w = 411, .box_h = 15, .box_w = 26, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 13460, .adv_w = 411, .box_h = 15, .box_w = 26, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 13655, .adv_w = 411, .box_h = 15, .box_w = 26, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 13850, .adv_w = 411, .box_h = 15, .box_w = 26, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 14045, .adv_w = 274, .box_h = 21, .box_w = 15, .ofs_x = 1, .ofs_y = -3}
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


static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = (const uint8_t *)(ARGON_RES_ADDR + MONTSERRAT_ALT_20_KERN_PAIR_GLYPH),
    .values = (const int8_t *)(ARGON_RES_ADDR + MONTSERRAT_ALT_20_KERN_PAIR_VALUE),
    .pair_cnt = 210,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

/*Store all the custom data of the font*/
static lv_font_fmt_txt_dsc_t font_dsc = {
    .glyph_bitmap = (const uint8_t *)(ARGON_RES_ADDR + MONTSERRAT_ALT_20_GLYPH_BMP),
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .cmap_num = 2,
    .bpp = 4,

    .kern_scale = 16,
    .kern_dsc = &kern_pairs,
    .kern_classes = 0
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
lv_font_t lv_font_montserrat_alternate_20 = {
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .line_height = 23,          /*The maximum line height required by the font*/
    .base_line = 5,             /*Baseline measured from the bottom of the line*/
};

#endif