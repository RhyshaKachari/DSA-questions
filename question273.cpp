// Fractional Knapsack - GFG

// Time Complexity = O(n log n)
// Space Complexity = O(n)

class Solution
{
public:
    static bool cmp(pair<double, Item> a, pair<double, Item> b)
    {
        return a.first > b.first;
    }

    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double, Item>> v;
        for (int i = 0; i < n; i++)
        {
            double perUnitValue = (1.0 * arr[i].value) / arr[i].weight;
            pair<double, Item> p = make_pair(perUnitValue, arr[i]);
            v.push_back(p);
        }

        sort(v.begin(), v.end(), cmp);
        double totalValue = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i].second.weight > W)
            {
                totalValue += W * v[i].first;
                W = 0;
            }
            else
            {
                totalValue += v[i].second.value;
                W -= v[i].second.weight;
            }
        }

        return totalValue;
    }
}

// Approach 2 : Without using any extra space
// Time Complexity - O(N log N)
// Space Complexity - O(1)


class Solution
{
public:
    static bool comp(Item a, Item b)
    {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, comp);
        int currWeight = 0;
        double finalValue = 0.0;
        for (int i = 0; i < n; i++)
        {
            if (currWeight + arr[i].weight <= W)
            {
                currWeight += arr[i].weight;
                finalValue += arr[i].value;
            }
            else
            {
                int remain = W - currWeight;
                finalValue += (arr[i].value / (double)arr[i].weight) * (double)remain;
                break;
            }
        }
        return finalValue;
    }
};
