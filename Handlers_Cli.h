void hand_reveil(int sig)
{
printf("Envoi du signal SIGUSER1\n");
    signal(SIGUSR1,hand_reveil);
}
