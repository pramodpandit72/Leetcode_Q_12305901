int hasDupAt(string s)
{
    int index = -1;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]==s[i+1])
        {
            index = i;
            break;
        }
    }
    return index;
}
string removeDuplicates(string s) 
{
    while (hasDupAt(s) >= 0)
    {
        s.erase(hasDupAt(s), 2);
    }
    return s;
}