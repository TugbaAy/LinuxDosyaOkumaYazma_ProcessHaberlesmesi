#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {

char dosyaAdi[50];
int j = read(3,dosyaAdi,50);
dosyaAdi[j]='\0';

  char c;
  printf("Karakter Giriniz->\n");
  scanf("%c",&c);

  printf("Girdiğiniz Karakter-> %c\n",c);


int fd;
	fd = open(dosyaAdi, O_RDWR,0644);
	int i=0;
	int s = lseek(fd,0,SEEK_END);
	char c1[2];
    	c1[0] = NULL;
	c1[1] = NULL;
	for(i=0; i<s ; i++){
		lseek(fd,i, SEEK_SET);
		read(fd,c1,1);
		if(strcmp(c1," ") == 0){
			lseek(fd,i,SEEK_SET);
			write(fd,&c,1);
		}
	}
char yeniDosyaAdi[50];
strcpy(yeniDosyaAdi,dosyaAdi);
 int k = 0;
  while(1){
    if (yeniDosyaAdi[k] == '\0') {
      yeniDosyaAdi[k] = '_';
      yeniDosyaAdi[k+1] = c;
      yeniDosyaAdi[k+2] = '\0';
      break;
    }
    k++;
  }

rename(dosyaAdi,yeniDosyaAdi);
write(4,yeniDosyaAdi,50);
close(fd);

  return 0;
}
