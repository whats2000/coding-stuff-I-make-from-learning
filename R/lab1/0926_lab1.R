library(dplyr)


# 查詢
?c
help(c)
# 查看已經載入的 package
search()
data() #R語言內建的資料集

# ctrl + L 清除console
# 使用 "<-" 賦值 (alt + -)
x <- 1
print(x) # 等同直接打 x
y <- "hello"
print(y)
z <- c(1:3) # 向量等於 "c(1, 2, 3)"
print(z)
rm(x)

# 透過class得知變數型別(也可用str)
class(20) # 數值類型，無論有無小數點，R預設都會存成numeric
class(2.5)
class(y) # 文字類型
class("你好") # '' or "" 皆可建立文字

class(z) # 整數類型
class(2)
class(2L)
class(2.5L)
aa <- 2.5L
class(aa)

class(TRUE) # 等同 "class(T)" 邏輯值類型
class(FALSE) # 等同 "class(F)"
class(True)
8 < 7
7 %in% c(8, 7) # 判斷 7 是否包含於 c(8, 7) 的向量之中

# 日期
date <- Sys.Date() # 系統日期
date
class(date)
as.integer(date)
# R 語言預設以西元 1970 年 1 月 1 日作為 0，
# 在這一天以後的每天都 +1 來記錄，而這一天以前的每天都 -1 來記錄。

date_char <- as.character(date) # 創造一個文字類型
date_char
class(date_char)
as.integer(date_char) # 文字無法轉成整數型態
# 轉換失敗時會產生NA值(遺失值)
date_of_origin <- as.Date("1970-01-01")
as.integer(date_of_origin)
as.integer(date_of_origin + 1)
as.integer(date_of_origin - 1)

date_of_origin + 1
date_of_origin - 1
date_char + 1

#時間
time <- Sys.time() # 系統時間
time # 看起來跟文字相同
class(time)
as.integer(time)
# R 語言預設以西元 1970 年 1 月 1 日格林威治標準時間（Greenwich Mean Time，GMT）00 時 00 分 00 秒
# 作為 0，在這個時間點以後的每秒都 +1 來記錄，這個時間點以前的每秒都 -1 來記錄。
time_of_origin <- as.POSIXct("1970-01-01 00:00:00", tz = "GMT")
as.integer(time_of_origin)
as.integer(time_of_origin + 1)
as.integer(time_of_origin - 1)

time_of_origin + 1
time_of_origin - 1

# 基本數學運算
# 加減乘除(+ - * /)

# 次方
2 ^ 5
2 ** 5

# 回傳商數
15 % / % 2

# 回傳餘數
15 % % 2

# 一般除法
15 / 2

# R 語言自動把答案轉換成了適當型別(R語言的彈性)
class(2 + 2) # 數值類型的運算
class(2L + 2L)
class(2 + 2L)
class(2L + 8 + TRUE)
2L + 8 + TRUE #1 1
# 在 R 語言中，TRUE 跟 1 或者 1L 是相等的；FALSE 跟 0 或者 0L 是相等的。

# 自訂function
add <- function(x, y) {
  return(x + y)
}
add(5, 8)

my_mean <- function(x) {
  m <- sum(x) / length(x)
  return(m)
}
my_mean(1:10)

# 練習
# 自訂一個函數 get_bmi(height, weight)
get_bmi <- function(height, weight) {
  return(weight / (height / 100) ^ 6)
}
get_bmi(172, 65)
# [1] 21.97134

# 變數型別的判斷 (數值/整數/文字/邏輯值) 都是 "is.xxx"
# 判斷是否為數值
is.numeric(8.7)
is.numeric("10")

# 判斷是否為整數
is.integer(7)
is.integer(80L)

# 判斷是否為邏輯值
is.logical(FALSE)
is.logical(False)

# 判斷是否為文字
is.character("TRUE")
is.character(TRUE)

# 判斷是否為日期 or 時間(inherits(x, what = "Date"/"POSIXct"))
inherits(Sys.Date(), what = "Date") # Sys.Date() 是日期型別
inherits("1970-01-01", what = "Date") # "1970-01-01" 是文字型別

