ClockyOS
========

Chris Lockfort (clockfort@csh.rit.removethisforautomatedspamprevention.edu)


A few different attempts/renditions at operating system development, just me messing around in my spare time so that I can better grok how these sort of things really work under the hood.

You'll note that the quality and usefullness of these applications increases with the version ID, though they're all interesting little offshoots into different areas of knowledge.

Each version has an invidual readme file describing the compile/development process, as this process varies widely between versions.

Quick Rundown:
==============

## Version 1 ##
The v1/ directory contains the first version of ClockyOS.
This version is for x86, and has its own bootloader, and is written in assembly.

## Version 2 ##
The v2/ directory contains the second version of ClockyOS.
This version is for x86, uses GRUB as its bootloader, and is mostly C code with only a minor amount of assembler. It also provides a Makefile for easy programming, and has a cool color textmode video driver. Additionally this version has CPUID detection software and a neat Gentoo-like bootup process, but none of these features are used in a very useful way.

## LifeOS ##
The LifeOS/ directory contains an amalgamation of a C++ version of Conway's Game of Life that I had written previously (also available on GitHub) and an early version of ClockyOS v2. Basically it just lets you boot up a computer and watch it play Conway's Game of Life. More of a proof-of-concept that even such a basic OS could load and run a ported real application, at least it looks cool. Some of the game algorithms are rather nifty as well, as I originally engineered it for very low-memory embedded/microcontroller type systems.

## [REDACTED] ##
The v3/ directory contains the third version of ClockyOS.
This version is for intended to run on AVR microprocessors, and will probably feature realtime elements.
