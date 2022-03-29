#include <stdio.h> 
#include <stdio.h>   
#include <string.h>  
#include <unistd.h>  
#include <fcntl.h>   
#include <errno.h>   
#include <termios.h> 
#include <signal.h>
#include <sys/time.h>

int main()
{
    short portfd=-1;
    int n,f,len;
    char buf[256],*s;
    alarm(2);
#if defined(O_NDELAY) && defined(F_SETFL)
    portfd = open("/dev/ttyUSB0", O_RDWR|O_NDELAY);
    if (portfd >= 0){
        /* Cancel the O_NDELAY flag. */
        printf("port openend\n");
        n = fcntl(portfd, F_GETFL, 0);
        (void) fcntl(portfd, F_SETFL, n & ~O_NDELAY);
    }
#else
    portfd = open("/dev/ttyUSB0", O_RDWR);
#endif
    if (portfd >= 0) 
    {
        if (len == 0) len = strlen(s);
        for(f = 0; f < len && f <100; f++)
            buf[f] = *s++ | 0x80;
        write(portfd, buf, f);
        printf("Do write\n");
        while(portfd>=0){
            printf("%s\n",buf);
        }
    }

    alarm(0);
    signal(SIGALRM, SIG_IGN);
    if (portfd < 0) {
        printf("cannot open %s. Sorry.\n", "/dev/ttyUSB0");
    }
}