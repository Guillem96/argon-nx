CSRCS += lv_font.c
CSRCS += lv_font_fmt_txt.c
CSRCS += lv_font_unscii_8.c
CSRCS += lv_font_montserrat_12.c
CSRCS += lv_font_ma_20.c
CSRCS += lv_font_ma_30.c
CSRCS += lv_font_ma_80.c
CSRCS += lv_font_ma_110.c

DEPPATH += --dep-path $(LVGL_DIR)/lvgl/src/lv_font
VPATH += :$(LVGL_DIR)/lvgl/src/lv_font

CFLAGS += "-I$(LVGL_DIR)/lvgl/src/lv_font"
