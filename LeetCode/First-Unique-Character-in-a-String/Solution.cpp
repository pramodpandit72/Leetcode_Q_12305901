    for i in s:
        if i not in frequency:
            frequency[i] = 1
        else:
            frequency[i] +=1

    for i in frequency:
        if frequency[i] == 1:
            return s.index(i)
            
    return -1