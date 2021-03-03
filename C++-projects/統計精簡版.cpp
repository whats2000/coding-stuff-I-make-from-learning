#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "成績統計\n請輸入統計人數:";
  //  while (cin >> n)
//    {
		cin >> n;)
        int ar[n],maxn = 0,minn=100,total=0,count[n];
        float average;
        for (int i = 0 ; i < n ; i++)
        {
            cout << "第" << i+1 << "號的成績:";
            cin >> ar[i];
        }
        for (int i = 0 ; i < n ; i++) 									cout << "輸入的第" << i+1 << "為" << ar[i] << "分" << endl;
        cout << "執行最終運算" << endl;
        for(int i = 0 ; i < n ;i++)
        {
        	if (ar[i] > maxn)
            {
                maxn = ar[i];
            }
            if (ar[i] < minn)
            {
                minn = ar[i];
            }
            total = total + ar[i];
        }
        average = total / n;
        cout << "===========================" << endl;
        cout << "最高分為" << maxn <<"分 號碼是" << endl;
        for (int i = 0 ; i < n ; i++)
        {
            if (ar[i] == maxn) 
            cout << i+1 <<"號 ";
        }
        cout << "\n最低分為"<< minn <<"分 號碼是" << endl;
        for (int i = 0 ; i < n ; i++)
        {
            if (ar[i] == minn) 
            cout << i+1<< "號 ";
        }
        cout << "\n總分為" << total;
        cout << "\n平均為" << average;
//    }
    return 0;
}