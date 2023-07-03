#ifndef EXERCICIOS_H
#define EXERCICIOS_H

#include "MyUtil.h"
#include "BTree.h"
#include "TLSEplayer.h"
#include "TLSE.h"
/*
(a)
1.quantos jogadores aposentados possuem títulos?
2.E quantos ativos?
Informe-os separadamente em ordem decrescente do número de títulos (e os respectivos títulos por grand
slam).
*/

/*
(b) se existem jogadores que nasceram no mesmo ano que seu compatriota (que possui um
ranking) ganhou o primeiro grand slam?
*/
void nascmentoPremi(BT *a);
/*
(c) se ninguém tivesse se aposentado ainda, qual seria a pontuação acumulada de cada um dos
aposentados, levando-se em consideração que se o jogador ganha o torneio, ele tem 2000
pontos, e o vice 1200. E a ordenação em ordem decrescente?
*/
void makeSlanHank(BT* a, int isAtivo);
/*
(d) qual é a ordenação acumulada em ordem decrescente dos jogadores que possuem um
ranking, levando-se em consideração somente os grand slams?
*/

/*
(e) se existe algum jogador aposentado que ganhou todos os grand slams no mesmo ano? Se
sim, retornar o(s) nome(s) do(s) jogador(es) e o(s) ano(s).
*/
TLSEp* Qe (BT * a, TLSEp* l, int av);
/*
(f) se existe algum jogador em atividade que ganhou todos os grand slams no mesmo ano? Se
sim, retornar o(s) nome(s) do(s) jogador(es) e o(s) ano(s).
*/
TLSEp* Qf (BT * a, TLSEp* l, int av);
/*
(g) retirar todos os jogadores em atividade de um determinado país.
*/
BT* retiraPais(BT *a,char *c,int t);
BT* mostraPais(BT *a,char *c,int t);




#endif // EXERCICIOS_H
