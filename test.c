
#include "types.h"
#include "user.h"
#include "stat.h"


#define NUMBER_OF_PROCESS 10
#define ARRAY_MAX_SIZE 2000

int size = ARRAY_MAX_SIZE;
int arr[ARRAY_MAX_SIZE];
int num = ARRAY_MAX_SIZE;

void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}



void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr+j, arr+j+1);
            }
        }
    }
}
void wasteTime(){
    for(int i=0; i<10;i++){

    for (int j = 0; j < size; j++) {
        arr[j] = num;
        num--;
    }
    bubble_sort(arr, size);

    }

}

int main() {
    int pid;

    
    
    for (int i = 0; i < NUMBER_OF_PROCESS; i++) {
        pid = fork((i+1)*100);
        if (pid < 0) {
            printf(1,"Failed to fork process.\n");
            exit();
        } else if (pid == 0) { 
            wasteTime();            
            printf(1,"Processo com tickets %d.\n", (i+1) *100); sleep(100);
            exit();
        }
    }
    
    // Wait for all child processes to finish
     while (wait() != -1);
   
    
    // printf(1,"Todos os processos filhos finalizaram.\n");
    exit();
    return 0;
}
/*
	Passar como parâmetro um número suficientemente grande para verificar a corretude do escalonador.
	Redirecionar a saída para um arquivo para melhor visualização do escalonamento.
	Exemplo de execução:
		./teste 10000 > arquivo_teste
*/

// #include "types.h"
// #include "stat.h"
// #include "user.h"
// #include "fcntl.h"
// #include "param.h"

// int stoi(char * str_num)
// {
//         int k = 0;
//         char * ptr = str_num;
//         while(*ptr)	{
//                 k *= 10;
// 				k += *ptr-'0';
//                 ptr++;
//         }
//         return k;
// }

// void test(int T, int i, char * name){
// 		int j, k;
// 		for(j = 0; j < 100; j++){
// 				for(k = 0; k < T; k++);
// 				printf(1, "%s - %d tickets\n", name, i); 
// 		}
// 		exit();
// }   

// int main(int argc, char **argv)
// {
//   int PID, T;
//        T = stoi(argv[1]);

//        PID = fork(1000);
//         if(PID == 0) {
// 				test(T, 1000, "filho");   
// 		}else if(PID > 0)        {
// 				PID = fork(500);
// 				if(PID == 0)	{
// 						test(T, 500, "filho");
// 				}else if(PID > 0)	{
// 						PID = fork(100);
// 						if(PID == 0){
// 									test(T, 100, "filho");
// 						}        
// 				}
// 		}
		
//         return 0;
// }
