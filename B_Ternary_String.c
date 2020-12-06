#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void cal(int n, char *a, int dp[n][5], int i)
{
    if (i == n)
    {
        return;
    }
    dp[i][1] = dp[i - 1][1];
    dp[i][2] = dp[i - 1][2];
    dp[i][3] = dp[i - 1][3];
    dp[i][4] = dp[i - 1][4];
    dp[i][((int)(a[i] - 48))]++;
    dp[i][4]++;
    while (1)
    {
        if (dp[i][((int)(a[i - dp[i][4] + 1] - 48))] > 1)
        {
            dp[i][((int)(a[i - dp[i][4] + 1] - 48))]--;
            dp[i][4]--;
        }
        else
        {
            break;
        }
    }
    if (dp[i][1] >= 1 && dp[i][2] >= 1 && dp[i][3] >= 1)
    {
        dp[i][0] = dp[i][4];
    }
    cal(n, a, dp, i + 1);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        char a[200000];
        scanf("%s", a);
        int n = strlen(a);
        int dp[n][5];
        for (size_t i = 0; i < n; i++)
        {
            for (size_t i1 = 0; i1 < 5; i1++)
            {
                dp[i][i1] = 0;
            }
        }
        dp[0][((int)(a[0] - 48))]++;
        dp[0][4] = 1;

        for (size_t i = 1; i < n; i++)
        {
            dp[i][1] = dp[i - 1][1];
            dp[i][2] = dp[i - 1][2];
            dp[i][3] = dp[i - 1][3];
            dp[i][4] = dp[i - 1][4];
            dp[i][((int)(a[i] - 48))]++;
            dp[i][4]++;
            while (1)
            {
                if (dp[i][((int)(a[i - dp[i][4] + 1] - 48))] > 1)
                {
                    dp[i][((int)(a[i - dp[i][4] + 1] - 48))]--;
                    dp[i][4]--;
                }
                else
                {
                    break;
                }
            }
            if (dp[i][1] >= 1 && dp[i][2] >= 1 && dp[i][3] >= 1)
            {
                dp[i][0] = dp[i][4];
            }
        }
    //    cal(n, a, dp, 1);
        int ans = n + 1;
        for (size_t i = 0; i < n; i++)
        {
            if (dp[i][0] > 0)
            {
                if (ans > dp[i][0])
                {
                    ans = dp[i][0];
                }
            }
        }
        if (ans == n + 1)
        {
            ans = 0;
        }
        printf("%d\n", ans);
    }
    return 0;
}