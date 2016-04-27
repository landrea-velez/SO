#include <stdio.h>

int main(void){
	int i;
	int vec[3];	
	char a = *vec;  
	
 	for(i=0; i<3; i++){
	    printf("Ingrese # %d: ", i+1);    
	    setbuf(stdin, NULL);    
	    scanf("%d", &vec[i]);
	}    

	for(i=0; i<3; i++){
	    printf("El numero es: %d \n", vec[a]);
	    a=a+1;
	}

return 0;
}
