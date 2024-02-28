#include <stdio.h>
#include <stdlib.h>

#define oi printf("oi\n");

void intercala(int* vet, int pri, int meio, int ult){
	int* resp = malloc(sizeof(int)*(ult-pri));
	
	int a=pri, b=meio;
	for(int i=pri; i<=ult; i++)
		if((vet[a] < vet[b] || b>ult) && a<meio){
			resp[i] = vet[a];
			a++;
		}
		else if(b<=ult){
			resp[i] = vet[b];
			b++;
		}
			
	for(int i=pri; i<=ult; i++)
		vet[i] = resp[i];
	
	free(resp);
}

void mergeSort(int* vet, int pri, int ult){
	if(ult > pri){
		int meio = pri+(ult-pri+1)/2;
		if(meio-pri>1)
			mergeSort(vet,pri,meio-1);
		if(ult-meio+1>1)
			mergeSort(vet,meio,ult);
		intercala(vet,pri,meio,ult);
	}
}

int main(void){
	int vet[] = {8, 6, 10, 90, 50, 4, 18};
	for(int i=0; i<sizeof(vet)/sizeof(int); i++)
		printf("vet[%d]=%d\n", i, vet[i]);
		
	mergeSort(vet,0,sizeof(vet)/sizeof(int)-1);
	for(int i=0; i<sizeof(vet)/sizeof(int); i++)
		printf("%dº posição do vetor: %d\n", i, vet[i]);
}
