typedef struct arvB arv;

void criarVazia(arv **T);
int verificarVazia(arv *T);
int inserirRaiz(arv **T, int valor);
arv* procura(arv* T, int valor);
arv* procuraPai(arv* T, int valor);
int inserirDir(arv *T, int no, int valor);
int inserirEsq(arv *T, int Pai, int valor);
void imprimir_arvore(arv* T);
void exibirFilhos(arv* T, int info);
void exibirFilhoDireito(arv* T, int info);
void exibirFilhoEsquerdo(arv* T, int info);
void exibirPai(arv *T, int info);
void removerNo (arv *T, int info);
void menu();
