#include "serv_cli_fifo.h"
#include "Handlers_Cli.h"


int main(){
    /* Déclarations */

        int fd1,fd2;
        int i,n;
        question q1;
        reponse rep1;


    /* Ouverture des tubes nommés */

	fd1 = open(fifo1, O_WRONLY);
	fd2 = open(fifo2, O_RDONLY);

    /*initialisation du générateur de nombres aléatoires*/
    srand(getpid());
    sleep(rand() % 5);



    /* Installation des Handlers */
    signal (SIGUSR1, hand_reveil);


    /* Construction et envoi d’une question */
    n=(rand() % NMAX)+1;
	printf(" n= %d\n ",n);
	q1.n=n;
	q1.pid=getpid();
    write(fd1, &q1, sizeof(question));
	close(fd1);

    /* Attente de la réponse */
    printf("\n en attente de la reponse du serveur ...\n");
    pause();

    /* Lecture de la réponse */
	read(fd2, &rep1, sizeof(reponse));
    close(fd2);

    /* Envoi du signal SIGUSR1 au serveur */
    kill(rep1.pid,SIGUSR1);


    /* Traitement local de la réponse */
    printf("La Réponse est: \n ");
    for(i=0;i<q1.n;i++)
        printf(" %d  \t ",rep1.arr[i]);
    printf("\nFin du client. \n ");
    return 0;

}
