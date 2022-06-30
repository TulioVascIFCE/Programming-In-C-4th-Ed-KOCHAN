//Bibliotecas
#include <stdio.h>

//Estrutura para data
typedef struct {
	int year, month, day;
} date;

//Potótipo da Funções 
int indexDate(date);
int functionF(int, int);
int functionG(int);

int main(){
	//Def. Variáveis de trabalho
	date pastDate, futureDate;
	int n1, n2;
	int totalDias;

	//Entradas
	puts("Entre com a data que ocorre primeiro");
	puts("Obs.: Formato DD/MM/YYYY");
	scanf("%d/%d/%d", &pastDate.day, &pastDate.month, &pastDate.year);

	puts("Entre com a data que ocorre por último");
	puts("Obs.: Formato DD/MM/YYYY");
	scanf("%d/%d/%d", &futureDate.day, &futureDate.month, &futureDate.year);

	//Processamento
	n1 = indexDate(pastDate);
	n2 = indexDate(futureDate);

	totalDias = n2 - n1;

	//Saídas
	printf("O valor de N1 é: %d\n", n1);
	printf("O valor de N2 é: %d\n", n2);
	printf("O número de dias entre N2 e N1 é: %d\n", totalDias);
	return 0;	
}

//Função para calcualr um índice numérico para a data
int indexDate(date normalDate){
	int N;
	printf("%d/4 + %d/5 + %d\n", (1461 * functionF(normalDate.year, normalDate.month)), (153 * functionG(normalDate.month)), normalDate.day);
	return N = 1461 * functionF(normalDate.year, normalDate.month) / 4  + 153 * functionG(normalDate.month) / 5 + normalDate.day;
}

//Função F
int functionF(int year, int month){
	if ( month <= 2 ) return year - 1;
	else return year;
}

int functionG(int month){
	if ( month <= 2 ) return month + 13;
	else return month + 1;
}