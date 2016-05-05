/* Copyright (C) 2016 David Gao <davidgao1001@gmail.com>
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

#ifndef _AIM_INIT_H
#define _AIM_INIT_H

typedef int (*initcall_t)(void);

#ifndef __ASSEMBLER__

#define __initcall(fn, sec) \
	static initcall_t __##sec##_##fn __used \
	__attribute__((__section__(".init" #sec))) = fn;

/*
 * In AIM, early, normal, and late initcalls ALL have stages, so we
 * can have different organizations for this part.
 * For a bootable kernel, not all of them need to be configured.
 */
#define EARLY_INITCALL(fn, id) \
	__initcall(fn, .early##id)

/* don't add NORM here as it should be the default pace to go */
#define INITCALL(fn, id) \
	__initcall(fn, .norm##id)

#define LATE_INITCALL(fn, id) \
	__initcall(fn, .late##id)

/* This is slightly different to linux. We assign a stage for rootfs. */
#define INITCALL_PURE(fn)	EARLY_INITCALL(fn, 0)
#define INITCALL_CORE(fn)	EARLY_INITCALL(fn, 1)
#define INITCALL_POSTCORE(fn)	EARLY_INITCALL(fn, 2)
#define INITCALL_ARCH(fn)	EARLY_INITCALL(fn, 3)
#define INITCALL_SUBSYS(fn)	EARLY_INITCALL(fn, 4)
#define INITCALL_FS(fn)		EARLY_INITCALL(fn, 5)
#define INITCALL_ROOTFS(fn)	EARLY_INITCALL(fn, 6)
#define INITCALL_DEV(fn)	EARLY_INITCALL(fn, 7)

#endif /* __ASSEMBLER__ */

#endif /* _AIM_INIT_H */
