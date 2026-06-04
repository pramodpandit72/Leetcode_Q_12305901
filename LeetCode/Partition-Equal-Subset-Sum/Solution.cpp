    if(target % 2 != 0)
    {
        return false;
    }
    target /= 2;

    
    int n = target + 1;
    bool[] possible = new bool[n];
    possible[0] = true;

    foreach(int num in nums)
    {
        for(int i=n-1; i >= 0; i--)
        {
            if(possible[i] && i + num < n)
            {
                possible[i + num] = true;
            }
        }
    }

    return possible[target];
}