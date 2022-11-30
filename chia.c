#include<stdio.h>
#include<stdlib.h>
int arraysum(int a[],int n){
    int i,sum=0;
    for(i=0;i<n;i++){
        sum+=a[i];
    }
    return sum;
}
 
int main(){
    int a; //幾堆方塊
    int c;//平均數
    scanf("%d",&a);
    int foo[a];
    int m=0;
    int n=0;
    int ans[m];
    while(a!=0){
        for(int i=0;i<a;i++){
            scanf("%d",&foo[i]);
        }
        c=arraysum(foo,a)/a;
        for(int j=0;j<a;j++){
            if(foo[j]>c){
                n=n+foo[j]-c;
            }
        }
        ans[m]=n;
        m+=1;
        scanf("%d",&a);
    }
    for(int i=0;i<m;i++){
        if(i==0){
            printf("Set #1\n");
            printf("The minimum number of moves is ");
            printf("%d.\n",ans[i]);
        }
        else if(i>0&&i<m-1){
            printf("\nSet #%d\n",i+1);
            printf("The minimum number of moves is ");
            printf("%d.\n",ans[i]);
        }
        else{
            printf("\nSet #%d\n",i+1);
            printf("The minimum number of moves is ");
            printf("%d.\n",ans[i]);
        }
    }
}

