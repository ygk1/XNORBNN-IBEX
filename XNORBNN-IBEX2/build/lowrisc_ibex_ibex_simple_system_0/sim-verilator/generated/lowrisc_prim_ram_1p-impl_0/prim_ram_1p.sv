// Copyright lowRISC contributors.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

// This file is auto-generated.

`ifndef PRIM_DEFAULT_IMPL
  `define PRIM_DEFAULT_IMPL prim_pkg::ImplGeneric
`endif

module prim_ram_1p

#(

  parameter  int Width           = 32, // bit
  parameter  int Depth           = 128,
  parameter  int DataBitsPerMask = 1, // Number of data bits per bit of write mask
  parameter      MemInitFile     = "", // VMEM file to initialize the memory with

  localparam int Aw              = $clog2(Depth)  // derived parameter

) (
  input  logic             clk_i,

  input  logic             req_i,
  input  logic             write_i,
  input  logic [Aw-1:0]    addr_i,
  input  logic [Width-1:0] wdata_i,
  input  logic [Width-1:0] wmask_i,
  output logic [Width-1:0] rdata_o // Read data. Data is returned one cycle after req_i is high.
);
  parameter prim_pkg::impl_e Impl = `PRIM_DEFAULT_IMPL;

if (Impl == prim_pkg::ImplBadbit) begin : gen_badbit
    prim_badbit_ram_1p #(
      .Depth(Depth),
      .MemInitFile(MemInitFile),
      .Width(Width),
      .DataBitsPerMask(DataBitsPerMask)
    ) u_impl_badbit (
      .*
    );
end else begin : gen_generic
    prim_generic_ram_1p #(
      .Depth(Depth),
      .MemInitFile(MemInitFile),
      .Width(Width),
      .DataBitsPerMask(DataBitsPerMask)
    ) u_impl_generic (
      .*
    );
end

endmodule
