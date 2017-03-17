#include<msp430x14x.h>

//pwm初始化
void int_pwm()
{
  P1SEL|=BIT2+BIT3;                     //P1.2  P1.3设为PWM输出功能
  P1DIR|=BIT2+BIT3;                     //设置方向为输出
  TACTL|=TASSEL1+MC0+TACLR;
  TACCR0=50000;  //50000                         //PWM周期值=100us
  TACCR1=25000;  //25000                         //比较寄存器1占空比50%（水泥电阻）
  TACCR2=10000; //12500                    //比较寄存器2占空比20%(风扇)
  TACCTL1=OUTMOD0+OUTMOD1+OUTMOD2;      //TA1输出模式为复位/置位
  TACCTL2=OUTMOD0+OUTMOD1+OUTMOD2;       //TA2输出模式为复位/置位
  TACTL|=MC0;                   //时钟源SMCLK，增计数模式
}

//定时器初始化
void init_tb()                          //TB初始化
{
  TBCTL|=TBSSEL1+TBCLR+ID0+ID1;         //TB时钟源为SMCLK，清零TB，输入8分频
  TBCTL|=MC0+TBIE;                      //TB增加模式，中断使能
  TBCCR0=49999;                         //中断周期为50ms
}

//调整占空比
void adjust(unsigned int uk)
{   unsigned int z=0;
    
    z=uk*500;
    TACCR1=z; 
   
}   