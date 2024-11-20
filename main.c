#include<stdio.h>

int crea_mazzo() {
	int dim_semi = 4;
	int dim_carte = 10;
	int mazzo [dim_semi][dim_carte];
	 for(int i=0; i<dim_semi; i++){
		for(int j=0; j<dim_carte; j++) {
			mazzo [i][j] = j+1;
		}
}

/*void mescola_mazzo(int** mazzo, int dim_semi, int dim_carte){

	int carte_per_seme = 10;
	for(i=0; i<carte_per_seme; i++) {
	    int carta_random = rand()%carte_per_seme;
		int aux;
		aux = mazzo_mescolato[0][i];
		mazzo_mescolato[0][i] = carta_random;
		carta_random = aux;
    
	}

							




}*/





	

	









int main() {
int n = 0;
if (n < 2 && n>20)
{
	n = 2;
}

int n_giocatori[n];
int n_carte[n][2];
int n_vite[n];

for(int i=0; i<n; i++) {
n_giocatori[i] = i + 1;
n_vite[i] = 2;
} 
for(int i=0; i<n; i++){
	printf("%d\n", n_giocatori);
}
