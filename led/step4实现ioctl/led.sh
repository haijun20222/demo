#!/bin/bash
insmod led.ko
mknod /dev/led c 500 0
./a.out




