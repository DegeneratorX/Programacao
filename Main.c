#include"Estruturas.c"

int main(){

struct CasaNo *no;
char navio = '@';
AlocaCasaNo(&no, navio);

PrintaCasaNo(no);

}