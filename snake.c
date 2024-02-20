#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
int kay=0, n,m,i,j,k,a,b,yem,yemx,yemy,zor=0,fh=0,puan=0,hamlesayisi,dem=0,bir,iki,uc,dort,buyume=1;
char hamle;
printf("TANITIM:\nBaslangic durumunda yilaniniz 1 ile gosterilmektedir. 0'lar yemdir ve onlari toplayarak buyuyebilirsiniz. Oyun alaninin disina cikmaya calisirsaniz kaybedersiniz. Ayni zamanda kendi yilaniniza degmemelisiniz. Oyun butun yemleri toplayinca bitmektedir.");
srand(time(NULL));
printf("\nnxm boyutlu oyun alani olusmaktadir. n ve m sayilarini giriniz\n");
scanf("%d%d",&n,&m);
printf("en fazla %d tane yem olmali. yem sayisini giriniz.",n*m-1);
scanf("%d", &yem);
while(yem>n*m-1){
	printf("yem sayisi en fazla %d tane olmali", m*n-1);
	scanf("%d", &yem);
}
int dizi[n][m];
int yilan[n*m][2];
for(i=0;i<n;i++){
	for(j=0;j<m;j++){
		dizi[i][j]='_';
	}
}
yemx=rand()%n;
yemy=rand()%m;
while(zor<yem){
	if(dizi[yemx][yemy]=='0'){
		fh=1;
	}
while(fh==1){
	yemx=rand()%n;
    yemy=rand()%m;
	if(dizi[yemx][yemy]!='0'){
		fh=0;
	}
}
dizi[yemx][yemy]='0';
zor=zor+1;
}	
 //yem sayisi isteme ve yem olusturma//
