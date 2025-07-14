#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void search(int arr[], int av, int sizear)
{
    int i;
    for (i = 0; i < sizear; i++)
    {
        if (arr[i] == av) { cout << i << ' '; }
    }
}

int lessthana(int arr[], int anumber, int sizear)
{
    int value = 0;
    for (int i = 0; i < sizear; i++)
    {
        if (arr[i] < anumber) { value++; }
    }
    return value;
}

int morethanb(int arr[], int bnumber, int sizear)
{
    int value = 0;
    for (int i = 0; i < sizear; i++)
    {
        if (arr[i] > bnumber) { value++; }
    }
    return value;
}

int binarysearch(int arr[], int value, int sizear)
{
    bool b = false;
    int start = 0, end = sizear - 1, mid, i = sizear, k = 0;
    while (i != 1) { i >>= 1; k += 1; }

    for (i = 1; i <= k; i++)
    {
        mid = (start + end) / 2;
        if (value == arr[mid]) { break; }
        if (value < arr[mid]) { end = mid - 1; }
        if (value > arr[mid]) { start = mid + 1; }
    }

    if (arr[mid] == value) { return mid; }
    else { return -1; }
}


int main()
{
    /* 1 point */
    const int sizear = 100;
    int array1[sizear];
	for (int i = 0; i < sizear; i++)
	{
		array1[i] = rand() % 199 + (-99);
	}
    
    /* 2 point */
    int array2[sizear], begin = 1, ends = sizear;
    bool stop = true;

    for (int i = 0; i < sizear; i++)
    {
        array2[i] = array1[i];
    }
    
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start1, end1;
    nanoseconds time1;

    start1 = steady_clock::now();
    while (stop)
    {
        stop = false;
        for (int i = begin; i < ends; i++)
        {
            if (array2[i] < array2[i - 1])
            {
                int c = array2[i];
                array2[i] = array2[i - 1];
                array2[i - 1] = c;
                stop = true;
            }
        }
        ends--;
        if (!stop) { break; }
        stop = false;
        for (int i = ends - 1; i >= begin; i--)
        {
            if (array2[i] < array2[i - 1])
            {
                int c = array2[i];
                array2[i] = array2[i - 1];
                array2[i - 1] = c;
                stop = true;
            }
        }
        begin++;
    }
    end1 = steady_clock::now();
    time1 = duration_cast<nanoseconds>(end1 - start1);
    
    /* 3 point */
    int minel = array1[0], maxel = array1[0];
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start2, end2;
    nanoseconds time2;
    start2 = steady_clock::now();
    
    minel = array2[0];
    maxel = array2[sizear - 1];

    end2 = steady_clock::now();
    time2 = duration_cast<nanoseconds>(end2 - start2);

    minel = array1[0];
    maxel = array1[0];

    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start3, end3;
    nanoseconds time3;
    start3 = steady_clock::now();
    for (int i = 0; i < sizear; i++)
    {
        if (array1[i] > maxel) { maxel = array1[i]; }
        if (array1[i] < minel) { minel = array1[i]; }
    }
    end3 = steady_clock::now();
    time3 = duration_cast<nanoseconds>(end3 - start3);

    /* 4 point */
    int average = (minel + maxel) / 2;
    int countsimilar=0;
    for (int i = 0; i < sizear; i++)
    {
        if (array1[i] == average) { countsimilar++; }
    }
    
    /* 8 point */
    int c;
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start4, end4;
    nanoseconds time4;

    start1 = steady_clock::now();

    /* Individual homework */
    int array3[sizear];
    for (int i = 0; i < sizear; i++)
    {
        if (i == sizear - 1) { array3[i] = array1[i] + array1[0]; }
        else { array3[i] = array1[i] + array1[i + 1]; }
    }
    int k;
    for (int i = 0; i < sizear; i++)
    {
        k = rand() % 100 + (0);
        c = array3[i];
        array3[i] = array3[k];
        array3[k] = c;
    }
    int count1 = sizear, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0, count7 = 0, count8 = 0, count9 = 0;
    for (int i = 0; i < sizear; i++)
    {
        if (array3[i] % 2 == 0) { count2++; }
        if (array3[i] % 3 == 0) { count3++; }
        if (array3[i] % 4 == 0) { count4++; }
        if (array3[i] % 5 == 0) { count5++; }
        if (array3[i] % 6 == 0) { count6++; }
        if (array3[i] % 7 == 0) { count7++; }
        if (array3[i] % 8 == 0) { count8++; }
        if (array3[i] % 9 == 0) { count9++; }
    }


    /* Choosing an item */
    int x = 1;
    while (x)
    {
        cout << endl << "Select an item: " << endl <<
            "1. Show an unorganised array." << endl <<
            "2. Show an organised array (with time)." << endl <<
            "3. Show max element and min element of array (with time.)" << endl <<
            "4. Show an average of min and max elements, indexes of equal elements, their numbers." << endl <<
            "5. Show number of elements that are less than your number. " << endl <<
            "6. Show number of elements that are greater than your number. " << endl <<
            "7. Show if your number is in the array. " << endl <<
            "8. Swap array elements. " << endl <<
            "9. Individual homework. " << endl <<
            "0. Stop working with code." << endl;
        cin >> x;
        switch (x)
        {
        case 1:
            for (int i = 0; i < sizear; i++)
            {
                cout << array1[i] << ' ';
                if ((i+1) % 20 == 0) { cout << endl; }
            }
            break;
        case 2: 
            for (int i = 0; i < sizear; i++)
            {
                cout << array2[i] << ' ';
                if ((i + 1) % 20 == 0) { cout << endl; }
            }
            cout << "Time: " << time1.count() << " nanoseconds.";
            break;
        case 3: 
            cout << "Max element: " << maxel << endl;
            cout << "Min element: " << minel << endl;
            cout << "Time for organised array: " << time2.count() << " nanoseconds." << endl;
            cout << "Time for unorganised array: " << time3.count() << " nanoseconds." << endl;
            break;
        case 4:
            cout << "An average of max and min elements: " << average << endl;
            if (countsimilar > 0)
            {
                cout << "Indexes of equal elements in unorganised array: ";
                search(array1, average, sizear); 
                cout << endl << "Indexes of equal elements in organised array: ";
                search(array2, average, sizear);
                cout << endl << "Their numbers: " << countsimilar << endl;
            }
            else { cout << "There are no equal elements." << endl; }
            break;
        case 5:
            cout << "Enter your number: ";
            int anumber;
            cin >> anumber;
            cout << "The number of elements that are less than your number: " << lessthana(array1, anumber, sizear) << endl;
            break;
        case 6: 
            cout << "Enter your number: ";
            int bnumber;
            cin >> bnumber;
            cout << "The number of elements that are greater than your number: " << morethanb(array1, bnumber, sizear) << endl;
            break;
        case 7:
            cout << "Enter your number: ";
            int cnumber;
            cin >> cnumber;
            if (binarysearch(array2, cnumber, sizear) == -1) { cout << "Your number was not found." << endl; }
            else { cout << "Your number has index: " << binarysearch(array2, cnumber, sizear) << endl; }
            break;
        case 8:
            cout << "Enter index of first element: ";
            int dnumber;
            cin >> dnumber;
            cout << "Enter index of second element: ";
            int enumber;
            cin >> enumber;
            start4 = steady_clock::now();
            c = array1[dnumber];
            array1[dnumber] = array1[enumber];
            array1[enumber] = c;
            end4 = steady_clock::now();
            time4 = duration_cast<nanoseconds>(end4 - start4);
            for (int i = 0; i < sizear; i++)
            {
                cout << array1[i] << ' ';
                if ((i + 1) % 20 == 0) { cout << endl; }
            }
            cout << "Time: " << time4.count();
            break;
        case 9:
            cout << "New array: " << endl;
            for (int i = 0; i < sizear; i++)
            {
                cout << array3[i] << ' ';
                if ((i + 1) % 20 == 0) { cout << endl; }
            }
            cout << "The number of elements divisible by 1: " << count1 << endl;
            cout << "The number of elements divisible by 2: " << count2 << endl;
            cout << "The number of elements divisible by 3: " << count3 << endl;
            cout << "The number of elements divisible by 4: " << count4 << endl;
            cout << "The number of elements divisible by 5: " << count5 << endl;
            cout << "The number of elements divisible by 6: " << count6 << endl;
            cout << "The number of elements divisible by 7: " << count7 << endl;
            cout << "The number of elements divisible by 8: " << count8 << endl;
            cout << "The number of elements divisible by 9: " << count9 << endl;
            break;
        case 0: 
            break;
        default: 
            cout << "Error, try again." << endl;
        }
        if (x == 0) { break; }
        system("pause");
    }

	return 0;
}