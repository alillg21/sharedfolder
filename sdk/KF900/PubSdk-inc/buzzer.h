#ifndef DEVICE_BUZZER_H
#define DEVICE_BUZZER_H

extern int buzzer_open	(void);
extern int buzzer_close	(void);
extern int buzzer_play	(int occupancy, int frequency, int delay);

#endif
