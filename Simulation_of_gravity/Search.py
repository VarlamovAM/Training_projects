def Search(final_Data, a):
    maximum = final_Data[0][0]
    minimum = final_Data[0][0]

    for i in range(a):
        for j in range(a):
            if (final_Data[i][j] > maximum):
                maximum = final_Data[i][j]
            if (final_Data[i][j] < minimum):
                minimum = final_Data[i][j]

    return maximum, minimum
