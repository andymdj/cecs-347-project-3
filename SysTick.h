#define CYCLES_PER_MS 80000
#define PERIOD (CYCLES_PER_MS * 100) // 10Hz screen refresh

void SysTick_Init(void);
void SysTick_Wait(unsigned long delay);
void SysTick_WaitMs(unsigned long ms);
