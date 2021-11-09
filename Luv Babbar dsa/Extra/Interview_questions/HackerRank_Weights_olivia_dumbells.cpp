int weightshelper(vector<int> weights, int capacity, int length)
{
    // base case
    if (length == 0 or capacity == 0)
    {
        return 0;
    }

    int result = 0;
    if (weights[length - 1] > capacity)
    {
        return weightshelper(weights, capacity, length - 1);
    }

    else
    {
        return max(weightshelper(weights, capacity, length - 1), weights[length - 1] + weightshelper(weights, capacity - weights[length - 1], length - 1));
    }
}

int weightCapacity(vector<int> weights, int maxCapacity)
{
    int n = weights.size();
    return weightshelper(weights, maxCapacity, n);
}
