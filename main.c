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
			printf("%2d ", arr[i][j]);
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

int getIntFigura(int n) {
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

char getCharSeme(int n) {
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

int getIntSeme(int n) {
	
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
    int x = getIntFigura(n);
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
	if(x>=0 && x<=6) {
		return 49+x;
	}
	return -1; // return '-1' = errore
}

int GetCartaNonUsata(int carte_giocatori[20][2], int target){
	for(int i=0; i<2; i++){
		if(carte_giocatori[target][i] == 0){
			return carte_giocatori[target][i];
		}
	}
	return -1;
}

int getGiocatoreSuccessivo(int target, int dim_giocatori){
	if(target+1 > dim_giocatori)
		return 0;
	return target+1;
}


int GetGiocatorePrecedente(int target, int dim_giocatori) {
	if(target-1 < 0) 
		return dim_giocatori-1;
	return target-1;
}

//	return la posizione del giocatore nell'array [TAJ]
int findpos( int indice, int giocatori[20][2], int num_giocatori) {
	for(int i=0; i<=num_giocatori; i++) {
		if(giocatori[i][1] == 0) {
			indice = i;
			return indice;
		}
}
}

//	per uccidere il giocatore con indice "target", aggiornare l'array  e diminuire il numero di giocatori [ISMA] 
void uccidiGiocatore(int target,int giocatori[20][2],int * num_giocatori) {
	int pos = findpos(target,giocatori,*num_giocatori);
	for(int i=0; i<*num_giocatori-1; i++){
		giocatori[pos][0] = giocatori[pos+1][0];
		giocatori[pos][1] = giocatori[pos+1][1];
		pos++;                                                //vado avanti di target per spostare tutti di una posizione sopra
	}
	*num_giocatori--;
}


void risolvi_effetto(int carta, int giocante[2], int giocatori[20][2], int* num_giocatori, int* vite_in_campo, int target, int carte_giocatori[20][2]) { 
	char c = getCharFigura(carta);
	if( c == '1' ) {  // il giocante perde 1 punto vita [emeka]
		giocatori[target][1] = giocatori[target][1]- 1;//all'array delle vite faccio meno uno al target
		*vite_in_campo = *vite_in_campo + 1;
		printf("Le vite in campo sono: %d\n", *vite_in_campo);
		printf("La vita del giocatore corrente è: %d\n", giocatori[target][1]);
		return;
	}
	else if( c == '7' ) { // il giocante costringe il giocatore successivo a scoprire la sua carta [Isma]
	 	int succ = getGiocatoreSuccessivo(target,*num_giocatori);
		int h = GetCartaNonUsata(carte_giocatori, succ);
		risolvi_effetto(carte_giocatori[succ][h], giocatori[succ], giocatori, *num_giocatori, vite_in_campo, succ, carte_giocatori);
		printf("\nEFFETTO DELLA CARTA [7]: il giocatore {%d} costringe il giocatore successivo a scoprire la sua carta\n", target);
		return;
	}
	else if( c == 'J' ) {  // il giocante che la gioca cede 1 punto vita al giocatore precedente [Taj]
		int prec = GetGiocatorePrecedente(target,*num_giocatori);
		giocante[1]--;
		giocatori[prec][1]++;
		printf("\nEFFETTO DELLA CARTA [J]: il giocatore {%d} cede 1 punto vita al giocatore precedente\n", target);
		return;
	}
	else if( c == 'Q' ) { // il giocatore che la gioca cede 1 punto di vita a 2 giocatori sucessivi [Taj]
		int succ = getGiocatoreSuccessivo(getGiocatoreSuccessivo(target,*num_giocatori),*num_giocatori); // ci da 2 successivi
		giocatori[succ][1]++;
		giocatori[target][1]--;
		printf("\nEFFETTO DELLA CARTA [Q]: il giocatore {%d} cede un punto vita a due giocatori successivi\n", target);
		return;
	}
	else if( c == 'K' )  { // il giocatore riceve tutti i punti vita persi nel campo [Isma]
		giocatori[target][1] += *vite_in_campo;
		printf("\nEFFETTO DELLA CARTA [K]: il giocatore {%d} riceve tutti i punti vita persi nel campo\n", target);
		printf("la vita del giocatore {%d} è: %d\n", target, giocatori[target][1]);
		return;
	}
	if(is_dead(giocatori,target)) {
		uccidiGiocatore(target,giocatori,num_giocatori);
	}
	return;
}

void print_Carta(int n) {
	char c = getCharSeme(n);
	char* seme;
	if(c == 'C') {
		seme = "Cuori";
	}
	if(c == 'Q') {
		seme = "Quadri";
	}
	if(c == 'P') {
		seme = "Picche";
	}
	if(c == 'F') {
		seme = "Fiori";
	}
	printf("%c di %s", getCharFigura(n), seme);
}

void crea_giocatori(int n_giocatori[], int n){
	for(int i=0; i<n; i++) {
		n_giocatori[i] = i+1;
	}
}

void assegna_vite(int giocatori[20][2], int n, int maxvite) {
	for(int i=0; i<n; i++){
		giocatori[i][1] = maxvite;
	}
}

bool is_dead(int giocatori[20][2], int indice) {
	return giocatori[indice][1]<=0?true:false;
}

int check_vittoria(const int giocatori[20][2], int n) { 
	int giocatore_alive = -1; 
	int count_alive = 0; 

	for (int i=0; i < n; i++){
		
		if (is_dead(giocatori,i)){
			count_alive++;
			giocatore_alive = i; //sto selezionando giocatore vivo
		}
	} 
	if (count_alive == 1){
		return giocatore_alive;
	} else {
		return -1; //nel main dovrò scrivere: "ERRORE! nessun giocatore ha ancora vinto"
	}
}

void distribuisci_carte(int carte[4][10], int n, int carte_giocatori[20][2]) {
	int x=0, y=0;
	for(int i=0; i<n ;i++) {
		for(int p=0; p<2; p++) {
			carte_giocatori[i][p] = carte[y][x];
			if(x+1>9) {
				x=0;
				y++;
			} else {
				x++;
			}
		}
	}
}

int gioca_turno(int giocatori[20][2], int giocatore, int carte_giocatori[20][2], int n) {
  int scelta;
  printf("\n\nTurno del Giocatore %d\n", giocatore);
  printf("Hai %d vite rimanenti.\n",giocatori[giocatore][1]);
  printf("Le tue carte sono: [");
  print_Carta(carte_giocatori[giocatore][0]);
  printf("] [");
  print_Carta(carte_giocatori[giocatore][1]);
  printf("] \n");
	printf("Scegli una carta:\n");
	char carta1 = getCharFigura(carte_giocatori[giocatore][0]),
	carta2 = getCharFigura(carte_giocatori[giocatore][1]);
	char insieme_carte1 = getCharFigura(carte_giocatori[giocatore][0]);
	char insieme_carte2 = getCharSeme(carte_giocatori[giocatore][1]);
	printf("   +===========+");                   printf("      +===========+\n");
	printf("   | %c         |",carta1);           printf("      | %c         |\n",carta2);
	printf("   |           |");                   printf("      |           |\n");
	printf("   |           |");                   printf("      |           |\n");
	printf("   |     %c     |",insieme_carte1);   printf("      |     %c     |\n",insieme_carte2);
	printf("   |           |");                   printf("      |           |\n");
	printf("   |           |");                   printf("      |           |\n");
	printf("   |         %c |",carta1);           printf("      |         %c |\n",carta2);
	printf("   +===========+");                   printf("      +===========+\n");
  printf("Premi 1 per [%d] o 2 per [%d]: ", carte_giocatori[giocatore][0], carte_giocatori[giocatore][1]);
  scanf("%d", &scelta);
  getchar();

  while (scelta != 1 && scelta != 2) {
    printf("Scelta non valida! Inserisci 1 o 2: ");
    scanf("%d", &scelta);
	getchar();
  }
  return scelta;
}

bool HasScelta(int used[4][10], int target, int carte_giocatori[20][2]){
  for(int i=0; i<2; i++){
	if (carte_giocatori[target][i] == 0){     //se il valore della carta in quella posizione è 0, la carta non è stata utilizzata. 
      return true;
      } 
  }
  return false;
}

void visualizza_giocatori(int n, int giocatori[20][2], int carte_giocatori[20][2],int vite_in_campo){
  char nascosto[] = "[...]";
  printf("\nvite in campo:%d\n",vite_in_campo);
  for (int i=0; i<n; i++) {
		if(giocatori[i][1] > 0) {
			printf("\n\nGiocatore %d: \nVite_rimaste: %d\nCarte assegnate: \"", i, giocatori[i][1]);
			print_Carta(carte_giocatori[i][0]);
			printf("\" %s", nascosto);
		} 
  }
}
   
int main() {
	// variabili del gioco
	bool gameover = false;
	int vincitore = -1;
	int vite_in_campo = 0; //le vite in campo
	

	int n_Giocatori = 4;
	int giocatori[n_Giocatori][2]; 
	int carte_gioc[n_Giocatori][2];
	int maxvite = 4; //diventerà maxvite deciso dall'utente, quindi poi aggiungi uno scanf
	assegna_vite(giocatori, n_Giocatori, maxvite);

	//carte
	int const dim_semi = 4;
	int const dim_carte = 10;
	int mazzo[dim_semi][dim_carte];
	crea_mazzo(mazzo, dim_semi, dim_carte);

	int used[4][10];
	for(int i=0;i<4;i++){
		for(int j=0;j<10;j++){
			used[i][j] = 0;

		}
		giocatori[i][1]=maxvite;
	}

	while(!gameover) {
		system("clear"); //funziona solo 
		mescola_mazzo(mazzo,dim_semi,dim_carte);
		distribuisci_carte(mazzo,n_Giocatori,carte_gioc);
		visualizza_giocatori(n_Giocatori, giocatori, carte_gioc, vite_in_campo);
		
		// scrolla i giocatori ( i = indice del giocatore)
		for(int i=0; i<n_Giocatori; i++) {
			bool usato = true;
			if(usato){
				int risposta = gioca_turno(giocatori,i,carte_gioc,n_Giocatori)-1; // il giocatore ci restituisce 1 o 2 e lo mettiamo dentro risposta
				risolvi_effetto(carte_gioc[i][risposta],giocatori[i],giocatori,n_Giocatori,&vite_in_campo,i,carte_gioc); // risolvi l'effetto della carta che ha scelto il giocatore
			}
			//vogliamo controllare se c'è un vincitore
			vincitore = check_vittoria(giocatori,n_Giocatori); //restituisce -1 se ci sono giocatori ancora vivi
			if(vincitore != -1) { // se è diverso da -1 c'è un vincitore
				gameover = true;
			}
		}
	}
}