def Export_Data(Points, N):
    export_data = open('Points.txt' , 'w')
    export_data.write(str(N))
    export_data.write('\n')
    for i in range (N):
        export_data.write(Points[i][0])
        export_data.write(' ')        
        export_data.write(Points[i][1])
        export_data.write(' ')
        export_data.write(Points[i][2])
        export_data.write('\n')
   
    export_data.close()

    
    return True
