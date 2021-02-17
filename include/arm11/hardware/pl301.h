#pragma once

/*
 *   This file is part of open_agb_firm
 *   Copyright (C) 2021 derrek, profi200
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <assert.h>
#include "types.h"
#include "mem_map.h"


#define PL301_REGS_BASE  (IO_MEM_ARM11_ONLY + 0xF400)

typedef struct
{
	struct
	{
		vu32 qos_tidemark;        // QoS tidemark.
		vu32 qos_acs;             // QoS access control.
		vu32 ar_arb;              // AR channel arbitration value.
		vu32 aw_arb;              // AW channel arbitration value.
		u8 _0x10[0x10];
	} mi[64]; // Master interface.
	u8 _0x800[0x7c0];
	const vu32 primecell_cfg0;    // PrimeCell Configuration Register 0.
	const vu32 primecell_cfg1;    // PrimeCell Configuration Register 1.
	const vu32 primecell_cfg2;    // PrimeCell Configuration Register 2.
	const vu32 primecell_cfg3;    // PrimeCell Configuration Register 3.
	u8 _0xfd0[0x10];
	const vu32 primecell_periph0; // PrimeCell Peripheral Register 0.
	const vu32 primecell_periph1; // PrimeCell Peripheral Register 1.
	const vu32 primecell_periph2; // PrimeCell Peripheral Register 2.
	const vu32 primecell_periph3; // PrimeCell Peripheral Register 3.
	const vu32 primecell_id0;     // PrimeCell ID Register 0.
	const vu32 primecell_id1;     // PrimeCell ID Register 1.
	const vu32 primecell_id2;     // PrimeCell ID Register 2.
	const vu32 primecell_id3;     // PrimeCell ID Register 3.
} Pl301;
static_assert(offsetof(Pl301, primecell_id3) == 0xFFC, "Error: Member primecell_id3 of Pl301 is not at offset 0xFFC!");

ALWAYS_INLINE Pl301* getPl301Regs(void)
{
	return (Pl301*)PL301_REGS_BASE;
}