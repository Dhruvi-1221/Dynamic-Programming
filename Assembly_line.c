#include <stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int assemblyLine(int a[2][100], int t[2][100], int e[2], int x[2], int n) {
    int f1[100], f2[100];
    
    // Base case
    f1[0] = e[0] + a[0][0];
    f2[0] = e[1] + a[1][0];
    
    // DP 
    for(int i = 1; i < n; i++) {
        f1[i] = min(f1[i-1] + a[0][i],
                    f2[i-1] + t[1][i] + a[0][i]);
        f2[i] = min(f2[i-1] + a[1][i],
                    f1[i-1] + t[0][i] + a[1][i]);
    }
    
    return min(f1[n-1] + x[0], f2[n-1] + x[1]);
}

int main() {
    int n;
    int a[2][100], t[2][100];
    int e[2], x[2];
    for(int i = 0; i < 100; i++) {
        t[0][i] = 0;
        t[1][i] = 0;
    }
    printf("Enter number of stations: ");
    scanf("%d", &n);
    if(n < 1 || n > 100) {
        printf("Error: Number of stations must be between 1 and 100.\n");
        return 1;
    }
    printf("Enter processing time for line 1:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[0][i]);
    printf("Enter processing time for line 2:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[1][i]);
    if(n > 1) {
        printf("Enter %d transfer times from line 1 to line 2 (station 1 to %d):\n", n-1, n-1);
        for(int i = 1; i < n; i++)
            scanf("%d", &t[0][i]);
        printf("Enter %d transfer times from line 2 to line 1 (station 1 to %d):\n", n-1, n-1);
        for(int i = 1; i < n; i++)
            scanf("%d", &t[1][i]);
    }
    printf("Enter entry time for line 1: ");
    scanf("%d", &e[0]);
    printf("Enter entry time for line 2: ");
    scanf("%d", &e[1]);
    printf("Enter exit time for line 1: ");
    scanf("%d", &x[0]);
    printf("Enter exit time for line 2: ");
    scanf("%d", &x[1]);
    
    int result = assemblyLine(a, t, e, x, n);
    printf("\nMinimum time = %d\n", result);
    
    return 0;
}
