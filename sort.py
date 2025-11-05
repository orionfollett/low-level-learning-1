def test_sort(lis):
    min = lis[0]
    
    for i in range(0, len(lis)):
        min_index = i
        min = lis[min_index]
        for j in range(i, len(lis)):
            if lis[j] < min:
                min = lis[j]
                min_index = j
        
        lis[min_index] = lis[i]
        lis[i] = min
        
    return lis
        

print(test_sort([4, 3, 2, 1]))