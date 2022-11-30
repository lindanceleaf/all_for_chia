#include<stdio.h>

void game_begins(){
    printf("Welcome, young boss!\n");
}

void each_day_begin(int dollars_of_young_boss,int minutes_of_making_a_hotdog,int price_of_hotdog,int amounts_of_speed_booster,int amounts_of_prize_booster,int amounts_of_area_booster){
    printf("Chop chop, It's dawn.\n");
    printf("You have %d dollars.\n",dollars_of_young_boss );
    printf("You need %d minutes to make a hotdog.\n",minutes_of_making_a_hotdog);
    printf("The price of a hotdog is $%d.\n",price_of_hotdog);
    printf("You have %d speed booster(s), %d price booster(s), %d area booster(s).\n",amounts_of_speed_booster,amounts_of_prize_booster,amounts_of_area_booster);
}

void invalid_for_all_input(){
    printf("Invalid input!!!!\n");
}

void choose_booster(_Bool a,_Bool b,_Bool c){
    printf("Open/Close boosters:\n");
    if(a)printf("  [1] Speed booster (now open)\n");
    else printf("  [1] Speed booster (now close)\n");//without bracket, the poer of else will only last before senni common
    if(b)printf("  [2] Price booster (now open)\n"); // if booster open
    else printf("  [2] Price booster (now close)\n");
    if(c)printf("  [3] Area  booster (now open)\n"); // if booster open
    else printf("  [3] Area  booster (now close)\n");
    printf("  [4] Finish\n");
    printf("Enter the number(s): ");
}

void choose_action(int tuition_of_cooking_speed,int tution_of_hotgog_flavor){
    printf("Actions you can take for each area:\n");
    printf("  [1] Sell the hotdogs\n");
    printf("  [2] Improve your cooking speed\n");
    printf("      (- $%d, - $%d, - $%d, - $%d for next four upgrades)\n",tuition_of_cooking_speed,tuition_of_cooking_speed*2,tuition_of_cooking_speed*4,tuition_of_cooking_speed*8);
    printf("  [3] Improve your hotdog flavor\n");
    printf("      (- $%d, - $%d, - $%d, - $%d for next four upgrades)\n",tution_of_hotgog_flavor,tution_of_hotgog_flavor*2,tution_of_hotgog_flavor*4,tution_of_hotgog_flavor*8);
    printf("Enter the number(s): ");
}

void re_enter_action(int re_enter_area){//check this variable
    printf("Actions you can take at Area %d:\n",re_enter_area);
    printf("  [1] Sell the hotdogs\n");
    printf("  [2] Improve your cooking speed\n");
    printf("  [3] Improve your hotdog flavor\n");
    printf("Enter the number(s): ");
}

void end_of_income_a_day(int daily_income){
    printf("Well done, you earn $%d today.\n",daily_income);
}

void end_of_actions_a_day(_Bool area_booster_switch,int c){
    printf("Which result of the area you want to check?\n");
    printf("  [1] Area 1\n");
    printf("  [2] Area 2\n");
    printf("  [3] Area 3\n");
    printf("  [4] Area 4\n");
    if((area_booster_switch)&&(c)){
        printf("  [5] Area 5\n");
        printf("  [6] Done\n"); 
    }
    else{
        printf("  [5] Done\n");
    }   
    printf("Enter the number(s): ");
}

void lack_of_money_to_upgrade_message(){
    printf("Can't you tell how poor you are?\n");
    printf("Go vending your hotdogs instead of thinking about self-improvement!\n");
}

void connot_reduce_any_time_message(){
    printf("Do you want to travel through time?\n");
    printf("GO WORK!!\n");
}

void speed_upgrade_message(){
    printf("You glimpse the secret of wind.\n");
    printf("Your hands can move faster now.\n");
}

void taste_upgrade_message(){
    printf("You feel the soul of the ingredients.\n");
    printf("Your hotdogs are more appetizing now.\n");
}

void sell_hotdog_message(int minutes_of_making_a_hotdog,int price_of_hotdog){
    printf("You make %d hotdogs here!\n",180/minutes_of_making_a_hotdog);
    printf("You earn $%d!\n",price_of_hotdog*(180/minutes_of_making_a_hotdog));
}

void continue_or_not(){
    printf("Do you want to continue or exit?\n");
    printf("  [1] Continue\n");
    printf("  [2] Exit\n");
    printf("Enter the number(s): ");
}

void continue_so_get_one_free_lottey_choice(){
    printf("You get one free choice.\n");
}

