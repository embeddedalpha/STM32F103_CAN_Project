/**
  ******************************************************************************
  * @file           : main.c
  * @author			: Kunal Salvi
  * @brief          : Main program body
  * 				  CAN Bus Project Template
  * 				  Kindly go through the CAN folder to understand how the
  * 				  driver is constructed.
  * 				  For any queries, please raise a issue on github.
  ******************************************************************************
  */

#include "main.h"

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void CAN1_RX0_IRQHandler(void);


CAN_TX_Typedef TX;
CAN_RX_Typedef RX;
CAN_Filter_TypeDef filter;
CAN_Init_Typedef CAN;

int32_t Identifier = 0x00;


int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  Console_Init(115600);

  CAN.CAN_INSTANCE = CAN1;
  CAN.baudrate = CAN_BAUDRATE_1000_KBPS;
  CAN.interrupt = Fifo0_Message_Pending;
  CAN_Init(&CAN);
  //Change Filter
  filter.ID = 0x00;
  filter.filter_id = 0;
  filter.id_type = CAN_ID_Standard;
  filter.frame_type = CAN_Frame_Remote;
  CAN_Filter_Init(&CAN, &filter);
  CAN_Start(&CAN);
	__disable_irq();
HAL_NVIC_SetPriority(USB_LP_CAN1_RX0_IRQn, 0, 0);
HAL_NVIC_EnableIRQ(USB_LP_CAN1_RX0_IRQn);
	__enable_irq();


  while (1)
  {
	  //To send Data
		TX.ID = Identifier;
		TX.id_type = CAN_ID_Standard;
		TX.frame_type = CAN_Frame_Remote;
		TX.data_length = 1;
		CAN_Send_Packet(&CAN, &TX);

  }

}



void CAN1_RX0_IRQHandler(void)
{
	//Get Data via RX interrupt
	CAN_Get_Packet(&CAN, &RX);
}





void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
