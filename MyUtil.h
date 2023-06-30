#ifndef MYUTIL_H
#define MYUTIL_H
/*
Biblioteca para funçoes aleatorias e uteis
que certamente existem em alguma outra biblioteca
mas é mais facil fazer a propria
*/

/**@brief Espera o usuario apertar uma tecla*/
void waitKey();

/*ToDo:*/
/**(Nao Implementada)Transforma um numero representado em string em um interio*/
int strToInt(char* num);
/**(Nao Implementada)Divide line em toda ocorrencia de uma key esoecifica e retorna um vetor de strings*/
char** splitStr(char* line, char* key, int numCol);
/**Quebra uma linha no terminal*/
void ln();
/**Limpa a tela do terminal*/
void cls();

char* country(char *a);//Retorna o pais entre colchetes RUSSIA -> [RUSSIA];
#endif  // MYUTIL_H
