#define CYCLES_PER_MS 80000

void SysTick_Init(void);
void SysTick_Wait(unsigned long delay);
void SysTick_WaitMs(unsigned long ms);
