#include <common.h>

#define GPJ2CON   (*( volatile unsigned int *)0xE0200280)
#define GPJ2DAT   (*( volatile unsigned int *)0xE0200284)

#define LED_A_ON     (1<<0)
#define LED_A_OFF    ~(0<<0)
#define LED_B_ON     (1<<1)
#define LED_B_OFF    ~(0<<1)
#define LED_C_ON     (1<<2)
#define LED_C_OFF    ~(0<<2)
#define LED_D_ON     (1<<3)
#define LED_D_OFF    ~(0<<3)

/** 设置CSB226板的0、1、2三个指示灯的开关状态
 * csb226_set_led: - switch LEDs on or off
 * @param led:   LED to switch (0,1,2)
 * @param state: switch on (1) or off (0)
 */
 void fnst2440_set_led(int led, int state)
{
      switch(led) {
             case 0:
            	 if (state==1) {
            	    GPJ2DAT |= LED_A_ON ;
                  } else if (state==0) {
                    GPJ2DAT &= LED_A_OFF ;
                  }
                  break;
             case 1:
            	 if (state==1) {
            	   GPJ2DAT |= LED_B_ON ;
                 } else if (state==0) {
                   GPJ2DAT &= LED_B_OFF ;
                 }
                  break;
             case 2:
            	 if (state==1) {
            	    GPJ2DAT |= LED_C_ON ;
                  } else if (state==0) {
                    GPJ2DAT &= LED_C_OFF ;
                  }
                  break;
             case 3:
            	 if (state==1) {
            	    GPJ2DAT |= LED_D_ON ;
                  } else if (state==0) {
                    GPJ2DAT &= LED_D_OFF ;
                  }
                  break;
             default:
            	 break;
      }

      return;
}
/** 显示启动进度函数，在比较重要的阶段，设置三个灯为亮的状态（1, 5, 15）**/
void show_led_progress (int status)
{
   static char state = 0;
   if (state == 0) {
       GPJ2CON |= 0x0000ffff;
       state = 1;
   }

      switch(status) {
            case  1: fnst2440_set_led(0,1); break;
            case  2: fnst2440_set_led(0,0); break;

            case  3: fnst2440_set_led(1,1); break;
            case  4: fnst2440_set_led(1,0); break;

            case  5: fnst2440_set_led(2,1); break;
            case  6: fnst2440_set_led(2,0); break;

            case  7: fnst2440_set_led(3,1); break;
            case  8: fnst2440_set_led(3,0); break;
            default:
            	break;

      }
      return;
}
