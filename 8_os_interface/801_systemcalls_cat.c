#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


void error(char *fmt, ...);

/* filecopy: copy file idf to file ofd */
void filecopy(int ifd, int ofd)
{
    int n;
    char buf[BUFSIZ];

    while ((n = read(ifd, buf, BUFSIZ)) > -1) {
        if (write(ofd, buf, n) != n)
            error("cat: write error");
    }
}
/* cat: concatenate files - read/write/open/close */
int main(int argc, char **argv)
{
    int fd;     // file descriptor
    void filecopy(int ifd, int ofd);

    if (argc == 1)      // no args: copy standard input to ouput
        filecopy(0, 1);
    else
        while (--argc > 0) {
            if ((fd = open(*++argv, O_RDONLY)) == -1)
                error("yh_cat: can't open %s", *argv);
            else {
                filecopy(fd, 1);
                close(fd);
            }
        }
    return 0;
}