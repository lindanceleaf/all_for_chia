#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void start_game(){
    printf("Welcome, young boss!\n");
}

void start_every_day(int dollars, int make_time, int price, int booster[3]){
    printf("Chop chop, It's dawn.\n");
    printf("You have %d dollars.\n", dollars);
    printf("You need %d minutes to make a hotdog.\n", make_time);
    printf("The price of a hotdog is $%d.\n", price);
    printf("You have %d speed booster(s), %d price booster(s), %d area booster(s).\n", booster[0], booster[1], booster[2]);
}

void invalid_input(){
    printf("Invalid input!!!!\n");
}

void choosing_booster(bool is_open[3]){
    printf("Open/Close boosters:\n");
    printf("  [1] Speed booster (now %s)\n", is_open[0] ? "open" : "close");
    printf("  [2] Price booster (now %s)\n", is_open[1] ? "open" : "close");
    printf("  [3] Area  booster (now %s)\n", is_open[2] ? "open" : "close");
    printf("  [4] Finish\n");
    printf("Enter the number(s): ");
}

void choosing_actions(int speed_cost, int flavor_cost){
    printf("Actions you can take for each area:\n");
    printf("  [1] Sell the hotdogs\n");
    printf("  [2] Improve your cooking speed\n");
    printf("      (- $%d, - $%d, - $%d, - $%d for next four upgrades)\n", speed_cost, speed_cost * 2, speed_cost * 4, speed_cost * 8);
    printf("  [3] Improve your hotdog flavor\n");
    printf("      (- $%d, - $%d, - $%d, - $%d for next four upgrades)\n", flavor_cost, flavor_cost * 2, flavor_cost * 4, flavor_cost * 8);
    printf("Enter the number(s): ");
}

void reentering_for_actions(int area){
    printf("Actions you can take at Area %d:\n", area);
    printf("  [1] Sell the hotdogs\n");
    printf("  [2] Improve your cooking speed\n");
    printf("  [3] Improve your hotdog flavor\n");
    printf("Enter the number(s): ");
}

void end_of_actions(int earn){
    printf("Well done, you earn $%d today.\n", earn);
}

void choosing_result_of_area(int areas_num){
    printf("Which result of the area you want to check?\n");
    for(int i = 1; i <= areas_num; i++){
        printf("  [%d] Area %d\n", i, i);
    }
    printf("  [%d] Done\n", areas_num + 1);
    printf("Enter the number(s): ");
}

void poor(){
    printf("Can't you tell how poor you are?\n");
    printf("Go vending your hotdogs instead of thinking about self-improvement!\n");
}

void cannot_faster(){
    printf("Do you want to travel through time?\n");
    printf("GO WORK!!\n");
}

void vending_hotdog(int hotdog, int earn){
    printf("You make %d hotdogs here!\n", hotdog);
    printf("You earn $%d!\n", earn);
}

void improve_speed(){
    printf("You glimpse the secret of wind.\n");
    printf("Your hands can move faster now.\n");
}

void improve_flavor(){
    printf("You feel the soul of the ingredients.\n");
    printf("Your hotdogs are more appetizing now.\n");
}

void whether_continue_the_game(){
    printf("Do you want to continue or exit?\n");
    printf("  [1] Continue\n");
    printf("  [2] Exit\n");
    printf("Enter the number(s): ");
}

void get_free_lottery(){
    printf("You get one free choice.\n");
}

void border_line(int size, int digit){
    printf("+");
    for(int i = 0; i < size; i++){
        for(int j = 0; j < digit + 2; j++){
            printf("-");
        }
        printf("+");
    }
    printf("\n");
}

void no_money_for_choosing(){
    printf("You have no money!\n");
}

void print_lottery(int size, bool **data){
    int digit = 0;
    int temp = size * size;
    while(temp){
        digit ++;
        temp /= 10;
    }
    
    border_line(size, digit);
    for(int i = 0; i < size; i++){
        printf("|");
        for(int j = 0; j < size; j++){
            if(data[i][j] == 0){
                printf(" %*d |", digit, (i * size) + j + 1);
            }
            else{
                printf(" %*c |", digit, 'x');
            }
        }
        printf("\n");
        border_line(size, digit);
    }
}

void choosing_grid(int cost){
    printf("You can choose\n");
    printf("  [number on cell] to open (- $%d)\n", cost);
    printf("  [0] to continue the game\n");
    printf("Enter the number(s): ");
}

void get_prize_1(int earn){
    printf("Fortune, fortune! You get $%d!\n", earn);
}

void get_prize_2(){
    printf("You get an extra choice!\n");
}

void get_prize_3_to_6(int place){
    printf("Another open on %d!\n", place);
}

void get_prize_7_to_9(){
    printf("You get a booster!!\n");
}

void fail_to_open(){
    printf("Bad Luck :(\n");
}

void end_of_game(){
    printf("We will miss you. Bye!\n");
}

