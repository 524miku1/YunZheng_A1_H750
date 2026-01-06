程序讲解：
  MX_TIM6_Init();//MX配置定时器，频率10K，计数0~9999，默认计时500ms

  HAL_TIM_Base_Start(&htim6);//启动定时器

__HAL_TIM_GET_COUNTER(&htim6);//读取定时器的计数值

其他：
注意定时器挂在240M的总线上，计算时不要弄错。
本程序未使用中断