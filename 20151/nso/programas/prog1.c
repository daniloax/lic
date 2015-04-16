main()
{
   int pid;

   if (( pid = fork()) < 0)
   {
     printf("erro no fork\n");
     exit(1);
   }
   if (pid == 0)
     printf("sou o processo filho\n");
   else
   {
		sleep(20);     
		printf("sou o processo pai\n");
     
   }
}
     
