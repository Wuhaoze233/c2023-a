#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "maps.h"
int player_x,player_y;
int score = 0;
char *p;
void Movement(char a,char *p);
void Visualize(char *p);
int main() {
    int level;
    char a = '\0';
    char score_file_str[60];
    char newrecord[20];
    char score_list[3][20];
    int score_file_int;
    FILE *stream;
    stream = fopen("score.txt","r");
    printf("Please choose the difficulty you wanna try:\n1.Easy\n2.Medium\n3.Hard:\n");
    scanf_s("%d",&level);
    system("cls");
    if (level == 1){
        p = map1[0];
        player_x = 6;
        player_y = 6;
        Visualize(p);
        while(a = getch()){
            Movement(a,p);
            if(map1[map1_target1_x][map1_target1_y] == 0)
                map1[map1_target1_x][map1_target1_y] = 3;
            if(map1[map1_target2_x][map1_target2_y] == 0)
                map1[map1_target2_x][map1_target2_y] = 3;
            if(map1[map1_target3_x][map1_target3_y] == 0)
                map1[map1_target3_x][map1_target3_y] = 3;
            if(map1[map1_target4_x][map1_target4_y] == 0)
                map1[map1_target4_x][map1_target4_y] = 3;
            Visualize(p);
            if(((map1[map1_target1_x][map1_target1_y] == 4)&&(map1[map1_target2_x][map1_target2_y] == 4)&&(map1[map1_target2_x][map1_target2_y] == 4)&&(map1[map1_target3_x][map1_target3_y] == 4)&&(map1[map1_target4_x][map1_target4_y] == 4)))
                break;
        }
        system("cls");
        printf("You win!\n");
        fgets(score_list[0],20,stream);
        fgets(score_list[1],20,stream);
        fgets(score_list[2],20,stream);
        score_file_int = atoi(score_list[0]);
        if(score < score_file_int){
            printf("New Record!It only takes you %d steps to win!",score);
            sprintf(newrecord,"%d",score);
            for (int i = 0; i < 20; i++)
                score_list[0][i] = newrecord[i];
            stream = fopen("score.txt","wt");
            fprintf(stream,"%s\n",score_list[0]);
            fprintf(stream,"%s",score_list[1]);
            fprintf(stream,"%s",score_list[2]);
        }
        else{printf("Your score is %d.All time high is %d.",score,score_file_int);}
        fclose(stream);
    }
    else if(level == 2){
        p = map2[0];
        player_x = 8;
        player_y = 5;
        Visualize(p);
        while(!((map2[map2_target1_x][map2_target1_y] == 4)&&(map2[map2_target2_x][map2_target2_y] == 4)&&(map2[map2_target2_x][map2_target2_y] == 4)&&(map2[map2_target3_x][map2_target3_y] == 4)&&(map2[map2_target4_x][map2_target4_y] == 4))){
            a = getch();
            Movement(a,p);
            if(map2[map2_target1_x][map2_target1_y] == 0)
                map2[map2_target1_x][map2_target1_y] = 3;
            if(map2[map2_target2_x][map2_target2_y] == 0)
                map2[map2_target2_x][map2_target2_y] = 3;
            if(map2[map2_target3_x][map2_target3_y] == 0)
                map2[map2_target3_x][map2_target3_y] = 3;
            if(map2[map2_target4_x][map2_target4_y] == 0)
                map2[map2_target4_x][map2_target4_y] = 3;
            Visualize(p);
        }
        system("cls");
        printf("You win!\n");
        fgets(score_list[0],20,stream);
        fgets(score_list[1],20,stream);
        fgets(score_list[2],20,stream);
        score_file_int = atoi(score_list[1]);
        if(score < score_file_int){
            printf("New Record!It only takes you %d steps to win!",score);
            sprintf(newrecord,"%d",score);
            for (int i = 0; i < 20; i++)
                score_list[1][i] = newrecord[i];
            stream = fopen("score.txt","wt");
            fprintf(stream,"%s",score_list[0]);
            fprintf(stream,"%s\n",score_list[1]);
            fprintf(stream,"%s",score_list[2]);
        }
        else{printf("Your score is %d.All time high is %d.",score,score_file_int);}
        fclose(stream);
    }
    else if(level == 3){
        p = map3[0];
        player_x = 5;
        player_y = 9;
        Visualize(p);
        while(!((map3[map3_target1_x][map3_target1_y] == 4)&&(map3[map3_target2_x][map3_target2_y] == 4)&&(map3[map3_target2_x][map3_target2_y] == 4)&&(map3[map3_target3_x][map3_target3_y] == 4)&&(map3[map3_target4_x][map3_target4_y] == 4))){
            a = getch();
            Movement(a,p);
            if(map3[map3_target1_x][map3_target1_y] == 0)
                map3[map3_target1_x][map3_target1_y] = 3;
            if(map3[map3_target2_x][map3_target2_y] == 0)
                map3[map3_target2_x][map3_target2_y] = 3;
            if(map3[map3_target3_x][map3_target3_y] == 0)
                map3[map3_target3_x][map3_target3_y] = 3;
            if(map3[map3_target4_x][map3_target4_y] == 0)
                map3[map3_target4_x][map3_target4_y] = 3;
            Visualize(p);
        }
        system("cls");
        printf("You win!\n");
        fgets(score_list[0],20,stream);
        fgets(score_list[1],20,stream);
        fgets(score_list[2],20,stream);
        sprintf(newrecord,"%d",score);
        score_file_int = atoi(score_list[2]);
        if(score < score_file_int){
            printf("New Record!It only takes you %d steps to win!",score);
            sprintf(newrecord,"%d",score);
            for (int i = 0; i < 20; i++)
                score_list[2][i] = newrecord[i];
            stream = fopen("score.txt","w");
            fprintf(stream,"%s",score_list[0]);
            fprintf(stream,"%s",score_list[1]);
            fprintf(stream,"%s\n",score_list[2]);
        }
        else{printf("Your score is %d.All time high is %d.",score,score_file_int);}
        fclose(stream);
    }
    system("pause");
    return 0;
}
void Visualize(char *p){
    system("cls");
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            if (*(p+x*N+y)==0)
                printf("%c", ' ');
            else if (*(p+x*N+y)==1)
                printf("%c%c",0xa8,0x80);
            else if (*(p+x*N+y)==2)
                printf("%c",'O');
            else if (*(p + x * N + y) == 3)
                printf("%c",'*');
            else if (*(p + x * N + y) == 4)
                printf("%c",'o');
        }
        printf("\n");
    }
}
void Movement(char a,char *p) {
    if (a == 'w'){
        if((*(p + (player_x - 1) * 12 + player_y) == 0) || (*(p + (player_x - 1) * 12 + player_y) == 3)){
            *(p + (player_x - 1) * 12 + player_y) = 2;
            *(p + player_x * 12 + player_y) = 0;
            player_x--;
            score++;
        }
        else if((*(p + (player_x - 1) * 12 + player_y) == 4) && ((*(p + (player_x - 2) * 12 + player_y) == 0) || (*(p + (player_x - 2) * 12 + player_y) == 3))){
            *(p + (player_x - 1) * 12 + player_y) = 2;
            *(p + (player_x - 2) * 12 + player_y) = 4;
            *(p + player_x * 12 + player_y) = 0;
            player_x--;
            score++;
        }
    }//向上移动或向上推箱子
    if (a == 's'){
        if((*(p + (player_x + 1) * 12 + player_y) == 0) || (*(p + (player_x + 1) * 12 + player_y) == 3)){
            *(p + (player_x + 1) * 12 + player_y) = 2;
            *(p + player_x * 12 + player_y) = 0;
            player_x++;
            score++;
        }
        else if((*(p + (player_x + 1) * N + player_y) == 4) && ((*(p + (player_x + 2) * N + player_y) == 0) || (*(p + (player_x + 2) * N + player_y) == 3))){
            *(p + (player_x + 1) * N + player_y) = 2;
            *(p + (player_x + 2) * N + player_y) = 4;
            *(p + player_x * N + player_y) = 0;
            player_x++;
            score++;
        }
    }//向下移动或向下推箱子
    if (a == 'a'){
        if((*(p + player_x * N + player_y - 1) == 0) || (*(p + player_x * N + player_y - 1) == 3)){
            *(p + player_x * N + player_y - 1) = 2;
            *(p + player_x * N + player_y) = 0;
            player_y--;
            score++;
        }
        else if((*(p + player_x * N + player_y - 1) == 4) && ((*(p + player_x * N + player_y - 2) == 0) || (*(p + player_x * N + player_y - 2) == 3))){
            *(p + player_x * N + player_y - 1) = 2;
            *(p + player_x * N + player_y - 2) = 4;
            *(p + player_x * N + player_y) = 0;
            player_y--;
            score++;
        }
    }//向左移动或向左推动箱子
    if (a == 'd'){
        if((*(p + player_x * N + player_y + 1) == 0) || (*(p + player_x * N + player_y + 1) == 3)){
            *(p + player_x * N + player_y + 1) = 2;
            *(p + player_x * N + player_y) = 0;
            player_y++;
            score++;
        }
        else if((*(p + player_x * N + player_y + 1) == 4) && ((*(p + player_x * N + player_y + 2) == 0) || (*(p + player_x * N + player_y + 2) == 3))){
            *(p + player_x * N + player_y + 1) = 2;
            *(p + player_x * N + player_y + 2) = 4;
            *(p + player_x * N + player_y) = 0;
            player_y++;
            score++;
        }
    }//向右移动或向右推动箱子

}
