Project: 5-stage RISC-V Pipeline (SV2012)

Overview
--------
This repository implements a simple 5-stage RISC-V pipeline (IF, ID, EX, MEM, WB) in SystemVerilog.
It includes a modular top (`src/riscvpipeline.sv`), a datapath (`src/datapath.sv`), a controller (`src/controller.sv`), forwarding and hazard units, a simple synchronous RAM (`src/memory.sv`), and a testbench (`tb/tb_pipeline.sv` and `tb/tb_modular.sv`).

Purpose
-------
- Provide a working 5-stage pipeline for teaching and small experiments.
- Run a small program (`tests/rvx10_pipeline.hex`) that stores a value into data memory and verifies the result.
- Measure simple performance: cycle_count and instructions retired -> CPI.

How to run
----------
From the repository root (`/home/pankaj/Downloads/Digital Logic/Assignment/pipe3/files1`):

```bash
# compile and run the modular TB
iverilog -g2012 -o pipeline_sim \
  tb/tb_modular.sv src/datapath.sv src/controller.sv src/forwarding_unit.sv src/hazard_unit.sv src/memory.sv src/riscvpipeline.sv && \
  vvp pipeline_sim

# or run the simpler TB
iverilog -g2012 -o pipeline_sim \
  tb/tb_pipeline.sv src/datapath.sv src/controller.sv src/forwarding_unit.sv src/hazard_unit.sv src/memory.sv src/riscvpipeline.sv && \
  vvp pipeline_sim
```

Both testbenches initialize instruction memory and data memory and run the simulation for a fixed window. The TB checks that a store writes the expected value to address 100 (word index 25) and prints cycle_count, instr_retired, and CPI.

Recent edits (what I changed)
----------------------------
- Fixed an ID/EX decode driving bug: replaced initializer-driven decode signals with continuous assignments in `src/datapath.sv` (this removed X propagation and allowed proper DMEM writes).
- Exposed ID/EX-latched control signals from the datapath to the hazard unit to avoid mismatches during stalling.
- Added verbose debug $display prints in the top and datapath for tracing pipeline registers and DMEM writes while debugging.
- Added a CPI summary print to `tb/tb_pipeline.sv` (prints cycles, instructions retired, measured CPI, comparisons to single-cycle and ideal pipeline baselines).
- Added some test-program edits to `tests/rvx10_pipeline.hex` on user request (branches, dependencies). Note: some edits included an early `ret` which may make later instructions unreachable; if you see a failing DMEM check, verify instruction ordering.

Sample run output (example)
---------------------------
TEST PASSED: dmem[100] == 25
cycle_count = 200
instr_retired = 14
Measured CPI = 14.29 (cycles/instr)
Baseline single-cycle CPI = 5.00 => expected cycles = 70.00
Ideal pipelined CPI = 1.00 => expected cycles = 14.00
Measured cycles = 200 (285.71% of single-cycle expected, 1328.57% over ideal)

Notes and recommendations
-------------------------
- The high measured CPI above is caused by the test program and stalls (few retired instructions relative to cycles). To get a lower CPI:
  - Remove early `ret` or long sequences of NOPs before the store.
  - Ensure the test program contains contiguous useful instructions that retire.
- The current per-cycle debug prints are helpful during debugging but noisy for routine runs. Consider gating them with a `DEBUG` parameter or removing them when not needed.

Next steps (suggested)
----------------------
- Gate or remove the verbose $display statements (`src/riscvpipeline.sv`, `src/datapath.sv`) to make TB output concise.
- Add a small `Makefile` with `make test` to compile and run TB automatically and capture results.
- Add unit/regression tests (small hex programs) and a CI script if you plan to evolve the core.

Files changed (recent)
----------------------
- tb/tb_pipeline.sv (CPI printing + testbench fixes to reference internal dmem and PC)
- tb/tb_modular.sv (CPI comparator summary prints)
- src/datapath.sv (fixed decode driving to remove Xs)
- src/riscvpipeline.sv (wiring, debug prints)
- tests/rvx10_pipeline.hex (user-updated program image)

Contact / Usage
---------------
If you'd like, I can:
- Quiet the debug prints behind a `DEBUG` parameter (safe, quick change).
- Add a `Makefile` with `make test` and `make clean`.
- Reorder or insert an explicit store-to-address-100 early in the program image so the TB always sees the expected store.

Report generated: 2025-11-01
