/*
 * Copyright (c) 2018 Atmosphère-NX
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
 
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <malloc.h>
#include <sys/iosupport.h>
#include "utils/utils.h"

void __libc_init_array(void);
void __libc_fini_array(void);

extern uint8_t __bss_start__[], __bss_end__[];
extern uint8_t __heap_start__[], __heap_end__[];

extern char *fake_heap_start;
extern char *fake_heap_end;

static void __program_init_heap(void) {
    fake_heap_start = (char*)__heap_start__;
    fake_heap_end   = (char*)__heap_end__;
}

void __program_init(int argc, char *argdata) {
    /* Zero-fill the .bss section */
    memset(__bss_start__, 0, __bss_end__ - __bss_start__);

    __program_init_heap();
    __libc_init_array();
}