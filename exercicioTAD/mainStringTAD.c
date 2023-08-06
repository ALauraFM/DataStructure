#include <stdio.h>
#include "tipoStringTAD.h"

int main(void) {
    tStringTAD umaString;

    umaString = CriaString("cafe");
    ExibeString(umaString, 1);
    printf("comprimento: %d\n", ComprimentoString(umaString));

    if (AlteraString(umaString, "cafe com leite") != NULL){
        ExibeString(umaString, 1);
        printf("comprimento: %d\n", ComprimentoString(umaString));
    }else{
        puts("nao foi possivel alterar a string");
    }

    if (ConcatenaString(umaString, " sem acucar") != NULL){
        ExibeString(umaString, 1);
        printf("comprimento: %d\n", ComprimentoString(umaString));
    }else{
        puts("nao foi possivel concatenar a string");
    }

    RemoveCaractere(umaString, 'c');
    ExibeString(umaString, 1);
    printf("comprimento: %d\n", ComprimentoString(umaString));

    DestroiString(&umaString);
    
    return 0;
}