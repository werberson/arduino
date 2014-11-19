#include <stdio.h>

typedef struct{
    char* nome;
    char* telefone;
}contato;

contato quebra(char* str) {
  contato agenda; 
  agenda.nome = strtok(str,"-");
  agenda.telefone = strtok(NULL,"-");
  return agenda;
}
int line_count(FILE *n) {
    int c;
    int lines = 0;
    
    while ((c = fgetc(n)) != EOF) {
          if (c == '\n') ++lines;
    }
    rewind(n);
    return lines;
}

int main(void)
{
	char url[]="telefone.txt", info[50];
	FILE *arq;
	arq = fopen(url, "r");
	int qtd_linhas = 2;
	contato contatos[qtd_linhas];
	
	if(arq == NULL) {
			printf("Erro, nao foi possivel abrir o arquivo\n");
	} else {
        int count = 0;
		while( (fgets(info, sizeof(info), arq))!=NULL ) {
               if(info[0] != '#') {
             			contatos[count++] = quebra(info);
             			printf("N: %s", contatos[count].nome);
	                    printf("T: %s", contatos[count].telefone);
             			//count++;
                }
                                        
         }
    }
	printf("\n\n########## FOR ##########\n\n\n");
	int i;
	for(i = 0; i < qtd_linhas; i++) {
          printf("N: %s", contatos[i].nome);
	      printf("T: %s", contatos[i].telefone);
    }
	
	fclose(arq);
	system("pause");
	return 0;
}
