/*Bu program otele gelen musterilerin bilglilerinin alir duzenler ve gerekli bilgilere 
ulasmamizi saglayarak otelin yonetimini kolaylastiri.*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
void rent(int** rooms,char names[6][25]);
void show_infos(int** rooms,char names[6][25]);
void empty_room(int** rooms,char names[6][25]);
int main()
{                                                                         // Oteldeki 6 otda icin arrayler ayrilir.Indexler sirasiyla
    int room1[4]={1,1,0,0};int room2[4]={1,2,0,0};int room3[4]={2,3,0,0}; // 0:kisi kapesitesi, 1:oda no, 2:bos ise 0 dolu ise 1
    int room4[4]={2,4,0,0};int room5[4]={3,5,0,0};int room6[4]={3,6,0,0}; // 3.Musterini gunluk olarak odedigi para miktari. 
    char names[6][25];  //Musterilerin isimlerini depolayacak degisken.                               
    int* rooms[6]={room1,room2,room3,room4,room5,room6};    //Odalari isaret eden pointer
    char islem;
    printf("Bilgilendirme : \nBu otelde 1 2 ve 3 kisilik odalardan 2 ser tane olmak uzere 6 oda vardir.\n");
    do{     //Programin ana dongusu do while kismidır.Fonksiyonlar burada cagrilir
        printf("--------Menu--------\nCikmak icin q\nBilgileri gormek icin b\nOda kiralamak icin icin k\nOda bosaltmak icin s : ");
        scanf(" %c",&islem);
        if(islem =='b')
            show_infos(rooms,names);
        else if (islem == 'k')
            rent(rooms,names);
        else if (islem == 's')
            empty_room(rooms,names);
        else if (islem == 'q'){}
        else{
            printf("Hatali islem.\nBeklenmeyen durum !!!\n");
            islem='q';
        }
    }
    while(islem !='q');
    printf("Program sonlaniyor ...");
                sleep(3);   //Program aniden kapanmasin ,son outputlarda okunsun diye 3 saniye bekleme suresi.
    return 0;
}
void rent(int** rooms,char names[6][25]){
    int i =0;
    int flag = 0; //Otel kapesitesi kontrolu icin for dongusu ve flag.
    for(i;i<6;i++){
        if (rooms[i][2]==0)
            flag = 1;
    }
    if (flag ==0){
        printf("Otel tamamen doludur.\n");
        return;
    }
    int n;
    printf("Kac kisilik oda ? : ");
    scanf(" %d",&n);
    if(n>3){
        printf("Bu oteldeki odalar maksimum 3 kisi almaktadir !!!\n");
    }
    else if(n<=0)
        printf("Girdigin sayiya dikkat et.\n");
    else{
        int i = 0;
        int flag = 0; //Kiralama islemi basarılı olup olmadıgını kontrol etmek icin.
        char name[25];
        for(i;i<6;i++){ //Bu dongu sırayla odalara bakar.
            if((rooms[i][0]==n)&&(rooms[i][2]==0)){ // ilk kosul istenilen kisi sayısı eslesiyormu 2.kosul ise oda dolumu bosmu kontrol eder.
                flag = 1;
                switch(n){ //Odanin kisi kapesitesine gore fiyatlandirma yapilir.
                    case 1:
                        rooms[i][3]=100;
                        break;
                    case 2:
                        rooms[i][3]=130;
                        break;
                    case 3:
                        rooms[i][3]=150;
                        break;
                }
                printf("Oda sahibinin ismi ? : ");
                scanf(" ");     // Bug dan oturu bu satir eklendi.
                fgets(name,sizeof(name),stdin);
                strcpy(names[i],name);
                rooms[i][2]=1;  //Odayı artık kiraladıgımız icin 2. index 1 e esitlendi. 
                char vip;
                printf("Vip hizmet alincak mi? evet icin 'e' hayir icin 'h' : ");
                scanf(" %c",&vip);
                if(vip=='e')    //Vip hizmet kabul edildiyse fiyata 20 $ daha eklenir.
                    rooms[i][3] +=20;                
                printf("--------------------\n");
                printf("Islem basariyla gerceklesmistir.\n");
                printf("Oda sahibinin adi : %sOda numarasi : %d\nOdadaki kisi sayisi : %d\nGunluk tutar : %d $\n",names[i],rooms[i][1],rooms[i][0],rooms[i][3]);
                break;
            }
        }
        if(flag==0){
            printf("Istenen kisi sayisina göre oda kalmamistir.\n");
        }
    }
}
void show_infos(int** rooms,char names[6][25]){
    int i;
    int arr[3] = {0,0,0};  //1 2 ve 3 kisilik odalardan kacar tanesinin bos kaldigini depolayacagimiz array.
    int income=0;
    for(i=0;i<6;i++){
        income+=rooms[i][3];    //her bir odadaki kira miktarı income degerine eklenir.
        if(rooms[i][2]==0){     
            arr[rooms[i][0]-1]++;   //eger oda bos ise +1
        }
    }
    printf("--------------------\n");
    printf("1 kisilik bos oda sayisi : %d\n2 kisilik bos oda sayisi : %d\n3 kisilik bos oda sayisi : %d\nToplam gelir : %d $\n",arr[0],arr[1],arr[2],income);
    int n;
    char n2;
    printf("Devam edip ayrintili bilgi gormek icin d geri donmek icin q : ");
    scanf(" %c",&n2);
    while((n2=='d')||(n2=='D')){
        printf("Ayrintili bilgi icin oda numarasi giriniz : ");
        scanf(" %d",&n);
        if((n<7)&&(rooms[n-1][2]==1)){
            printf("--------------------\n");
            printf("Oda sahibinin adi : %sOda numarasi : %d\nOdadaki kisi sayisi : %d\nGunluk tutar : %d $\n",names[n-1],rooms[n-1][1],rooms[n-1][0],rooms[n-1][3]);
            printf("--------------------\n");
        }
        else if((n<7)&&(names[n-1][2]==0))
            printf("Bu oda bos\n");
        else
            printf("Bu numaraya sahip bir oda bulunmamaktadir\n");
        printf("Devam icin d geri donmek icin q : ");
        scanf(" %c",&n2);
    }
}
void empty_room(int** rooms,char names[6][25]){
    int i;
    printf("Bosaltmak isediginiz odanin numarasini giriniz : ");
    scanf(" %d",&i);
    if((i>6)||(i<1)){
        printf("Bu oteldeki oda numaralari 1-6 !!!\n");
    }
    else{
        if(rooms[i-1][2]==0)
            printf("Bu oda zaten bos.\n");
        else{
            rooms[i-1][2]=0;
            strcpy(names[i-1],"");
            rooms[i-1][3]=0;
            printf("%d nolu oda bosaltildi\n",i);
    }
    }
}