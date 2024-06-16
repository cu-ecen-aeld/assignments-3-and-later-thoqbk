#include <stdio.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
        openlog("writer", LOG_PID, LOG_USER);
        if (argc != 3) { // the first arg is for program's name
                syslog(LOG_ERR, "Must pass in exactly 2 args for writefile and writestr");
                closelog();
                return 1;
        }
        char *writefile = argv[1];
        char *writestr = argv[2];
        syslog(LOG_DEBUG, "Write \"%s\" to %s", writefile, writestr);
        FILE *fp = fopen(writefile, "w");
        if (fp == NULL) {
                syslog(LOG_ERR, "Error opening file");
                closelog();
                return 1;
        }
        if (fputs(writestr, fp) == EOF) {
                syslog(LOG_ERR, "Error writing to file");
                fclose(fp);
                closelog();
                return 1;
        }
        fclose(fp);
        closelog();
        return 0;
}
