def Import_data(Data):

    array_of_string = []

    file = open(Data, 'r')

    a = 0

    for line in file:
        a = a + 1
        array_of_string.append(line)

    file.close()

    
    number = []
    list = []
    final_Data = []

    for i in range(a):
        final_Data.append([])

    for i in range(a):
        number.append(array_of_string[i].split())
        list.append(number[i])

    for i in range(a):
        for j in range(a):
            final_Data[i].append(float(list[i][j]))

    
    return final_Data, a
