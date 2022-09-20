#!/bin/bash
make clean
make
aarch64-linux-gnu-gcc app.c
cp led.ko a.out /nfs/rootfs


