/**
  ******************************************************************************
  * @file    main.c
  * @author  ����
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   emWin��������������
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:���� iSO STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
	
#include "stm32f10x.h"

#include "GUI.h"

#include "..\User\usart\bsp_usart1.h"
#include "..\User\SysTick\bsp_SysTick.h"
#include "..\User\led\bsp_led.h"
#include "..\User\lcd\bsp_xpt2046_lcd.h"
#include "..\User\ExSRAM\bsp_fsmc_sram.h"
#include "..\User\lcd\bsp_ili9341_lcd.h"
#include "GUIDEMO.h"

/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{	
	FSMC_SRAM_Init();
	
	/* LED �˿ڳ�ʼ�� */
	LED_GPIO_Config();	
  
  USART1_Config();
	
	XPT2046_Init();
	
	/* ��ʼ����ʱ�� */
	SysTick_Init();
	
	/*CRC��emWinû�й�ϵ��ֻ������Ϊ�˿�ı��������ģ�����STemWin�Ŀ�ֻ������ST��оƬ���棬���оƬ���޷�ʹ�õġ� */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_CRC, ENABLE);
	
	/* ��ʼ��GUI */
	GUI_Init(); 
	
	GUI_Delay(100);
	LCD_BK_EN;//��Һ��������
	
	while(1)
	{
		GUIDEMO_Main();
	}

}


/*********************************************END OF FILE**********************/
