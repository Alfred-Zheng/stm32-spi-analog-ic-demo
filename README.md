# stm32-spi-analog-ic-demo
A virtual STM32 SPI demo project for analog IC register read/write

## Goal

Use STM32 to communicate with an analog IC through SPI.

## Basic SPI Signals

- SCLK: SPI clock
- MOSI: master output, slave input
- MISO: master input, slave output
- CS: chip select

## Planned Functions

- Read one register
- Write one register
- Read multiple registers
- Write multiple registers
- Read chip ID

## SPI Frame

One SPI transaction contains 24 bits:

```text
Byte 0: command / address
Byte 1: data high
Byte 2: data low
