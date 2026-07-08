# SPI Protocol Notes

This document summarizes the 24-bit SPI protocol used by the 4-channel high-side switch demo device.

## SPI Role

- STM32: SPI master
- High-side switch IC: SPI slave
- Frame length: 24 bits
- Bit order: MSB first
- CS/CSN: active low

## SPI Frame Format

Each SPI transaction contains 24 bits:

```text
Byte 0: Command byte
Byte 1: Data high byte
Byte 2: Data low byte

bit7 bit6 bit5 bit4 bit3 bit2 bit1 bit0
 OC1  OC0  A5   A4   A3   A2   A1   A0

#define HSS_OP_WRITE              0x00u
#define HSS_OP_READ               0x40u
#define HSS_OP_READ_CLEAR_STATUS  0x80u
#define HSS_OP_READ_DEVICE_INFO   0xC0u
#define HSS_ADDR_MASK             0x3Fuo

cmd = op | (addr & HSS_ADDR_MASK);

MOSI: Command byte + 16-bit data
MISO: Global status byte + previous 16-bit register content

MOSI: Command byte + 16-bit clear mask
MISO: Global status byte + 16-bit status data

Command byte: 0xFF
Data field:   0x0000
Frame:        0xFF0000

hss_software_reset();
