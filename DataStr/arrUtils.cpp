#include "arrUtils.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>

using namespace std;

bool arrUtils::isValidNumber(int str_size, char* str)
{

    int i, first_appearance = 0;
    int counter_num_after_point = -1; // cuase in same iterstion we'r checking point_counter == 1
    int point_counter = 0;
    for (i = 0; i < str_size; i++)
    {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '.') // if the char is not a number or point 
        {
            return false;
        }
        if (str[i] == '.') // if there are more then one point 
        {
            point_counter++;
            if (point_counter > 1)
            {
                return false;
            }

        }
        if (point_counter == 1) // if there are more the 4 numbers after the poit
        {
            counter_num_after_point++;
            if (counter_num_after_point > 5)
            {
                return false;
            }
        }


    }
    if (point_counter != 1 || point_counter == 0)
    {
        return false;
    }
    return true;

}
void arrUtils::getArr()
{
    char curr_char;
    int i = 0, j, size_arr;
    char str[256];
    double num;
 

    cout << "Pleas enter num of numbers\n";
    cin >> size_arr;
    arr = new double[size_arr];
    cout << "Pleas enter numbers\n";
    curr_char = getchar(); // for whitespace from arr size 
   
    for (j = 0; j < size_arr; j++)
    { 
        curr_char = getchar();
        while (curr_char != ' ' && curr_char != '\n') //here we get each of the number characters
        {
            str[i] = curr_char;
            curr_char = getchar();
            i++;
        }
        str[i + 1] = '\n';
        if (isValidNumber(i, str)) // i is the str size
        {
           num = atof(str); //we got a valid number and change its type to double 
       /*     cout << fixed << showpoint;
            cout << setprecision(2);
            cout << num << endl;*/
            
           // cout <<fixed<<setprecision(3) << num;
          /*  cout.precision(4);
            cout << num << endl;*/

            std::cout << std::setprecision(4) << num;
            arr[j] = num;
        }
        else
        {
            cout << "Wrong iput" << endl;
            exit(-1);
        }

        i = 0;


    }
    setArr(arr, size_arr);

}
void arrUtils::printArr()
{
    int i;
    for (i = 0; i < size_arr; i++)
    {
        printf("%lf\n", arr[i]);
    }
}