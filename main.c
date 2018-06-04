#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <curl/curl.h>
#include "stuff.h"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

//extern CURL *curl;

int main()
{
    //printf("Hello world!\n");
    char *txt;
    int i;

    char request[256];
    struct timeval  tv1, tv2;

    gettimeofday(&tv1, NULL);


    gcurl_init();

    for (i=0; i < 1000; i++) {

        snprintf(request, 256, "{\"jsonrpc\": \"1.0\", \"id\":\"curltest\", \"method\": \"getblock\", \"params\": [\"%d\"] }", i+1);
        txt = daemon_request("localhost", 7771, "bitcoinrpc", "password", request);

        printf(YELLOW "Result:" RESET " %s", txt);
        free(txt);
    }

    #ifdef RECONNECT
    gcurl_cleanup();
    #endif // RECONNECT

    gettimeofday(&tv2, NULL);
    printf ("Total time = " YELLOW "%f seconds\n" RESET,
         (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
         (double) (tv2.tv_sec - tv1.tv_sec));

    return 0;
}
