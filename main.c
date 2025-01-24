#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>

/**
 *@brief funzione che crea il mazzo 
 *@details una matrice bidimensionale con numeri univoci  
 * che rappresentano le carte di un mazzo. Ogni riga della matrice rappresenta  
 * un seme, mentre ogni colonna rappresenta una carta di quel seme.
 *@param arr Matrice bidimensionale che rappresenta il mazzo di carte
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
 * @brief funzione che ci permette di scegliere il numero di giocatori
 * @details la funzione chiede all'utente di scegliere il numero di giocatori, se il numero di giocatori
 * è maggiore di 20 o inferiore a 2 verrà mostrato un messaggio di avvertenza ("Errato: I giocatori devono 
 * essere almeno 2 e massimo 20. Scegli il numero di giocatori:"), il valore scelto viene poi restituito
 * @param giocatori variabile utilizzata per salvare il valore scelto dall'utente
 * @return ci ritorna il valore selezionato dall'utente
 */

int num_Giocatori() {
	int giocatori;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");	  	
	printf("Scegli il numero di giocatori: ");
		scanf("%d", &giocatori);
		getchar();
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  while(giocatori < 2 || giocatori >20){
  	printf("\nErrore: I giocatori devono essere almeno 2 e massimo 20. \n\nScegli il numero di giocatori: ");
  	scanf("%d", &giocatori);
		getchar();
	}
    return giocatori;
}

/**
*@brief funzione che permette all'utente di selezionare con quante vite i giocatori cominciano la partita
*@details all'esecuzione, la funzione chiederà all'utente con quante vite comincia ogni giocatore. 
*Nel caso in cui però l'utente inserisca un numero di vite inferiore al minimo, ovvero due, la funzione farà ripetere
*la scelta finchè non verrà inserito un valore accettabile
*@return la funzione ritorna il numero di vite iniziali inserite dall'utente.
*/

