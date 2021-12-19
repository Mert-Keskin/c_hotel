#include <stdio.h>
#include <string.h>
void book(int** rooms,char names[6][25]);
int main()
{
    int room1[3]={1,1,1};int room2[3]={1,2,0};int room3[3]={2,3,0};int room4[3]={2,4,0};int room5[3]={3,5,0};int room6[3]={3,6,0};
    char names[6][25]={"mert keskin"};
    int* rooms[6]={room1,room2,room3,room4,room5,room6};
    book(rooms,names);
    return 0;
}
void book(int** rooms,char names[6][25]){
    int n;
    printf("Kac kisilik oda ? : ");
    scanf("%d",&n);
    if(n>3){
        printf("Mevcut oda bulunmamaktadir.");
        //pass
    }
    else{
        int i = 0;
        char name[25];
        for(i;i<6;i++){
            if((rooms[i][0]==n)&&(rooms[i][2]==0)){
                printf("Oda sahibinin ismi ? : ");
                scanf("%s",&name);
                strcpy(names[i],name);
                printf("%d.odanin sahibi %s\n",i+1,names[i]);
                break;
            }
        }
    }
}