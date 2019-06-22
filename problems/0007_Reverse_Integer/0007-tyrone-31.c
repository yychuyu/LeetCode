int reverse(int x)
{    
	long new_x = (long)x;    
	int i = 0, sign = 0, bit_number = 0;    
	char original_number[31] = {0}, new_number[31] = {0};        
	
	/* 获取原数字的符号，sign为0表示整数，为-1表示负数 */    
	if (x < 0) {        
		sign = -1;        
		new_x = new_x * (-1);    
	} else        
		sign = 0;        
		
	/* 获取原数字的字符串数组 */    
	for (i = 30; i >= 0; i --) {        
		original_number[i] = new_x / (pow(10, i));        
		if (original_number[i])            
		new_x -= original_number[i] *(pow(10, i));        
		if (original_number[i] && !bit_number) {            
			bit_number = i;        
		}    
	}        
		
	/* 将字符串数组做翻转 */    
	for (i = 0; i <= bit_number; i ++) {        
		new_number[i] = original_number[bit_number - i];    
	}        
	
	/* 将新字符数组转换成数字 */    
	new_x = 0;    
	for (i = 0; i <= bit_number; i ++) {        
		new_x += new_number[i] * (pow(10, i));    
	}        
		
	if (!sign && new_x > (pow(2, 31) - 1))        
		return 0;        
		
	if (sign && new_x > pow(2, 31))        
		return 0;        

	/* 把符号加上 */    
	if (sign) {        
		new_x *= -1;    
	}        

	return (int)new_x;
}
