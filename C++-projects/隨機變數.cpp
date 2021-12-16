#include <functional>
#include <random>
#include <chrono>
#include <iostream>

int main()
{
 std::random_device rd;                       // 種子產生器
 std::uniform_real_distribution<> dis(-1, 1); // 使用平均分佈

 auto seed = std::time(nullptr) ^ std::random_device()(); // 確保 random_device 沒正常工作下依然能使用
 std::mt19937 gen(seed);

 auto randfun = std::bind(dis, gen); // 將引擎和分佈綁在一起變成新函數 randfun

 std::cout << randfun() << ' ' << randfun() << ' ' << randfun() << std::endl; // 可以直接重複呼叫
}
