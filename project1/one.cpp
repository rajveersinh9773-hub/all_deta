#include<iostream>
using namespace std;


void printarray(int array[], int size){

    for(int i=0; i<size; i++){
        cout<<array[i]<<" ";
    }
}


void bubblesort(int array[], int size){

    int pass = 1;

    while(pass < size)
    {
        for(int i=0; i<size-pass; i++){
            if(array[i] > array[i+1]){

                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;

            }
        }
        pass++;
    }
}


void insertionsort(int array[], int size)
{
    for(int i = 1; i<size; i++){

        int key = array[i];
        int j = i-1;

        while(j>=0 && key<array[j]){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}


void selectionsort(int array[], int size)
{
    for(int i=0; i<size-1; i++){

        int minindex = i;

        for(int j=i+1; j<size; j++){
            if(array[j] < array[minindex]){minindex = j;}
        }

        int temp = array[minindex];
        array[minindex] = array[i];
        array[i] =  temp;

    }
}

int main(){
    int size;
    cout<<"enter size for array: ";
    cin>>size;

    cout<<endl;

    int array[size];
    
    for(int i=0; i<size; i++)
    {
        cout<<"enter value at index "<<i<<": ";
        cin>>array[i];
    }

    cout<<endl<<"Original Array :-  ";
    printarray(array, size);
    cout<<endl;

    int choise;
    
    cout<<endl<<"enter 1 for Bubble sort ";
    cout<<endl<<"enter 2 for Insertion sort ";
    cout<<endl<<"enter 3 for Selection sort ";
    
    cout<<endl<<endl<<"Select Any Sorting Technique : ";
    cin>>choise;
    
    if(choise == 1){
    
        bubblesort(array, size);
        cout<<endl<<"array Sorted using bubble sort : ";
    }
    else if(choise == 2){
    
        insertionsort(array,size);
        cout<<endl<<"array Sorted using insertion sort : ";
    }
    else if(choise == 3){
    
        selectionsort(array, size);
        cout<<endl<<"array Sorted using selection sort : ";
    }
    else{
        cout << "you entered wrong number:";
    }

    printarray(array,size);


    return 0;
}