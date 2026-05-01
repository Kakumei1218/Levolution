#include <stdio.h>

int main(int argc,char** argv){
    int a = 100;		//	int型の変数
    double b = 123.4;	//	double型の変数
    float c = 123.4f;	//	float型の変数(数値の後ろにfつける)
    char d = 'a';		//	char型の変数
    printf("aの値は%d、大きさは%zubyte、アドレスは0x%p\n",a,sizeof(int),&a);
    printf("bの値は%f、大きさは%zubyte、アドレスは0x%p\n",b,sizeof(double),&b);
    printf("cの値は%f、大きさは%zubyte、アドレスは0x%p\n",c,sizeof(float),&c);
    printf("dの値は%c、大きさは%zubyte、アドレスは0x%p\n",d,sizeof(char),&d);
    return 0;
}