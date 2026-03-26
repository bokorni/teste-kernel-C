#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

    FILE *arquivo = fopen("relatorio.txt", "w");
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo \n");
        return 1;

    }

    fprintf(arquivo, "Aluno: Lucas Bokorni Amaya\n");
    fprintf(arquivo, "PID do processo: %d\n", getpid());
    fprintf(arquivo, "Data: 25/03/2026\n");
    fprintf(arquivo, "Teste prático de interação com Kernel\n");

    fclose(arquivo);

    pid_t pid = fork();

    if(pid == 0){
        printf("Processo filho em execução. PID = %d\n", getpid());
    }

    else if(pid > 0){
        printf("Processo pai em execução. PID = %d\n", getpid());
        wait(NULL);
    }

    else{
        printf("Erro.\n");
    }

    int vetor[10];

    for(int i = 0; i < 10; i++){

        vetor[i] = i;

    }

    printf("Conteudo do Vetor\n");
    for(int i = 0; i < 10; i++){
        printf("%d ", vetor[i]);
    }

    printf("\n");

    FILE *leitura = fopen("relatorio.txt", "r");
    char linha[256];

    printf("Conteudo do arquivo: \n");
    while(fgets(linha, sizeof(linha),leitura) != NULL){
        printf("%s", linha);
        }

    fclose(leitura);
    
    
    
    
    return 0;
}
