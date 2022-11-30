#include <stdio.h>

int is_leap_year(int year){
    if(year % 400 == 0 || year % 100 && year % 4 == 0) return 1;
    else return 0;
}

int month_date(int year, int month){
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            if(is_leap_year(year)) return 29;
            else return 28;
    }
}

int main(){
    long long int year, month, date;
    scanf("%lld/%lld/%lld", &year, &month, &date);

    int interval = 0;
    int cnt = 0;
    int data;
    while(scanf("%d", &data) != EOF){
        interval += data;
        cnt ++;
    }
    interval /= cnt;
    
    date += interval;
    while(month > 1){
        date += month_date(year, month - 1);
        month --;
    }

    // to get the correct year
    while(1){
        if(is_leap_year(year) && date > 366){
            year ++;
            month = 1;
            date -= 366;
        }
        else if(!is_leap_year(year) && date > 365){
            year ++;
            month = 1;
            date -= 365;
        }
        else break;
    }

    // to get the correct month
    while(1){
        int the_month_date = month_date(year, month);
        if(date > the_month_date){
            month ++;
            date -= the_month_date;
        }
        else break;
    }

    printf("%4lld/%02lld/%2lld\n", year, month, date);
}