def BiSearch(v, key):
    v.sort()
    left = 0
    right = len(v) - 1
    while True:
        mid = (left + right)//2        
        if key < v[mid]:
            right = mid - 1
        elif key > v[mid]:
            left = mid + 1
        else:
            break    
    return (v, mid)
