#ifndef STUFF_H_INCLUDED
#define STUFF_H_INCLUDED

#define BUFFER_SIZE  (256 * 1024)  /* 256 KB */

#define URL_FORMAT   "https://api.github.com/repos/%s/%s/commits"
#define URL_SIZE     256

void gcurl_init();
void gcurl_cleanup();

char *daemon_request(char *daemon_ip, int daemon_port, char *daemon_username, char *daemon_password, char *command);

#endif // STUFF_H_INCLUDED
