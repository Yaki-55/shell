#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
int main(){
  int pid;
  char com[100];
  char parametros[100];
  pid=fork();
  if(pid==0){
    printf("yakiShell> ");
        // Leer el comando y sus parámetros
        scanf("%[^\n]", parametros);
        // Separar el comando y sus parámetros
        sscanf(parametros, "%s %[^\n]", com, parametros);
        if(strcmp(com,parametros) == 0){ //Si no tenia parametros entonces parametros y comando seran iguales
          execlp(com,com,NULL);
          printf("Comando no encontrado\n");
        }else{
          execlp(com, com, parametros, NULL);
          printf("Comando no encontrado\n");
        }
  }else{
    wait(NULL);
    execlp("./shell", "./shell", NULL);
  }
  return 0;
}