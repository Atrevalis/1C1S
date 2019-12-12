#include <iostream>
#include <fstream>
#include <math.h>
int dimA;
int dimB;
using namespace std;
int** ConsoleInsert(bool check,int **predArray,int num);
int** FileInsert(bool check,int **predArray,int num);
void editArray();
int main() {
    int f;//номер функции
    bool exit = false;// выход Д/Н
    int ins;//номер матрицы
    int **arrayA;
    int **arrayB;
    bool checkA = false;//чекер заполнения массива А
    bool checkB = false;//чекер заполнения массива Б
    while(exit== false){
        cout<<"Выберите дальнейшее действие:"<<"\n";
        cout<<"1:Ввод матрицы "<<"\n";
        cout<<"2:Вывод матрицы "<<"\n";
        cout<<"3:Редактирование матрицы "<<"\n";
        cout<<"4:Перемножение матриц "<<"\n";
        cout<<"5:Завершение программы "<<"\n";
        cout<<"================================================================"<<"\n";
        cin>>f;//ПОПРАВИТЬ ОШИБКУ С ВВОДОМ НЕ ЧИСЕЛ
        cout<<"================================================================"<<"\n";
        switch(f){
            case 1:
                cout<<"Выберите какую матрицу вы будете вводить:"<<"\n";
                cout<<"1:A"<<"\n"<<"2:Б"<<"\n"<<"Чтобы вернутся в меню введите любое значение кроме предложенных"<<"\n";
                cout<<"================================================================"<<"\n";
                cin>>ins;//ПОПРАВИТЬ ОШИБКУ С ВВОДОМ НЕ ЧИСЕЛ
                cout<<"================================================================"<<"\n";
                switch(ins){
                    case 1:
                        cout<<"Выберите каким способом вы будете заполнять матрицу"<<"\n"<<"1:Консоль"<<"\n"<<"2:Файл"<<"\n";
                        cout<<"Чтобы вернутся в меню введите любое значение кроме предложенных"<<"\n";
                        cout<<"================================================================"<<"\n";
                        cin>>(ins);//ПОПРАВИТЬ ОШИБКУ С ВВОДОМ НЕ ЧИСЕЛ
                        cout<<"================================================================"<<"\n";
                        switch(ins){
                            case 1: arrayA = ConsoleInsert(checkA,arrayA,ins);
                            checkA = true;
                            break;
                          case 2: arrayA = FileInsert(checkA,arrayA,ins);
                          checkA = true;
                          break;
                            default:break;
                        }
                        break;
                    case 2:
                        cout<<"Выберите каким способом вы будете заполнять матрицу"<<"\n"<<"1:Консоль"<<"\n"<<"2:Файл"<<"\n";
                        cout<<"Чтобы вернутся в меню введите любое значение кроме предложенных"<<"\n";
                        cout<<"================================================================"<<"\n";
                        cin>>(ins);//ПОПРАВИТЬ ОШИБКУ С ВВОДОМ НЕ ЧИСЕЛ
                        cout<<"================================================================"<<"\n";
                        switch(ins){
                            case 1: arrayB = ConsoleInsert(checkB,arrayB,ins);
                                checkA = true;
                                break;
                          case 2: arrayB = FileInsert(checkB,arrayB,ins);
                                checkB = true;
                          break;
                            default:break;
                        }
                        break;
                }
                break;
            case 2:
                cout<<"Выберите, какую матрицу вы хотите вывести"<<"\n"<<"1:А"<<"\n"<<"2:Б"<<"\n";
                cout<<"================================================================"<<"\n";
                cin>>(ins);//ПОПРАВИТЬ ОШИБКУ С ВВОДОМ НЕ ЧИСЕЛ
                cout<<"================================================================"<<"\n";
                switch(ins){
                    case 1:
                        break;
                    case 2:
                        break;
                    default:
                        break;
                }
                break;
            case 3: break;
            case 4: break;
            case 5:
                exit = true;
                cout<<"ОКОНЧАНИЕ РАБОТЫ ПРОГРАММЫ";
                break;
            default:
                cout<<"Введено неправильное значение. Попробуйте еще раз"<<"\n";
                break;
        }
    }
}

int** ConsoleInsert(bool check,int **predArray,int num){//ПРОВЕРИТЬ ОЧИСТКУ ПАМЯТИ И ЕЕ ЗАПОЛНЕНИЕ
    if(check == true){delete[] predArray;}
    int dim;
    cout<<"Введите размерность матрицы"<<"\n";
    cout<<"================================================================"<<"\n";
    cin>>dim;//ПОПРАВИТЬ ОШИБКУ С ВВОДОМ НЕ ЧИСЕЛ
    cout<<"================================================================"<<"\n";
    if(num == 1){ dimA = dim;}
    if(num == 2){ dimB = dim;}
    int **array;
    array = new int*[dim];//создание строк
    for(int i = 0;i<dim;i++){array[i]=new int[dim];}//создание столбцов
        cout<<"Введите матрицу размерностью "<<dim<<"X"<<dim<<"\n";
    cout<<"================================================================"<<"\n";

    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            cin>>array[i][j];
        }
    }
    cout<<"================================================================"<<"\n";

    return array;
}
int** FileInsert(bool check,int **predArray,int num){//Может быть проблема с Переводом чар в инт
    if(check == true){delete[] predArray;}
    bool  exit=false;
    int **array;
    string path;
    cout<<"Введите путь файла"<<"\n";
    cout<<"================================================================"<<"\n";
    cin>>path;
    ifstream matrix;
    matrix.open(path);
    while(exit==false) {
        if (matrix.is_open()) {
            matrix.seekg(0, ios_base::end);
            int dim = (int) sqrt((double) matrix.tellg());//нахождение размерности
            if(num == 1){ dimA = dim;}
            if(num == 2){ dimB = dim;}
            array = new int*[dim];//создание строк
            for(int i = 0;i<dim;i++){array[i]=new int[dim];}//создание столбцов
            for(int i=0;i<dim;i++){
                for(int j=0;j<dim;j++){
                    matrix>>array[i][j];
                }
            }
            exit = true;
        } else { cout << "Файл не был найден, попробуйте еще раз" << "\n"; }
    }
    matrix.close();
    return array;
}
void editArray(){

}
void outputArray(bool check,int **array,int dim) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {

        }
    }
}

