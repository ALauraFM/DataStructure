#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tipoStringTAD.h"

struct stringTAD { //completando o tipo
    char *str;
    int comprimento;
    };    

tStringTAD CriaString(const char *str){
    tStringTAD novaString = malloc(sizeof(struct stringTAD));
    if (!novaString)
        return NULL;

    novaString->str = NULL;
    novaString->comprimento = -1;

    novaString->str = malloc(strlen(str) * sizeof(char));
    if (!novaString->str){
        free(novaString);
        return NULL;
    }
    novaString->comprimento = strlen(str);
    for(int i = 0; i < ComprimentoString(novaString); i++){
        novaString->str[i] = str[i];
    }

    return novaString;
}

void DestroiString(tStringTAD *c){
    //vazamento de memória?
    free(*c);
    *c = NULL;
}

tStringTAD AlteraString(tStringTAD str, const char *novaStr){
    char *novoEspaco = realloc(str->str, strlen(novaStr));
    if (novoEspaco){
        str->str = novoEspaco;
        novoEspaco = NULL;
    }else{
        return NULL; //string nao foi alterada
    }

    str->comprimento = strlen(novaStr);
    for(int i = 0; i < ComprimentoString(str); i++){
        str->str[i] = novaStr[i];
    }

    return str;
}

tStringTAD ConcatenaString(tStringTAD str, const char *novaParte) {
    int novaParteLen = strlen(novaParte);
    int novaStrLen = str->comprimento + novaParteLen;

    char *novaString = realloc(str->str, novaStrLen + 1);
    if (novaString) {
        str->str = novaString;
        for (int i = 0; i < novaParteLen; i++) {
            str->str[str->comprimento + i] = novaParte[i];
        }
        str->str[novaStrLen] = '\0'; // Adiciona o terminador '\0'
        str->comprimento = novaStrLen;
    } else {
        // Se a realocação falhar, retornamos NULL para indicar o erro
        return NULL;
    }

    return str;
}


tStringTAD RemoveCaractere(tStringTAD str, char c) {
    int writeIndex = 0;
    for (int readIndex = 0; readIndex < str->comprimento; readIndex++) {
        if (str->str[readIndex] != c) {
            str->str[writeIndex++] = str->str[readIndex];
        }
    }
    str->comprimento = writeIndex;

    // Reduzimos o tamanho do bloco de memória da string
    char *novaString = realloc(str->str, str->comprimento + 1);
    if (novaString) {
        str->str = novaString;
        str->str[str->comprimento] = '\0'; // Adiciona o terminador '\0'
    } else {
        // Se a realocação falhar, retornamos NULL para indicar o erro
        return NULL;
    }

    return str;
}


void ExibeString(tStringTAD str, int pulaLinha){
    for (int i = 0; i < str->comprimento; i++){
        printf("%c", str->str[i]);
    }
    if (pulaLinha)
        puts("");
}

int ComprimentoString(tStringTAD str){
    return str->comprimento;
}

char *RecuperaStringC(tStringTAD str) {
    char *novaStringC = malloc((str->comprimento + 1) * sizeof(char));
    if (novaStringC) {
        for (int i = 0; i < str->comprimento; i++) {
            novaStringC[i] = str->str[i];
        }
        novaStringC[str->comprimento] = '\0'; // Adiciona o terminador '\0'
    }
    return novaStringC;

    //essa função deve retornar uma string padrão do C, ou seja, uma sequencia de caracteres com o \0 no final

    //Responda: Quais são os possíveis problemas com a implementação dessa função?
    //não consegui pensar ou analisar os possíveis problemas
}