int vite_Giocatori() {
	int vite;
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  	printf("Scegli il numero delle vite iniziali: ");
	scanf("%d", &vite);
	getchar();
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	
	while(vite < 2){		
		printf("\nErrore, le vite iniziali dei giocatori devono essere almeno 2. \n\nScegli il numero delle vite: ");
		scanf("%d", &vite);
		getchar();
	}
		return vite;
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
*@details La funzione fa in modo di restituire un numero che va da 0 a 40 indipendentemente 
 dal suo valore, purchè sia maggiore di 0 e minore di 40
*@param n è il numero della carta all'interno del mazzo
*@return ritorna un numero da 0 a 9. Ritornerà un messaggio di errore nel caso prenda un numero minore
 di 0 o maggiore o uguale di 40.
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
*@details La funzione identifica ciascuna riga dell'array bidimensionale in un seme specifico.
*@param n è il numero della carta all'interno del mazzo
*@return la funzione ritorna 'F' di fiori se il numero va da 0 a 9, 'P' di picche se il numero va 
*da 10 a 19 e così via..
*Se la funzione riceve un numerominore di 0 o maggiore o uguale a 40 genererà un errore
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
*@details Questa funzione identifica ciascun seme con un identificativo che va da 0 a 3. In base alla riga in cui si trova la carta, essa verrà identificata con un
*suo indice specifico.
*@param n è il numero della carta all'interno del mazzo
*@return la funzione ritorna 0 se la carta ha valore da 0 a 9. Quindi il seme Fiori ha indice 0.
*E così via per tutti gli altri semi.
*Se la funzione riceve un numero minore di 0 o maggiore o uguale a 40, genererà un errore
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
 * @brief Funzione che resituisce Jack, Queen, King per le carte 7, 8 e 9 
 * @details la funzione converte i numeri 7, 8 e 9 nelle rispettive lettere J, Q e K. Se si presenta un errore ci restituisce in output -1
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
*@details la funzione ritorna la carta che non è stata utilizzata dal giocatore tramite un controllo dall'array bidimensionale. 
*Il ciclo for scorre le due carte di un giocatore e vede quale è stata usata o meno. +++++++++++++++++++++++++++++++(controllare)
*@param carte_giocatori[20][2] è l'array che indica le carte che sono state distribuite ad ogni giocatore
*@param target indica l'indice del giocatore a cui vogliamo controllare le carte.
*@return se il valore della carta è uguale a 0, la carta non è stata utilizzata e ci viene data dalla funzione, altrimenti restituirà un messaggio che comunicherà al giocatore che non 
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
*@details La funzione ci restituisce il giocatore successivo all'indice che riceve. Nel caso in cui però l'indice sia quello
*dell'ultimo giocatore della lista dei giocatori, la funzione restituisce 0. 
*@param target rappresenta l'indice del giocatore corrente
*@param dim_giocatori rappresenta la quantità di giocatori presenti nel gioco
*@return la funzione ritorna il giocatore successivo all'indice che la funzione riceve.
 */

int getGiocatoreSuccessivo(int target, int dim_giocatori){
	if(target+1 >= dim_giocatori)
		return 0;
	return target+1;
}

/**
*@brief funzione che restituisce il giocatore precedente
*@details La funzione ci restituisce il giocatore precedente all'indice che riceve. Però nel caso in cui l'indice sia quello
*del primo giocatore, la funzione ci restituirà l'indice dell'ultimo giocatore della lista.
*@param target rappresenta l'indice del giocatore corrente
*@param dim_giocatori rappresenta la quantità di giocatori presenti nel gioco
*@return la funzione ritorna il giocatore precedente all'indice che la funzione riceve.
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
*@details la funzione uccide il giocatore rimpiazzandolo con quello successivo, spostando quindi tutti i giocatori
*successivi a quello morto di un indice superiore
*@param target rappresenta l'indice di un giocatore
*@param giocatori è un array bidimensionale che contiene il numero di giocatori più le loro vite
*@param num_giocatori è una variabile che indica il numero di giocatori
*/

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
*@details La funzione controlla se un giocatore ha una vita o più per continuare a giocare.
*@param giocatori è un array bidimensionale che contiene il numero di giocatori più le loro vite
*@param indice è una variabile che indica la posizione del giocatore
*@return ci ritorna vero nel caso in cui la condizione venisse rispettata, viceversa falso
*/

bool is_dead(int giocatori[20][2], int indice) {
	return giocatori[indice][1]<=0?true:false;
}

/**
*@brief funzione che rimuove le vite ai giocatori
*@details la funzione rimuove una vita al giocatore corrente. Nel caso in cui
*il giocatore non avesse più vite, non vengono rimosse vite.
*@param giocatori è la lista dei giocatori in partita
*@param target è l'indice del giocatore corrente
 */

void rimuovi_vita(int giocatori[20][2], int target) {
	if(giocatori[target][1]<=0){
		return;
	}
	giocatori[target][1]--;
	return;
}

/**
 * @brief funzione che gestisce gli effetti delle carta e stampa degli avvertimenti 
 * @details la funzione contiene diversi parametri tra cui 4 interi, 2 array bidimensionale e un array dimensionale. la funzione 
 * quando rileva una carta "speciale" ovvero che può applicare un effetto, applica l'effetto della carta e al contempo stampa
 * un avvertimento dicendo quale carta è stata usata, da chi e che effetto ha avuto sulla partita/giocatori. la funzione tiene conto
 * anche delle vite in campo che viene inserito come una variabile che viene incrementato ogni volta che "Asso" viene applicato 
 * e viene azzerato ogni volta che la carta "K" viene applicata. 
 * @param carta rappresenta mazzo di carte                                             
 * @param giocante indica la vita del giocatore corrente
 * @param giocatori indica il numero di giocatori e i loro punti vita
 * @param num_giocatori il numero di giocatori all'interno della partita
 * @param vite_in_campo indica il numero di vite presenti sul campo
 * @param target rappresenta il giocatore corrente 
 * @param carte_giocatori indica tutte le carte in possesso dai giocatori
 */

void risolvi_effetto(int carta, int giocante[2], int giocatori[20][2], int* num_giocatori, int* vite_in_campo, int target, int carte_giocatori[20][2]) { 
	char c = getCharFigura(carta);
	if( c == '1' ) {  // il giocante perde 1 punto vita 
		//giocatori[target][1]--;//all'array delle vite faccio meno uno al target
		rimuovi_vita(giocatori,target);
		*vite_in_campo = *vite_in_campo + 1;
		printf("=============================================\n");
		printf("EFFETTO DELLA CARTA [1]: il giocatore {%d} perde un punto vita e lo lascia sul campo\n", target);
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
	else if( c == 'J' ) {  // il giocante che la gioca cede 1 punto vita al giocatore precedente 
		int prec = GetGiocatorePrecedente(target,*num_giocatori);
		//giocatori[target][1]--;
		rimuovi_vita(giocatori,target);
		giocatori[prec][1]++;
		printf("=============================================");
		printf("\nEFFETTO DELLA CARTA [J]: il giocatore {%d} cede 1 punto vita al giocatore precedente\n", target);
		return;
	}
	else if( c == 'Q' ) { // il giocatore che la gioca cede 1 punto di vita a 2 giocatori sucessivi 
		int succ = getGiocatoreSuccessivo(getGiocatoreSuccessivo(target,*num_giocatori),*num_giocatori); // ci da 2 successivi
		giocatori[succ][1]++;
		//giocatori[target][1]--;
		rimuovi_vita(giocatori,target);
		printf("=============================================");
		printf("\nEFFETTO DELLA CARTA [Q]: il giocatore {%d} cede un punto vita a due giocatori successivi\n", target);
		return;
	}
	else if( c == 'K' )  { // il giocatore riceve tutti i punti vita persi nel campo 
		giocatori[target][1] += *vite_in_campo;
		*vite_in_campo = 0;
		printf("=============================================");
		printf("\nEFFETTO DELLA CARTA [K]: il giocatore {%d} riceve tutti i punti vita persi nel campo\n", target);
		printf("la vita del giocatore {%d} è: %d\n", target, giocatori[target][1]);
		return;
	}
	return;
}

/**
*@brief funzione che stampa il seme della carta
*@details la funzione restituisce il valore di ritorno di getCharSeme e ci ritorna il nome completo del seme
*@param n è il numero della carta presente all'interno del mazzo
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

// void crea_giocatori(int n_giocatori[], int n){
	// for(int i=0; i<n; i++) {
		// n_giocatori[i] = i+1;
	// }
// }

/**
*@brief Funzione che assegna vite ai giocatori all'inizio di ogni partita
*@details la funzione assegna le vite ad ogni giocatore presente in gioco, scorrendo
*dell'array bidimensionale tramite un ciclo for.
*@param giocatori è l'array bidimensionale di giocatori e vite per ogni giocatore
*@param n rappresenta il numero di giocatori presenti nella partita attualeparam 
*@param maxvite indica le vite con cui i giocatori partono all'inizio della partita. 
*/

void assegna_vite(int giocatori[20][2], int n, int maxvite) {
	for(int i=0; i<n; i++) {
		giocatori[i][0] = i;
		giocatori[i][1] = maxvite;
	}
	return;
}

/**
* @brief la funzione verifica se c'è un vincitore
* @details attraverso l'array bidimensionale la funzione verifica se un giocatore è vivo, nel caso in cui il giocatore è vivo la funzione
* memorizza il suo indice nel caso in cui un solo un giocatore resta vita (ovvero count_alive = 1) alla fine di un turno, quest'ultimo sarà il vincitore
* @param giocatori indica l'array bidimensionale di giocatori e i loro punti vita
* @param n indica il numero di giocatori
* @return abbiamo in return l'indice del vincitore, nel caso rimanga solo un giocatore in vita, in caso contrario -1, implica che non c'è ancora nessun vincitore.
*/

int check_vittoria(int giocatori[20][2], int n) { 
	int giocatore_alive = -1; 
	int count_alive = 0; 

	for (int i=0; i < n; i++){
		if (!is_dead(giocatori,i)){  //verifica se il giocatore è vivo
			count_alive++;
			giocatore_alive = giocatori[i][0]; //memorizza l'indice dell'ultimo giocatore vivo
		}
	}  
	if (count_alive == 1){
		return giocatore_alive;  //Indice del vincitore
	} else {
		return -1; //Ancora nessun vincitore
	}
}

/**
*@brief funzione che distribuisce le carte ad ogni giocatore
*@details questa funzione assegna due carte ad ogni giocatore tramite un for annidato.
*il primo for scorre i giocatori, il secondo, ovvero quello più interno, scorre le carte.
*Tramite un if, questa funzione è un grado di andara al seme successivo cambiando la riga.
*@param carte è il mazzo di carte.
*@param n è il numero di giocatori presenti in partita
*@param carte_giocatori è l'array bidimensionale dove verranno distribuite due carte per ogni giocatore. 
*Le righe [20] rappresentano i giocatori, le colonne [2] rappresentano le carte.
 */


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

/**
*@brief funzione che verifica quali carte uccidono e chi morirebbe per il loro effetto.
*@details Questa funzione attribuisce alle carte speciali 1 J e Q un punto. Quando
*un giocatore sceglierà una di queste carte nel caso in cui abbia una sola vita, la funzione restituisce true
*perchè il giocatore morirebbe.
*@param giocatori è la lista di giocatori presenti in partita
*@param Giocatore indica l'indice del giocatore che sta giocando 
*@param carta è la carta giocata dal giocatore.
*@return true se il giocatore muore per effetto della carta, false se non muore.
 */

bool uccide(int giocatori[20][2], int Giocatore, int carta) {
	int punti = 0;
	char figura = getCharFigura(carta);
	if(figura=='J') {
		punti = 1;
	}
	if(figura=='Q') {
		punti = 1;
	}
	if(figura=='1') {
		punti = 1;
	}
	if(giocatori[Giocatore][1]-punti<=0) {
		return true;
	} else {
		return false;
	}
}

/**
 *@brief funzione che inizia il turno per ogni giocatore.
 *@details La funzione stampa a schermo l'identificativo del giocatore, le sue vite e le due carte in 
 *suo possesso. La funzione stampa anche una grafica che raffigura le carte del giocatore.
 *La scelta della carta viene eseguita dando in input 1 o 2, rispettivamente per la prima e la seconda carta.
 *Nel caso in cui venga inserito un input diverso, varrà chiesto di ripetere la scelta finchè 
 *non viene inserito quello giusto.
 *E' anche presente un controllo nel caso in cui un giocatore giochi una carta che provocherebbe la sua morte.
 *Tramite la funzione "uccide" il giocatore può esprimere il suo consenso a giocare quella carta, in caso contrario il giocatore
 *è legittimato a ripetere la sua scelta.
 *@param giocatori rappresenta la lista dei giocatori presenti in partita
 *@param target è l'indice del giocatore che sta giocando il suo turno
 *@param carte_giocatori sono le carte assegnate ad ogni giocatore
 *@param n è il numero di giocatori presenti in partita
 *@return la funzione ritorna la scelta del giocatore: 1 oppure 2
 */ 
int gioca_turno(int giocatori[20][2], int target, int carte_giocatori[20][2], int n) {
	int scelta;
	printf("=============================================\n");
	printf("Turno del Giocatore %d\n", target);
	printf("=============================================\n\n");
	printf("Hai %d vite rimanenti.\n",giocatori[target][1]);
	printf("Le tue carte sono: [");
	print_Carta(carte_giocatori[target][0]);
	printf("] [");
	print_Carta(carte_giocatori[target][1]);
	printf("] \n");
	printf("Scegli una carta:\n");
	printf("=============================================\n\n\n");
	int c1 = carte_giocatori[target][0],c2 = carte_giocatori[target][1];
	char carta1 = getCharFigura(carte_giocatori[target][0]),
	carta2 = getCharFigura(carte_giocatori[target][1]);
	char insieme_carte1 = getCharSeme(carte_giocatori[target][0]);
	char insieme_carte2 = getCharSeme(carte_giocatori[target][1]);
	printf("   +===========+");                   printf("      +===========+\n");
	printf("   | %c         |",carta1);           printf("      | %c         |\n",carta2);
	printf("   |           |");                   printf("      |           |\n");
	printf("   |           |");                   printf("      |           |\n");
	printf("   |     %c     |",insieme_carte1);   printf("      |     %c     |\n",insieme_carte2);
	printf("   |           |");                   printf("      |           |\n");
	printf("   |           |");                   printf("      |           |\n");
	printf("   |         %c |",carta1);           printf("      |         %c |\n",carta2);
	printf("   +===========+");                   printf("      +===========+\n\n\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Premi 1 per [%c%c] o 2 per [%c%c]: ", getCharSeme(c1), getCharFigura(c1), getCharSeme(c2), getCharFigura(c2)); 

	scanf("%d", &scelta);
	getchar();
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

	while (scelta != 1 && scelta != 2) {
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("Scelta non valida! Inserisci 1 o 2: ");

		scanf("%d", &scelta);
		getchar();
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	}
	// capire se la carta uccide il giocatore
	char risposta = 'N';
	if (uccide(giocatori,target,carte_giocatori[target][scelta-1])) {
		printf("Questa carta provocherebbe la tua morte, sei sicuro di voler continuare? [S(si)/N(no)]:");
		scanf("%c",&risposta);
		getchar();
		if(risposta=='N'|| risposta=='n') {
			return gioca_turno(giocatori,target,carte_giocatori,n);
		} else if (risposta=='S'||risposta=='s') {
			scelta;
		}
	}
	return scelta;
}

/**
 * @brief la funzione verifica se possiamo usare una carta o meno
 * @details la funzione verifica se possiamo effettivamente giocare una carta attraverso l'utilizo di un ciclo for che controlla entrambre le carte
 * e se il valore della carta, in quella posizione, è 0 allora la carta non è stata utilizzata
 * @param used è un array bidimensionale che tiene traccia del mazzo di carte
 * @param target è una variabile che fa riferimento al giocatore corrente
 * @param carte_giocatori è un array bidimensionale che tiene conto dei giocatori e delle carte in loro possesso
 * @return ci ritorna true se il valore della carta in quella posizione è 0 altrimenti ci ritorna falso
 */

bool HasScelta(int used[4][10], int target, int carte_giocatori[20][2]){
  for(int i=0; i<2; i++){
	if (carte_giocatori[target][i] == 0){     //se il valore della carta in quella posizione è 0, la carta non è stata utilizzata. 
      return true;
      } 
  }
  return false;
}

/**
 * @brief funzione che stampa informazioni sul gioco e sui giocatori
 * @details questa funzione stampa la carta nascosta, le vite in campo, e le informazioni sui giocatori ad esempio il numero del giocatore
 * le vite rimaste e le carte assegnate, tutte le informazioni sono divise da dei divisiori
 * @param n è il numero di giocatori presenti in partita
 * @param giocatori rappresenta il numero di giocatori presenti all'interno della partita e i loro punti vita 
 * @param carte_giocatori rappresenta il numero di gicoatori presenti all'interno della partita e le carte a loro disposizoni
 * @param vite_in_campo è un intero che racchiude tutti i punti vita lasciati sul campo
 */

void visualizza_giocatori(int n, int giocatori[20][2], int carte_giocatori[20][2],int vite_in_campo){
	char nascosto[] = "[...]\n";
	printf("=============================================\n");
	printf("vite in campo: %d\n",vite_in_campo);
	for (int i=0; i<n; i++) {
		if(giocatori[i][1] > 0) {
			printf("=============================================");
			printf("\n\nGiocatore %d: \nVite_rimaste: %d\nCarte assegnate: \"", giocatori[i][0], giocatori[i][1]);
			print_Carta(carte_giocatori[i][0]);
			printf("\" %s", nascosto);
		} 
	}
}


/**
*@brief funzione che elimina i giocatori dal gioco.
*@details La funzione effettua un controllo sui giocatori per verificare che essi abbiano almeno una vita.
*In caso contrario, i giocatori vengono eliminati facendo ricorso alla funzione uccidiGiocatore.
*@param giocatori rappresenta la lista dei giocatori presenti in partita
*@param n_giocatori indica il numero dei giocatori in partita
*/

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

	int n_Giocatori = num_Giocatori();
	int maxvite = vite_Giocatori();
	int giocatori[n_Giocatori][2]; 
	int carte_gioc[n_Giocatori][2];
	assegna_vite(giocatori, n_Giocatori, maxvite);

	//carte
	int const dim_semi = 4;
	int const dim_carte = 10;
	int mazzo[dim_semi][dim_carte];
	crea_mazzo(mazzo, dim_semi, dim_carte);


	while(!gameover) {
		system("clear"); //funziona solo 
		mescola_mazzo(mazzo,dim_semi,dim_carte);
		distribuisci_carte(mazzo,n_Giocatori,carte_gioc);
		visualizza_giocatori(n_Giocatori, giocatori, carte_gioc, vite_in_campo);
		
		// scrolla i giocatori ( i = indice del giocatore)
		for(int i=0; i<n_Giocatori; i++) {
			bool usato = true;
			if(usato){
				int risposta = -1; // -1 è errore
				while(risposta==-1) {
					risposta = gioca_turno(giocatori,giocatori[i][0],carte_gioc,n_Giocatori)-1; // il giocatore ci restituisce 1 o 2 e lo mettiamo dentro risposta
				}
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




