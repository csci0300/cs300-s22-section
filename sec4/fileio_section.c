#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    // "welcome to file io section from cs300"
    int fd = open("test.txt", O_RDONLY);
    char buf[40];

    int r = read(fd, buf, 7);
    buf[r] = 0;
    printf("bytes read: %d, buffer: %s\n", r, buf);

    r = read(fd, buf, 9);
    buf[r] = 0;
    printf("bytes read: %d, buffer: %s\n", r, buf);

    r = read(fd, buf, 40);
    buf[r] = 0;
    printf("bytes read: %d, buffer: %s\n", r, buf);

    r = read(-2, buf, 40);
    printf("bytes read: %d\n", r);

    char write_buf[] = {'!'};
    int w = write(fd, write_buf, 1);
    printf("bytes written: %d\n", w);

    close(fd);
    fd = open("test.txt", O_RDWR);

    w = write(fd, write_buf, 1);
    printf("bytes written: %d\n", w);

    w = write(fd, write_buf, 1);
    printf("bytes written: %d\n", w);

    lseek(fd, 5, SEEK_CUR);
    w = write(fd, write_buf, 1);
    printf("bytes written: %d\n", w);

    lseek(fd, -1, SEEK_END);
    w = write(fd, write_buf, 1);
    printf("bytes written: %d\n", w);

    lseek(fd, 10, SEEK_SET);
    w = write(fd, write_buf, 1);
    printf("bytes written: %d\n", w);

    const char *new_words = "FILE IO ";
    w = write(fd, new_words, 8);

    r = read(fd, buf, 8);
    buf[r] = 0;
    printf("bytes read: %d, buffer: %s\n", r, buf);

    close(fd);

    return 0;
}
