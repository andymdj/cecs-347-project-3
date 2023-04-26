#include "tm4c123gh6pm.h"
#include "SysTick.h"

// Initialize SysTick with busy wait running at bus clock.
void SysTick_Init(void) {
	NVIC_ST_CTRL_R = 0;                   // disable SysTick during setup
	NVIC_ST_RELOAD_R = NVIC_ST_RELOAD_M;  // maximum reload value
	NVIC_ST_CURRENT_R = 0;                // any write to current clears it
                                        // enable SysTick with core clock
	NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE + NVIC_ST_CTRL_CLK_SRC;
}

// Wait a number of clock cycles.
void SysTick_Wait(unsigned long delay) {
	volatile unsigned long elapsedTime;
	unsigned long startTime = NVIC_ST_CURRENT_R;
	do {
		elapsedTime = (startTime - NVIC_ST_CURRENT_R) & NVIC_ST_CURRENT_M;
	}
	while(elapsedTime <= delay);
}

// Wait one millisecond based on the CYCLES_PER_MS constant in Systick.h
void SysTick_WaitMs(unsigned long ms) {
	for(int i = 0; i < ms; i++) {
		SysTick_Wait(CYCLES_PER_MS);
	}
}