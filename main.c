#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void crea_mazzo(int arr[4][10], int dim_semi, int dim_carte) {
	for(int i=0; i<dim_semi; i++) {
		for(int j=0; j<dim_carte; j++) {
			arr[i][j] = j+1;
		}
	}
}

void visualizza_mazzo(int arr[4][10], int dim_semi, int dim_carte){
	for(int i=0; i<dim_semi; i++) {
		for(int j=0; j<dim_carte; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void mescola_mazzo(int mazzo[4][10], int dim_semi, int dim_carte) { 
    srand(time(NULL)); 
    for (int i = 0; i < dim_semi; i++) {
        for (int j = 0; j < dim_carte; j++) {
            int random_c = rand() % dim_carte ;
            int temp = mazzo[i][j];
            mazzo[i][j] = mazzo[i][random_c];
            mazzo[i][random_c] = temp;
        }
    }
}



void crea_giocatori(int n_giocatori[], int n){
	for(int i=0; i<n; i++) {
		n_giocatori[i] = i+1;
	}
}

void visualizza_giocatori(int n_giocatori[], int n) {
	for(int i=0; i<n; i++) {
		printf("I giocatori sono: %d \n", n_giocatori[i]);
	}
}

void distribuisci_carte(int** carte, int n_giocatori[], int n, int** carte_giocatori) {
	for(int i=0; i<n; i++){
			for(int j=0; j<2;j++){
				carte_giocatori[i][j] = carte[i][j];
			}
			
		}
		for(int i=0; i<n; i++){
			printf("Carte giocatore: %d, %d\n ", carte_giocatori[i][0], carte_giocatori[i][1]);
		}
}


int main() {
  int const dim_semi = 4;
  int const dim_carte = 10;
  int arr[dim_semi][dim_carte];
  crea_mazzo(arr, dim_semi, dim_carte);
  mescola_mazzo(arr,dim_semi, dim_carte);
  visualizza_mazzo(arr,dim_semi, dim_carte);
	
  return 0;
}
