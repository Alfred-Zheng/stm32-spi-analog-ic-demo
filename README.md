# stm32-spi-analog-ic-demo

A virtual STM32 SPI demo project for the HD708204Q 4-channel high-side driver.

## Goal

Use STM32 to communicate with the HD708204Q through its 24-bit SPI interface.

## Basic SPI Signals

- SCK: SPI clock
- SDI: master output, slave input
- SDO: master input, slave output
- CSN: chip select, active low

## STM32 SPI Settings

- Master mode
- Full duplex
- 8-bit data size
- MSB first
- CPOL = 0
- CPHA = 0
- Software-controlled CSN GPIO
- Clock frequency <= 8 MHz

## Planned Functions

- Read one register
- Write one register
- Read status registers
- Clear status registers
- Read device information

## SPI Frame

One SPI transaction contains exactly 24 bits:

```text
Byte 0: command / address
Byte 1: data high
Byte 2: data low
```

Command byte:

```text
bit:  7   6   5   4   3   2   1   0
      OC1 OC0 A5  A4  A3  A2  A1  A0
```

MOSI/SDI sends:

```text
command byte + 16-bit data
```

MISO/SDO returns:

```text
global status byte + 16-bit data
```

## Hardware Hookup

The demo keeps `HSS_USE_STM32_HAL` disabled by default so the files can be read without an STM32CubeMX project.

To connect real hardware:

1. Copy `driver/hss_driver.c` and `driver/hss_driver.h` into the STM32 project.
2. Set `HSS_USE_STM32_HAL` to `1`.
3. Include the generated STM32 HAL headers.
4. Define the real `HSS_CSN_GPIO_Port` and `HSS_CSN_Pin` symbols.
5. Confirm the SPI peripheral uses CPOL 0, CPHA 0, MSB first, and 8-bit frames.
