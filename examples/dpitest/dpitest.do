
vlib work

vlog -sv -work work ../../../riscv-isa-sim/softfloat/*.c
vlog -sv -work work ../../src/coverfloat_pkg.sv ../../src/*.c
vlog -sv -work work ./tb.sv

vsim -lib work tb

run -all