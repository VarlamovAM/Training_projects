from tkinter import *
import Search as Search
import Import_Data as ID
import Export_Data as ED
import Colour_Maker as CM
import Check_Input as CI
import Random_Input as RI
import os


def main():
    width_of_window = int(1005)
    height_of_window = int(1005)

    points = []
    correct_input = True

    while correct_input:
        N = input("Введите число точек: (Целое число, после ввода нажмите enter)")


        if not N.isdigit():
            print('Некорректный ввод, повторите попытку: ')
            continue

        N = int(N)

        if N == 0:
            print('Введите число, отличное от 0')
            continue


        print('Как произвести заполнение данных о точках, вручную или случайным образом?')
        mod = int(input('Введите 0, если заполнение будет в ручном режиме, или 1, если желаете заполнить данные'
                        ' автоматически: '))

        if mod == 1:
            points = RI.Random_points(N)
        else:
            i = 0
            while i < N:
                points.append([input("Введите массу точки в десятичном формате (XXX.X), затем нажмите enter): "),
                               input("Введите координату x точки (целое число, не больше 200), затем нажмите enter: "),
                               input("Введите координату н точки (целое число, не больше 200), затем нажмите enter: ")])

                if ((CI.is_digit(points[i][0]) is False or (points[i][0].isdigit())) or
                        ((points[i][1].isdigit() is False) or (int(points[i][1]) < 0 or int(points[i][1]) > 200)) or
                        ((points[i][2].isdigit() is False) or (int(points[i][2]) < 0 or int(points[i][2]) > 200))):
                    print('Вы ввели некоректные данные. Повторите ввод данный последней точки: ')
                    points.pop(i)
                else:
                    i = i + 1

        ED.Export_Data(points, N)

        os.system('.\Simulation.exe')

        Data, a = ID.Import_data("Data.txt")
        maximum, minimum = Search.Search(Data, a)

        os.system('del Data.txt')
        os.system('del Points.txt')

        correct_input = False

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
