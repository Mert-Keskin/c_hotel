#include <stdio.h>
#include <string.h>
void book(int** rooms,char names[6][25]);
void show_infos(int** rooms,char names[6][25]);
int main()
{
    int room1[3]={1,1,1};int room2[3]={1,2,0};int room3[3]={2,3,0};int room4[3]={2,4,0};int room5[3]={3,5,0};int room6[3]={3,6,0};
    char names[6][25]={"mert keskin"};
    int* rooms[6]={room1,room2,room3,room4,room5,room6};
    char islem;
    do{
        printf("Cikmak icin q\nBilgileri görmek icin b\nRezervasyon icin r\nOda bosaltmak icin s : ");
        scanf(" %c",&islem);
        if(islem =='b')
            show_infos(rooms,names);
        else if (islem == 'r')
            book(rooms,names);
    }
    while(islem !='q');
    return 0;
}
void book(int** rooms,char names[6][25]){
    int n;
    printf("Kac kisilik oda ? : ");
    scanf(" %d",&n);
    if(n>3){
        printf("Bu oteldeki odala maksimum 3 kisi almaktadir\n");
    }
    else{
        int i = 0;
        int flag = 0;
        char name[25];
        for(i;i<6;i++){
            if((rooms[i][0]==n)&&(rooms[i][2]==0)){
                flag = 1;
                printf("Oda sahibinin ismi ? : ");
                scanf(" %s",name);
                strcpy(names[i],name);
                rooms[i][2]=1;
                printf("%d.odanin sahibi %s\n",i+1,names[i]);
                break;
            }
        }
        if(flag==0)
            printf("Istenen kisi sayisina göre oda kalmamistir");
    }
}
void show_infos(int** rooms,char names[6][25]){
    int i;
    int arr[3] = {0,0,0};
    for(i=0;i<6;i++){
        if(rooms[i][2]==0){
            arr[rooms[i][0]-1]++;
        }
    }
    printf("1 kisilik bos oda sayisi : %d\n2 kisilik bos oda sayisi : %d\n3 kisilik bos oda sayisi : %d\n",arr[0],arr[1],arr[2]);
    int n;
    char n2;
    do{
        printf("Ayrintili bilgi icin oda numarasi giriniz : ");
        scanf(" %d",&n);
        printf("Oda sahibinin adi %s\nOdadaki kisi sayisi %d\n",names[n-1],rooms[n-1][0]);
        printf("Devam icin d cickmak icin q : ");
        scanf(" %c",&n2);
    }
    while((n2!='q')&&(n2!='Q'));
}