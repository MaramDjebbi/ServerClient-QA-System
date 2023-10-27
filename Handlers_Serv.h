void hand_reveil(int sig)
{
printf("Signal envoyé par le client \n");
signal(SIGUSR1,hand_reveil);
}


void fin_serveur(int sig){
printf("Fin du serveur \n");
//unlink(fifo1);
//unlink(fifo2);
exit(0);
}



