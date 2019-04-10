#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>

void main(int argv,char **argc)
{
if(argv > 1){
int sequ = atoi(argc[1]);
if(sequ > 0){
pid_t p;
p = fork();
if(p<0){
printf("Error Occured");
}
else if(p == 0){
for(sequ;sequ >= 1;sequ = sequ / 2){
printf("%d\n",sequ);
}
}
else{
wait(NULL);
}
}
else{
printf("Please Provide Positive Integer\n");
}
}
else{
printf("No Arguments Supplied\n");
}
}

