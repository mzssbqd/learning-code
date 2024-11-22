    #include <iostream>

    using namespace std;

    #define MAX_N 8
    int arr[MAX_N + 5];

    void print(int step)
    {
        if(step == 1) return;
        for(int i = 0; i < step;i++)
        {
            printf("%d",arr[i]);
            if(i != step -1) printf("+");
        }
        printf("\n");
        return;
    }
    void dfs(int n,int sum,int step)
    {
        if(n == 0)
        {
            print(step);
            return;
        }
        if(sum > n) return ;
        for(int i = sum; i <= n;i++)
        {
            arr[step] = i;
            dfs(n - i, i , step + 1);
        }
    }
    int main()
    {
        int n;
        cin>>n;
        dfs(n,1,0);
        return 0;
    }