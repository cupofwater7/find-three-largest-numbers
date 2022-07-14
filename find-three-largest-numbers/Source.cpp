#include <vector>
#include <climits>
#include <iostream>

using namespace std;



void updateLargest(vector<int>& threeLargest, int num);
void shiftAndUpdate(vector<int>& array, int num, int idx);
vector<int> findThreeLargestNumbers(vector<int> array);

int main()
{

    vector<int> result = findThreeLargestNumbers({ 141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7 });

    for (int number : result)
    {
        cout << number << " ";
    }
    

    return 0;

}

// o(n) time | o(1) space
vector<int> findThreeLargestNumbers(vector<int> array) {
    vector<int> threelargest{ INT_MIN, INT_MIN, INT_MIN };
    for (int num : array)
    {
        updateLargest(threelargest, num);
    }
    // Write your code here.
    return threelargest;
}

void updateLargest(vector<int>& threeLargest, int num)
{
    if (num > threeLargest[2])
        shiftAndUpdate(threeLargest, num, 2);

    else if (num > threeLargest[1])
        shiftAndUpdate(threeLargest, num, 1);

    else if (num > threeLargest[0])
        shiftAndUpdate(threeLargest, num, 0);
}

void shiftAndUpdate(vector<int>& array, int num, int idx)
{
    for (int i = 0; i <= idx; i++)
    {
        if (i == idx)
        {
            array[i] = num;
        }
        else
        {
            array[i] = array[i + 1];
        }
    }
}