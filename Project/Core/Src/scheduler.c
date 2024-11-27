/*
 * scheduler.c
 *
 *  Created on: Nov 27, 2024
 *      Author: ACER
 */

#include "scheduler.h"

sTasks SCH_tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task = 0;

void SCH_Init(void) {
	current_index_task = 0;
}

void SCH_Add_Task(void(*pFunction)(), uint32_t DELAY, unit32_t PERIOD) {
	if (current_index_task < SCH_MAX_TASKS) {

	}
}

void SCH_Update(void) {

}

void SCH_Dispatch_Tasks(void) {

}