int turn_to_prize_type(int number){
    int reverse_number = 0;
    while(number){
        reverse_number *= 10;
        reverse_number += (number % 10);
        number /= 10;
    }

    int weight = 1;
    int final_number = 0;
    while(reverse_number){
        final_number += ((reverse_number % 10) * weight);
        reverse_number /= 10;
        weight *= 16;
    }
    
    return final_number % 9 + 1;
}

int main(){
    int dollars = 100;
    int time_for_making_hotdog = 15;
    int hotdog_price = 30;
    int booster_num[3] = {0};
    int speed_cost = 50, flavor_cost = 100;
    int lottery_size = 3;
    int free_lottery = 0;
    bool **lottery_data = malloc(lottery_size * sizeof(bool *));
    for(int i = 0; i < lottery_size; i++) lottery_data[i] = calloc(lottery_size, sizeof(bool));
    int used_lottery_cnt = 0;
    int lottery_cost = 500;
    bool yesterday_booster[3] = {false};

    // start game
    start_game();

    while(1){
        // start a day
        start_every_day(dollars, time_for_making_hotdog, hotdog_price, booster_num);

        // ask whether open the boosters
        bool booster_is_open[3];
        for(int i = 0; i < 3; i++) booster_is_open[i] = yesterday_booster[i];
        int booster_choice;
        while(1){
            choosing_booster(booster_is_open);
            scanf("%d", &booster_choice);
            // only 1~4 can scanf as usual or invalid input
            if(booster_choice <= 3 && booster_choice >= 1){
                booster_choice--; // to let choice's and booster's number are the same
                booster_is_open[booster_choice] = !booster_is_open[booster_choice];
            }
            else if(booster_choice == 4) break;
            else invalid_input();
        }

        for(int i = 0; i < 3; i++) yesterday_booster[i] = booster_is_open[i];

        // to avoid open booster without having none
        for(int i = 0; i < 3; i++){
            booster_is_open[i] = booster_is_open[i] && booster_num[i];
            if(booster_is_open[i]) booster_num[i]--;
        }

        // ask actions to areas
        int area_actions[5] = {0, 0, 0, 0, 1};
        int areas_num = 4;
        if(booster_is_open[2]) areas_num = 5;
        choosing_actions(speed_cost, flavor_cost);
        for(int i = 0; i < 4; i++) scanf("%d", &area_actions[i]);
        while(1){
            bool areas_ckecker[4] = {false}; // to ckeck whether every area is input valid
            bool is_all_valid = true;
            for(int i = 0; i < 4; i++){
                if(area_actions[i] >= 1 && area_actions[i] <= 3) areas_ckecker[i] = true;
                else is_all_valid = false;
            }
            if(is_all_valid) break;
            else{
                for(int i = 0; i < 4; i++){
                    if(areas_ckecker[i] == false){
                        invalid_input();
                        reentering_for_actions(i+1);
                        scanf("%d", &area_actions[i]);
                    }
                }
            }
        }

        // do every action and record
        int earn_money[5] = {0};
        int sell_hotdog[5] = {0};
        int all_earn = 0;
        bool error_code[5] = {0};
        for(int i = 0; i < areas_num; i++){
            if(area_actions[i] == 1){ // vending hotdogs
                sell_hotdog[i] = 180 / time_for_making_hotdog;
                if(booster_is_open[0]) sell_hotdog[i] *= 2;
                earn_money[i] = hotdog_price * sell_hotdog[i];
                if(booster_is_open[1]) earn_money[i] *= 2;
                
                all_earn += earn_money[i];
                dollars += earn_money[i];
            }
            else if(area_actions[i] == 2){ // improve making speed
                if(dollars >= speed_cost && time_for_making_hotdog > 1){
                    dollars -= speed_cost;
                    speed_cost *= 2;
                    time_for_making_hotdog--;
                }
                else{
                    if(time_for_making_hotdog == 1) error_code[i] = 1; // 0 for no money to do
                    sell_hotdog[i] = 180 / time_for_making_hotdog;
                    if(booster_is_open[0]) sell_hotdog[i] *= 2;
                    earn_money[i] = hotdog_price * sell_hotdog[i];
                    if(booster_is_open[1]) earn_money[i] *= 2;
                    all_earn += earn_money[i];
                    dollars += earn_money[i];
                }
            }
            else if(area_actions[i] == 3){ // improve hotdogs' flavor
                if(dollars >= flavor_cost){
                    dollars -= flavor_cost;
                    flavor_cost *= 2;
                    hotdog_price += 10;
                }
                else{
                    sell_hotdog[i] = 180 / time_for_making_hotdog;
                    if(booster_is_open[0]) sell_hotdog[i] *= 2;
                    earn_money[i] = hotdog_price * sell_hotdog[i];
                    if(booster_is_open[1]) earn_money[i] *= 2;
                    all_earn += earn_money[i];
                    dollars += earn_money[i];
                }
            }
        }

        // output the earn money
        end_of_actions(all_earn);

        // ask to check the result of area
        int result_choice;
        while(1){
            choosing_result_of_area(areas_num);
            scanf("%d", &result_choice);
            if(result_choice == areas_num + 1) break;
            else if(!(result_choice >= 1 && result_choice <= areas_num)) invalid_input();
            else{
                result_choice--; // to let the number and areas number are the same
                if(area_actions[result_choice] == 1) vending_hotdog(sell_hotdog[result_choice], earn_money[result_choice]);
                else if(area_actions[result_choice] == 2){
                    if(earn_money[result_choice] == 0){ // 0 represent the action is able not turn to sell hotdog
                        improve_speed();
                    }
                    else{
                        if(error_code[result_choice]){
                            cannot_faster();
                            vending_hotdog(sell_hotdog[result_choice], earn_money[result_choice]);
                        }
                        else{
                            poor();
                            vending_hotdog(sell_hotdog[result_choice], earn_money[result_choice]);
                        }
                    }
                }
                else if(area_actions[result_choice] == 3){
                    if(earn_money[result_choice] == 0){ // 0 represent the action is able not turn to sell hotdog.
                        improve_flavor();
                    }
                    else{
                        poor();
                        vending_hotdog(sell_hotdog[result_choice], earn_money[result_choice]);
                    }
                }
            }
        }

        // decide whether continue the game
        int continue_choice;
        while(1){
            whether_continue_the_game();
            scanf("%d", &continue_choice);
            if(continue_choice == 1 || continue_choice == 2) break;
            else invalid_input();
        }
        if(continue_choice == 2) break;

        // start lottery
        get_free_lottery();
        free_lottery++;
        while(1){
            // change size
            if(used_lottery_cnt == lottery_size * lottery_size){
                lottery_size += 2;
                lottery_data = realloc(lottery_data, lottery_size * sizeof(bool *));
                for(int i = 0; i < lottery_size; i++) lottery_data[i] = calloc(lottery_size, sizeof(bool));
                used_lottery_cnt = 0;
                lottery_cost = 500;
            }

            int grid_choice;
            int row, column;
            while(1){
                print_lottery(lottery_size, lottery_data);

                if(free_lottery) choosing_grid(0);  
                else choosing_grid(lottery_cost);

                scanf("%d", &grid_choice);
                grid_choice--; // to feat the number in the array
                row = grid_choice / lottery_size;
                column = grid_choice % lottery_size;
                if((grid_choice >= -1 && lottery_data[row][column] == 0)) break;
                else invalid_input();
            }

            if(grid_choice == -1) break;
            else if(free_lottery) free_lottery--;
            else if(dollars < lottery_cost){
                no_money_for_choosing();
                break;
            }
            else{
                dollars -= lottery_cost;
                lottery_cost += 500;
            }

            bool is_lottery_end = false;
            while(!is_lottery_end){
                lottery_data[row][column] = true;
                used_lottery_cnt++;
                int final_prize = turn_to_prize_type(row * lottery_size + column + 1);
                int earn_money;
                switch(final_prize){
                    case 1:
                        earn_money = 100 * hotdog_price;
                        dollars += earn_money;
                        get_prize_1(earn_money);
                        is_lottery_end = true;
                        break;
                    case 2:
                        free_lottery++;
                        get_prize_2();
                        is_lottery_end = true;
                        break;
                    case 3:
                        if(row == lottery_size - 1) row = 0;
                        else row++;
                        if(lottery_data[row][column]){ // if that == 1, that is opened
                            fail_to_open();
                            is_lottery_end = true;
                        }
                        else get_prize_3_to_6(row * lottery_size + column + 1);
                        break;
                    case 4:
                        if(row == 0) row = lottery_size - 1;
                        else row--;
                        if(lottery_data[row][column]){ // if that == 1, that is opened
                            fail_to_open();
                            is_lottery_end = true;
                        }
                        else get_prize_3_to_6(row * lottery_size + column + 1);
                        break;
                    case 5:
                        if(column == 0) column = lottery_size - 1;
                        else column--;
                        if(lottery_data[row][column]){ // if that == 1, that is opened
                            fail_to_open();
                            is_lottery_end = true;
                        }
                        else get_prize_3_to_6(row * lottery_size + column + 1);
                        break;
                    case 6:
                        if(column == lottery_size - 1) column = 0;
                        else column++;
                        if(lottery_data[row][column]){ // if that == 1, that is opened
                            fail_to_open();
                            is_lottery_end = true;
                        }
                        else get_prize_3_to_6(row * lottery_size + column + 1);
                        break;
                    case 7: case 8: case 9:
                        booster_num[final_prize - 7]++;
                        get_prize_7_to_9();
                        is_lottery_end = true;
                        break;
                }
            }
        }
    }
    end_of_game();
}