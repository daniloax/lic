"""Quick Sort"""

def quicksort(v):

    if len(v) <= 1:
        return v

    less, equal, greater = [], [], []
    pivot = v[0]

    for x in v:

        if x < pivot:
            less.append(x)

        elif x == pivot:
            equal.append(x)

        else:
            greater.append(x)

    return quicksort(less) + equal + quicksort(greater)