inherits(Sys.time(), what = "POSIXct") # Sys.time() 是時間型別
inherits("1970-01-01 00:00:00", what = "POSIXct") # "1970-01-01 00:00:00" 是文字型別

# 變數型別的轉換(as.型別名稱())
# 轉換成數值 (輸入整數、邏輯值、日期或時間都可以轉換成數值。)
as.numeric(7L)
as.numeric(TRUE)
as.numeric(FALSE)
as.numeric(Sys.Date())
as.numeric(Sys.time())

# 轉換成整數 (可以輸入數值、邏輯值、日期或時間轉換成整數。)
as.integer(7)
as.integer(-7.84545)
as.integer(TRUE)
as.integer(FALSE)
as.integer(Sys.Date())
as.integer(Sys.time())

# 轉換成邏輯值
as.logical(0)
as.logical(0L)
as.logical(1L)
as.logical(-1.3) # 非 0 的數字都會轉成 TRUE
as.logical(87)

# 輸入文字型別的 "TRUE"、"True" 或 "true" 則會轉換成為 TRUE，反之亦同。
as.logical("TRUE")
as.logical("True")
as.logical("true")
as.logical("FALSE")
as.logical("False")
as.logical("false")

# 轉換成文字(可以輸入任意的變數型別轉換成文字。)
as.character(8.7)
as.character(87L)
as.character(TRUE)
as.character(Sys.Date())
as.character(Sys.time())

# 轉換成日期(預設可以識別 %Y-%m-%d 或 %Y/%m/%d 這兩種格式)
as.Date("2022-09-20")
as.Date("2021/09/01")
as.Date("01-10-2022") # 轉換錯誤
as.Date("01-10-2022", format = "%m-%d-%Y") # 轉換正確
as.Date("4/11/2022", format = "%m/%d/%y") # 轉換正確
# 常見的符號代表格式 %m = 月, %d = 日, %Y = 四位數的年, %y = 兩位數的年

# 轉換成時間
as.POSIXct("2022-10-01 00:00:00") # 如果沒有指定參數"tz="會預設使用電腦的時區。
as.POSIXct("2022-08-17 00:00:00", tz = "GMT")

# 資料結構
# 向量"vector" 使用 c()
a <- c(5, 10, 15, 20, 25)           # 建立一個number vector
b <- c("Tom", "Henry", "John")  # 建立一個character vector
str(a)
str(b)

a[1] # 透過索引取值
b[3]
a[1:3]
a[c(2, 4)] # 取第2和第4個element
aa <- a[c(-2, -4)] # 刪除第2和第4個element
aa
my_lucky_number <- a == 15 # 利用判斷運算子來對向量進行篩選
a[my_lucky_number]

# 除了手動建 c()，還有其他快速建立的方式
# rep() 函數可以生成"重複"變數的向量
rep(7L, times = 8)
rep("R", times = 10)

# seq()函數可以生成等差數列
seq(from = 7, to = 77, by = 7)
seq(from = 1, to = 10, by = 1) # 等於1:10

# sample()隨機產生一個向量
sample(x = 1:100, size = 10)  # 從1~100數字中，隨機挑10個數字，產生一個數列(vector)

# 可以透過：order(), sort()進行排序
a[order(a, decreasing = TRUE)]   # 把數列由大排到小, decreasing=FALSE則由小到大
sort(a, decreasing = TRUE)

# 在vector裡有個需要注意的規則 -「每一個element」都會是相同的型態!!
a1 <- c(1, "john", 3)
str(a1)
b1 <- c(TRUE, 3, FALSE)
str(b1)

# vector 間也可以進行數學運算
a2 <- c(7, 8, 6, 9, 5)
b2 <- c(2, 4, 6, 0, 1)
a2 * b2
b2 ^ 3
b2 > 3

# 重要!! 類別變數 (factor)(category variable)
gender <- c("boy", "girl", "boy", "boy", "girl")  # 建立一個character vector
gender <- factor(gender)   # 轉換成factor型態
gender # Levels(層級) 的屬性代表:在這個變數裡面，存在哪些類別
levels(gender)

gender <- factor(gender, ordered = TRUE, levels = c("boy", "girl")) #小 到 大
gender

gender <- factor(gender, ordered = TRUE) # 預設使用字母順序排序
gender

