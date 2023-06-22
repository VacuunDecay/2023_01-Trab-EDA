# 2023_01-Trab-EDA

## Resumo das bibliotecas

- BTree -> para estrutura principal do programa a arvore b modificada
- Menus -> Onde os menus e a interface principal esta
- MyUtil -> usada para gruardar funcoes que nao tem ligação com nada em particular mas que podem ser util em qualquer parte do codigo
- TARVB -> Um backUp da estrutura de arvore b horiginal
- test -> para gruardar testes feitos ao longo do processo de programação e debuging
-> TLSE -> uma lista simplesmente encadeada modificada para servir a estrutura principal


## Distribuição de tarefas

### ToDo
- Estrutura da BTree 
  - Remove
  - Libera
- Preencimento de dados

- Coleta de dados
- char** get_slam_line(FILE* fp);
- char** get_ativo_line(FILE* fp);
- Funções auxiliares


OBS.: sintam-se livres pra mudar a chamadas das funções por enquanto
### Fazendo
- [seu nome] - [Descrição ou nome da tarefa]
### Feito
- [seu nome] - [Descrição ou nome da tarefa]
- Busca por nome
- BT* BT_Insere_slam(BT* T, int ano, char* camp, char* win, char* vice);
- BT* BT_Insere_ativo(BT* T, int rank, char* pais, char* nome, int point, int idade);
- char** strSplit(char* line, char key);
