#include "../drivers/hss_driver.h"

#define HSS_REG_STATUS_CH1    0x10u
#define HSS_REG_STATUS_CH2    0x11u
#define HSS_REG_STATUS_CH3    0x12u
#define HSS_REG_STATUS_CH4    0x13u

void example_read_channel_status(void)
{
    uint16_t ch1_status;
    uint16_t ch2_status;
    uint16_t ch3_status;
    uint16_t ch4_status;
    uint8_t global_status;

    ch1_status = hss_read_reg(HSS_REG_STATUS_CH1);
    ch2_status = hss_read_reg(HSS_REG_STATUS_CH2);
    ch3_status = hss_read_reg(HSS_REG_STATUS_CH3);
    ch4_status = hss_read_reg(HSS_REG_STATUS_CH4);

    global_status = hss_get_last_global_status();

    (void)ch1_status;
    (void)ch2_status;
    (void)ch3_status;
    (void)ch4_status;
    (void)global_status;
}

void example_clear_all_faults(void)
{
    hss_clear_all_status();
}
