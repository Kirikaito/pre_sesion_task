#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, ins = 0,bou = 0,S = 0,d;
    float x1,x2,y1,y2,t,b;
    vector<pair<int,int>> points;
    pair<int,int> point;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> point.first >> point.second;
        points.push_back(point);
    }
    for(int i = 1;i<n;i++){
        x1 = points[i-1].first;
        x2 = points[i].first;
        y1 = points[i-1].second;
        y2 = points[i].second;
        if(y2 < y1){          // перестановка для универсальности и удобства
            t = y2;
            y2 = y1;
            y1 = t;
            t = x2;
            x2 = x1;
            x1 = t;
        } 
        t = (x2-x1)/(y2-y1);          // подсчёт всех целых чисел на отрезке из двух точек 
        for(int y = y1;y <= y2;y++){  // перебором всех целых значений y и проверкой целостности x при этом y.
            d = (((y-y1)*t) - x1)*10000;
            if(d%10000 == 0){bou++;}
        }
    }
    
    for(int i = 1; i < n;i++){ // рассчетаем площадь по формуле площади Гаусса
        S += (points[i].first * (points[i+1].second - points[i-1].second))/2;
    }
    b = bou;
    ins = S - (b/2) + 1; //Вырозим целые точки внутри из формулы Пика
    
    cout << ins << ' ' << bou;
}
