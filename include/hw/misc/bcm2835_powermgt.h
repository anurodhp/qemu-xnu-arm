/*
 * BCM2835 Power Management emulation
 *
 * Copyright (C) 2017 Marcin Chojnacki <marcinch7@gmail.com>
 * Copyright (C) 2021 Nolan Leake <nolan@sigbus.net>
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or later.
 * See the COPYING file in the top-level directory.
 */

#ifndef BCM2835_POWERMGT_H
#define BCM2835_POWERMGT_H

#include "hw/sysbus.h"

/*
 * Backported from upstream QEMU v6.2.0 (include/hw/misc/bcm2835_powermgt.h)
 * to this 2.12-based tree: OBJECT_DECLARE_SIMPLE_TYPE does not exist here,
 * so the typedef and cast macro are spelled out.
 */
#define TYPE_BCM2835_POWERMGT "bcm2835-powermgt"
#define BCM2835_POWERMGT(obj) \
    OBJECT_CHECK(BCM2835PowerMgtState, (obj), TYPE_BCM2835_POWERMGT)

typedef struct BCM2835PowerMgtState {
    SysBusDevice busdev;
    MemoryRegion iomem;

    uint32_t rstc;
    uint32_t rsts;
    uint32_t wdog;
} BCM2835PowerMgtState;

#endif
