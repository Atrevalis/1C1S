#include <iostream>
#include <fstream>
#include <cmath>
int dimA;//по возможности заменить функцией
int dimB;//
int dimC;
using namespace std;
int** consoleInsert(bool check,int **&array, char symbol);
int** fileInsert(bool check,int **&array, char symbol);
void editArray(bool check,int **&array, int dim);
void fileOutput(bool check, int **&array, int dim);
void consoleOutput(bool check, int **&array, int dim);
int** calculate(int **&array1,int **&array2,int **&array3, bool check1,bool check2,int dim1,int dim2);
int summ(int dim, int indi,int indj,int **&array1,int **&array2) ;

int main() {
    char A = 'A';//symbol
    char B = 'B';//symbol
    char C = 'C';//symbol
    char f;//номер функции
    bool exit = false;// выход Д/Н
    char ins;//номер матрицы
    int **arrayA;
    int **arrayB;
    int **arrayC;
    bool checkA = false;//чекер заполнения массива А
    bool checkB = false;//чекер заполнения массива B
    bool checkC = false;//чекер заполнения массива C
    while(!exit){
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
                cout<<"1:A"<<"\n"<<"2:B"<<"\n"<<"3:C"<<"\n"<<"Чтобы вернутся в меню введите любое значение кроме предложенных"<<"\n";
                cin>>ins;
                switch(ins){
                    case '1':
                        cout<<"Выберите каким способом вы будете заполнять матрицу"<<"\n"<<"1:Консоль"<<"\n"<<"2:Файл"<<"\n";
                        cout<<"Чтобы вернутся в меню введите любое значение кроме предложенных"<<"\n";
                        cin>>(ins);
                        switch(ins){
                            case '1': arrayA = consoleInsert(checkA,arrayA,A);
                                checkA = true;
                                break;
                            case '2': arrayA = fileInsert(checkA,arrayA,A);
                                checkA = true;
                                break;
                            default:break;
                        }
                        break;
                    case '2':
                        cout<<"Выберите каким способом вы будете заполнять матрицу"<<"\n"<<"1:Консоль"<<"\n"<<"2:Файл"<<"\n";
                        cout<<"Чтобы вернутся в меню введите любое значение кроме предложенных"<<"\n";
                        cin>>(ins);//ПОПРАВИТЬ ОШИБКУ С ВВОДОМ НЕ ЧИСЕЛ
                        switch(ins){
                            case '1': arrayB = consoleInsert(checkB,arrayB,B);
                                checkB = true;
                                break;
                            case '2': arrayB = fileInsert(checkB,arrayB,B);
                                checkB = true;
                                break;
                            default:break;
                        }
                        break;
                    case '3':
                        cout<<"Выберите каким способом вы будете заполнять матрицу"<<"\n"<<"1:Консоль"<<"\n"<<"2:Файл"<<"\n";
                        cout<<"Чтобы вернутся в меню введите любое значение кроме предложенных"<<"\n";
                        cin>>(ins);
                        switch(ins){
                            case '1': arrayC = consoleInsert(checkC,arrayC,C);
                                checkB = true;
                                break;
                            case '2': arrayC = fileInsert(checkC,arrayC,C);
                                checkB = true;
                                break;
                            default:break;
                        }
                        break;
                    default:break;
                }
                break;
            case '2':
                cout<<"Выберите, какую матрицу вы хотите вывести"<<"\n"<<"1:А"<<"\n"<<"2:B"<<"3:C"<<"\n";
                cin>>(ins);
                switch(ins){
                    case '1':
                        cout<<"Выберите каким способом вы будете выводить матрицу"<<"\n"<<"1:Консоль"<<"\n"<<"2:Файл"<<"\n";
                        cout<<"Чтобы вернутся в меню введите любое значение кроме предложенных"<<"\n";
                        cin>>(ins);
                        switch(ins){
                            case '1':
                                consoleOutput(checkA,arrayA,dimA);
                                break;
                            case '2':
                                fileOutput(checkA,arrayA,dimA);
                                break;
                        }
                        break;
                    case '2':
                        cout<<"Выберите каким способом вы будете выводить матрицу"<<"\n"<<"1:Консоль"<<"\n"<<"2:Файл"<<"\n";
                        cout<<"Чтобы вернутся в меню введите любое значение кроме предложенных"<<"\n";
                        cin>>(ins);
                        switch(ins){
                            case '1':
                                consoleOutput(checkB,arrayB,dimB);
                                break;
                            case '2':
                                fileOutput(checkB,arrayB,dimB);
                                break;
                        }
                        break;
                    case '3':
                        cout<<"Выберите каким способом вы будете выводить матрицу"<<"\n"<<"1:Консоль"<<"\n"<<"2:Файл"<<"\n";
                        cout<<"Чтобы вернутся в меню введите любое значение кроме предложенных"<<"\n";
                        cin>>(ins);
                        switch(ins){
                            case '1':
                                consoleOutput(checkC,arrayC,dimC);
                                break;
                            case '2':
                                fileOutput(checkC,arrayC,dimC);
                                break;
                        }
                        break;
                    default:
                        break;
                }
                break;
            case '3':
                cout<<"Выберите, какую матрицу вы хотите отредактировать"<<"\n"<<"1:А"<<"\n"<<"2:B"<<"\n"<<"3:C"<<"\n";
                cout<<"Чтобы вернутся в меню введите любое значение кроме предложенных"<<"\n";
                cin>>(ins);
                switch(ins) {
                    case '1':
                        editArray(checkA, arrayA,dimA);
                        break;
                    case '2':
                        editArray(checkB, arrayB,dimB);
                        break;
                    case '3':
                        editArray(checkC, arrayC,dimC);
                        break;
                    default:
                        break;
                }
            case '4':
                cout<<"Выберите вариант умножения матриц:"<<"\n";
                cout<<"1:А*B = С"<<"\n"<<"2:B*A = С"<<"\n";
                cout<<"Чтобы вернутся в меню введите любое значение кроме предложенных"<<"\n";
                cin>>(ins);
                switch (ins){
                    case '1':
                        arrayC = calculate(arrayA,arrayB,arrayC,checkA,checkB,dimA,dimB);
                        break;
                    case '2':
                        arrayC = calculate(arrayA,arrayB,arrayC,checkA,checkB,dimA,dimB);
                        break;
                    default:
                        break;
                }
                break;
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

void consoleOutput(bool check, int **&array, int dim) {//DONE
    if (check) {
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                cout << array[i][j]<<" ";
            }
           cout <<"\n";
        }
    }else{cout<<"Массива не существует"<<"\n";}
}
void fileOutput(bool check, int **&array, int dim){//DONE
    if (check) {
        ofstream matrix;
        bool  exit=false;
        string path;
        while(!exit) {
            cout<<"Введите путь файла"<<"\n";
            cin>>path;
            matrix.open(path);
            if (matrix.is_open()) {
                for(int i=0;i<dim;i++){
                    for(int j=0;j<dim;j++){matrix<<array[i][j]<<" ";}
                    matrix<<"\n";
                }
                exit = true;
            } else {cout << "Файл не был найден, попробуйте еще раз" << "\n"; }
        }
        matrix.close();
    } else{cout<<"Массива не существует"<<"\n";}
}
int** consoleInsert(bool check,int **&array,char symbol){//DONE
    if(check){delete[] array;}
    int dim;
    cout<<"Введите размерность квадратной матрицы"<<"\n";
    cin>>dim;//ПОПРАВИТЬ ОШИБКУ С ВВОДОМ НЕ ЧИСЕЛ
    if(symbol == 'A'){ dimA = dim;}
    if(symbol == 'B'){ dimB = dim;}
    if(symbol == 'C'){ dimC = dim;}
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
int** fileInsert(bool check,int **&array,char symbol){//DONE
    if(check){delete[] array;}
    bool  exit=false;
    string path;
    ifstream matrix;
    while(!exit) {
        cout<<"Введите путь файла"<<"\n";
        cin>>path;
        matrix.open(path);
        if (matrix.is_open()) {
            matrix.seekg(0, ios_base::end);
            int dim = (int) sqrt((double) matrix.tellg()/2);//нахождение размерности
            matrix.seekg(0, ios_base::beg);
            if(symbol == 'A'){ dimA = dim;}
            if(symbol == 'B'){ dimB = dim;}
            if(symbol == 'C'){ dimC = dim;}
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
void editArray(bool check,int **&array,int dim){//DONE
    int column;
    int line;
    char trigger;
    bool exit = false;
    if(check) {
        while (!exit) {
            cout <<"Выберите элемент, который вы хотите изменить" << "\n";
            cout <<"+===========================================+"<< "\n";
            cout << "Введите строку в которой содержится элемент" << "\n";
            cin >> line;
            cout << "Введите столбец в котором содержится элемент" << "\n";
            cin >> column;
            if((line<=dim)&&(column<=dim)){
            cout << "Введите новое значение " << "\n";
            cin >> array[--line][--column];}else{cout<<"элемента не существует"<< "\n";}
            cout << "Продолжить изменение массива? Y/N"<< "\n";
            cin >> trigger;
            if ((trigger == 'N') or (trigger == 'n')) { exit = true; }
        }
    } else{cout<<"Массива не существует"<<"\n";}
}
int** calculate(int **&array1,int **&array2,int **&array3, bool check1,bool check2,int dim1,int dim2){
    if(dim1==dim2){
    delete[] array3;
    int dim = dim1;
        array3 = new int*[dim];//создание строк
        for(int i = 0;i<dim;i++){array3[i]=new int[dim];}//создание столбцов
        for(int i=0;i<dim;i++){
            for(int j=0;j<dim;j++){
                array3[i][j]=summ(dim,i,j,array1,array2);
            }
        }
    }else{cout<<"Умножение не осуществимо"<<"\n";}
    return array3;
}
int summ(int dim, int indi,int indj,int **&array1,int **&array2) {
    int summ = 0;
    for (int i = 0; i < dim; i++) {summ += array1[indi][i] * array2[i][indj];}
    return summ;
}