# 列表(list)
jay <- list(gender = "man", age = 18, hobby = c("tease", "be teased"))
jay
str(jay) #list可以存放"任何型態"的變數
jay$hobby        # Dr.Lee的嗜好
jay$age
jay[[3]]
jay[3]
str(jay[[3]])     # 取出來的資料是vector
str(jay[3])       # 取出來的資料是list

# 矩陣(matrix)
m <- matrix(c(1:6), nrow = 3, ncol = 2) # 建立一個3x2的矩陣(預設會依"欄"填入)
m
m1 <- matrix(c(1:6), nrow = 3, ncol = 2, byrow = TRUE) # 建立一個3x2的矩陣(預設會依"欄"填入)
m1

n <- matrix(c(3:8), nrow = 2, ncol = 3) # 建立一個2x3的矩陣
n
n1 <- matrix(c(3:8), nrow = 2, ncol = 3, byrow = TRUE) # 建立一個2x3的矩陣
n1

n1[1, 3]
n1[1, ]
n1[, 3]

mat <- matrix(c(0, 2, TRUE, FALSE, 3, 4), nrow = 2)
mat # 與向量類似，只能包含一種變數型態

# "重要!!" 資料框(dataframe)
team_name <- c("Chicago Bulls", "Golden State Warriors")
wins <- c(72, 73)
losses <- c(10, 9)
is_champion <- c(TRUE, FALSE)
season <- c("1995-96", "2015-16")
great_nba_teams <- data.frame(team_name, wins, losses, is_champion, season)
id <- c(1, 2)
great_nba_teams <- cbind(great_nba_teams, id) # 新增一個欄位
great_nba_teams["total_games"] <- great_nba_teams$wins +
    great_nba_teams$losses # 另一種新增欄位的方式

great_nba_teams
nrow(great_nba_teams) # 共有幾列(筆)

str(great_nba_teams)

great_nba_teams[, 1]
# 等於great_nba_teams[ ,"team_name"] 也等於great_nba_teams$team_name

# 敘述統計函式
# 使用R內建的鳶尾花資料(iris)
str(iris)
summary(iris)
mean(iris$Sepal.Length)     # 「花萼長度」的平均值
var(iris$Sepal.Length)      # 「花萼長度」的變異數
sd(iris$Sepal.Length)       # 「花萼長度」的標準差
median(iris$Sepal.Length)   # 「花萼長度」的中位數
max(iris$Sepal.Length)      # 「花萼長度」中的最大值
min(iris$Sepal.Length)      # 「花萼長度」中的最小值
sum(iris$Sepal.Length)      # 「花萼長度」加總
range(iris$Sepal.Length)    # 「花萼長度」最小值和最大值(全距)
quantile(iris$Sepal.Length, probs = 0.25)  # 第一四分位數
# prob=0.1，就代表「在連續分布上，對應到機率0.1的那個點是多少」

# 請建立一個dataframe("Student_info")資料如下
# "student": Bob,Nick,Mary,Harry,John，"studentID": 1, 5, 9, 13, 8
# "math_score": 80, 75, 60, 90, 85
# "reading_score": 75, 85, 90, 65, 70
# "listening_score": 40, 70, 85, 70, 90
# 新增一欄:"total_score"將每位學生的三科成績做加總，
# 新增一欄:"average_score"將每位學生的三科成績做平均
student <- c("Bob", "Nick", "Mary", "Harr", "John")
student_id <- c(1, 5, 9, 13, 8)
math_score <- c(80, 75, 60, 90, 85)
reading_score <- c(75, 85, 90, 65, 70)
listening_score <- c(40, 70, 85, 70, 90)

student_info <- data.frame(
    student,
    student_id,
    math_score,
    reading_score,
    listening_score
)
student_info
student_info["total_score"] <- math_score + reading_score + listening_score
student_info
student_info["average_score"] <- student_info["total_score"] / 3
student_info

# 載入gapminder 資料
library(gapminder)
# "install.packages("gapminder")"
head(gapminder) # 預設看前6筆資料
head(gapminder, 10)
tail(gapminder)
str(gapminder)

# %>% 連結上數函式，將所有函式計算串在一起執行
f1 <- gapminder %>%
  filter(year == 2007)

