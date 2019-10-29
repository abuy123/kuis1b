#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h> 

void input_fork(){
	int pid;

	FILE *file_kata;
	file_kata = fopen("text.txt", "r");


	int i;
	int spasi=0;
	char temp[200];

	do{
		fscanf(file_kata, "%s", temp);
		spasi++;
	}while(strcmp(temp, "###") != 0);

	printf("Ada %d Kata\n", spasi-1);

	fclose(file_kata);

	
	switch(pid = fork()){

	case 0:
	file_kata = fopen("text.txt", "r");


	i=0;
	spasi=0;

	do{
		fscanf(file_kata, "%s", temp);
		spasi++;
	}while(strcmp(temp, "###") != 0);

	printf("Ada %d Kata\n", spasi-1);

	fclose(file_kata);
		break;
	default:
		printf("proses ortu: pid=%d, anak pid = %d\n", getpid(), pid);
		break;
	case -1:
		perror("fork");
		exit(1);
	}
	exit(0);
}
void *myThread(void *vargp) 
{ 
    sleep(1); 
    
	FILE *file_kata;
	file_kata = fopen("text.txt", "r");


	int i;
	int spasi=0;
	char temp[200];

	do{
		fscanf(file_kata, "%s", temp);
		spasi++;
	}while(strcmp(temp, "###") != 0);

	printf("Ada %d Kata\n", spasi-1);

	fclose(file_kata);

    return NULL; 
} 


int main(int argc, char **argv){
	printf("1. Fork\n");
	printf("2. Thread\nSilahkan memilih menu(1/2)\n");

	int n;
	scanf("%d", &n);

	if (n==1){
		input_fork();
	}
	else if (n==2){
		pthread_t thread_id; 
		    
		FILE *file_kata;
		file_kata = fopen("text2.txt", "r");


		int i;
		int spasi=0;
		char temp[200];

		do{
			fscanf(file_kata, "%s", temp);
			spasi++;
		}while(strcmp(temp, "###") != 0);

		printf("Ada %d Kata\n", spasi-1);

		fclose(file_kata); 
	    //buat thread
	    pthread_create(&thread_id, NULL, myThread, NULL); 

	    //tunggu thread selesai, jika tdk ada join, maka akan langsung exit
	    pthread_join(thread_id, NULL); 
	    printf("Thread selesai\n"); 
	    exit(0); 

	}
	else{
		printf("Menu tidak ada\n");
	}


return 0;
}

