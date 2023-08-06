#ifndef _TipoString3_H_
#define _TipoString3_H_

typedef struct stringTAD *tStringTAD; //tipo incompleto

extern tStringTAD CriaString(const char *str);
extern void DestroiString(tStringTAD *str);

extern tStringTAD AlteraString(tStringTAD str, const char *novaStr); //retorna a mesma recebida ou NULL se nao conseguir
extern tStringTAD ConcatenaString(tStringTAD str, const char *novaParte); //idem
extern tStringTAD RemoveCaractere(tStringTAD str, char c); //remove todas as ocorrencias do caractere da string, diminuindo seu tamanho e seu bloco de memória. 

extern void ExibeString(tStringTAD str, int pulaLinha);
extern int ComprimentoString(tStringTAD str);

extern char *RecuperaStringC(tStringTAD str); //retornar uma string do C, array de caracteres

#endif