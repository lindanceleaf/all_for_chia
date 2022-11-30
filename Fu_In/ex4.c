#include <stdio.h>

int main(){
    int blood, strength, level;

    printf("Welcome, Adventurer!\n");
    printf("Please enter blood, strength, level: ");
    scanf("%d %d %d", &blood, &strength, &level);
    printf("You have %d blood and %d strength\n", blood, strength);

    while(1){
        int monster;
        printf("Please choose which monster (1 yo 4) you want to fight: ");
        scanf("%d", &monster);
        if(monster >= 1 && monster <= 4){
            printf("You are fighting Monster %d!\n", monster);
            int monster_strength;
            if(monster == 1) monster_strength = level;
            else if(monster == 2) monster_strength = (level % 2) + 2;
            else if(monster == 3) monster_strength = (level > 3 ? level : 3);
            else monster_strength = level * 4;

            if(strength >= monster_strength){
                printf("You Win!\n");
                strength ++;
            }
            else{
                printf("You Lose!\n");
                blood -= (level + monster);
            }

            int choice;
            printf("Do you want to go on your adventure (1: Yes; 0: No) ?:");
            scanf("%d", &choice);
            if(choice == 1){
                if(blood > 0){
                    printf("You have %d blood and %d strength\n", blood, strength);
                    continue;//jump to next loop
                }
                else{
                    printf("You have %d blood and %d strength\n", blood, strength);
                    printf("You dead. Bye!\n");
                    break;
                }
            }
            else{
                printf("We will miss you. Bye!\n");
                break;
            }
        }
        else{
            printf("No such monster, please enter 1 to 4 to choose the monster.\n");
            int choice;
            printf("Do you want to go on your adventure (1: Yes; 0: No) ?:");
            scanf("%d", &choice);
            if(choice == 1){
                printf("You have %d blood and %d strength\n", blood, strength);
                continue;
            }
            else{
                printf("We will miss you. Bye!\n");
                break;
            }
        }
    }
}