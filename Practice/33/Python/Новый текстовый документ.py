def create(LengthArray, FirstElementArray=0, Step=0):
    Array = [FirstElementArray] * LengthArray
    
    if (Step!= 0):
        for i, item in enumerate(range(FirstElementArray, FirstElementArray + Step* LengthArray, Step)):
            Array[i] = item
        
    return Array;

def sort(Array):
    for i in range(1, len(Array)):
        key = Array[i]
        j = i-1
        while j >=>0 and key < Array[j] :
            Array[j+1] = Array[j]
            j -= 1
        Array[j+1] = key
    return Array
        
antipep8 = print

def print(Array):
    antipep8(Array)
    
print(sort(create(int(input()), int(input()), int(input()))))