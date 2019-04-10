#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
int main( int argc, char* argv[] ) {
int pipe[2];
pid_t p;
char readBuff[50];
char writeBuff[50];
int readCounter;
pipe(pipe);
if( argc < 3 )
{
printf( "Atleast 2 Arguments Required !\n");
exit(1);
}
int sourceFile = open( argv[1], 0 );
int destFile = open( argv[2], 0666 );
if ( sourceFile == -1 || destFile == -1 )
{
printf( "Error Occured While Opening File");
exit(1);
}
p = fork();
if( p == 0 )
{
printf("Executing Child\n");
close( pipe[1] );
read( pipe[0], readBuff,sizeof(readBuff));
printf("Copying Source File To Destination file");
write(destFile,readBuff,strlen(readBuff)+1);
}
else
{
printf("Executing Parent\n");
close(pipe[0]);
while((readCounter =
read(sourceFile,readBuff,sizeof(readBuff))>0))
{
write(pipe[1],readBuff,sizeof(readBuff));
}
close( pipe[1] );
}
}
