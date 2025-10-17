
/****************************************************************************************************
* Copyright(c) 2025 Shenzhen AnniuSmart Innovation CO., LTD. All right reserved. * History Information
| Author		| 	 Date	   	 |   Version	|				Description															|
|-----------|--------------|------------|-----------------------------------------------|
| bin.chen  | 2025/10/17   |	V1.0			|				CommonDefine														|
|-----------|--------------|------------|-----------------------------------------------|
****************************************************************************************************/
#ifndef __COMMON_H	
#define __COMMON_H

#define     BIT(n)							    (1UL << (n))																									//1��λ  //����ֵ��()Ϊ�˷�ֹ��չ��ʱ����������ȼ������߼�����
#define 	GET_BIT(Val, n) 				  (((Val) >> (n)) & 1)																					//��ȡ����ĳ��λ
#define     BITS_X2Y(x, y)					(((BIT(y)|(BIT(y)-1))) & (~(BIT(x)-1)))												//�� x(��)���� y(��)λΪ 1������λΪ 0
#define		CLR_BITS(Val, Bits)				((Val) & (~(Bits)))																						//���ĳ��λ
#define     ARRAY_SIZE(Array)  			(sizeof(Array)/sizeof(Array[0]))														  //�����С
#define		SET_BITS(Val, Bits)				((Val) | (Bits))																							//���� Bits ָ����λ����Ϊ 1
#define		FLIP_BIT(Val, Bits)				((Val) ^= (1UL << (Bits)))																		//��תĳһλ
#define		OFFSET(Type, Member)			(size_t)&(((Type*)NULL)->Member)															//��ȡƫ����
#define		DEFINE_CMP_FUNC(TypeName, Type)																			\
											int Compave_##TypeName(const void* A, const void* B)    \
											{																												\
	    									Type ValueA = *(const Type*)A;												\
												Type ValueB = *(const Type*)B;												\
												if(ValueA < ValueB) return 0;													\
												if(ValueA > ValueB) return 1;													\
											}																																								//���㶨������������ֵ�Ĵ�С

#define		ALIGN_UP(Adr,Byte)						(((Adr) + (Byte) - 1) & ~((Byte) - 1))												//��ַ���϶�����ٸ��ֽڣ�����DMA��
#define		ALIGN_DOWN(Adr,Byte)					((Adr) & ~((Byte) - 1))																				//��ַ���¶�����ٸ��ֽڣ�����DMA��
#define		OFFSET_STRUCT(Type, Member)  	((Adr) & ~((Byte) - 1))																				//��ȡ�ṹ���Աƫ����
#define		DYNAMIC_FREE(Temp)						do{if((Temp)) {free(Temp); Temp = NULL;}}while(1);						//��̬�ڴ�����ͷţ�
#define		DYNAMIC_CREATE(Size)					((Size)? malloc(Size):NULL)																		//��̬�ڴ����������

	
enum BOOL
{
	FALSE,
	TRUE
}

#endif