#include<stdio.h>
int main (){
    int sell_or_enhance,continue_or_exit=1;
    int today_income=0,dollar=100,minute=15,price=30,speed_tuition=50,delicious_tuition=100;
    printf("Welcome, young boss!\n");
    
    while(continue_or_exit==1){
        printf("Chop chop, It's dawn.\n");
            today_income=0;
        for(int area=1;area<5;area++){
            
            printf("You are at Area %d.\nYou have %d dollars.\nYou need %d minutes to make a hotdog.\nThe price of a hotdog is $%d.\n",area,dollar,minute,price);
            printf("Please choose which action you want to take:\n");
            printf("  [1] Sell the hotdogs (+ $%d)\n  [2] Improve your cooking speed (- $%d / - 1 min for making a hotdog)\n  [3] Improve your hotdog flavor (- $%d / + $10 for each hotdog)\nEnter the number: ",(price*(180/minute)),speed_tuition,delicious_tuition);
            scanf("%d",&sell_or_enhance);

            while(sell_or_enhance>3||sell_or_enhance<1){
                printf("Invalid input!!!!\n");
                printf("  [1] Sell the hotdogs (+ $%d)\n  [2] Improve your cooking speed (- $%d / - 1 min for making a hotdog)\n  [3] Improve your hotdog flavor (- $%d / + $10 for each hotdog)\nEnter the number: ",(price*(180/minute)),speed_tuition,delicious_tuition);
                scanf("%d",&sell_or_enhance);
            }
            switch (sell_or_enhance){
                case 1:
                    printf("You make %d hotdogs here!\nYou earn $%d!\n",(180/minute),(price*(180/minute)));
                    dollar+=(price*(180/minute));
                    today_income+=(price*(180/minute));
                    break;

                case 2:
                    if(dollar<speed_tuition){
                        printf("Can't you tell how poor you are?\nGo vending your hotdogs instead of thinking about self-improvement!\n");//檢查測資到底要不要換行
                        printf("You make %d hotdogs here!\nYou earn $%d!\n",(180/minute),(price*(180/minute)));
                        dollar+=(price*(180/minute));
                        today_income+=(price*(180/minute));
                        break;
                    }
                    if(minute==1){
                        printf("Do you want to travel through time?\nGO WORK!!\n");
                    }
                    else{
                        minute--;
                        dollar-=speed_tuition;
                        speed_tuition*=2;
                        printf("You glimpse the secret of wind.\nYour hands can move faster now.\n");
                    }
                    break;

                case 3:
                    if(dollar<delicious_tuition){
                        printf("Can't you tell how poor you are?\nGo vending your hotdogs instead of thinking about self-improvement!\n");//檢查測資到底要不要換行
                        printf("You make %d hotdogs here!\nYou earn $%d!\n",(180/minute),(price*180/minute));
                        dollar+=(price*(180/minute));
                        today_income+=(price*180/minute);
                        break;
                    }
                    else{
                        price+=10;
                        dollar-=delicious_tuition;
                        delicious_tuition*=2;
                        printf("You feel the soul of the ingredients.\nYour hotdogs are more appetizing now.\n");
                    }
                    break;
    
            }
        }
        printf("Well done, you earn $%d today.\n",today_income);
        printf("Do you want to continue or exit?\n  [1] Continue\n  [2] Exit Enter the number: ");
        scanf("%d",&continue_or_exit);
        while(continue_or_exit>2||continue_or_exit<1){
            printf("Invalid input!!!!\n");
            printf("Do you want to continue or exit?\n  [1] Continue\n  [2] Exit Enter the number: ");
            scanf("%d",&continue_or_exit);
        }
        if(continue_or_exit!=1){
            printf("We will miss you. Bye!\n");
            break;
        }
    }
}