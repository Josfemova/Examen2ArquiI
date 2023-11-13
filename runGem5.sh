#!/bin/bash
export GEM5_DIR=/root
export BENCHMARK=./src/benchmark

ARRAY_SZ=( "0x1000" "0x2000" "0x3000"  "0x4000" "0x5000" "0x6000" "0x7000")

function gem5(){
    $GEM5_DIR/build/X86/gem5.opt -d m5out/ \
        $GEM5_DIR/configs/deprecated/example/se.py -c $BENCHMARK -I 100000000 \
        --cpu-type=TimingSimpleCPU --caches --l2cache \
        --l1d_size=64kB --l1i_size=64kB --l2_size=256kB \
        --l1d_assoc=1 --l1i_assoc=1 --l2_assoc=4 --cacheline_size=64 
}

rm -rf pruebas
mkdir pruebas

for x in ${ARRAY_SZ[@]}; do
    export DATOS=$x;
    
    # fusion de arreglos
    resdir=pruebas/fusion/d_$x
    mkdir -p $resdir
    cd src; make f0; cd ..; 
    gem5
    grep -E "u.cpi|u.ipc|numCycles|overallMissRate::total" m5out/stats.txt \
        > $resdir/resF0.txt
    cd src; make f1; cd ..; 
    gem5
    grep -E "u.cpi|u.ipc|numCycles|overallMissRate::total" m5out/stats.txt \
        > $resdir/resF1.txt

    # intercambio de ciclos
    resdir=pruebas/intercambio/d_$x
    mkdir -p $resdir
    cd src; make i0; cd ..; 
    gem5
    grep -E "u.cpi|u.ipc|numCycles|overallMissRate::total" m5out/stats.txt \
        > $resdir/resI0.txt
    cd src; make i1; cd ..; 
    gem5
    grep -E "u.cpi|u.ipc|numCycles|overallMissRate::total" m5out/stats.txt \
        > $resdir/resI1.txt
done