void choose_cell_on_lottery_table(int prize_of_lottery){
    printf("You can choose\n");
    printf("  [number on cell] to open (- $%d)\n",prize_of_lottery);
    printf("  [0] to continue the game\n");
    printf("Enter the number(s): ");
}

void no_money_to_choose(){
    printf("You have no money!\n");
}

void prize_type_1(int prize_type_1){//check its number
    printf("Fortune, fortune! You get $%d!\n",prize_type_1);
}

void prize_type_2(){
    printf("You get an extra choice!\n");
}

void prize_type_3to6_success(int another_open){//
    printf("Another open on %d!\n",another_open);
}

void prize_type_3to6_failed(){
    printf("Bad Luck :(\n");
}

void prize_type_7to9(){
    printf("You get a booster!!\n");
}

void end_game(){
    printf("We will miss you. Bye!\n");
}

void work_sell_hotdog(int *daily_income, int *dollars_of_young_boss, int minutes_of_making_a_hotdog, int price_of_hotdog){
    *daily_income+=(180/(minutes_of_making_a_hotdog)*(price_of_hotdog));
    *dollars_of_young_boss+=(180/(minutes_of_making_a_hotdog)*(price_of_hotdog));
}

void upgrade_speed(int *dollars_of_young_boss,int *tuition_of_cooking_speed, int *minutes_of_making_a_hotdog){
    *dollars_of_young_boss-=(*tuition_of_cooking_speed);
    *tuition_of_cooking_speed*=2;
    *minutes_of_making_a_hotdog--;
}

void upgrade_flavor(int *dollars_of_young_boss,int *tuition_of_hotdog_flavor, int *price_of_hotdog){
    *dollars_of_young_boss-=*tuition_of_hotdog_flavor;
    *tuition_of_hotdog_flavor*=2;
    *price_of_hotdog+=10;
}

/*void computing_daily_income(int a,int b,int c,int d,_Bool area_booster_switch,int *amounts_of_area_booster,int *daily_income,int *minute_of_making_a_hotdog, int *price_of_hotdog,int *dollars_of_young_boss,int *tuition_of_cooking_speed,int *tuition_of_hotdog_flavor){
    int area[4]={a,b,c,d};
    for(int i=0;i<4;i++){
        int temp=area[i];
        switch(area[i]){
            case 1:
                *daily_income+=180/(*minute_of_making_a_hotdog)*(*price_of_hotdog);
                *dollars_of_young_boss+=180/(*minute_of_making_a_hotdog)*(*price_of_hotdog);
                break;
            case 2:
                *dollars_of_young_boss-=*tuition_of_cooking_speed;
                *tuition_of_cooking_speed*=2;
                *minute_of_making_a_hotdog--;
                break;
            case 3:
                *dollars_of_young_boss-=*tuition_of_hotdog_flavor;
                *tuition_of_hotdog_flavor*=2;
                *price_of_hotdog+=10;
                break;
        }
    }
    if((area_booster_switch)&&(*amounts_of_area_booster)){
        daily_income+=180/(*minute_of_making_a_hotdog)*(*price_of_hotdog);
        *amounts_of_area_booster--;
    }
    
}*/

