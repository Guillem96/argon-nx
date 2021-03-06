#ifndef _ARGON_RESOURCES_H_
#define _ARGON_RESOURCES_H_

#define ARGON_RES_ADDR 0xEE000000

// Montserrat 12 font
#define MONTSERRAT_12_GLYPH_BMP 0x0
#define MONTSERRAT_12_KERN_PAIR_GLYPH 0x9FE
#define MONTSERRAT_12_KERN_PAIR_VALUE 0xFF6

// Montserrat 40 font
#define MONTSERRAT_40_GLYPH_BMP 0x12F2
#define MONTSERRAT_40_KERN_PAIR_GLYPH 0xE587
#define MONTSERRAT_40_KERN_PAIR_VALUE 0xEB7F

// Montserrat Alternate 80 font
#define MONTSERRAT_ALT_80_GLYPH_BMP 0xEE7B
#define MONTSERRAT_ALT_80_KERN_PAIR_GLYPH 0x42822
#define MONTSERRAT_ALT_80_KERN_PAIR_VALUE 0x429C6

// Montserrat Alternate 20 font
#define MONTSERRAT_ALT_20_GLYPH_BMP 0x42A98
#define MONTSERRAT_ALT_20_KERN_PAIR_GLYPH 0x46213
#define MONTSERRAT_ALT_20_KERN_PAIR_VALUE 0x463B7

// Montserrat Alternate 30 font
#define MONTSERRAT_ALT_30_GLYPH_BMP 0x46489
#define MONTSERRAT_ALT_30_KERN_PAIR_GLYPH 0x4DE14
#define MONTSERRAT_ALT_30_KERN_PAIR_VALUE 0x4DFB8

// Montserrat Alternate 110 font
#define MONTSERRAT_ALT_110_GLYPH_BMP 0x4E08A
#define MONTSERRAT_ALT_110_KERN_LEFT_MAP 0x7B294
#define MONTSERRAT_ALT_110_KERN_RIGHT_MAP 0x7B2F6
#define MONTSERRAT_ALT_110_KERN_CLASS_VALUE 0x7B358

void argon_resources_init();

#endif