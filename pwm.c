#include<msp430x14x.h>

//pwm��ʼ��
void int_pwm()
{
  P1SEL|=BIT2+BIT3;                     //P1.2  P1.3��ΪPWM�������
  P1DIR|=BIT2+BIT3;                     //���÷���Ϊ���
  TACTL|=TASSEL1+MC0+TACLR;
  TACCR0=50000;  //50000                         //PWM����ֵ=100us
  TACCR1=25000;  //25000                         //�ȽϼĴ���1ռ�ձ�50%��ˮ����裩
  TACCR2=10000; //12500                    //�ȽϼĴ���2ռ�ձ�20%(����)
  TACCTL1=OUTMOD0+OUTMOD1+OUTMOD2;      //TA1���ģʽΪ��λ/��λ
  TACCTL2=OUTMOD0+OUTMOD1+OUTMOD2;       //TA2���ģʽΪ��λ/��λ
  TACTL|=MC0;                   //ʱ��ԴSMCLK��������ģʽ
}

//��ʱ����ʼ��
void init_tb()                          //TB��ʼ��
{
  TBCTL|=TBSSEL1+TBCLR+ID0+ID1;         //TBʱ��ԴΪSMCLK������TB������8��Ƶ
  TBCTL|=MC0+TBIE;                      //TB����ģʽ���ж�ʹ��
  TBCCR0=49999;                         //�ж�����Ϊ50ms
}

//����ռ�ձ�
void adjust(unsigned int uk)
{   unsigned int z=0;
    
    z=uk*500;
    TACCR1=z; 
   
}   