#include <stdio.h>

int main(int argc, char** argv) {
	int a[4][4][4];
	int m,n,l;
	for(m=0;m<4; m++){
		for(n=0;n<4; n++){
			for(l=0;l<4; l++){
				a[n][m][l]=m+n+l;
			}
		}
	}
	for(m=0;m<4; m++){
		for(n=0;n<4; n++){
			for(l=0;l<4; l++){
				printf("%d",a[n][m][l]);
			}
			printf("\n");
		}
				printf("\n");}
    return 0;
}