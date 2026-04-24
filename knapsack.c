      #include<stdio.h>

      void knapsack(int n,int W,int *w,int *p){
        int arr[n+1][W+1];
        for (int i=0;i<=n;i++){
            for(int j=0;j<=W;j++){
                arr[i][j]=0;
            }
        }
        for (int i=1;i<=n;i++){
            for(int j=1;j<=W;j++){
                if (w[i-1]>j){
                    arr[i][j]=arr[i-1][j];
                }
                else{
                    arr[i][j]=(p[i-1]+arr[i-1][j-w[i-1]]>arr[i-1][j])? p[i-1]+arr[i-1][j-w[i-1]]:arr[i-1][j];
                }
            }
        }
        printf("Max profit: %d\n",arr[n][W]);
        int j=W;
        for (int i=n;i>=1;i--){
            if(arr[i][j]!=arr[i-1][j]){
                printf("Item %d (weight %d profit%d)\n",i,w[i-1],p[i-1]);
                j=j-w[i-1];
            }
        }
    }

    int main(){
        int n;
        printf("Enter the number of item: ");
        scanf("%d",&n);
        int weight[n] ,profit[n];
        printf("\nEnter weight and profit for all %d item\n",n);
        for (int i=0;i<n;i++){
            scanf("%d",&weight[i]);
            scanf("%d",&profit[i]);
        }
        int w;
        printf("\nEnter capacity of knapsack: ");
        scanf("%d",&w);
        knapsack(n,w,&weight[0],&profit[0]);
        return 0;
    }