f1

s1 <- gapminder %>%
  filter(year == 2007) %>%
  select(country)

s1

# 新增衍生變數(新增欄位) "mutate"
gapminder_new <- gapminder %>%
  mutate(pop_in_thousands = pop / 1000)

gapminder_new

# 排序(arrange)
gapminder_new <- gapminder_new %>%
  arrange(year)

gapminder_new

# 聚合變數
# 在summarise()函數中輸入想要聚合的變數名稱與聚合公式，
# 聚合運算的結果通常是一個數字，代表某個數列的運算結果，
# 像是總和、平均數或標準差都是聚合運算的結果，舉例來說，
# 我們可以算gapminder中2007年全球的人口數
sum1 <- gapminder %>%
  filter(year == 2007) %>%
  summarise(ttl_pop = sum(pop))

sum1

# 聚合函數的運算常常會搭配 group_by() 函數一起使用
# 計算 gapminder 中 2007 年各洲的人口數
sum2 <- gapminder %>%
  filter(year == 2007) %>%
  group_by(continent) %>%
  summarise(ttl_pop = sum(pop))

sum2

# 重新命名欄位名稱(rename)
rename1 <- rename(gapminder, Cont = continent)
rename1

# 練習
# 有幾筆資料是continent為Asia的?
sum3 <- gapminder %>%
  filter(continent == "Asia") %>%
  summarise(count = n())

sum3

# 視覺化
# "install.packages("ggplot2")"
library(ggplot2)
# 散佈圖(y一定要是連續變數) 當x&y都為連續變數時，就能檢視二個變數的關聯性,大小,方向,趨勢
# 每個人的GDP和預期壽命之間的關係
scatter_plot <- ggplot(f1, aes(x = gdpPercap, y = lifeExp)) +
    geom_point() +
    geom_smooth(method = "lm")

scatter_plot # 正相關

# 折線圖
north_asia <- gapminder %>%
  filter(country %in% c("China", "Japan", "Taiwan", "Korea, Rep.")) #篩出北亞地區國家
# 看這幾個國家這幾年的GDP趨勢為何?
line_plot <- ggplot(
    north_asia, aes(
        x = year,
        y = gdpPercap,
        colour = country
        )
) + geom_line()

line_plot

# 直方圖
# 看GDP的分佈
hist_plot <- ggplot(f1, aes(x = gdpPercap)) +
    geom_histogram(bins = 20) # 分箱數(bins)使用了30個分箱預設值

hist_plot

# 盒鬚圖
# 北亞那四個國家的GDP分佈
box_plot <- ggplot(f1, aes(x = continent, y = gdpPercap)) +
    geom_boxplot()

box_plot

# 長條圖
gdp_percap_2007_na <- gapminder %>%
    filter(year == 2007 & country %in% c(
        "China",
        "Japan",
        "Taiwan",
        "Korea, Rep."
    )) # 篩出2007年這四個國家的資料

bar_plot <- ggplot(gdp_percap_2007_na, aes(x = country, y = gdpPercap)) +
  geom_bar(stat = "identity")
bar_plot
# stat預設值為”stat0_count”，即每個x資料點對應的資料次數。
# 如果希望bar圖的高度呈現資料值，則須將stat = “identity”。

# 考試
# 資料集：mtcars
mtcars
# 1.裡面的車子油耗平均為多少?標準差為多少?第三分位數為何?
mean(mtcars$mpg)
sd(mtcars$mpg)
quantile(mtcars$mpg, probs = 0.75)

# 2.篩選出車重超過3.5的車型有哪些?共有幾筆?
target <- mtcars %>%
    filter(mtcars["wt"] > 3.5) %>%
    select(wt)

target

sum(target$wt > 3.5)

# 3.(a.)請畫出車重VS油耗的散佈圖，觀察之間有何關係，(b.)並將你觀察的結果寫出來
# (a.)
plot <- ggplot(mtcars, aes(x = wt, y = mpg)) +
    geom_point() +
    geom_smooth(method = "lm")

plot
# (b.) 根據觀察，wt 與 mpg 呈現負相關，
# 車越重(wt越高)，油耗越高(mpg越低)
