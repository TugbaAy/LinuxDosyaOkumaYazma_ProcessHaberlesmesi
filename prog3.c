#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

char dosyaAdi[50];
int j = read(3,dosyaAdi,50);
dosyaAdi[j]='\0';

FILE *fp;

  fp = fopen(dosyaAdi, "r");
  int a;
  char ch;

while( ( ch = fgetc(fp) ) != EOF ){
      printf("%c",ch);
}

fclose(fp);
remove(dosyaAdi);

  return 0;
}
