#ifndef _PID_H_
#define _PID_H_
typedef struct PIDValue
{
  unsigned   long int    Ek[3];               //��ֵ���棬�����ͷ����Ĳ�ֵ
  unsigned   char        EkF[3];              //���ţ�1���Ӧ��Ϊ������0Ϊ��Ӧ��Ϊ����     
  float         KP;
  float         KI;
  float         KD;
  unsigned   int    Uk;              //��һʱ�̵Ŀ��Ƶ�ѹ
  unsigned   int    RK;              //�趨ֵ
  long               CK; }            //ʵ��ֵ 
PIDValueStr;

//extern PIDValueStr  PID;

unsigned int PIDOperation(unsigned int rk,long ck);


#endif