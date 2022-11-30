#include <stdio.h>

int main(){
    printf("Welcome, young boss!\n");
    int own_dollars = 100;
    int made_time = 15;
    int hot_dog_price = 30;
    int income = hot_dog_price * (180 / made_time);
    int speedup_cost = 50, delicious_cost = 100;
    while(1){
        printf("Chop chop, It's dawn.\n");
        int earning = 0;
        for(int i = 1; i <= 4; i++){
            printf("You are at Area %d.\n", i);
            printf("You have %d dollars.\n", own_dollars);
            printf("You need %d minutes to make a hotdog.\n", made_time);
            printf("The price of a hotdog is $%d.\n", hot_dog_price);

            int action_choice;
            while(1){
                printf("Please choose which action you want to take:\n");
                printf("  [1] Sell the hotdogs (+ $%d)\n", income);
                printf("  [2] Improve your cooking speed (- $%d / - 1 min for making a hotdog)\n", speedup_cost);
                printf("  [3] Improve your hotdog flavor (- $%d / + $10 for each hotdog)\n", delicious_cost);
                printf("Enter the number: ");
                scanf("%d", &action_choice);
                if((action_choice == 2 && own_dollars < speedup_cost) || (action_choice == 3 && own_dollars < delicious_cost)){
                    printf("Can't you tell how poor you are?\n");
                    printf("Go vending your hotdogs instead of thinking about self-improvement!\n");
                    action_choice = 1;
                    break;
                }
                else if(action_choice == 2 && made_time == 1){
                    printf("Do you want to travel through time?\n");
                    printf("GO WORK!!\n");
                    action_choice = 1;
                    break;
                }
                else if(action_choice <= 3 && action_choice >= 1) break;
                else printf("Invalid input!!!!\n");
            }

            switch(action_choice){
                case 1:
                    printf("You make %d hotdogs here!\n", (180 / made_time));
                    printf("You earn $%d!\n", income);
                    own_dollars += income;
                    earning += income;
                    break;
                case 2:
                    printf("You glimpse the secret of wind.\n");
                    printf("Your hands can move faster now.\n");
                    made_time--;
                    income = hot_dog_price * (180 / made_time);
                    own_dollars -= speedup_cost;
                    speedup_cost *= 2;
                    break;
                case 3:
                    printf("You feel the soul of the ingredients.\n");
                    printf("Your hotdogs are more appetizing now.\n");
                    hot_dog_price += 10;
                    income = hot_dog_price * (180 / made_time);
                    own_dollars -= delicious_cost;
                    delicious_cost *= 2;
                    break;
            }
        }
        
        printf("Well done, you earn $%d today.\n", earning);
        int is_continue;
        while(1){
            printf("Do you want to continue or exit?\n");
            printf("  [1] Continue\n");
            printf("  [2] Exit\n");
            printf("Enter the number: ");
            scanf("%d", &is_continue);
            if(is_continue == 1 || is_continue == 2) break;
            else{
                printf("Invalid input!!!!\n");
            }
        }

        if(is_continue == 2){
            printf("We will miss you. Bye!\n");
            break;
        }
    }
}