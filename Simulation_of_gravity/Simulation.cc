#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>





const int16_t M = 201; //Size of plan's in M x M table;





struct Maps_with_forces{

	float A[M][M] = {};
	bool Flag = false;

};



struct Maps_with_forces Simple_Filing(struct Maps_with_forces K, double mass, int16_t M){

    int i = 0, j = 0;

	if (K.Flag == false){

        K.A[(M/2)][(M/2)] = mass;

		for (i >= 0; i <= (M/2); i++){
			for (j >= i + 1; j <= (M/2); j++){
                if ( !(i == (M/2)) || !(j += (M/2)) ){
                        K.A[i][j] = K.A[(M/2)][(M/2)] * (100000./((i - (M/2)) * (i - (M/2))) + ((j - (M/2)) * (j - (M/2)))); // I -> I
                        K.A[j][i] = K.A[i][j];K.A[i][j];// I -> II
                        K.A[M - 1 -j][i] = K.A[i][j];// I -> III
                        K.A[M - 1 - i][j] = K.A[i][j];// I -> IV
                        K.A[M - 1 - i][M - 1 - j] = K.A[i][j];// I -> V
                        K.A[M - 1 - j][M - 1 - i] = K.A[i][j];// I -> VI
                        K.A[j][M - 1 - i] = K.A[i][j];// I -> VII
                        K.A[i][M - 1 - j] = K.A[i][j];// I -> VIII
                }
			}
            j = i + 1;
		}

		K.Flag = true;
	}

    i = 0;
    j = 0;

	return K;
}



struct Maps_with_forces Filing(struct Maps_with_forces K, double mass, int16_t M, int16_t x, int16_t y){

    int i = 0, j = 0;


    K.A[y][x] = mass;


    for (i >= 0; i < M; i++){
        for (j >= 0; j < M; j++){
            if ( !(i == y) || !(j == x) ){
                K.A[i][j] += (K.A[y][x] * (1./sqrt(sqrt(((i - y) * (i - y)) + ((j - x) * (j - x))))));
            }
        }
        j = 0;
    }

    i = 0;
    j = 0;
    K.Flag = true;

	return K;
}



void Print_results(struct Maps_with_forces K){



    if (K.Flag){

        int k = 0, l = 0;

		for (k >= 0; k < M; k++){
			for (l >= 0; l < M; l++){
                std::cout << '\t' << std::setprecision(3) << K.A[k][l];
            }
            std::cout << '\n';
            std::cout << '\n';
            std::cout << '\n';
            l = 0;

        }
    } else {
            std::cout << "Array is empty :(" << '\n';
        }

    return;
}



void Print_results_in_file(struct Maps_with_forces K){



    if (K.Flag){


        int k = 0, l = 0;
        std::ofstream out;          // поток для записи
        out.open("C:\data.txt"); // окрываем файл для записи


        if (out.is_open())
            {




            for (k >= 0; k < M; k++){
                for (l >= 0; l < M; l++){
                    out << '\t' << std::setprecision(3) << K.A[k][l];
                }
                out << '\n';
                l = 0;

                }
            }
        } else {
            std::cout << "Array is empty :(" << '\n';
        }

    return;
}



int main(){



    struct Maps_with_forces K;
    int h = 0, N = 0;


    std::string line;

    std::ifstream in("C:\Points.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        in >> N;



        for ( h >= 0; h < N; h++){
            int16_t a = 0;
            int16_t b = 0;
            double Mass = 0.0;
            in >> Mass >> a >> b;
            K = Filing(K, Mass, M, a, b);
        }

        h = 0;

    }

    in.close();     // закрываем файл


    std::ofstream out;          // поток для записи
    out.open("C:\data.txt"); // окрываем файл для записи
    if (out.is_open())
    {
        Print_results_in_file(K);
    }




    std::cout << "final" << '\n';


	return 0;
}
