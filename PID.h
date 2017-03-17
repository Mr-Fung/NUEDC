#ifndef _PID_H_
#define _PID_H_
typedef struct PIDValue
{
  unsigned   long int    Ek[3];               //差值保存，给定和反馈的差值
  unsigned   char        EkF[3];              //符号，1则对应的为负数，0为对应的为正数     
  float         KP;
  float         KI;
  float         KD;
  unsigned   int    Uk;              //上一时刻的控制电压
  unsigned   int    RK;              //设定值
  long               CK; }            //实际值 
PIDValueStr;

//extern PIDValueStr  PID;

unsigned int PIDOperation(unsigned int rk,long ck);


#endif