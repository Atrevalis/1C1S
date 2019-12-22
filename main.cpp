#include <iostream>
#include <fstream>
#include <cmath>
int dimA;
int dimB;//хуйня не работает
using namespace std;
int** ConsoleInsert(bool check,int **&predArray, char symbol);
int** FileInsert(bool check,int **&predArray, char symbol);
void editArray(bool check,int **&array,int dim);

void outputArray(bool check, int **&Array, int dim);

int main() {
    char A = 'A';
    char B = 'B';
    char f;//номер функции
    bool exit = false;// выход Д/Н
    int ins;//номер матрицы
    int **arrayA;
    int **arrayB;
    bool checkA = false;//чекер заполнения массива А
    bool checkB = false;//чекер заполнения массива Б
    while(exit == false){
        cout<<"Выберите дальнейшее действие:"<<"\n";
        cout<<"1:Ввод матрицы "<<"\n";
        cout<<"2:Вывод матрицы "<<"\n";
        cout<<"3:Редактирование матрицы "<<"\n";
        cout<<"4:Перемножение матриц "<<"\n";
        cout<<"5:Завершение программы "<<"\n";
        cin>>f;
        switch(f){
            case '1':
                cout<<"Выберите какую матрицу вы будете вводить:"<<"\n";
                cout<<"1:A"<<"\n"<<"2:Б"<<"\n"<<"Чтобы вернутся в меню введите любое значение кроме предложенных"<<"\n";
                cin>>ins;//ПОПРАВИТЬ ОШИБКУ С ВВОДОМ НЕ ЧИСЕЛ
                switch(ins){
                    case 1:
                        cout<<"Выберите каким способом вы будете заполнять матрицу"<<"\n"<<"1:Консоль"<<"\n"<<"2:Файл"<<"\n";
                        cout<<"Чтобы вернутся в меню введите любое значение кроме предложенных"<<"\n";
                        cin>>(ins);//ПОПРАВИТЬ ОШИБКУ С ВВОДОМ НЕ ЧИСЕЛ
                        switch(ins){
                            case 1: arrayA = ConsoleInsert(checkA,arrayA,A);
                            checkA = true;
                            break;
                          case 2: arrayA = FileInsert(checkA,arrayA,A);
                          checkA = true;
                          break;
                            default:break;
                        }
                        break;
                    case 2:
                        cout<<"Выберите каким способом вы будете заполнять матрицу"<<"\n"<<"1:Консоль"<<"\n"<<"2:Файл"<<"\n";
                        cout<<"Чтобы вернутся в меню введите любое значение кроме предложенных"<<"\n";
                        cin>>(ins);//ПОПРАВИТЬ ОШИБКУ С ВВОДОМ НЕ ЧИСЕЛ
                        switch(ins){
                            case 1: arrayB = ConsoleInsert(checkB,arrayB,B);
                                checkB = true;
                                break;
                            case 2: arrayB = FileInsert(checkB,arrayB,B);
                                checkB = true;
                                break;
                            default:break;
                        }
                        break;
                }
                break;
            case '2':
                cout<<"Выберите, какую матрицу вы хотите вывести"<<"\n"<<"1:А"<<"\n"<<"2:Б"<<"\n";
                cin>>(ins);
                switch(ins){
                    case 1:
                        outputArray(checkA,arrayA,dimA);
                        break;
                    case '2':
                        outputArray(checkB,arrayB,dimB);
                        break;
                    default:
                        break;
                }
                break;
            case '3':
                break;
            case '4': break;
            case '5':
                exit = true;
                cout<<"ОКОНЧАНИЕ РАБОТЫ ПРОГРАММЫ";
                break;
            default:
                cout<<"Введено неправильное значение. Попробуйте еще раз"<<"\n";
                break;
        }
    }
}

void outputArray(bool check, int **&array, int dim) {
    if (check == true) {
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                cout << array[i][j]<<" ";
            }
           cout <<"\n";
        }
    }else{cout<<"Массива не существует"<<"\n";}
}

int** ConsoleInsert(bool check,int **&array,char symbol){//ПРОВЕРИТЬ ОЧИСТКУ ПАМЯТИ И ЕЕ ЗАПОЛНЕНИЕ
    if(check){delete[] array;}
    int dim;
    cout<<"Введите размерность квадратной матрицы"<<"\n";
    cin>>dim;//ПОПРАВИТЬ ОШИБКУ С ВВОДОМ НЕ ЧИСЕЛ
    if(symbol == 'A'){ dimA = dim;}
    if(symbol == 'B'){ dimB = dim;}
    array = new int*[dim];//создание строк
    for(int i = 0;i<dim;i++){array[i]=new int[dim];}//создание столбцов
    cout<<"Введите матрицу размерностью "<<dim<<"X"<<dim<<"\n";
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            cin>>array[i][j];
        }
    }
    return array;
}
int** FileInsert(bool check,int **&predArray,int num){//Может быть проблема с Переводом чар в инт
    if(check){delete[] predArray;}
    bool  exit=false;
    int **array;
    string path;
    cout<<"Введите путь файла"<<"\n";
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
        } else {cout << "Файл не был найден, попробуйте еще раз" << "\n"; }
    }
    matrix.close();
    return array;
}
void editArray(bool check,int **&array,int dim){
    int column;
    int line;
    char trigger;
    bool exit = false;
    if(check== true) {
        while (exit == false) {
            cout << "Выберите элемент, который вы хотите изменить" << "\n";;
            cout << "Введите строку в которой содержится элемент" << "\n";;
            cin >> line;
            cout << "Введите столбец в котором содержится элемент" << "\n";;
            cin >> column;
            cout << "Введите новое значение " << "\n";;
            cin >> array[line][column];
            cout << "Продолжить изменение массива? Y/N";
            cin >> trigger;
            if ((trigger == 'N') or (trigger == 'n')) { exit = true; }
        }
    } else{cout<<"Массива не существует";}
}
void Calculate(int **&arrayA,int **&arrayB, int dimA, int dimB, bool checktrue){

}

