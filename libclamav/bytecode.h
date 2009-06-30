/*
 *  Load, verify and execute ClamAV bytecode.
 *
 *  Copyright (C) 2009 Sourcefire, Inc.
 *
 *  Authors: Török Edvin
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *  MA 02110-1301, USA.
 */
#ifndef BYTECODE_H
#define BYTECODE_H
#include <stdio.h>
#include "clambc.h"
struct cli_dbio;
struct cli_bc_ctx;
struct cli_bc_func;

struct cli_bc {
  unsigned verifier;
  char *sigmaker;
  unsigned id;
  struct bytecode_metadata metadata;
  unsigned num_func;
  struct cli_bc_func *funcs;
};

struct cli_bc_ctx *cli_bytecode_alloc_context(void);
void cli_bytecode_destroy_context(struct cli_bc_ctx *ctx);

int cli_bytecode_load(struct cli_bc *bc, FILE *f, struct cli_dbio *dbio);
void cli_bytecode_run(struct cli_bc *bc, struct cli_bc_ctx *ctx);
void cli_bytecode_destroy(struct cli_bc *bc);

#endif