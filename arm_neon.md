## Arm_neon

- C代码

	```C/C++
    #include <iostream> 
    using namespace std; 
    float sum_array(float *arr, int len) 
    { 
        if(NULL == arr || len < 1) 
        { 
            cout<<"input error\n"; 
            return 0; 
        } 
        float sum(0.0); 
        for(int i=0; i<len; ++i) {
            sum += *arr++; 
        } 
        return sum; 
    }   
    ```
    
- ARM_NEON 代码
    
    ```C/C++
    #include <iostream> 
    #include <arm_neon.h> //需包含的头文件 
    using namespace std; 
    float sum_array(float *arr, int len) 
    { 
        if(NULL == arr || len < 1) { 
            cout<<"input error\n"; 
            return 0; 
        } 
        int dim4 = len >> 2; // 数组长度除4整数 
        int left4 = len & 3; // 数组长度除4余数 
        float32x4_t sum_vec = vdupq_n_f32(0.0);//定义用于暂存累加结果的寄存器且初始化为0 
        for (; dim4>0; dim4--, arr+=4) //每次同时访问4个数组元素 
        { 
            float32x4_t data_vec = vld1q_f32(arr); //依次取4个元素存入寄存器
            vec sum_vec = vaddq_f32(sum_vec, data_vec);//ri = ai + bi 计算两组寄存器对应元素之和并存放到相应结果 
        } 
        float sum = vgetq_lane_f32(sum_vec, 0)+vgetq_lane_f32(sum_vec, 1)+vgetq_lane_f32(sum_vec, 2)+vgetq_lane_f32(sum_vec, 3);//将累加结果寄存器中的所有元素相加得到最终累加值 
        for (; left4>0; left4--, arr++) 
            sum += (*arr) ; //对于剩下的少于4的数字，依次计算累加即可 
        return sum; 
    }
    ```
    
 - NEON编码流程

	1. 将数据划分为块，按neon单次load的比特位来决定（本例分为4块），不能整分的单独处理
	2. 遍历每个块，分别进行相同的计算
	3. 最后处理所有块的计算
	4. 单独处理不能整分的计算

- 常用函数：
 
   - float32x4_t vdupq_n_f32 (float32_t value)

	将value复制4分存到返回的寄存器中

   - float32x4_t vld1q_f32 (float32_t const * ptr)

	从数组中依次Load4个元素存到寄存器中

   - void vst1q_f32 (float32_t * ptr, float32x4_t val)
   
   	将寄存器中的值写入数组中

   - float32x4_t vaddq_f32 (float32x4_t a, float32x4_t b)

	返回两个寄存器对应元素之和 r = a+b

   - float32x4_t vsubq_f32 (float32x4_t a, float32x4_t b)

	返回两个寄存器对应元素之差 r = a-b

   - float32_t vgetq_lane_f32 (float32x4_t v, const int lane)

	返回寄存器某一lane的值

   - float32x4_t vmulq_f32 (float32x4_t a, float32x4_t b)

 	返回两个寄存器对应元素之积 r = a\*b

   - float32x4_t vmlaq_f32 (float32x4_t a, float32x4_t b, float32x4_t c)
	
    r = a +b*c

   - float32x4_t vextq_f32 (float32x4_t a, float32x4_t b, const int n)

	拼接两个寄存器并返回从第n位开始的大小为4的寄存器 0<=n<=3

	- 例如

		a: 1 2 3 4
		
        b: 5 6 7 8

		vextq_f32(a,b,1) -> r: 2 3 4 5

		vextq_f32(a,b,2) -> r: 3 4 5 6

		vextq_f32(a,b,3) -> r: 4 5 6 7