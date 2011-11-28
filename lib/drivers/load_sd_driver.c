/*
# #########################################################
# This file loads the SD driver cog code.
#   
# Written by Dave Hein
# Copyright (c) 2011 Parallax, Inc.
# MIT Licensed
# #########################################################
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <sys/driver.h>
#include <compiler.h>
#include <errno.h>
#include <cog.h>
#include <sys/driver.h>
#include "propdev.h"

extern uint32_t *_sd_mbox_p;
static volatile uint32_t __attribute__((section(".hub"))) sd_mbox[2];

// This routine starts the SD driver cog
void LoadSDDriver(uint8_t *pins)
{
    extern void *sd_driver_array;
    int32_t pinmask[5];

    use_cog_driver(cogsys1);

    _sd_mbox_p = (uint32_t *)sd_mbox;

    // Overwrite pin masks if pins are specified
    if (pins)
    {
        pinmask[0] = 1 << pins[0];  // SD MISO
        pinmask[1] = 1 << pins[1];  // SD CLK
        pinmask[2] = 1 << pins[2];  // SD MOSI
        pinmask[3] = 1 << pins[3];  // SD CS
        pinmask[4] = 0;             // Zero disables C3 mode
        memcpy(sd_driver_array+4, pinmask, 20);
    }

    sd_mbox[0] = 1;
    load_cog_driver(sd_driver_array, cogsys1, (uint32_t *)sd_mbox);
    while (sd_mbox[0]);
}

/*
+--------------------------------------------------------------------
|  TERMS OF USE: MIT License
+--------------------------------------------------------------------
Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files
(the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge,
publish, distribute, sublicense, and/or sell copies of the Software,
and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
+------------------------------------------------------------------
*/