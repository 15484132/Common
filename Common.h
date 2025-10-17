
/****************************************************************************************************
* Copyright(c) 2025 Shenzhen AnniuSmart Innovation CO., LTD. All right reserved. * History Information
| Author		| 	 Date	   	 |   Version	|				Description															|
|-----------|--------------|------------|-----------------------------------------------|
| bin.chen  | 2025/10/17   |	V1.0			|				CommonDefine														|
|-----------|--------------|------------|-----------------------------------------------|
****************************************************************************************************/
#ifndef __COMMON_H	
#define __COMMON_H

#define     BIT(n)							    (1UL << (n))																									//1移位  //传入值加()为了防止宏展开时因运算符优先级导致逻辑错误
#define 	GET_BIT(Val, n) 				  (((Val) >> (n)) & 1)																					//获取变量某个位
#define     BITS_X2Y(x, y)					(((BIT(y)|(BIT(y)-1))) & (~(BIT(x)-1)))												//第 x(含)至第 y(含)位为 1，其它位为 0
#define		CLR_BITS(Val, Bits)				((Val) & (~(Bits)))																						//清除某个位
#define     ARRAY_SIZE(Array)  			(sizeof(Array)/sizeof(Array[0]))														  //数组大小
#define		SET_BITS(Val, Bits)				((Val) | (Bits))																							//把由 Bits 指定的位设置为 1
#define		FLIP_BIT(Val, Bits)				((Val) ^= (1UL << (Bits)))																		//翻转某一位
#define		OFFSET(Type, Member)			(size_t)&(((Type*)NULL)->Member)															//获取偏移量
#define		DEFINE_CMP_FUNC(TypeName, Type)																			\
											int Compave_##TypeName(const void* A, const void* B)    \
											{																												\
	    									Type ValueA = *(const Type*)A;												\
												Type ValueB = *(const Type*)B;												\
												if(ValueA < ValueB) return 0;													\
												if(ValueA > ValueB) return 1;													\
											}																																								//计算定义类型中两个值的大小

#define		ALIGN_UP(Adr,Byte)						(((Adr) + (Byte) - 1) & ~((Byte) - 1))												//地址向上对齐多少个字节（用于DMA）
#define		ALIGN_DOWN(Adr,Byte)					((Adr) & ~((Byte) - 1))																				//地址向下对齐多少个字节（用于DMA）
#define		OFFSET_STRUCT(Type, Member)  	((Adr) & ~((Byte) - 1))																				//获取结构体成员偏移量
#define		DYNAMIC_FREE(Temp)						do{if((Temp)) {free(Temp); Temp = NULL;}}while(1);						//动态内存管理（释放）
#define		DYNAMIC_CREATE(Size)					((Size)? malloc(Size):NULL)																		//动态内存管理（创建）

	
enum BOOL
{
	FALSE,
	TRUE
}

#endif