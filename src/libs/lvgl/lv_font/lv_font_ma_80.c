#include "libs/lvgl/lvgl.h"
#include "core/argon-resources.h"


#ifndef LV_FONT_MA_80
#define LV_FONT_MA_80 1
#endif

#if LV_FONT_MA_80

/*-----------------
 *    BITMAPS
 *----------------*/
static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_h = 0, .box_w = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 351, .box_h = 0, .box_w = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 0, .adv_w = 378, .box_h = 59, .box_w = 12, .ofs_x = 6, .ofs_y = -1},
    {.bitmap_index = 354, .adv_w = 479, .box_h = 20, .box_w = 18, .ofs_x = 6, .ofs_y = 36},
    {.bitmap_index = 534, .adv_w = 941, .box_h = 58, .box_w = 53, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 2071, .adv_w = 792, .box_h = 67, .box_w = 43, .ofs_x = 3, .ofs_y = -6},
    {.bitmap_index = 3512, .adv_w = 1006, .box_h = 59, .box_w = 57, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 5194, .adv_w = 888, .box_h = 60, .box_w = 50, .ofs_x = 4, .ofs_y = -2},
    {.bitmap_index = 6694, .adv_w = 297, .box_h = 20, .box_w = 7, .ofs_x = 6, .ofs_y = 36},
    {.bitmap_index = 6764, .adv_w = 425, .box_h = 72, .box_w = 20, .ofs_x = 4, .ofs_y = -11},
    {.bitmap_index = 7484, .adv_w = 425, .box_h = 72, .box_w = 21, .ofs_x = 2, .ofs_y = -11},
    {.bitmap_index = 8240, .adv_w = 553, .box_h = 26, .box_w = 26, .ofs_x = 4, .ofs_y = 30},
    {.bitmap_index = 8578, .adv_w = 727, .box_h = 38, .box_w = 39, .ofs_x = 3, .ofs_y = 12},
    {.bitmap_index = 9319, .adv_w = 360, .box_h = 21, .box_w = 13, .ofs_x = 5, .ofs_y = -9},
    {.bitmap_index = 9456, .adv_w = 609, .box_h = 10, .box_w = 28, .ofs_x = 5, .ofs_y = 19},
    {.bitmap_index = 9596, .adv_w = 358, .box_h = 13, .box_w = 13, .ofs_x = 5, .ofs_y = -1},
    {.bitmap_index = 9681, .adv_w = 751, .box_h = 75, .box_w = 43, .ofs_x = 2, .ofs_y = -10},
    {.bitmap_index = 11294, .adv_w = 881, .box_h = 51, .box_w = 47, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 12493, .adv_w = 488, .box_h = 48, .box_w = 21, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 12997, .adv_w = 754, .box_h = 50, .box_w = 39, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 13972, .adv_w = 740, .box_h = 57, .box_w = 39, .ofs_x = 3, .ofs_y = -9},
    {.bitmap_index = 15084, .adv_w = 732, .box_h = 56, .box_w = 41, .ofs_x = 2, .ofs_y = -8},
    {.bitmap_index = 16232, .adv_w = 741, .box_h = 57, .box_w = 39, .ofs_x = 4, .ofs_y = -9},
    {.bitmap_index = 17344, .adv_w = 794, .box_h = 58, .box_w = 42, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 18562, .adv_w = 724, .box_h = 56, .box_w = 40, .ofs_x = 3, .ofs_y = -8},
    {.bitmap_index = 19682, .adv_w = 814, .box_h = 58, .box_w = 43, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 20929, .adv_w = 792, .box_h = 58, .box_w = 41, .ofs_x = 4, .ofs_y = -9},
    {.bitmap_index = 22118, .adv_w = 375, .box_h = 32, .box_w = 13, .ofs_x = 5, .ofs_y = -1},
    {.bitmap_index = 22326, .adv_w = 379, .box_h = 40, .box_w = 13, .ofs_x = 5, .ofs_y = -9},
    {.bitmap_index = 22586, .adv_w = 758, .box_h = 46, .box_w = 39, .ofs_x = 3, .ofs_y = 9},
    {.bitmap_index = 23483, .adv_w = 799, .box_h = 24, .box_w = 42, .ofs_x = 4, .ofs_y = 19},
    {.bitmap_index = 23987, .adv_w = 758, .box_h = 46, .box_w = 38, .ofs_x = 6, .ofs_y = 9},
    {.bitmap_index = 24861, .adv_w = 650, .box_h = 58, .box_w = 34, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 25847, .adv_w = 1157, .box_h = 64, .box_w = 65, .ofs_x = 4, .ofs_y = -10},
    {.bitmap_index = 27927, .adv_w = 982, .box_h = 58, .box_w = 48, .ofs_x = 7, .ofs_y = 0},
    {.bitmap_index = 29319, .adv_w = 904, .box_h = 56, .box_w = 46, .ofs_x = 7, .ofs_y = 0},
    {.bitmap_index = 30607, .adv_w = 942, .box_h = 59, .box_w = 52, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 32141, .adv_w = 1001, .box_h = 56, .box_w = 52, .ofs_x = 7, .ofs_y = 0},
    {.bitmap_index = 33597, .adv_w = 744, .box_h = 59, .box_w = 40, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 34777, .adv_w = 745, .box_h = 58, .box_w = 38, .ofs_x = 7, .ofs_y = 0},
    {.bitmap_index = 35879, .adv_w = 975, .box_h = 59, .box_w = 52, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 37413, .adv_w = 995, .box_h = 56, .box_w = 48, .ofs_x = 7, .ofs_y = 0},
    {.bitmap_index = 38757, .adv_w = 620, .box_h = 57, .box_w = 31, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 39641, .adv_w = 728, .box_h = 66, .box_w = 37, .ofs_x = 1, .ofs_y = -10},
    {.bitmap_index = 40862, .adv_w = 901, .box_h = 56, .box_w = 48, .ofs_x = 7, .ofs_y = 0},
    {.bitmap_index = 42206, .adv_w = 724, .box_h = 56, .box_w = 36, .ofs_x = 7, .ofs_y = 0},
    {.bitmap_index = 43214, .adv_w = 1379, .box_h = 58, .box_w = 72, .ofs_x = 7, .ofs_y = 0},
    {.bitmap_index = 45302, .adv_w = 996, .box_h = 58, .box_w = 49, .ofs_x = 7, .ofs_y = 0},
    {.bitmap_index = 46723, .adv_w = 1075, .box_h = 59, .box_w = 59, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 48464, .adv_w = 876, .box_h = 56, .box_w = 45, .ofs_x = 7, .ofs_y = 0},
    {.bitmap_index = 49724, .adv_w = 1075, .box_h = 68, .box_w = 59, .ofs_x = 4, .ofs_y = -10},
    {.bitmap_index = 51730, .adv_w = 932, .box_h = 56, .box_w = 48, .ofs_x = 7, .ofs_y = 0},
    {.bitmap_index = 53074, .adv_w = 806, .box_h = 59, .box_w = 44, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 54372, .adv_w = 865, .box_h = 58, .box_w = 52, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 55880, .adv_w = 995, .box_h = 57, .box_w = 48, .ofs_x = 7, .ofs_y = -1},
    {.bitmap_index = 57248, .adv_w = 896, .box_h = 56, .box_w = 56, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 58816, .adv_w = 1340, .box_h = 57, .box_w = 70, .ofs_x = 7, .ofs_y = -1},
    {.bitmap_index = 60811, .adv_w = 867, .box_h = 56, .box_w = 52, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 62267, .adv_w = 927, .box_h = 66, .box_w = 46, .ofs_x = 5, .ofs_y = -10},
    {.bitmap_index = 63785, .adv_w = 864, .box_h = 56, .box_w = 47, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 65101, .adv_w = 454, .box_h = 73, .box_w = 19, .ofs_x = 7, .ofs_y = -12},
    {.bitmap_index = 65795, .adv_w = 668, .box_h = 61, .box_w = 38, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 66954, .adv_w = 454, .box_h = 73, .box_w = 19, .ofs_x = 3, .ofs_y = -12},
    {.bitmap_index = 67648, .adv_w = 504, .box_h = 13, .box_w = 29, .ofs_x = 1, .ofs_y = 59},
    {.bitmap_index = 67837, .adv_w = 924, .box_h = 5, .box_w = 47, .ofs_x = 5, .ofs_y = -11},
    {.bitmap_index = 67955, .adv_w = 1066, .box_h = 12, .box_w = 19, .ofs_x = 25, .ofs_y = 48},
    {.bitmap_index = 68069, .adv_w = 860, .box_h = 45, .box_w = 45, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 69082, .adv_w = 860, .box_h = 61, .box_w = 44, .ofs_x = 6, .ofs_y = -1},
    {.bitmap_index = 70424, .adv_w = 737, .box_h = 45, .box_w = 41, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 71347, .adv_w = 860, .box_h = 61, .box_w = 45, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 72720, .adv_w = 783, .box_h = 45, .box_w = 44, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 73710, .adv_w = 474, .box_h = 58, .box_w = 28, .ofs_x = 6, .ofs_y = 0},
    {.bitmap_index = 74522, .adv_w = 837, .box_h = 61, .box_w = 43, .ofs_x = 3, .ofs_y = -17},
    {.bitmap_index = 75834, .adv_w = 827, .box_h = 60, .box_w = 40, .ofs_x = 6, .ofs_y = 0},
    {.bitmap_index = 77034, .adv_w = 351, .box_h = 61, .box_w = 12, .ofs_x = 5, .ofs_y = 0},
    {.bitmap_index = 77400, .adv_w = 351, .box_h = 78, .box_w = 26, .ofs_x = -9, .ofs_y = -17},
    {.bitmap_index = 78414, .adv_w = 744, .box_h = 60, .box_w = 40, .ofs_x = 6, .ofs_y = 0},
    {.bitmap_index = 79614, .adv_w = 440, .box_h = 57, .box_w = 22, .ofs_x = 6, .ofs_y = -1},
    {.bitmap_index = 80241, .adv_w = 1298, .box_h = 44, .box_w = 70, .ofs_x = 6, .ofs_y = 0},
    {.bitmap_index = 81781, .adv_w = 827, .box_h = 44, .box_w = 40, .ofs_x = 6, .ofs_y = 0},
    {.bitmap_index = 82661, .adv_w = 835, .box_h = 45, .box_w = 46, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 83696, .adv_w = 860, .box_h = 60, .box_w = 44, .ofs_x = 6, .ofs_y = -16},
    {.bitmap_index = 85016, .adv_w = 860, .box_h = 60, .box_w = 45, .ofs_x = 3, .ofs_y = -16},
    {.bitmap_index = 86366, .adv_w = 508, .box_h = 44, .box_w = 24, .ofs_x = 6, .ofs_y = 0},
    {.bitmap_index = 86894, .adv_w = 648, .box_h = 45, .box_w = 35, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 87682, .adv_w = 495, .box_h = 57, .box_w = 25, .ofs_x = 6, .ofs_y = -1},
    {.bitmap_index = 88395, .adv_w = 827, .box_h = 44, .box_w = 40, .ofs_x = 6, .ofs_y = -1},
    {.bitmap_index = 89275, .adv_w = 732, .box_h = 43, .box_w = 45, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 90243, .adv_w = 1167, .box_h = 43, .box_w = 71, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 91770, .adv_w = 714, .box_h = 43, .box_w = 42, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 92673, .adv_w = 826, .box_h = 60, .box_w = 41, .ofs_x = 4, .ofs_y = -17},
    {.bitmap_index = 93903, .adv_w = 691, .box_h = 43, .box_w = 37, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 94699, .adv_w = 430, .box_h = 73, .box_w = 20, .ofs_x = 3, .ofs_y = -12},
    {.bitmap_index = 95429, .adv_w = 329, .box_h = 76, .box_w = 8, .ofs_x = 6, .ofs_y = -13},
    {.bitmap_index = 95733, .adv_w = 430, .box_h = 73, .box_w = 20, .ofs_x = 4, .ofs_y = -12},
    {.bitmap_index = 96463, .adv_w = 737, .box_h = 17, .box_w = 40, .ofs_x = 3, .ofs_y = 22},
    {.bitmap_index = 96803, .adv_w = 1097, .box_h = 75, .box_w = 69, .ofs_x = 0, .ofs_y = -12},
    {.bitmap_index = 99391, .adv_w = 1371, .box_h = 75, .box_w = 86, .ofs_x = 0, .ofs_y = -12},
    {.bitmap_index = 102616, .adv_w = 1280, .box_h = 63, .box_w = 80, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 105136, .adv_w = 1280, .box_h = 54, .box_w = 70, .ofs_x = 5, .ofs_y = 0},
    {.bitmap_index = 107026, .adv_w = 1006, .box_h = 54, .box_w = 54, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 108484, .adv_w = 1097, .box_h = 75, .box_w = 69, .ofs_x = 0, .ofs_y = -6},
    {.bitmap_index = 111072, .adv_w = 1097, .box_h = 69, .box_w = 69, .ofs_x = 0, .ofs_y = -6},
    {.bitmap_index = 113453, .adv_w = 1006, .box_h = 69, .box_w = 63, .ofs_x = 0, .ofs_y = -6},
    {.bitmap_index = 115627, .adv_w = 1189, .box_h = 58, .box_w = 72, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 117715, .adv_w = 1189, .box_h = 69, .box_w = 75, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 120303, .adv_w = 1097, .box_h = 58, .box_w = 69, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 122304, .adv_w = 1097, .box_h = 69, .box_w = 69, .ofs_x = 0, .ofs_y = -6},
    {.bitmap_index = 124685, .adv_w = 549, .box_h = 55, .box_w = 35, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 125648, .adv_w = 823, .box_h = 55, .box_w = 52, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 127078, .adv_w = 1189, .box_h = 65, .box_w = 75, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 129516, .adv_w = 1371, .box_h = 69, .box_w = 86, .ofs_x = 0, .ofs_y = -6},
    {.bitmap_index = 132483, .adv_w = 1097, .box_h = 68, .box_w = 68, .ofs_x = 0, .ofs_y = -6},
    {.bitmap_index = 134795, .adv_w = 731, .box_h = 69, .box_w = 46, .ofs_x = 0, .ofs_y = -6},
    {.bitmap_index = 136382, .adv_w = 1006, .box_h = 70, .box_w = 63, .ofs_x = 0, .ofs_y = -6},
    {.bitmap_index = 138587, .adv_w = 1097, .box_h = 69, .box_w = 69, .ofs_x = 0, .ofs_y = -6},
    {.bitmap_index = 140968, .adv_w = 1097, .box_h = 69, .box_w = 69, .ofs_x = 0, .ofs_y = -6},
    {.bitmap_index = 143349, .adv_w = 731, .box_h = 69, .box_w = 46, .ofs_x = 0, .ofs_y = -6},
    {.bitmap_index = 144936, .adv_w = 1099, .box_h = 58, .box_w = 69, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 146937, .adv_w = 914, .box_h = 73, .box_w = 48, .ofs_x = 6, .ofs_y = -5},
    {.bitmap_index = 148689, .adv_w = 914, .box_h = 73, .box_w = 47, .ofs_x = 4, .ofs_y = -5},
    {.bitmap_index = 150405, .adv_w = 1006, .box_h = 63, .box_w = 63, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 152390, .adv_w = 1006, .box_h = 18, .box_w = 63, .ofs_x = 0, .ofs_y = 22},
    {.bitmap_index = 152957, .adv_w = 1280, .box_h = 75, .box_w = 80, .ofs_x = 0, .ofs_y = -6},
    {.bitmap_index = 155957, .adv_w = 1280, .box_h = 72, .box_w = 80, .ofs_x = 0, .ofs_y = -5},
    {.bitmap_index = 158837, .adv_w = 1280, .box_h = 47, .box_w = 72, .ofs_x = 4, .ofs_y = 1},
    {.bitmap_index = 160529, .adv_w = 1280, .box_h = 47, .box_w = 72, .ofs_x = 4, .ofs_y = -2},
    {.bitmap_index = 162221, .adv_w = 1371, .box_h = 52, .box_w = 86, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 164457, .adv_w = 1189, .box_h = 63, .box_w = 75, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 166820, .adv_w = 1189, .box_h = 72, .box_w = 75, .ofs_x = 0, .ofs_y = -6},
    {.bitmap_index = 169520, .adv_w = 1006, .box_h = 63, .box_w = 63, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 171505, .adv_w = 1280, .box_h = 64, .box_w = 80, .ofs_x = 0, .ofs_y = -6},
    {.bitmap_index = 174065, .adv_w = 1280, .box_h = 81, .box_w = 80, .ofs_x = 0, .ofs_y = -12},
    {.bitmap_index = 177305, .adv_w = 1097, .box_h = 69, .box_w = 69, .ofs_x = 0, .ofs_y = -6},
    {.bitmap_index = 179686, .adv_w = 640, .box_h = 75, .box_w = 40, .ofs_x = 0, .ofs_y = -12},
    {.bitmap_index = 181186, .adv_w = 1280, .box_h = 81, .box_w = 74, .ofs_x = 3, .ofs_y = -12},
    {.bitmap_index = 184183, .adv_w = 1371, .box_h = 52, .box_w = 86, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 186419, .adv_w = 1006, .box_h = 64, .box_w = 63, .ofs_x = 0, .ofs_y = -6},
    {.bitmap_index = 188435, .adv_w = 1097, .box_h = 81, .box_w = 69, .ofs_x = 0, .ofs_y = -12},
    {.bitmap_index = 191230, .adv_w = 1463, .box_h = 63, .box_w = 88, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 194002, .adv_w = 1646, .box_h = 58, .box_w = 103, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 196989, .adv_w = 1646, .box_h = 58, .box_w = 103, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 199976, .adv_w = 1646, .box_h = 58, .box_w = 103, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 202963, .adv_w = 1646, .box_h = 58, .box_w = 103, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 205950, .adv_w = 1646, .box_h = 58, .box_w = 103, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 208937, .adv_w = 1097, .box_h = 81, .box_w = 60, .ofs_x = 4, .ofs_y = -12}
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
    .glyph_ids = (const uint8_t *)(ARGON_RES_ADDR + MONTSERRAT_ALT_80_KERN_PAIR_GLYPH),
    .values = (const int8_t *)(ARGON_RES_ADDR + MONTSERRAT_ALT_80_KERN_PAIR_VALUE),
    .pair_cnt = 210,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

/*Store all the custom data of the font*/
static lv_font_fmt_txt_dsc_t font_dsc = {
    .glyph_bitmap = (const uint8_t *)(ARGON_RES_ADDR + MONTSERRAT_ALT_80_GLYPH_BMP),
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .cmap_num = 2,
    .bpp = 4,

    .kern_scale = 48,
    .kern_dsc = &kern_pairs,
    .kern_classes = 0
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
lv_font_t lv_font_montserrat_alternate_80 = {
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .line_height = 89,          /*The maximum line height required by the font*/
    .base_line = 17,             /*Baseline measured from the bottom of the line*/
};

#endif /*#if MONTSERRAT_ALTERNATE_80*/