a=rand()%n;
b=rand()%m;
if(dizi[a][b]=='0'){
 	dem=1;
}
while(dem==1){
 	a=rand()%n;
    b=rand()%m;
    if(dizi[a][b]!='0'){
    	dem=0;
	}
 }
 uc=a;
 dort=b;
 yilan[0][0]=uc;
 yilan[0][1]=dort;
 dizi[a][b]='1';
 yilan[a][b]=1;
 for(i=0;i<n;i++){
	for(j=0;j<m;j++){
		printf("%c",dizi[i][j]);
	}
	printf("\n");
}
 //yem olmayan yerlerden birine rastgele 1 koyma//
 
 while(yem>0&&kay==0){
 	printf("Yapmak istediginiz hamleyi girin: a-sol w-yukari d-sag -asagi\n");
    scanf("%c", &hamle);
    if(dort==0 && hamle=='a'){
 	    kay=1;
 	    printf("puaniniz:%d\n",puan);
	   	printf("hamle sayiniz:%d\n",hamlesayisi);
	   	printf("kalan yem sayisi:%d \n",yem);
	   	printf("KAYBETTINIZ.\n");
    }
    else if(dort==m-1 && hamle=='d'){
 		kay=1;
 		printf("puaniniz:%d\n",puan);
	   	printf("hamle sayiniz:%d \n",hamlesayisi);
	   	printf("kalan yem sayisi:%d \n",yem);
	   	printf("KAYBETTINIZ.\n");
    }
    else if(uc==0 && hamle=='w'){
 		kay=1;
 		printf("puaniniz:%d\n",puan);
	   	printf("hamle sayiniz:%d\n",hamlesayisi);
	   	printf("kalan yem sayisi:%d \n",yem);
	   	printf("KAYBETTINIZ.\n");
    }
    else if(uc==n-1 && hamle=='s'){
 		kay=1;
 		printf("puaniniz:%d\n",puan);
	   	printf("hamle sayiniz:%d\n",hamlesayisi);
	   	printf("kalan yem sayisi:%d \n",yem);
	   	printf("KAYBETTINIZ.\n");
    }
    else if(b!=0 && hamle=='a'){
        if(dizi[uc][dort-1]=='0'){       //yem varsa
          puan=puan+1;
       	  hamlesayisi=hamlesayisi+1;
          yem=yem-1;
	    } 
	    else if(dizi[uc][dort-1]=='_'){           //yem yoksa
	   	hamlesayisi=hamlesayisi+1;
	    }
		else{
			printf("Kaybettiniz.");
			return 0;
			}
	    dort=dort-1;
	    yilan[hamlesayisi][0]=uc;
	    yilan[hamlesayisi][1]=dort;
	    for(i=0;i<n;i++){
	      for(j=0;j<m;j++){
	      	if(dizi[i][j]!='0'){
	      		dizi[i][j]='_';
			  }
	      }
        }
        buyume=1;
        for(i=hamlesayisi;i>hamlesayisi-puan-1;i--){
        	dizi[yilan[i][0]][yilan[i][1]]=buyume;
        	buyume=buyume+1;
		}
        for(i=0;i<n;i++){
	      for(j=0;j<m;j++){
	      	if(dizi[i][j]>0&&dizi[i][j]<95&&dizi[i][j]!=48){
	      		printf("%d",dizi[i][j]);
			  }
			  else
		    printf("%c",dizi[i][j]);
	      }
	      printf("\n");
        }
        printf("puaniniz:%d\n",puan);
   	    printf("hamle sayiniz:%d\n",hamlesayisi);
   	    printf("kalan yem sayisi:%d\n",yem);
    }
    else if(b!=m-1 && hamle=='d'){
    	   if(dizi[uc][dort+1]=='0'){       //yem varsa
          puan=puan+1;
       	  hamlesayisi=hamlesayisi+1;
          yem=yem-1;
	    } 
	    else if(dizi[uc][dort+1]=='_'){      //yem yoksa
	   	hamlesayisi=hamlesayisi+1;
	    }
		else{
			printf("Kaybettiniz.");
			return 0;
			}
	    dort=dort+1;
	    yilan[hamlesayisi][0]=uc;
	    yilan[hamlesayisi][1]=dort;
	    for(i=0;i<n;i++){
	      for(j=0;j<m;j++){
	      	if(dizi[i][j]!='0'){
	      		dizi[i][j]='_';
			  }
	      }
        }
        buyume=1;
        for(i=hamlesayisi;i>hamlesayisi-puan-1;i--){
        	dizi[yilan[i][0]][yilan[i][1]]=buyume;
		    buyume=buyume+1;
		}
        for(i=0;i<n;i++){
	      for(j=0;j<m;j++){
	      	if(dizi[i][j]>0&&dizi[i][j]<95&&dizi[i][j]!=48){
	      		printf("%d",dizi[i][j]);
			  }
			  else
		    printf("%c",dizi[i][j]);
	      }
	      printf("\n");
        }
        printf("puaniniz:%d\n",puan);
   	    printf("hamle sayiniz:%d\n",hamlesayisi);
   	    printf("kalan yem sayisi:%d\n",yem);
    }
    else if(a!=0 && hamle=='w'){
       if(dizi[uc-1][dort]=='0'){      
          puan=puan+1;
       	  hamlesayisi=hamlesayisi+1;
          yem=yem-1;
	    } 
	    else if(dizi[uc-1][dort]=='_'){                         
	   	hamlesayisi=hamlesayisi+1;
	    }
		else{
			printf("Kaybettiniz.");
			return 0;
			}
	    uc=uc-1;
	    yilan[hamlesayisi][0]=uc;
	    yilan[hamlesayisi][1]=dort;
	    for(i=0;i<n;i++){
	      for(j=0;j<m;j++){
	      	if(dizi[i][j]!='0'){
	      		dizi[i][j]='_';
			  }
	      }
        }
        buyume=1;
        for(i=hamlesayisi;i>hamlesayisi-puan-1;i--){
        	dizi[yilan[i][0]][yilan[i][1]]=buyume;
        	buyume=buyume+1;
		}
        for(i=0;i<n;i++){
	      for(j=0;j<m;j++){
	      	if(dizi[i][j]>0&&dizi[i][j]<95&&dizi[i][j]!=48){
	      		printf("%d",dizi[i][j]);
			  }
			  else
		    printf("%c",dizi[i][j]);
	      }
	      printf("\n");
        }
        printf("puaniniz:%d\n",puan);
   	    printf("hamle sayiniz:%d\n",hamlesayisi);
   	    printf("kalan yem sayisi:%d\n",yem);
    }
    else if(a!=n-1 && hamle=='s'){
    	   if(dizi[uc+1][dort]=='0'){       
          puan=puan+1;
       	  hamlesayisi=hamlesayisi+1;
          yem=yem-1;
	    } 
	    else if(dizi[uc+1][dort]=='_'){                         
	   	hamlesayisi=hamlesayisi+1;
	    }
		else{
			printf("Kaybettiniz.");
			return 0;
			}
	    uc=uc+1;
	    yilan[hamlesayisi][0]=uc;
	    yilan[hamlesayisi][1]=dort;
	    for(i=0;i<n;i++){
	      for(j=0;j<m;j++){
	      	if(dizi[i][j]!='0'){
	      		dizi[i][j]='_';
			  }
	      }
        }
        buyume=1;
        for(i=hamlesayisi;i>hamlesayisi-puan-1;i--){
        	dizi[yilan[i][0]][yilan[i][1]]=buyume;
        	buyume=buyume+1;
		}
        for(i=0;i<n;i++){
	      for(j=0;j<m;j++){
	      	if(dizi[i][j]>0&&dizi[i][j]<95&&dizi[i][j]!=48){
	      		printf("%d",dizi[i][j]);
			  }
		    else
			printf("%c",dizi[i][j]);
	      }
	      printf("\n");
        }
        printf("puaniniz:%d\n",puan);
   	    printf("hamle sayiniz:%d\n",hamlesayisi);
   	    printf("kalan yem sayisi:%d\n",yem);
   }
}
printf("OYUN BITTI.");
	return 0;
}

