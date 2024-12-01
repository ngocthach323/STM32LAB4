/*
 * fsm_setting.c
 *
 *  Created on: Oct 30, 2024
 *      Author: ACER
 */
#include "fsm_setting.h"

int status_modify = RED_MODIFY;

void fsm_setting() {
	if (status_system == AUTO) {
		return;
	}
	switch (status_modify) {
		case RED_MODIFY:
			//tắt đèn vàng và xanh
			turn_off_yellow_green();
			//nhấp nháy đèn đỏ
			toggle_red_led();

			//button2
			if (isButtonPressed(1) == 1) {
				time_red_ver++;
				time_red_hor++;
			}
			//update buffer
			led_buffer_ver[0] = time_red_ver / 10;
			led_buffer_ver[1] = time_red_ver % 10;
			led_buffer_hor[0] = 0;
			led_buffer_hor[1] = 1;
			break;
		case YELLOW_MODIFY:
			//tắt đèn đỏ và xanh
			turn_off_red_green();
			//nhấp nháy đèn vàng
			toggle_yellow_led();
			//button2
			if (isButtonPressed(1) == 1) {
				time_yellow_ver++;
				time_yellow_hor++;
				//check
				if (time_yellow_ver + time_green_ver > time_red_ver) {
					time_red_ver++;
					time_red_hor++;
				}
			}
			//update buffer
			led_buffer_ver[0] = time_yellow_ver / 10;
			led_buffer_ver[1] = time_yellow_ver % 10;
			led_buffer_hor[0] = 0;
			led_buffer_hor[1] = 2;
			break;
		case GREEN_MODIFY:
			//tắt đèn đỏ và vàng
			turn_off_red_yellow();
			//nhấp nháy đèn xanh
			toggle_green_led();
			//button2
			if (isButtonPressed(1) == 1) {
				time_green_ver++;
				time_green_hor++;
				//check
				if (time_yellow_ver + time_green_ver > time_red_ver) {
					time_red_ver++;
					time_red_hor++;
				}
			}
			//update buffer
			led_buffer_ver[0] = time_green_ver / 10;
			led_buffer_ver[1] = time_green_ver % 10;
			led_buffer_hor[0] = 0;
			led_buffer_hor[1] = 3;
			break;
	}
}
