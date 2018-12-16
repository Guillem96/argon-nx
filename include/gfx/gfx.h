/*
 * Copyright (c) 2018 naehrwert
 * Copyright (C) 2018 CTCaer
 * Copyright (C) 2018 M4xw
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _GFX_H_
#define _GFX_H_

typedef struct _gfx_ctxt_t
{
	unsigned int *fb;
	unsigned int width;
	unsigned int height;
	unsigned int stride;
} gfx_ctxt_t;

typedef struct _gfx_con_t
{
	gfx_ctxt_t *gfx_ctxt;
	unsigned int fntsz;
	unsigned int x;
	unsigned int y;
	unsigned int savedx;
	unsigned int savedy;
	unsigned int fgcol;
	int fillbg;
	unsigned int bgcol;
	int mute;
} gfx_con_t;

void gfx_init_ctxt(gfx_ctxt_t *ctxt, unsigned int *fb, unsigned int width, unsigned int height, unsigned int stride);
void gfx_clear_grey(gfx_ctxt_t *ctxt, unsigned char color);
void gfx_clear_partial_grey(gfx_ctxt_t *ctxt, unsigned char color, unsigned int pos_x, unsigned int height);
void gfx_clear_color(gfx_ctxt_t *ctxt, unsigned int color);
void gfx_con_init(gfx_con_t *con, gfx_ctxt_t *ctxt);
void gfx_con_setcol(gfx_con_t *con, unsigned int fgcol, int fillbg, unsigned int bgcol);
void gfx_con_getpos(gfx_con_t *con, unsigned int *x, unsigned int *y);
void gfx_con_setpos(gfx_con_t *con, unsigned int x, unsigned int y);
void gfx_putc(gfx_con_t *con, char c);
void gfx_puts(gfx_con_t *con, const char *s);
void gfx_printf(gfx_con_t *con, const char *fmt, ...);
void gfx_hexdump(gfx_con_t *con, unsigned int base, const unsigned char *buf, unsigned int len);

void gfx_set_pixel(gfx_ctxt_t *ctxt, unsigned int x, unsigned int y, unsigned int color);
void gfx_line(gfx_ctxt_t *ctxt, int x0, int y0, int x1, int y1, unsigned int color);
void gfx_put_small_sep(gfx_con_t *con);
void gfx_put_big_sep(gfx_con_t *con);
void gfx_set_rect_grey(gfx_ctxt_t *ctxt, const unsigned char *buf, unsigned int size_x, unsigned int size_y, unsigned int pos_x, unsigned int pos_y);
void gfx_set_rect_rgb(gfx_ctxt_t *ctxt, const unsigned char *buf, unsigned int size_x, unsigned int size_y, unsigned int pos_x, unsigned int pos_y);
void gfx_set_rect_argb(gfx_ctxt_t *ctxt, const unsigned int *buf, unsigned int size_x, unsigned int size_y, unsigned int pos_x, unsigned int pos_y);
void gfx_render_bmp_argb(gfx_ctxt_t *ctxt, const unsigned int *buf, unsigned int size_x, unsigned int size_y, unsigned int pos_x, unsigned int pos_y);

#endif