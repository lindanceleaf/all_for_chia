#include <stdio.h>
#include <ctype.h>

void traversing(int data[]){
    for(int i = 0; i < 10; i++){
        printf("%d", data[i]);
        if(i != 9)printf(" ");
    }
}

void insertion(int data[], int place, int value){
    for(int i = 9; i > place; i--){
        data[i] = data[i - 1];
    }
    data[place] = value;
}

void updation(int data[], int place, int value){
    data[place] = value;
}

void deletion(int data[], int place){
    data[place] = 0;
}

int main(){
    int data[10] = {0};
    for(int i = 1; i <= 10; i++){
        data[i - 1] = i;
    }

    int action_num;
    printf("num of actions:");
    scanf("%d", &action_num);
    printf("\n");
    char action[action_num];

    for(int i = 0; i < action_num; i++){
        char temp;
        while(1){
            scanf("%c", &temp);
            if(isalpha(temp)) break;
        }
        action[i] = temp;
    }

    int place;
    int value;
    for(int i = 0; i < action_num; i++){
        switch(action[i]){
            case 'i':
                printf("position to insert:");
                scanf("%d", &place);
                printf("\n");
                if(!(place >= 0 && place <= 9)){
                    printf("INVALID POSITION\n");
                    break;
                }

                printf("enter the value to insert:");
                scanf("%d", &value);
                printf("\n");
                
                insertion(data, place, value);

                traversing(data);
                printf(" \n");
                break;
            
            case 'u':
                printf("position to update:");
                scanf("%d", &place);
                printf("\n");
                if(!(place >= 0 && place <= 9)){
                    printf("INVALID POSITION\n");
                    break;
                }

                printf("enter the value to update:");
                scanf("%d", &value);
                printf("\n");

                updation(data, place, value);

                traversing(data);
                printf("\n");
                break;
            
            case 'd':
                printf("position to delete:");
                scanf("%d", &place);
                printf("\n");
                if(!(place >= 0 && place <= 9)){
                    printf("INVALID POSITION\n");
                    break;
                }
                
                deletion(data, place);

                traversing(data);
                printf("\n");
                break;
            case 't':
                traversing(data);
                break;
            
            default:
                printf("INVALID ACTION\n");
                break;
        }
    }
}