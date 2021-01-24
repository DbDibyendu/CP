class Solution
{
public:
    int check(vector<int> &weights, int mid)
    {
        int i;
        int n = weights.size();
        int sub_sum = 0;
        int count = 1;
        for (i = 0; i < n; i++)
        {
            sub_sum += weights[i];
            if (sub_sum > mid)
            {
                sub_sum = weights[i];
                count++;
            }
        }
        return count;
    }
    int shipWithinDays(vector<int> &weights, int D)
    {

        int n = weights.size();
        int i, j;
        int l = 0, total = 0;
        int answer;
        for (i = 0; i < n; i++)
        {
            l = max(l, weights[i]);
            total += weights[i];
        }
        while (l <= max)
        {
            int mid = (l + max) / 2;
            int days = check(weights, mid);
            if (days > mid)
            {
                l=mid+1;
            }
            else{
                _answer=mid;
                 max=mid-1;
            }
        }
        return answer;
    }
};