#include <iostream>
using namespace std;

int main()
{
    unsigned int N;

    cin >> N;

    if (N <= 0)
    {
        cout << "N <= 0" << endl;
        return 0;
    }

    int arr[N][2];
    int res[N];

    for (int i = 0; i < N; i++)
    {
        arr[i][0] = N - i;
        cin >> arr[i][1];
    }

    cout << endl;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[j][1] == i)
            {
                res[i - 1] = arr[j][0];
                break;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << res[i] << endl;
    }

    return 0;
}