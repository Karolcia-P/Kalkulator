#include <cmath>

using namespace std;

class Calc_3 {
    char mathOperators[7] = {'+', '-', '*', '/', '%', '^', 'p'};
    string input;
    float result = 0;
public:
    int size = 0;

    bool working = true;
    int currentIndex;
    void getInput(){
        cin >> input;
        if(input == "E"){
            working = false;
        }else{
            work();
        }
    }

    void printResult()
    {
        cout << result << endl;
    }

    void addition(float x, float y){
        result = x + y;
    }

    void subtraction(float x, float y){
        result = x - y;
    }

    void multiplication(float x, float y){
        result = x * y;
    }

    void division(float x, float y){
        if(y == 0){
            cout << "You cannot divide by zero " << endl;
            result = 0;
        }else{
            result = x/y;
        }
    }

    void square(float x, float y){
        if(y == 0){
            cout << "You cannot divide by zero " << endl;
            result = 0;
        }else{
            result = pow(x,1/y);
        }

    }

    void power(float x, float y){
        result = pow(x,y);
    }

    void percent(float x, float y){
        result = ((x/100) * y);
    }


    void work(){
        result = 0;
        size = input.length();
        string arr[size];
        int i = 0;
        string tmp;
        int indeks = 0;
        while(input[i] != '\0'){
            tmp = "";
            if(checkIfMathOp(input[i])){
                tmp += input[i];
                i++;
            }
            else{
                while(!checkIfMathOp(input[i]) && input.length() > i){
                    tmp += input[i];
                    i++;
                }
            }
            arr[indeks] = tmp;
            indeks++;
        }

        bool finish = false;
        char sign;
        char h1[3] = {'%', '^', 'p'};
        char h2[2] = {'*', '/'};
        char h3[2] = {'+', '-'};
        while(!finish){
            if(checkSign(h1[0], arr) || checkSign(h1[1], arr) || checkSign(h1[2], arr)){
                sign = firstElem(h1, arr, 3);
                switch (sign) {
                    case '%':
                        percent(stof(arr[currentIndex-1]), stof(arr[currentIndex+1]));
                        break;
                    case '^':
                        power(stof(arr[currentIndex-1]), stof(arr[currentIndex+1]));
                        break;
                    case 'p':
                        square(stof(arr[currentIndex-1]), stof(arr[currentIndex+1]));
                        break;
                }
                arr[currentIndex] = to_string(result);
                delElem(arr, currentIndex+1);
                delElem(arr, currentIndex-1);
            }else if(checkSign(h2[0], arr) || checkSign(h2[1], arr)){
                sign = firstElem(h2, arr, 2);
                switch (sign) {
                    case '/':
                        division(stof(arr[currentIndex-1]), stof(arr[currentIndex+1]));
                        break;
                    case '*':
                        multiplication(stof(arr[currentIndex-1]), stof(arr[currentIndex+1]));
                        break;
                }
                arr[currentIndex] = to_string(result);
                delElem(arr, currentIndex+1);
                delElem(arr, currentIndex-1);
            }else if(checkSign(h3[0], arr) || checkSign(h3[1], arr)){
                sign = firstElem(h3, arr,2);
                switch (sign) {
                    case '+':
                        addition(stof(arr[currentIndex-1]), stof(arr[currentIndex+1]));
                        break;
                    case '-':
                        subtraction(stof(arr[currentIndex-1]), stof(arr[currentIndex+1]));
                        break;
                }
                arr[currentIndex] = to_string(result);
                delElem(arr, currentIndex+1);
                delElem(arr, currentIndex-1);
            }else {
                finish = true;
            }

        }
    }

    void delElem(string arr[],int indeks ){
        for(int i=0; i<size; i++)
        {
            if(i == indeks)
            {
                for(int j=i; j<(size-1); j++){
                    arr[j] = arr[j+1];
                }
            }
        }
    }

    char firstElem(char el[], string arr[], int len){
        for(int i=0; i < size; i++){
            for(int j=0; j <len; j++){
                if(el[j] == arr[i][0]){
                    currentIndex = i;
                    return el[j];
                }
            }
        }
        return 0;
    }

    bool checkIfMathOp(char x){
        for(int i=0; i < sizeof(mathOperators); i++){
            if(x == mathOperators[i]){
                return true;
            }
        }
        return false;
    }

    bool checkSign(char x, string arr[]){
        for(int i=0; i < size; i++){
            if(x == arr[i][0]){
                return true;
            }
        }
        return false;
    }

//    void printArray(string arr[]){
//        for (int i = 0; i < size; i++)
//            cout << arr[i] + " " ;
//        cout << endl;
//    }
};

