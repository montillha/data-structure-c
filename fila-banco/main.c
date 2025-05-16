#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fila.h"
int main(int argc, char const *argv[]){
    t_queue* preferencial=create();
    t_queue* normal=create();
    char atendimento[MAX_FILA*2][25];
    int size_atendimento=0;
    char cliente[25];
    char identificador;
    int preferenciais_atendidos=0;
    char cliente_atendido[25];

    scanf(" %c",&identificador);
    while(identificador!='f'){
        if(identificador=='s'){
            if(preferenciais_atendidos>= 3){

                if(!is_empty(normal)){
                    if(out(normal,cliente_atendido)){
                        strcpy(atendimento[size_atendimento++],cliente_atendido);
                    }
                    preferenciais_atendidos = 0;
                } else{
                    if(out(preferencial,cliente_atendido)){
                        strcpy(atendimento[size_atendimento++],cliente_atendido);
                    }
                    preferenciais_atendidos = 3;
                }

            }else{
                if(is_empty(preferencial)) {
                    if(out(normal, cliente_atendido)){
                        strcpy(atendimento[size_atendimento++],cliente_atendido);
                    }
                } else{
                    if(out(preferencial, cliente_atendido)){
                        strcpy(atendimento[size_atendimento++],cliente_atendido);
                    }
                    preferenciais_atendidos++;
                }
            }
        }else{
            scanf("%s",cliente);
            if(is_full(normal) && is_full(preferencial)) {
                return 0;
            }else{
                if(identificador=='g') {
                    in(normal,cliente);
                }else{
                    in(preferencial,cliente);
                }
            }
        }
        scanf(" %c", &identificador);
    }

    printf("Ordem de atendimento:\n");
    for (int i = 0; i < size_atendimento; i++) {
        printf("%s\n", atendimento[i]);
    }
    return 0;
}
