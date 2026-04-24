#include<stdio.h>
#include<limits.h>

    void coinchange(int n,int *a1,int a){
        int arr[1+a];
        arr[0]=0;
        for(int i=1;i<=a;i++){
            arr[i]=INT_MAX;
        }
        for(int i=0;i<n;i++){
            for(int j=a1[i];j<=a;j++){
                if(arr[j - a1[i]] != INT_MAX && arr[j - a1[i]] + 1 < arr[j])
                    arr[j] = arr[j - a1[i]] + 1;
            }
        }
        if(arr[a] == INT_MAX)
        printf("No solution\n");
        else
        printf("Minimum coins: %d\n", arr[a]); 
    }

    int main(){
        // number of array
        int n;
        printf("Enter the numbers of coins: ");
        scanf("%d",&n);
        // arr that store coin
        int arr[n];
        printf("\nEnter coins: ");
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        //amount
        int amount;
        printf("Enter amount: ");
        scanf("%d",&amount);

        coinchange(n,arr,amount);
        return 0;
    }