int main(){
    int dollars_of_young_boss=100,minutes_of_making_a_hotdog=15,price_of_hotdog=30;
    int amounts_of_speed_booster=5,amounts_of_price_booster=5,amounts_of_area_booster=5;
    int tuition_of_cooking_speed=50,tuition_of_hotdog_flavor=100;
    _Bool booster_switch[4]={0};
    int daily_income=0;
    int continue_or_not_choice=1;
    int booster_choice=0,area_result_check=0,area_result_temp[6][6]={0};
    int area[6];
    game_begins();
    while(continue_or_not_choice==1){
        daily_income=0;
        each_day_begin(dollars_of_young_boss,minutes_of_making_a_hotdog,price_of_hotdog,amounts_of_speed_booster,amounts_of_price_booster,amounts_of_area_booster);
        booster_choice=0;
        while(booster_choice!=4){
            choose_booster(booster_switch[0],booster_switch[1],booster_switch[2]);
            scanf("%d",&booster_choice);
            if((booster_choice>=1)&&(booster_choice<=3)){
                booster_switch[booster_choice-1]=!booster_switch[booster_choice-1];
            }
            else if((booster_choice>4)||(booster_choice<1)){
                invalid_for_all_input();
            }
        }
        choose_action(tuition_of_cooking_speed,tuition_of_hotdog_flavor);
        scanf("%d%d%d%d",&area[0],&area[1],&area[2],&area[3]);//Invalid Input system haven't been implemented!!!
        for(int i=0;i<4;i++){
            while((area[i]<1)||(area[i]>3)){
                invalid_for_all_input();
                re_enter_action(i+1);
                scanf("%d",&area[i]);
            }
        }
        
        for(int i=0;i<4;i++){
                area_result_temp[i][0]=minutes_of_making_a_hotdog;
                area_result_temp[i][1]=price_of_hotdog;
                area_result_temp[i][2]=dollars_of_young_boss;
                area_result_temp[i][3]=tuition_of_cooking_speed;
                area_result_temp[i][4]=tuition_of_hotdog_flavor;
            switch(area[i]){
                case 1:
                    work_sell_hotdog(&daily_income,&dollars_of_young_boss,minutes_of_making_a_hotdog,price_of_hotdog);
                    break;
                case 2:
                    if((dollars_of_young_boss>=tuition_of_cooking_speed)&&(minutes_of_making_a_hotdog>1)){
                        upgrade_speed(&dollars_of_young_boss,&tuition_of_cooking_speed,&minutes_of_making_a_hotdog);
                        
                    }
                    else if(dollars_of_young_boss<tuition_of_cooking_speed){
                        work_sell_hotdog(&daily_income,&dollars_of_young_boss,minutes_of_making_a_hotdog,price_of_hotdog);
                    }
                    else{
                        work_sell_hotdog(&daily_income,&dollars_of_young_boss,minutes_of_making_a_hotdog,price_of_hotdog);
                    } 
                    break;
                case 3:
                    if(dollars_of_young_boss>=tuition_of_hotdog_flavor){
                        upgrade_flavor(&dollars_of_young_boss,&tuition_of_cooking_speed,&price_of_hotdog);
                    }
                    else{
                        work_sell_hotdog(&daily_income,&dollars_of_young_boss,minutes_of_making_a_hotdog,price_of_hotdog);
                    }
                    break;
            }
        }
            if((booster_switch[2])&&(amounts_of_area_booster)){
                area_result_temp[4][0]=minutes_of_making_a_hotdog;
                area_result_temp[4][1]=price_of_hotdog;
                area_result_temp[4][2]=dollars_of_young_boss;
                area_result_temp[4][3]=tuition_of_cooking_speed;
                area_result_temp[4][4]=tuition_of_hotdog_flavor;
                work_sell_hotdog(&daily_income,&dollars_of_young_boss,minutes_of_making_a_hotdog,price_of_hotdog);
                area_result_temp[4][5]=amounts_of_area_booster;
                amounts_of_area_booster--;
                area[4]=1;
            }
        
        end_of_income_a_day(daily_income);
        
        while(1){
            end_of_actions_a_day(booster_switch[2],amounts_of_area_booster);
            scanf("%d",&area_result_check);
            
            if((booster_switch[2])&&(area_result_temp[4][5])){
                if(area_result_check==6){
                    break;
                }
                else if((area_result_check>6)||(area_result_check<1)){
                    invalid_for_all_input();
                    continue;
                }
            }
            else {
                if(area_result_check==5){
                    break;
                }
                if((area_result_check>5)||(area_result_check<1)){
                    invalid_for_all_input();
                    continue;
                }
            }
            
            switch(area[area_result_check-1]){
                
                case 1:
                    sell_hotdog_message(area_result_temp[area_result_check-1][0],area_result_temp[area_result_check-1][1]);
                    break;
                case 2:
                    if((area_result_temp[area_result_check-1][2]>=area_result_temp[area_result_check-1][3])&&(area_result_temp[area_result_check-1][0]>1)){
                        speed_upgrade_message();
                    }
                    else if(area_result_temp[area_result_check-1][2]<area_result_temp[area_result_check-1][3]){
                        lack_of_money_to_upgrade_message();
                        sell_hotdog_message(area_result_temp[area_result_check-1][0],area_result_temp[area_result_check-1][1]);
                    }
                    else{
                        connot_reduce_any_time_message();
                        sell_hotdog_message(area_result_temp[area_result_check-1][0],area_result_temp[area_result_check-1][1]);
                    } 
                    break;
                case 3:
                    if(area_result_temp[area_result_check-1][2]>=area_result_temp[area_result_check-1][4]){
                        taste_upgrade_message();
                    }
                    else{
                        lack_of_money_to_upgrade_message();
                        sell_hotdog_message(area_result_temp[area_result_check-1][0],area_result_temp[area_result_check-1][1]);
                    }
                    break;
                default:
                    break;
            }
        }
        continue_or_not();
        scanf("%d",&continue_or_not_choice);
    }
    end_game();
    return 0;
}


