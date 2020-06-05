import tkinter as Tk


def Import_data(Data):

    array_of_string = []

    file = open(Data, 'r')

    a = 0

    for line in file:
        a = a + 1
        array_of_string.append(line)

    file.close()

    return array_of_string, a



def main():

    Data=[]

    Data, a = Import_data("Data.txt")
    number = []
    list = []
    final_Data = [[], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], []]

    for i in range(a):
        number.append(Data[i].split())
        list.append(number[i])


    for i in range(a):
        for j in range(20):
            final_Data[i].append(float(list[i][j]))


        for j in range(20):
            print(final_Data[j], sep=' ')
        print('\n')






main()