#include <fcntl.h>
#include <stdio.h>


char *readLine(void){
  char *line = NULL;
  ssize_t bufsize = 0;
  getline(&line, &bufsize, stdin);
  return line;
}

char *trim(char *s) {
    char *ptr;
    if (!s)
        return NULL;
    if (!*s)
        return s;
    for (ptr = s + strlen(s) - 1; (ptr >= s) && isspace(*ptr); --ptr);
    ptr[1] = '\0';
    return s;
}

int main(int argc, char *argv[]){

char *dosyaAdi, *metin;
int fd;

printf("Dosya Adı Giriniz->\n");
fflush(stdout);
dosyaAdi = trim(readLine());

printf("Girilen Dosya Adı-> %s\n",dosyaAdi);

fd = open(dosyaAdi,  O_CREAT | O_WRONLY | O_TRUNC, 0644);

printf("Dosyaya Yazılacak Metni Giriniz->\n");
fflush(stdout);
metin = readLine();

write(fd,metin,strlen(metin));
close(fd);
write(4,dosyaAdi,50);

return 0;

}
