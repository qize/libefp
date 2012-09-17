/*-
 * Copyright (c) 2012 Ilya Kaliman
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef EFPMD_COMMON_H
#define EFPMD_COMMON_H

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <compat.h>
#include <phys_const.h>

#include "cfg.h"

#define NORETURN __attribute__((noreturn))
#define UNUSED __attribute__((unused))

#define EPSILON 1.0e-8
#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

#define streq(a, b) (u_strcasecmp(a, b) == 0)
#define strneq(a, b, n) (u_strncasecmp(a, b, n) == 0)

#define ANGSTROM_TO_BOHR(x) ((x) / BOHR_RADIUS)
#define BOHR_TO_ANGSTROM(x) ((x) * BOHR_RADIUS)

void NORETURN die(const char *, ...);
void NORETURN error(const char *, ...);
void NORETURN lib_error(enum efp_result);

void *xmalloc(size_t);
void *xcalloc(size_t, size_t);
void *xrealloc(void *, size_t);

void print_geometry(struct efp *);
void print_energy(struct efp *);
void print_gradient(struct efp *);
void print_fragment(const char *, const double *, const double *);
void print_matrix(int, int, const double *);

#endif /* EFPMD_COMMON_H */