#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>

void crea_mazzo(int arr[4][10], int dim_semi, int dim_carte) {
	int contatore = 0;
	for(int i=0; i<dim_semi; i++) {
		for(int j=0; j<dim_carte; j++) {
			arr[i][j] = contatore;
			contatore++;
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
            int random_c = rand() % (dim_carte) ;
			int random_s = rand() % (dim_semi);
            int temp = mazzo[i][j];
            mazzo[i][j] = mazzo[random_s][random_c];
            mazzo[random_s][random_c] = temp;
        }
    }
}

int GetIntFigura(int n) {
	if(n>= 0 && n<=9) {
		return n;
	}
	if(n>= 10 && n<=19)  {
		return n-10;
	}
	if(n>= 20 && n<=29) {
		return n-20;
	}
	if(n>= 30 && n<=39) {
		return n-30;
	}
	else {return -1;} // return '-1' = errore
}

char GetcharSeme(int n) {
	if(n >= 0 && n <= 9 ) {
	  return 'F';
	}
	else if(n >= 10 && n <= 19) {
		return 'P';
	}
	else if (n >= 20 && n <= 29) {
		return 'Q';
	}
	else if (n >= 30 && n <= 39) {
		return 'C';
	}
	else {
		return -1; // return '-1' = errore
	}
}

int getintseme(int n) {
	
	if(n>= 0 && n<=9) {
		return 0;
	}
 	if(n>= 10 && n<=19) {
		return 1;
	}
	if(n>= 20 && n<=29) {
		return 2;
	}
	if(n>= 30 && n<=39) {
		return 3;
	}
	return -1; // return '-1' = errore
}


char getCharFigura(int n) {
    int x = GetIntFigura(n);
	if(x==7) {
		return 'J';
	}
	if(x==8) {
		return 'Q';
	}
	if(x==9) {
		return 'K';
	}
	// conversione da char ---> int
	if(n>=0 && n<=6) {
		return 49+n;
	}
	return -1; // return '-1' = errore
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
void assegna_vite(int giocatori[20][2], int n, int maxvite) {
	for(int i=0; i<n; i++){
		giocatori[i][1] = maxvite;
	}
}

void distribuisci_carte(int carte[4][10], int n, int carte_giocatori[20][2]) {
	int gioc = 0;
	int index = 0;
	for(int i=0; i<4; i++){
		for(int j=0; j<10;j++){
			if(gioc>n) {
				return;
			}
			carte_giocatori[gioc][index] = carte[i][j];
			if(index>=1) {
				gioc += 1;
				index = 0;
			} else {
				index++;	
			}
		}
	}
}

int gioca_turno(int n_giocatori[20][2], int giocatore, int carte_giocatori[20][2], int n) {
  int scelta, i = giocatore;
  printf("\n\nTurno del Giocatore %d\n", n_giocatori[i][0]);
  printf("Hai %d vite rimanenti.\n", n_giocatori[i][1]);
  printf("Le tue carte sono: [%d] e [%d]\n", carte_giocatori[i][0], carte_giocatori[i][1]);

  printf("Scegli una carta:\n");
  printf("Premi 1 per [%d] o 2 per [%d]: ", carte_giocatori[i][0], carte_giocatori[i][1]);
  scanf("%d", &scelta);
  getchar();

  while (scelta != 1 && scelta != 2) {
    printf("Scelta non valida! Inserisci 1 o 2: ");
    scanf("%d", &scelta);
	getchar();
  }
  return scelta;
}



int main() {
  // variabili del gioco
  bool gameover = false;

  // giocatori
  int n = 4;
  int giocatori[n][2];
  int carte_gioc[n][2];
  int maxvite = 4; //diventerà maxvite deciso dall'utente, quindi poi aggiungi uno scanf
  assegna_vite(giocatori, n, maxvite);


  //carte
  int const dim_semi = 4;
  int const dim_carte = 10;
  int mazzo[dim_semi][dim_carte];
  crea_mazzo(mazzo, dim_semi, dim_carte);
  mescola_mazzo(mazzo, dim_semi, dim_carte);
  visualizza_mazzo(mazzo,dim_semi,dim_carte);
  distribuisci_carte(mazzo, n, carte_gioc);

   while(!gameover) {
	mescola_mazzo(mazzo,dim_semi,dim_carte);
	distribuisci_carte(mazzo,n,carte_gioc);
	for(int i=0; i<n; i++) {
		int risposta = gioca_turno(giocatori,i,carte_gioc,n);
	}
	break;
   }

  return 0;
}
