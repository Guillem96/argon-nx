#include "libs/lvgl/lvgl.h"
#include "core/argon-resources.h"


#ifndef LV_FONT_MA_30
#define LV_FONT_MA_30 1
#endif

#if LV_FONT_MA_30

/*-----------------
 *    BITMAPS
 *----------------*/
static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_h = 0, .box_w = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 132, .box_h = 0, .box_w = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 0, .adv_w = 142, .box_h = 23, .box_w = 5, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 58, .adv_w = 180, .box_h = 8, .box_w = 7, .ofs_x = 2, .ofs_y = 13},
    {.bitmap_index = 86, .adv_w = 353, .box_h = 22, .box_w = 20, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 306, .adv_w = 297, .box_h = 26, .box_w = 17, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 527, .adv_w = 377, .box_h = 23, .box_w = 22, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 780, .adv_w = 333, .box_h = 23, .box_w = 19, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 999, .adv_w = 111, .box_h = 8, .box_w = 3, .ofs_x = 2, .ofs_y = 13},
    {.bitmap_index = 1011, .adv_w = 159, .box_h = 27, .box_w = 8, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1119, .adv_w = 159, .box_h = 27, .box_w = 8, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1227, .adv_w = 207, .box_h = 10, .box_w = 10, .ofs_x = 1, .ofs_y = 11},
    {.bitmap_index = 1277, .adv_w = 273, .box_h = 15, .box_w = 15, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 1390, .adv_w = 135, .box_h = 9, .box_w = 5, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 1413, .adv_w = 228, .box_h = 4, .box_w = 11, .ofs_x = 2, .ofs_y = 7},
    {.bitmap_index = 1435, .adv_w = 134, .box_h = 6, .box_w = 5, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 1450, .adv_w = 282, .box_h = 29, .box_w = 17, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 1697, .adv_w = 330, .box_h = 20, .box_w = 18, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1877, .adv_w = 183, .box_h = 18, .box_w = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1958, .adv_w = 283, .box_h = 19, .box_w = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2101, .adv_w = 277, .box_h = 22, .box_w = 15, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 2266, .adv_w = 275, .box_h = 21, .box_w = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 2424, .adv_w = 278, .box_h = 22, .box_w = 15, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 2589, .adv_w = 298, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 2773, .adv_w = 272, .box_h = 21, .box_w = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 2941, .adv_w = 305, .box_h = 23, .box_w = 17, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 3137, .adv_w = 297, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 3321, .adv_w = 141, .box_h = 13, .box_w = 5, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 3354, .adv_w = 142, .box_h = 16, .box_w = 5, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 3394, .adv_w = 284, .box_h = 18, .box_w = 15, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 3529, .adv_w = 300, .box_h = 9, .box_w = 16, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 3601, .adv_w = 284, .box_h = 18, .box_w = 15, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 3736, .adv_w = 244, .box_h = 23, .box_w = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 3886, .adv_w = 434, .box_h = 25, .box_w = 25, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 4199, .adv_w = 368, .box_h = 22, .box_w = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 4408, .adv_w = 339, .box_h = 21, .box_w = 17, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 4587, .adv_w = 353, .box_h = 23, .box_w = 20, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 4817, .adv_w = 375, .box_h = 21, .box_w = 19, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 5017, .adv_w = 279, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 5201, .adv_w = 279, .box_h = 22, .box_w = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 5366, .adv_w = 366, .box_h = 23, .box_w = 20, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 5596, .adv_w = 373, .box_h = 21, .box_w = 18, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 5785, .adv_w = 232, .box_h = 22, .box_w = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 5917, .adv_w = 273, .box_h = 25, .box_w = 15, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 6105, .adv_w = 338, .box_h = 21, .box_w = 18, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 6294, .adv_w = 272, .box_h = 21, .box_w = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 6452, .adv_w = 517, .box_h = 22, .box_w = 27, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 6749, .adv_w = 373, .box_h = 22, .box_w = 18, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 6947, .adv_w = 403, .box_h = 23, .box_w = 23, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 7212, .adv_w = 328, .box_h = 21, .box_w = 17, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 7391, .adv_w = 403, .box_h = 26, .box_w = 23, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 7690, .adv_w = 349, .box_h = 21, .box_w = 18, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 7879, .adv_w = 302, .box_h = 23, .box_w = 17, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 8075, .adv_w = 324, .box_h = 22, .box_w = 20, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 8295, .adv_w = 373, .box_h = 22, .box_w = 19, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 8504, .adv_w = 336, .box_h = 21, .box_w = 21, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 8725, .adv_w = 503, .box_h = 22, .box_w = 27, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 9022, .adv_w = 325, .box_h = 21, .box_w = 20, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 9232, .adv_w = 348, .box_h = 25, .box_w = 17, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 9445, .adv_w = 324, .box_h = 21, .box_w = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 9634, .adv_w = 170, .box_h = 28, .box_w = 8, .ofs_x = 2, .ofs_y = -5},
    {.bitmap_index = 9746, .adv_w = 251, .box_h = 23, .box_w = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 9919, .adv_w = 170, .box_h = 28, .box_w = 8, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 10031, .adv_w = 189, .box_h = 5, .box_w = 11, .ofs_x = 0, .ofs_y = 22},
    {.bitmap_index = 10059, .adv_w = 347, .box_h = 3, .box_w = 18, .ofs_x = 2, .ofs_y = -5},
    {.bitmap_index = 10086, .adv_w = 400, .box_h = 5, .box_w = 7, .ofs_x = 9, .ofs_y = 18},
    {.bitmap_index = 10104, .adv_w = 323, .box_h = 18, .box_w = 17, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 10257, .adv_w = 323, .box_h = 24, .box_w = 17, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 10461, .adv_w = 276, .box_h = 18, .box_w = 15, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 10596, .adv_w = 323, .box_h = 24, .box_w = 17, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 10800, .adv_w = 294, .box_h = 18, .box_w = 17, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 10953, .adv_w = 178, .box_h = 22, .box_w = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 11074, .adv_w = 314, .box_h = 24, .box_w = 17, .ofs_x = 1, .ofs_y = -7},
    {.bitmap_index = 11278, .adv_w = 310, .box_h = 23, .box_w = 16, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 11462, .adv_w = 132, .box_h = 23, .box_w = 5, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 11520, .adv_w = 132, .box_h = 30, .box_w = 11, .ofs_x = -4, .ofs_y = -7},
    {.bitmap_index = 11685, .adv_w = 279, .box_h = 23, .box_w = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 11858, .adv_w = 165, .box_h = 22, .box_w = 9, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 11957, .adv_w = 487, .box_h = 17, .box_w = 27, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 12187, .adv_w = 310, .box_h = 17, .box_w = 16, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 12323, .adv_w = 313, .box_h = 18, .box_w = 18, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 12485, .adv_w = 323, .box_h = 23, .box_w = 17, .ofs_x = 2, .ofs_y = -6},
    {.bitmap_index = 12681, .adv_w = 323, .box_h = 23, .box_w = 17, .ofs_x = 1, .ofs_y = -6},
    {.bitmap_index = 12877, .adv_w = 191, .box_h = 17, .box_w = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 12954, .adv_w = 243, .box_h = 18, .box_w = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 13071, .adv_w = 186, .box_h = 22, .box_w = 10, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 13181, .adv_w = 310, .box_h = 17, .box_w = 15, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 13309, .adv_w = 275, .box_h = 16, .box_w = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 13445, .adv_w = 438, .box_h = 16, .box_w = 27, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 13661, .adv_w = 268, .box_h = 16, .box_w = 16, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 13789, .adv_w = 310, .box_h = 23, .box_w = 16, .ofs_x = 1, .ofs_y = -7},
    {.bitmap_index = 13973, .adv_w = 259, .box_h = 16, .box_w = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 14085, .adv_w = 161, .box_h = 28, .box_w = 8, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 14197, .adv_w = 123, .box_h = 29, .box_w = 4, .ofs_x = 2, .ofs_y = -5},
    {.bitmap_index = 14255, .adv_w = 161, .box_h = 28, .box_w = 8, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 14367, .adv_w = 276, .box_h = 7, .box_w = 15, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 14420, .adv_w = 411, .box_h = 29, .box_w = 26, .ofs_x = 0, .ofs_y = -5},
    {.bitmap_index = 14797, .adv_w = 514, .box_h = 29, .box_w = 33, .ofs_x = 0, .ofs_y = -5},
    {.bitmap_index = 15276, .adv_w = 480, .box_h = 24, .box_w = 30, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 15636, .adv_w = 480, .box_h = 20, .box_w = 26, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 15896, .adv_w = 377, .box_h = 21, .box_w = 21, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 16117, .adv_w = 411, .box_h = 29, .box_w = 26, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 16494, .adv_w = 411, .box_h = 27, .box_w = 26, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 16845, .adv_w = 377, .box_h = 27, .box_w = 24, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 17169, .adv_w = 446, .box_h = 22, .box_w = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 17477, .adv_w = 446, .box_h = 26, .box_w = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 17841, .adv_w = 411, .box_h = 22, .box_w = 26, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 18127, .adv_w = 411, .box_h = 27, .box_w = 26, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 18478, .adv_w = 206, .box_h = 21, .box_w = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 18615, .adv_w = 309, .box_h = 21, .box_w = 20, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 18825, .adv_w = 446, .box_h = 25, .box_w = 28, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 19175, .adv_w = 514, .box_h = 27, .box_w = 33, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 19621, .adv_w = 411, .box_h = 27, .box_w = 26, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 19972, .adv_w = 274, .box_h = 27, .box_w = 18, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 20215, .adv_w = 377, .box_h = 27, .box_w = 24, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 20539, .adv_w = 411, .box_h = 27, .box_w = 26, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 20890, .adv_w = 411, .box_h = 27, .box_w = 26, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 21241, .adv_w = 274, .box_h = 27, .box_w = 18, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 21484, .adv_w = 412, .box_h = 22, .box_w = 26, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 21770, .adv_w = 343, .box_h = 28, .box_w = 18, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 22022, .adv_w = 343, .box_h = 28, .box_w = 18, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 22274, .adv_w = 377, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 22562, .adv_w = 377, .box_h = 7, .box_w = 24, .ofs_x = 0, .ofs_y = 8},
    {.bitmap_index = 22646, .adv_w = 480, .box_h = 29, .box_w = 30, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 23081, .adv_w = 480, .box_h = 28, .box_w = 30, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 23501, .adv_w = 480, .box_h = 18, .box_w = 28, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 23753, .adv_w = 480, .box_h = 18, .box_w = 28, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 24005, .adv_w = 514, .box_h = 20, .box_w = 32, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 24325, .adv_w = 446, .box_h = 24, .box_w = 28, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 24661, .adv_w = 446, .box_h = 28, .box_w = 28, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 25053, .adv_w = 377, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 25341, .adv_w = 480, .box_h = 25, .box_w = 30, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 25716, .adv_w = 480, .box_h = 31, .box_w = 30, .ofs_x = 0, .ofs_y = -5},
    {.bitmap_index = 26181, .adv_w = 411, .box_h = 27, .box_w = 26, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 26532, .adv_w = 240, .box_h = 29, .box_w = 15, .ofs_x = 0, .ofs_y = -5},
    {.bitmap_index = 26750, .adv_w = 480, .box_h = 31, .box_w = 28, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 27184, .adv_w = 514, .box_h = 20, .box_w = 33, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 27514, .adv_w = 377, .box_h = 24, .box_w = 24, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 27802, .adv_w = 411, .box_h = 31, .box_w = 26, .ofs_x = 0, .ofs_y = -5},
    {.bitmap_index = 28205, .adv_w = 549, .box_h = 24, .box_w = 34, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 28613, .adv_w = 617, .box_h = 22, .box_w = 39, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 29042, .adv_w = 617, .box_h = 22, .box_w = 39, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 29471, .adv_w = 617, .box_h = 22, .box_w = 39, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 29900, .adv_w = 617, .box_h = 22, .box_w = 39, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 30329, .adv_w = 617, .box_h = 22, .box_w = 39, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 30758, .adv_w = 411, .box_h = 31, .box_w = 23, .ofs_x = 1, .ofs_y = -5}
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
    .glyph_ids = (const uint8_t *)(ARGON_RES_ADDR + MONTSERRAT_ALT_30_KERN_PAIR_GLYPH),
    .values = (const int8_t *)(ARGON_RES_ADDR + MONTSERRAT_ALT_30_KERN_PAIR_VALUE),
    .pair_cnt = 210,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

/*Store all the custom data of the font*/
static lv_font_fmt_txt_dsc_t font_dsc = {
    .glyph_bitmap = (const uint8_t *)(ARGON_RES_ADDR + MONTSERRAT_ALT_30_GLYPH_BMP),
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .cmap_num = 2,
    .bpp = 4,

    .kern_scale = 18,
    .kern_dsc = &kern_pairs,
    .kern_classes = 0
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
lv_font_t lv_font_montserrat_alternate_30 = {
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .line_height = 34,          /*The maximum line height required by the font*/
    .base_line = 7,             /*Baseline measured from the bottom of the line*/
};

#endif