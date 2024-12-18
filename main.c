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

void risolvi_effetto(int carta, int giocante[2], int giocatori[20][2], int num_giocatori, int *vite_in_campo, int target, int carte_giocatori[20][2]) { 
	char c = getCharFigura(carta);
	if( c = '1' ) {  // il giocante perde 1 punto vita [emeka]
		
	}
	else if( c = '7' ) { // il giocante costringe il giocatore sucessivo a scoprire la sua carta [Isma]
	if(target+1>=0 && target+1<=19){
		int carta = 1;
		int h = GetCartaNonUsata(carte_giocatori, target);
	}
	}
	else if( c = 'J' ) {  // il giocante che la gioca cede 1 punto vita a il giocatore precedente [Taj]
		if(target-1>=0 && target-1<=19) 
		{
		giocante[2] -= 1; 
		giocatori[target-1][2] += 1;
		}
			else {
			target==target-1-19;
			giocante[2] -= 1;
			giocatori[target+2][2] += 1;
			}
	}
	else if( c = 'Q' ) { // il giocatore che la gioca cede 1 punto di vita a 2 giocatori sucessivi [Taj]
		if(target+2>=0 && target+2<=19) 
		{
		giocante[2] -= 1;
		giocatori[target+2][2] += 1;
		}
			else {
			target==target+2-19;
			giocante[2] -= 1;
			giocatori[target+2][2] += 1;
			}
	}
	else if( c = 'K' )  { // il giocatore riceve tutti i punti vita persi nel campo [Isma]
}giocante[2] += *vite_in_campo;
	vite_in_campo = 0;
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

bool is_dead(const int giocatori[20][2], int indice) {
	return giocatori[indice][1] <=0;
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

int gioca_turno(int giocatori[20][2], int giocatore, int carte_giocatori[20][2], int n) {
  int scelta;
  printf("\n\nTurno del Giocatore %d\n", giocatore);
  printf("Hai %d vite rimanenti.\n",giocatori[giocatore][1]);
  printf("Le tue carte sono: [%d] e [%d]\n", carte_giocatori[giocatore][0], carte_giocatori[giocatore][1]);

  printf("Scegli una carta:\n");
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
  printf("vite in campo:%d\n",vite_in_campo);
  for (int i=0; i<n; i++){
    if(giocatori[i][1] > 0){
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
	int vite_in_campo = 0;

	// giocatori
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
			used[i][j] = 0;                //0 indica che lo slot mazzo non è stato utilizzato
		}
	}

	while(!gameover) {
		mescola_mazzo(mazzo,dim_semi,dim_carte);
		distribuisci_carte(mazzo,n_Giocatori,carte_gioc);
		visualizza_mazzo(mazzo,dim_semi,dim_carte);
		giocatori[0][1] = maxvite; // soluzione temporanea per il nostro "problemino" [da sistemare]
		visualizza_giocatori(n_Giocatori, giocatori, carte_gioc, vite_in_campo);
		
		// scrolla i giocatori ( i = indice del giocatore)
		for(int i=0; i<n_Giocatori; i++) {
			bool usato = HasScelta(used, i, carte_gioc);
			if(usato == true){
				int risposta = gioca_turno(giocatori,i,carte_gioc,n_Giocatori); // il giocatore ci restituisce 1 o 2 e lo mettiamo dentro risposta
				// risolvi_effetto(carte_gioc[i][risposta-1], i, giocatori, n_Giocatori); // risolvi l'effetto della carta che ha scelto il giocatore
			}
			//vogliamo controllare se c'è un vincitore
			vincitore = check_vittoria(giocatori,n_Giocatori); //restituisce -1 se ci sono giocatori ancora vivi
			if(vincitore != -1) { // se è diverso da -1 c'è un vincitore
				gameover = true;
	}

		}
	}
}