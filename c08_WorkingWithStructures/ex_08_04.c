//Bibliotecas
#include <stdio.h>

//Estrutura para data
typedef struct {
	int year, month, day;
} date;

typedef struct{
	char dayName[9];
} weekDaysNames;

//Potótipo da Funções 
int indexDate(date);
int functionF(int, int);
int functionG(int);

int main(){
	//Def. Variáveis de trabalho
	date oneDate;
	int weekDaysNumber, aux = 0;
	weekDaysNames weekName[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

	//Entradas
	puts("Entre com uma data");
	puts("Obs.: Formato DD/MM/YYYY");
	scanf("%d/%d/%d", &oneDate.day, &oneDate.month, &oneDate.year);

	//Processamento
	weekDaysNumber = (indexDate(oneDate) - 621049) % 7;
	printf("%d, %d\n", (indexDate(oneDate) - 621049), weekDaysNumber);

	//Saídas
	printf("O dia %d/%.2d/%d caiu numa: ", oneDate.day, oneDate.month, oneDate.year);
	while (weekName[weekDaysNumber].dayName[aux] != '\0'){
		printf("%c", weekName[weekDaysNumber].dayName[aux]);
		aux++;
	}
	puts("");
	
	return 0;	
}

//Função para calcualr um índice numérico para a data
int indexDate(date normalDate){
	return 1461 * functionF(normalDate.year, normalDate.month) / 4  + 153 * functionG(normalDate.month) / 5 + normalDate.day;
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