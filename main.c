#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>

/**
 *@brief funzione che crea il mazzo 
 *@details una matrice bidimensionale con numeri univoci  
 * che rappresentano le carte di un mazzo. Ogni riga della matrice rappresenta  
 * un seme, mentre ogni colonna rappresenta una carta di quel seme.
 *@param arr Matrice bidimensionale [4][10] avente come dimensioni [dim_carte0] [dim_semmi]
 * entrami rappresentato il mazzo di carte
 *@param dim_semi numero di semi all'interno del mazzo (righe della matrice)
 *@param dim_carte mumero di carte per ogni seme (colonne  della matrice)
 */
void crea_mazzo(int arr[4][10], int dim_semi, int dim_carte) {
	int contatore = 0;
	for(int i=0; i<dim_semi; i++) {
		for(int j=0; j<dim_carte; j++) {
			arr[i][j] = contatore;
			contatore++;
		}
	}
}

/**
 * @brief funzione di tipo void che stampa a schermo il mazzo di carte
 * @details la funzione riceve tre parametri, un array bidimensionale e due interi
 * @param arr è l'array che contiene le carte
 * @param dim_semi rappresenta la prima dimensione dell'array e indica i semi delle carte
 * @param dim_carte rappresenta il numero di carte per seme
*/

void visualizza_mazzo(int arr[4][10], int dim_semi, int dim_carte){
	for(int i=0; i<dim_semi; i++) {
		for(int j=0; j<dim_carte; j++) {
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
}

/**
 * @brief funzione che ci permette di scegliere il numero di giocatori
 * @details la funzione chiede all'utente di scegliere il numero di giocatori, se il numero di giocatori
 * è maggiore di 20 o inferiore a 2 verrà mostrato un messaggio di avvertenza ("Errato: I giocatori devono 
 * essere almeno 2 e massimo 20. Scegli il numero di giocatori:"), il valore scelto viene poi restituito
 * @param giocatori variabile utilizzata per salvare il valore scelto dall'utente
 * @return ci ritorna il valore selezionato dall'utente
 */

int num_Giocatori() {
	int giocatori;
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  	printf("Scegli il numero di giocatori: ");
		scanf("%d", &giocatori);
		getchar();
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  while(giocatori < 2 || giocatori >20){
  	printf("\nErrato: I giocatori devono essere almeno 2 e massimo 20. \nScegli il numero di giocatori: ");
  	scanf("%d", &giocatori);
		getchar();
	}
    return giocatori;
}

/**
 * @brief mescola causalmente il mazzo di carte
 * @details la funzione utilizza un algoritmo di mescolamento per scambiare le posizioni
 * delle carte presenti all'interno della matrice bidimensionale, grazie alle funzione rand 
 * ogni carta viene scambiata con un'altra carta selezionata casualmente, mentre, la funzione 
 * time(NULL) serve per garantire la casualità per ogni esecuzione
 * @param arr Matrice bidimensionale avente come dimensioni [dim_carte0] [dim_semmi]
 * entrami rappresentato il mazzo di carte
 * @param dim_semi numero di semi all'interno del mazzo (righe della matrice)
 * @param dim_carte mumero di carte per ogni seme (colonne  della matrice)
 */

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

/**
*@brief funzione di tipo int che converte tutti i numeri del mazzo in una lista che va da 0 a 9
*@details la funzione riceve come parametro un intero
*@param n è il numero della carta all'interno del mazzo
*@return la funzione restituisce il numero che andrà da 0 a 9. Se la funzione riceve 
*un numero maggiore o uguale a 40 genererà un errore.
 */

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

/**
*@brief funzione che identifica le carte del mazzo con i semi delle carte
*@details la funzione riceve come parametro un intero
*@param n è il numero della carta all'interno del mazzo
*@return la funzione ritorna 'F' di fiori se il numero va da 0 a 9, 'P' di picche se il numero va 
*da 10 a 19 e così via..
*Se la funzione riceve un numero maggiore o uguale a 40 genererà un errore
*/

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

/**
*@brief funzione che identifica i semi del mazzo con un indice
*@details la funzione riceve un intero come parametro
*@param n è il numero della carta all'interno del mazzo
*@return la funzione ritorna 0 se la carta ha valore da 0 a 9. Quindi il seme Fiori ha indice 0.
*E così via per tutti gli altri semi.
*Se la funzione riceve un numero maggiore o uguale a 40, genererà un errore
*/
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

/**
 * @brief Funzione che identifica le carte "speciali"
 * @details se la funzione rileva, dall'array bidimensionale, che abbiamo delle carte "speciali" (ovvero carte che applicano un effetto)
 * ci restituisce in output le lettere J, Q, K ovvero le carte applicano un effetto mentre per le carte che non applicano un effetto vengono 
 * restituiti in int se si presenta un errore ci restituisce in output -1
 * @param n è il numero della carta presente all'interno del mazzo
 * @return la funzione resituisce J per le carte con nummero 7, Q per le carte con numero 8, K per le carte con numero 9, e restituisce carte
 * comprese tra 0 e 6 in int e restitusice -1 se si presenta un erorre
 */

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

/**
*@brief funzione che restituisce la carta non usata
*@details la funzione riceve come parametri un array bidimensionale e un intero
*@param carte_giocatori[20][2] è l'array che indica le carte che sono state distribuite ad ogni giocatore
*@param target indica l'indice del giocatore a cui vogliamo controllare le carte.
*@return la funzione ritorna la carta che non è stata utilizzata dal giocatore tramite in controllo all'array bidimensionale.
*se il valore della carta è uguale a 0, la carta non è stata utilizzata, altrimenti restituirà un messaggio che comunicherà al giocatore che non 
*ha carte utilizzabili.
*/

int GetCartaNonUsata(int carte_giocatori[20][2], int target){
	for(int i=0; i<2; i++){
		if(carte_giocatori[target][i] == 0){
			return carte_giocatori[target][i];
		}
	}
	return -1;
}

/**
*@brief funzione che restituisce il giocatore successivo
*@details la funzione riceve come parametri due interi
*@param target rappresenta l'indice di un giocatore
*@param dim_giocatori rappresenta la quantità di giocatori presenti nel gioco
*@return la funzione ritorna il giocatore successivo all'indice che la funzione riceve. Nel caso non ci sia
*un giocatore successivo all'indice ricevuto, la funzione restituirà un messaggio di errore.
 */

int getGiocatoreSuccessivo(int target, int dim_giocatori){
	if(target+1 >= dim_giocatori)
		return 0;
	return target+1;
}

/**
*@brief funzione che restituisce il giocatore precedente
*@details la funzione riceve come parametri due interi
*@param target rappresenta l'indice di un giocatore
*@param dim_giocatori rappresenta la quantità di giocatori presenti nel gioco
*@return la funzione ritorna il giocatore precedente all'indice che la funzione riceve. Nel caso non ci sia
*un giocatore precedente all'indice ricevuto, la funzione restituirà un messaggio di errore.
 */

int GetGiocatorePrecedente(int target, int dim_giocatori) {
	if(target-1 < 0) 
		return dim_giocatori-1;
	return target-1;
}

/**
 * @brief funzione che restituisce la posizione dei giocatori
 * @details la funzione riceve come parametri due interi e un array bidimensionale e attraverso un ciclo for
 * ricaviamo la posizione di ogni gicatore 
 * @param indice è una variabile che ci serve per determinare la posizione del giocatore corrente 
 * @param giocatori è un array bidimensionale che contiene il numero di giocatori più le loro vite
 * @param num_giocatori è una variabile che indica il numero di giocatori
 * @return la funzione ritorna la posiziione del giocatore e in caso di errore ci restitusice -1
 */

//	return la posizione del giocatore nell'array [TAJ]
int findpos(int indice, int giocatori[20][2], int num_giocatori) {
	for(int i=0; i<=num_giocatori; i++) {
		if(giocatori[i][1] == 0) {
			indice = i;
			return indice;
		}
	}
	return -1;
}

/**
*@brief funzione che elimina i giocatori dalla lista
*@details la funzione riceve come parametri due interi e un array bidimensionale
*@param target rappresenta l'indice di un giocatore
*@param giocatori è un array bidimensionale che contiene il numero di giocatori più le loro vite
*@param num_giocatori è una variabile che indica il numero di giocatori
*/

//	per uccidere il giocatore con indice "target", aggiornare l'array  e diminuire il numero di giocatori [ISMA] 
void uccidiGiocatore(int target,int giocatori[20][2],int * num_giocatori) {
	int pos = findpos(target,giocatori,*num_giocatori);
	for(int i=0; i<*num_giocatori-1; i++){
		giocatori[pos][0] = giocatori[pos+1][0];
		giocatori[pos][1] = giocatori[pos+1][1];
		pos++;                                                //vado avanti di target per spostare tutti di una posizione sopra
	}
	(*num_giocatori)--;
}

/**
*@brief funzione che rileva i giocatori senza vita dalla lista
*@details la funzione riceve come parametri un intero e un array bidimensionale
*@param giocatori è un array bidimensionale che contiene il numero di giocatori più le loro vite
*@param indice è una variabile che indica la posizione del giocatore
*@return ci ritorna vero nel caso in cui la condizione venisse rispettata, viceversa falso
*/

bool is_dead(int giocatori[20][2], int indice) {
	return giocatori[indice][1]<=0?true:false;
}

/**
 * @brief funzione che gestisce gli effetti delle carta e stampa dei avvertimenti 
 * @details la funzione contiene diversi parametri tra cui 4 interi, 2 array bidimensionale e un array dimensionale. la funzione 
 * quando rileva una carta "speciale" ovvero che può applicare un effetto, applica l'effetto della carta e al coltempo stampa
 * un avvertimento dicendo quale carta è stata usata, da chi e che effetto ha avuto sulla partita/giocatori. la funzione tiene conto
 * anche delle vite in campo che viene inserito come una variabile che viene incrementato ogni volta che "Asso" viene applicato 
 * e viene azzerato ogni volta che la carta "K" viene applicata. 
 * @param                                                     
 * @param 
 * @param
 * @param
 * @param
 * @param
 * @param
 */

void risolvi_effetto(int carta, int giocante[2], int giocatori[20][2], int* num_giocatori, int* vite_in_campo, int target, int carte_giocatori[20][2]) { 
	char c = getCharFigura(carta);
	if( c == '1' ) {  // il giocante perde 1 punto vita [emeka]
		giocatori[target][1] = giocatori[target][1]- 1;//all'array delle vite faccio meno uno al target
		*vite_in_campo = *vite_in_campo + 1;
		printf("=============================================\n");
		printf("Le vite in campo sono: %d\n", *vite_in_campo);
		printf("La vita del giocatore corrente è: %d\n", giocatori[target][1]);
		return;
	}
	else if( c == '7' ) { // il giocante costringe il giocatore successivo a scoprire la sua carta [Isma]
	 	int succ = getGiocatoreSuccessivo(target,*num_giocatori);
		int h = GetCartaNonUsata(carte_giocatori, succ);
		risolvi_effetto(carte_giocatori[succ][h], giocatori[succ], giocatori, num_giocatori, vite_in_campo, succ, carte_giocatori);
		printf("=============================================");
		printf("\nEFFETTO DELLA CARTA [7]: il giocatore {%d} costringe il giocatore successivo a scoprire la sua carta\n", target);
		return;
	}
	else if( c == 'J' ) {  // il giocante che la gioca cede 1 punto vita al giocatore precedente [Taj]
		int prec = GetGiocatorePrecedente(target,*num_giocatori);
		giocante[1]--;
		giocatori[prec][1]++;
		printf("=============================================");
		printf("\nEFFETTO DELLA CARTA [J]: il giocatore {%d} cede 1 punto vita al giocatore precedente\n", target);
		return;
	}
	else if( c == 'Q' ) { // il giocatore che la gioca cede 1 punto di vita a 2 giocatori sucessivi [Taj]
		int succ = getGiocatoreSuccessivo(getGiocatoreSuccessivo(target,*num_giocatori),*num_giocatori); // ci da 2 successivi
		giocatori[succ][1]++;
		giocatori[target][1]--;
		printf("=============================================");
		printf("\nEFFETTO DELLA CARTA [Q]: il giocatore {%d} cede un punto vita a due giocatori successivi\n", target);
		return;
	}
	else if( c == 'K' )  { // il giocatore riceve tutti i punti vita persi nel campo [Isma]
		giocatori[target][1] += *vite_in_campo;
		printf("=============================================");
		printf("\nEFFETTO DELLA CARTA [K]: il giocatore {%d} riceve tutti i punti vita persi nel campo\n", target);
		printf("la vita del giocatore {%d} è: %d\n", target, giocatori[target][1]);
		
		return;
	}
	return;
}

/**
*@brief funzione che  
 */

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
	for(int i=0; i<n; i++)
		giocatori[i][1] = maxvite;
	return;
}

int check_vittoria(int giocatori[20][2], int n) { 
	int giocatore_alive = -1; 
	int count_alive = 0; 

	for (int i=0; i < n; i++){
		
		if (!is_dead(giocatori,i)){  //verifica se il giocatore è vivo
			count_alive++;
			giocatore_alive = i; //memorizza l'indice dell'ultimo giocatore vivo
		}
	}  
	if (count_alive == 1){
		return giocatore_alive;  //Indice del vincitore
	} else {
		return -1; //Ancora nessun vincitore
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
	printf("=============================================\n");
	printf("Turno del Giocatore %d\n", giocatore);
	printf("=============================================\n\n");
	printf("Hai %d vite rimanenti.\n",giocatori[giocatore][1]);
	printf("Le tue carte sono: [");
	print_Carta(carte_giocatori[giocatore][0]);
	printf("] [");
	print_Carta(carte_giocatori[giocatore][1]);
	printf("] \n");
	printf("Scegli una carta:\n");
	printf("=============================================\n\n\n");
	int c1 = carte_giocatori[giocatore][0],c2 = carte_giocatori[giocatore][1];
	char carta1 = getCharFigura(carte_giocatori[giocatore][0]),
	carta2 = getCharFigura(carte_giocatori[giocatore][1]);
	char insieme_carte1 = getCharSeme(carte_giocatori[giocatore][0]);
	char insieme_carte2 = getCharSeme(carte_giocatori[giocatore][1]);
	printf("   +===========+");                   printf("      +===========+\n");
	printf("   | %c         |",carta1);           printf("      | %c         |\n",carta2);
	printf("   |           |");                   printf("      |           |\n");
	printf("   |           |");                   printf("      |           |\n");
	printf("   |     %c     |",insieme_carte1);   printf("      |     %c     |\n",insieme_carte2);
	printf("   |           |");                   printf("      |           |\n");
	printf("   |           |");                   printf("      |           |\n");
	printf("   |         %c |",carta1);           printf("      |         %c |\n",carta2);
	printf("   +===========+");                   printf("      +===========+\n\n\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Premi 1 per [%c%c] o 2 per [%c%c]: ", getCharSeme(c1), getCharFigura(c1), getCharSeme(c2), getCharFigura(c2)); 
	scanf("%d", &scelta);
	getchar();
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

	while (scelta != 1 && scelta != 2) {
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("Scelta non valida! Inserisci 1 o 2: ");
		scanf("%d", &scelta);
		getchar();
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
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
  char nascosto[] = "[...]\n";
	printf("=============================================\n");
  printf("vite in campo:%d\n",vite_in_campo);
  for (int i=0; i<n; i++) {
		if(giocatori[i][1] > 0) {
			printf("=============================================");
			printf("\n\nGiocatore %d: \nVite_rimaste: %d\nCarte assegnate: \"", i, giocatori[i][1]);
			print_Carta(carte_giocatori[i][0]);
			printf("\" %s", nascosto);
		} 
  }
}

void eliminaGiocatori(int giocatori[20][2], int* n_Giocatori){
	for(int i = 0; i < *n_Giocatori; i++){
		if(giocatori[i][1] <= 0){
			uccidiGiocatore(i, giocatori, n_Giocatori);
		}
	}
}
   
int main() {
	// variabili del gioco
	bool gameover = false;
	int vincitore = -1;
	int vite_in_campo = 0; //le vite in campo

	int n = 0;
	int n_Giocatori = num_Giocatori();
	int giocatori[n_Giocatori][2]; 
	int carte_gioc[n_Giocatori][2];
	int maxvite = 2; 
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
				risolvi_effetto(carte_gioc[i][risposta],giocatori[i],giocatori,&n_Giocatori,&vite_in_campo,i,carte_gioc); // risolvi l'effetto della carta che ha scelto il giocatore
			}
		}
		eliminaGiocatori(giocatori, &n_Giocatori);
		//vogliamo controllare se c'è un vincitore
		vincitore = check_vittoria(giocatori,n_Giocatori); //restituisce -1 se ci sono giocatori ancora vivi
		if(vincitore != -1) { // se è diverso da -1 c'è un vincitore
			gameover = true;
			printf("=============================================\n");
			printf("Il giocatore %d ha vinto il gioco!\n", vincitore);
			printf("=============================================\n\n");
		}
	}
	
}