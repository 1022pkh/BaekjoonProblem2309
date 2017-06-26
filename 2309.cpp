//
//  main.cpp
//  Study
//
//  Created by 경현 on 2017. 6. 14..
//  Copyright © 2017년 박경현. All rights reserved.
//




/*
1. 문제를 이해하고 자신의 용어로 재정의 한다.

 // 일곱난쟁이 문제 : https://www.acmicpc.net/problem/2309
 // 오름차순 정렬... 7개만 출력한다.
 // 퀵정렬을 사용한다.
 // 9명의 난쟁이.. 가짜 2명이다.
 // 결국은 9명의 키를 더해서 100을 뺀 값..이것이 바로 가짜 두놈의 키를 더한 값
 // 결과적으로 동전갯수를 찾는 문제와 같은 것 같다.
 
2. 이 문제의 유형이 무엇인지 판단한다.
한번 문제를 풀었기 때문에 이미 문제의 유형을 알고 있는 경우가 있을 것인데,
이 경우 문제의 어느부분에서 해당 유형이라고 판단할 수 있었는지 명확하게 적는다.
 
 // 일단 정렬 + 동전 갯수 찾기 유형이다.
 // 키를 오름차순으로 정렬한다음 높은 키부터 계산에서 찾으면 된다.
 

3. 문제에 주어진 제약조건(범위 등)들을 고려하면서 자신이 생각한 유형으로 문제를 풀었을때의 시간복잡도를  계산한다.
만약, 자신이 생각한 방법으로 시간복잡도를 계산 했을때 시간초과가 발생할 것 같으면
다시 2번으로 돌아간다.
 
 // 이 문제의 경우 시간복잡도는 단순하다.
 // 정해진 상수. 즉 9명의 난쟁이로 고정되어있기땨문에
 // 빅오표기법으로 계산해도 시간초과는 없을 것 같다.

4. 자신이 생각한 방법으로 구현한다.

5. 내가 생각한 유형이 맞는지 다시 확인한다.
오답이 한번이라도 났으면 원인을 적는다.

*/

#include <iostream>

using namespace std;

void quickSort(int array[], int start, int end);
int partition(int array[], int start, int end);

int findFake(int people[], int totalSum, int start, int end);

int a;
int b;

int main(int argc, const char * argv[]) {
    
    // 9명의 난쟁이..
    // 그 중 진짜는 7명이다.
    // 7명의 키는 100이다..
    
    int totalSum = 0 ; // 9명을 더한값.
    int people[9];
    
    int fakeOne = -1;
    int fakeTwo = -1;
    
    for(int i = 0 ; i<9;i++){
        cin>>people[i];
        totalSum += people[i];
    }
    
    quickSort(people, 0, 8);
    
//    cout<<totalSum<<endl;

    // 결국 정렬해서..동전갯수구하는 문제랑 비슷한 것 같음. 높은 키부터 더하면서 가면 될듯.
    // 9명을 다 더한 값 - 100 =
    // 2명의 가짜 난쟁이를 더한 키값이 저 결과값. 그렇다면 그 값을 충족하는 것을 찾자.
    // 높은 놈부터 체크해보자.
    
//    for(int i = 8; i>-1; i--){
//        
//        for(int j=i-1; j> -1; j--){
//            
//            if(people[i] + people[j] == (totalSum - 100)){
//                fakeOne = i;
//                fakeTwo = j;
//                break;
//            }
//            
//        }
//        if(fakeOne != -1 && fakeTwo != -1)
//            break;
//        
//    }
//    
//    
//    for(int i = 0; i < 9;i++){
//        if(fakeOne != i && fakeTwo != i)
//            cout << people[i] << endl;
//    }


    //재귀방법
    findFake(people,totalSum,8,7);
    
    
    for(int i = 0; i < 9;i++){
        if(a != i && b != i)
            cout << people[i] << endl;
    }
    
    
    return 0;
}


int findFake(int people[], int totalSum, int start, int end){
    
    if( start < 1 || end < 1)
        return -1;
    
    else{
        if(people[start] + people[end] ==(totalSum - 100)){
            a = start;
            b = end;
            return 0;
        }
        else{
            
            if(end == 0 )
                return findFake(people,totalSum,start-1,start-2);
            else
                return findFake(people,totalSum,start,end-1);

        }
    }
}


void quickSort(int array[], int start, int end) {
    if (start < end) {
        // 1) 분할
        int standIndex = partition(array, start, end);
        // 2) 왼쪽 부분 배열 정렬
        quickSort(array, start, standIndex - 1);
        // 3) 오른쪽 부분 배열 정렬
        quickSort(array, standIndex + 1, end);
    }
}

int partition(int array[], int start, int end) {
    
    // 기준 원소는 마지막 값으로 정한다.
    int standard = array[end];
    int i = start - 1;
    int temp;
    
    for (int j = start; j < end; j++) {
        if (array[j] <= standard) {
            temp = array[++i];
            array[i] = array[j];
            array[j] = temp;
            
        }
    }
    
    temp = array[i + 1];
    array[i + 1] = array[end];
    array[end] = temp;
    
    return i + 1;
    
}
