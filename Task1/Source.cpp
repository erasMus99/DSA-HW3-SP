#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif


using namespace std;

int arr[21][41];

void deploy_arr(int arr[][41])
{
    for (unsigned i = 0; i < 21; i++)
    {
        for (unsigned j = 0; j < 41; j++)
        {
            arr[i][j] = 0;
        }
    }
}

void display(int arr[][41])
{
    for (unsigned i = 0; i < 21; i++)
    {
        for (unsigned j = 0; j < 41; j++)
        {
            if (arr[i][j] == 0 && (i != 21 || j != 41))
                cout << "- ";
            else if (arr[i][j] == 0 && (i == 21 || j == 41))
                cout << "-";
            else if (arr[i][j] == 1)
                cout << "+ ";
            else if (arr[i][j] == 2)
                cout << "0";
        }
        cout << endl;
    }
    cout << endl;
}

void display_and_resolve(int arr[][41])
{
    unsigned aX;
    unsigned aY;
    unsigned bX;
    unsigned bY;
    cout << "Enter value for A x: ";
    cin >> aX;
    cout << "Enter value for A y: ";
    cin >> aY;
    cout << "Enter value for B x: ";
    cin >> bX;
    cout << "Enter value for B y: ";
    cin >> bY;

    arr[aX][aY] = 1;
    arr[bX][bY] = 2;

    display(arr);

    for (aX; aX != bX; aX++)
    {

        system("clear");
        //system("cls")
        arr[aX - 1][aY] = 0;
        arr[aX][aY] = 1;
        display(arr);
        sleep(1);
    }

    //Clearing the +
    arr[aX][aY] = 0;

    for (aY; aY != bY; aY++)
    {

        system("clear");
        //system("cls")
        arr[aX][aY - 1] = 0;
        arr[aX][aY] = 1;
        display(arr);
        sleep(1);
    }
}


int main()
{

    deploy_arr(arr);
    display_and_resolve(arr);
    return 0;
}
