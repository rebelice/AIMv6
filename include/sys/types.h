/* Copyright (C) 2016 Gan Quan <coin2028@hotmail.com>
 * Copyright (C) 2016 David Gao <davidgao1001@gmail.com>
 *
 * This file is part of AIMv6.
 *
 * AIMv6 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * AIMv6 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

#ifndef __ASSEMBLER__
/*
 * This macro is a wrapper for casting integer constants to unsigned longs,
 * freeing the code from compiler warnings and assembler errors (GCC
 * warns about shift count if a "UL" suffix is not appended while GAS
 * refuses to recognize the "UL" suffix).
 */
#define __ULCAST(i)	(i##UL)
#else	/* __ASSEMBLER__ */
#define __ULCAST(i)	i
#endif	/* !__ASSEMBLER__ */

#ifndef __ASSEMBLER__

/* 
 * Type usage should be unified across AIMv6.
 * When a foreign module is imported, it MUST either apply AIMv6 type naming, 
 * or provide typedefs by itself. Normally typedefs SHOULD NOT be added to
 * this header.
 */

typedef unsigned char	uint8_t;
typedef signed char	int8_t;
typedef unsigned short	uint16_t;
typedef signed short	int16_t;
typedef unsigned int	uint32_t;
typedef signed int	int32_t;
typedef unsigned long long	uint64_t;
typedef signed long long	int64_t;

typedef uint32_t atomic_t;
typedef int32_t satomic_t;

typedef unsigned long ulong;

typedef unsigned int bool;
#define false	0
#define true	1

#define EOF	-1

/* For in-memory objects, same as POSIX */
typedef unsigned long size_t;
typedef signed long ssize_t;

typedef void *uintptr_t;
#define	NULL	0

/*
 * For use with other address space, like physical address space,
 * IO address space, etc. Note that 64-bit address spaces may present even on
 * 32-bit systems.
 * Use the unsigned version to indicate address and size,
 * the signed version to indicate offset.
 */
typedef unsigned long long addr_t;
typedef signed long long saddr_t;

/*
 * Define types used within the system.
 * This is only a design pattern.
 */
typedef ulong	devid_t;

/* A generic void function pointer type, allow any number of arguments */
typedef void (*generic_fp)();
typedef void (*callback_fp)();

#endif

#endif

