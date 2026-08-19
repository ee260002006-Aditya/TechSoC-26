#include <iostream>
#include <climits>
// #include <algorithm>

using namespace std;

int main()
{
  //taking input of C as max storage capacity
  int C;
  cout << " maximum port storage capacity" << endl;

  cin >> C;
  //taking input of N as no of containers
  int N;
  cout << "number of containers " << endl;
  cin >> N;
  //as defined in ques, taking N<=1000 for ease..
  if (N <= 1000)
  {

    // defining max and min...we use max = int min cuz we are setting the max value initially as the minimum value the code allows so as to make sure that the value user enters isnt less than the max value as set

    double total = 0;
    int max = INT_MIN;
    int min = INT_MAX;
//taking input values of all the weights of containers by defining a temp variable to save storage space in the meantime
//defining total as total+temp after every entry so as to make sure every the total gets updated after every entry
    cout << "enter the weight of containers." << endl;
    for (int i = 0; i < N; i++)
    {
      int temp;

      cin >> temp;
      total += temp;
      if (temp > max)
      {
        max = temp;
      }

      if (temp < min)
      {
        min = temp;
      }
    }
   
    cout << "Total Weight: " << total << endl;
//define N not equal to zero to prevent programmme crash or fatal errors...
    if (N != 0)
    {
      cout << "Average Container Weight: " << total / N << endl;
    }

    if (total >= 200)
      cout << "Classification:Heavy" << endl;

    else
      cout << "Classification:Light" << endl;

    cout << "Port Capacity: " << C << endl;
    cout << "Max weight among all the containers is: " << max << endl;
    cout << "Min weight among all the containers is: " << min << endl;

  
    cout << "Total Shipment Weight: " << total << endl;

    if (total <= C)
    {
      cout << "Shipment can be unloaded" << endl;
    }

    else
    {
      cout << "Shipment exceeds port capacity" << endl;
    }
  }
//case if N>1000 
  else
  {
    cout << "Please enter value under 1000" << endl;
  }

  return 0;
}
