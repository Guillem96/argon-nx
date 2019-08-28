CSRCS += lv_theme.c
CSRCS += lv_theme_default.c
CSRCS += lv_theme_argon.c

DEPPATH += --dep-path $(LVGL_DIR)/lvgl/src/lv_themes
VPATH += :$(LVGL_DIR)/lvgl/src/lv_themes

CFLAGS += "-I$(LVGL_DIR)/lvgl/src/lv_themes"
