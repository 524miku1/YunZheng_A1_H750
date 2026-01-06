程序讲解：

	HAL_Init();												//初始化HAL库，初始化滴答定时器1ms、配置debug

	SystemClock_Config();										//MX配置时钟，内部时钟源，系统频率480M

	MX_GPIO_Init();											//MX配置GPIO，并初始化

	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);			//反转LED引脚
	HAL_Delay(500);										//阻塞延时500ms

其他：

手动添加flash下载算法，128k，one-chip
默认ram的size为0x0800，太小了，下载算法加载不进去，需手动改为0x1000
