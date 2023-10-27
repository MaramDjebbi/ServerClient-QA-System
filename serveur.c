#include "serv_cli_fifo.h"
#include "Handlers_Serv.h"

int main(){

    /*Déclarations */
    int fd1,fd2;
    int i,n;
    question q1;
    reponse rep1;



    /* Création des tubes nommés */
	if(mkfifo(fifo1, 0777)==-1){
		if(errno!=EEXIST){
		printf("erreur lors de la creation du fifo1");
		return -1;
		}
	}

	if(mkfifo(fifo2, 0777)==-1){
		if(errno!=EEXIST){
		printf("erreur lors de la creation du fifo2");
		return -1;
		}
	}

    /*initialisation du générateur de nombres aléatoires*/
    	srand(getpid());



    /* Ouverture des tubes nommés  */
    fd1 = open(fifo1, O_RDONLY);
    fd2 = open(fifo2, O_WRONLY);

    /* Installation des Handlers */
    signal (SIGUSR1, hand_reveil);

	for(i=1;i<=NSIG;i++){
        if(i!=SIGUSR1)
        signal(i,fin_serveur);
	}

    printf("chargement....\n");

    while(1){
        /* lecture d’une question */
        if(read(fd1, &q1, sizeof(question))!=0)
        {
        /* construction de la réponse */
        for(i=0;i<q1.n;i++){
            n=(rand() % NMAX)+1;
            rep1.arr[i]=n;
            }
        rep1.pid=getpid();

        /* envoi de la réponse */
        write(fd2, &rep1, sizeof(reponse));

        /* envoi du signal SIGUSR1 au client concerné */
        kill(q1.pid,SIGUSR1);


        pause();


        }
        else usleep(500000);



        }



return 0;

}
