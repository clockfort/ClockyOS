#!/bin/bash
rm load
rm kernel
nasm kernel.s
dd conv=notrunch if=kernel of=qemu.img
nasm load.s
dd conv=notrunc if=load of=qemu.img
#Make Magic Boot Sector
(for i in $(seq 1 1 256); do echo -en "\x55\xAA"; done; for i in $(seq 1 1 512); do echo -en "\x42"; done) | dd conv=notrunc of=qemu.img
