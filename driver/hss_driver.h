#ifndef HSS_DRIVER_H
#define HSS_DRIVER_H

#include <stdint.h>

#define HSS_OP_WRITE              0x00u
#define HSS_OP_READ               0x40u
#define HSS_OP_READ_CLEAR_STATUS  0x80u
#define HSS_OP_READ_DEVICE_INFO   0xC0u

#define HSS_ADDR_MASK             0x3Fu
#define HSS_ADDR_ALL_STATUS       0x3Fu

#define HSS_CMD_SW_RESET          0xFFu
#define HSS_CMD_CLEAR_ALL_STATUS  0xBFu

uint32_t hss_transfer24(uint8_t cmd, uint16_t data);

uint16_t hss_write_reg(uint8_t addr, uint16_t value);
uint16_t hss_read_reg(uint8_t addr);
uint16_t hss_read_clear_status(uint8_t addr);
uint16_t hss_read_device_info(uint8_t addr);

void hss_software_reset(void);
void hss_clear_all_status(void);

uint8_t hss_get_last_global_status(void);

#endif
