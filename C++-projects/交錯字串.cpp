#include <iostream>
#include <string>

using namespace std;

// 取得字母大小寫
char letterCase(char c)
{
    if(islower(c)) return 'l';
    if(isupper(c)) return 'u';
    return 'n';
}

int main(void) {
    int k;
    string str;

    while(cin >> k)
    {
        int g = 0;      // 交錯字串最大長度
        int cg = 0;     // 目前交錯字串長度
        cin >> str;
        int len = str.length();

        char preL = 'n';    // 上一個字母是大寫u、小寫 l、未知n。
        char curL;          // 目前字母是大寫u、小寫 l、未知n。
        int ck = 0;         // 目前字母case累積次數

        //  k 為 1 時要另外處理
        if(k == 1)
        {
            for(int i = 0; i < len; i++)
            {
                curL = letterCase(str[i]);      // 取得字母大小寫
                if(preL != curL)    // 轉換大小寫時
                    cg++;
                else                // 沒轉換大小寫時
                {
                    g = max(cg, g);     // g 和 cg 誰是最大交錯字串長度
                    cg = 1;
                }

                preL = curL;        // 上一個字母case為目前字母case
            }
        }
        else
        {
            for(int i = 0; i < len; i++)
            {
                curL = letterCase(str[i]);

                if(preL == curL)
                {
                    ck++;
                    if(ck == k)             // 累積到 k 次
                    {
                        cg += k;            // 加到目前交錯字串長度
                        g = max(cg, g);     // g 和 cg 誰是最大交錯字串長度
                    }

                    if(ck > k)              // 目前case次數超過 k 次
                        cg = k;             // 目前交錯字串長度也只能等於 k
                }
                else if(preL != curL)       // 轉換大小寫時
                {
                    if(ck < k) cg = 0;      // 目前case次數小於 k 次，目前交錯字串長度歸零
                    ck = 1;                 // case次數從 1 開始
                }
                preL = curL;                // 上一個字母case為目前字母case
            }
        }

        cout << g << endl;
    }
    return 0;
}