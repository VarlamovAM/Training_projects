from tkinter import *
import Search as Search
import Import_Data as ID
import Export_Data as ED
import Colour_Maker as CM
import os


def main():
    width_of_window = int(1005)
    height_of_window = int(1005)


    Points = []
    N = int(input("Введите число точек: (Целое число, после ввода нажмите enter)"))


    for i in range(N):
        Points.append([input("Введите массу точки в десятичном формате (XXX.X), затем нажмите enter)"),
                       input("Введите координату x точки (целое число), затем нажмите enter"),
                       input("Введите координату н точки (целое число), затем нажмите enter")])


    ED.Export_Data(Points, N)

    os.system('.\Simulation.exe')

    Data, a = ID.Import_data("Data.txt")
    maximum, minimum = Search.Search(Data, a)



    root = Tk()
    c = Canvas(root, width=width_of_window, height=height_of_window, bg='white')

    rectangle_width = int(width_of_window / a)
    rectangle_height = int(height_of_window / a)

    for i in range(a):
        for j in range(a):
            colour = CM.Make_colour_index(Data[i][j], minimum, maximum)
            x_up = j * rectangle_width
            y_up = i * rectangle_height
            x_down = x_up + rectangle_width
            y_down = y_up + rectangle_height
            c.create_rectangle(x_up, y_up, x_down, y_down, fill=colour)

    c.pack()
    root.mainloop()


main()
