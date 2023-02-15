library(BSDA)
library(MASS)
library(readr)
library(dplyr)
library(ggplot2)
library(car)

# Two sample z test
# Hypotheses:
# H0 : μ1−μ2=d0, H1 : μ1−μ2≠d0
# H0 : μ1−μ2≤d0, H1 : μ1−μ2>d0
# H0 : μ1−μ2≥d0, H1 : μ1−μ2<d0

# z test
# 使用時機:大樣本(可用樣本變異數取代母體變異數)
# 或抽樣的群體本身為常態分佈且母體變異數"已知"
# 1.檢定A班與B班的平均身高是否有差異(大樣本, 母體變異數A班=4, B班=3)
# H0 : μ1−μ2=0, H1 : μ1−μ2≠0
height_a <- c(
    180, 162, 162, 165, 170, 172, 172, 172, 175, 178,
    176, 176, 170, 172, 173, 168, 177, 164, 155, 157,
    175, 157, 150, 153, 177, 173, 155, 158, 163, 163
)
height_b <- c(
    188, 165, 163, 167, 170, 177, 178, 179, 155, 155,
    177, 180, 163, 163, 170, 175, 176, 164, 168, 178,
    179, 168, 169, 174, 177, 175, 170, 172, 167, 157
)

z.test(height_a, height_b, "two.sided",
    mu = 0, sigma.x = 4,
    sigma.y = 3, conf.level = 0.95
)
# z = -3.615, p-value = 0.0003004, 拒絕H0, 表示兩班的平均身高具有差異

# 2.同上，若兩組母體變異數都未知時
z.test(height_a, height_b, "two.sided",
    mu = 0, sigma.x = sqrt(var(height_a)),
    sigma.y = sqrt(var(height_b)), conf.level = 0.95
)
# z = -1.5535, p-value = 0.1203, 不拒絕H0, 表示兩班的平均身高相等

# 3.檢定A班平均體重是否大於B班3公斤(大樣本, 母體變異數A班=3, B班=3)
# H0 : μ1−μ2<=3, H1 : μ1−μ2>3
# 小樣本，但母體變異數已知
weight_a <- c(80, 72, 65, 50, 48)
weight_b <- c(70, 66, 51, 55, 73)
z.test(weight_a, weight_b, "greater",
    mu = 3, sigma.x = 3,
    sigma.y = 3, conf.level = 0.95
)
# z = -1.5811, p-value = 0.9431, 不拒絕H0, 表示A班的平均體重小於等於3公斤

# 練習:鳶尾花資料集
str(iris)

# 1.平均的花萼和花瓣長度是否有差異?
z.test(iris$Sepal.Length, iris$Petal.Length, "two.sided",
    mu = 0, sigma.x = sqrt(var(iris$Sepal.Length)),
    sigma.y = sqrt(var(iris$Petal.Length)), conf.level = 0.95
)

# 2.平均的花萼寬度是否小於花瓣寬度1公分?
z.test(iris$Sepal.Width, iris$Petal.Width, "less",
    mu = 1, sigma.x = sqrt(var(iris$Sepal.Width)),
    sigma.y = sqrt(var(iris$Petal.Width)), conf.level = 0.95
)

# 迴圈
month.name
month.name[1]
month.name[5:8]

# for迴圈
# for (i in x){
# 每次迭代要執行的程式
# }

for (i in month.name) {
    print(i)
}

# 計算 1+2+3+4...+100 的值是多少？
result <- 0

for (i in c(1:100)) {
    result <- result + i
}

result

# break 及 next
# break 主要用來跳出迴圈
for (i in c(1:5)) {
    if (i == 3) break # 當i等於3的時候，跳出迴圈
    print(i)
}

# next 主要用來省略此次迴圈的行為，直接進入下一次迴圈
for (i in c(1:5)) {
    if (i == 3) next # 當i等於3的時候，省略此次迴圈(skip)的動作，從下一個i=4開始
    print(i)
}

# while迴圈
# while (某種條件){
# 每次迭代要執行的程式
# }

i <- 1
while (i < 13) {
    print(month.name[i])
    i <- i + 1
}

# 練習 (While)：計算 1+2+3+4...+100 的值
result <- 0
i <- 1
while (i < 101) {
    result <- result + i
    i <- i + 1
}

print(result)

# 'repeat' - loop (與while類似)
# 計算 1+2+3+4...+100 的值
i <- 1
result <- 0
repeat {
    if (i > 100) break # 當i比100大時，用break跳出迴圈

    result <- result + i
    i <- i + 1
}
result

# apply家族
# 1.apply:可應用在data frame or matrix，並依照我們的function回傳一個list or vector
# apply(x, margin, function )
# 1:row, 2:column(決定計算的方向)
# 建一個 'matrix' (若要依照row填入資料則需加入byrow = TRUE)
sample_matrix <- matrix(1:10, nrow = 3, ncol = 10) # 預設是按照 column 填入資料
sample_matrix

# 利用 apply() function 獲得"每列"的總和
apply(sample_matrix, 1, sum)

# 利用 apply() function 獲得"每行"的平均
apply(sample_matrix, 2, mean)

# 2.lapply:輸入的資料可以是data frame, list, or vector，並依照我們的function回傳一個list
# 使用 'lapply(x, func)'

# 建一個vector
names <- c("Amy", "Berry", "Kate", "John", "Dora")
names[[1]]

# 利用 lapply() function 將vector中的值全部轉成大寫
lapply(names, toupper) # 方法 'toupper(x)' -> 轉成大寫; 'tolower(x)' -> 轉成小寫

# 3.sapply:與lapply可輸入的資料型態相同，但回傳的值是array或matrix
# 使用 'sapply(x, func)'

# 建一個dataframe
df <- data.frame(x = c(1, 2, 3, 4, 5, 6), y = c(3, 2, 4, 2, 34, 5))
df

# 利用 sapply() function找出dataframe中最大的值
sapply(df, max)

# 練習
# 1.建一個matrix -> 1~100, 20行5列, 按照row填入資料, 並計算每列的平均數
sample_matrix <- matrix(1:10, nrow = 5, ncol = 20, byrow = TRUE)
sample_matrix
apply(sample_matrix, 1, mean)

# 2.建一個list -> 第一維放一個matrix(1~4, 2列2行, 依照column填入資料)
# 第二維放vector(5~20), 得出這兩維的最小值
list_a <- list(matrix(1:4, nrow = 2, ncol = 2), c(5:20))
list_a
lapply(list_a, min)


# 讀取csv檔
getwd() # 查詢路徑
setwd("C:/Users/eddie/OneDrive/文档/GitHub/coding-stuff-I-make-from-learning/R/lab3") # 設定路徑
dataset <- read_csv("test_scores.csv")
str(dataset)
head(dataset) # 查看前6筆資料

set.seed(123)

# Sample rows of data with Base R
data_s1 <- dataset[sample(1:nrow(dataset), 200), ]
data_s1

ggplot(data_s1, aes(x = as.factor(school_setting), y = pretest)) +
    geom_boxplot() # 學校位置與pretest的關係

# 單因子變異數分析(one-way ANOVA)
# 比較多組之間的平均數差異
# 前提假設：
# 1.自變數為類別變數(x)，依變數必須是連續變數(y)
# 2.母群體必須是常態分佈(Normal Distribution)
# 3.獨立樣本
# 4.變異數同質性(兩組樣本的母體變異數必須相等)

# 常態性檢測
# 1.繪製 QQ plot
ggplot(data_s1, aes(sample = pretest)) +
    stat_qq() +
    stat_qq_line()

# 2.Shapiro-Wilk 檢定
# H0: 母體資料為常態分布
# H1: 母體資料不為常態分布

# p-value > 0.05，不拒絕 H0，資料符合常態分布。
# p-value < 0.05，拒絕 H0，資料不符合常態分布。

shapiro.test(data_s1$pretest)
# W = 0.98662, p-value = 0.0559
# p-value > 0.05，所以不拒絕 H0，表示符合常態分佈

# 直方圖
hist(data_s1$pretest)

# 資料轉換成常態的方法
# 1.取log
# 2.開根號

# 取log
shapiro.test(log(data_s1$pretest))
# W = 0.97655, p-value = 0.001982，不符合常態

# 開根號
shapiro.test(sqrt(data_s1$pretest))
# W = 0.98652, p-value = 0.05406，符合常態

# 變異數同質性檢定
# H0: σ1 = (...)=σk
# H1: 至少有兩組變異數不相等

# p-value > 0.05，不拒絕 H0，各組變異數相等。
# p-value < 0.05，拒絕 H0，至少有兩組變異數不相等。

# 1.Bartlett’s test(接近常態分佈時使用)
bartlett.test(pretest ~ as.factor(school_setting), data = data_s1)
# Bartlett's K-squared = 1.493, df = 2, p-value = 0.474
# p-value > 0.05，不拒絕 H0，表示各組變異數相等

# 2.Levene’s test
leveneTest(pretest ~ as.factor(school_setting), data = data_s1)
# p-value = 0.1365
# p-value > 0.05，不拒絕 H0，表示各組變異數相等

# ANOVA檢定
# H0:各組平均數皆相等
# H1:至少有兩組之間的平均數不相等
# F值愈大，組間差異愈大

# 不同學校位置的平均前側成績是否相等?
# H0:不同學校位置的平均前側成績皆相等
# H1:至少有兩個學校位置的平均前測成績不相等

res <- aov(data_s1$pretest ~ as.factor(data_s1$school_setting))
summary(res)
# F = 28.31，p-value = 1.56e-11
# p-value < 0.05，所以拒絕H0，表示至少有兩組之間的平均數不相等(具有差異)

# ANOVA事後檢定(Post hoc)：用Tukey法檢定兩兩之間是否有顯著性差異
# 當ANOVA結果各組有顯著差異時(也就是至少有兩組平均數不相等時)

# Tukey HSD test:
TukeyHSD(res, conf.level = .95)

# 視覺化
plot(TukeyHSD(res, conf.level = .95), las = 2)
# Suburban-Rural & Urban-Suburban 在95%信心水準之下存在顯著差異

# 練習
# 將第二個資料檔讀進去，並觀察各欄位的結構和代表意思為何
# 資料集:https://www.kaggle.com/datasets/uciml/student-alcohol-consumption
dataset2 <- read_csv("student-mat.csv")


# 視覺化
# 男女比率 圓餅圖
pie <- ggplot(dataset2, aes(x = "", fill = sex)) +
    geom_bar(width = 1) +
    coord_polar("y")
pie

# 年齡分布 直方圖
ggplot(dataset2) +
    geom_histogram(aes(x = age, fill = sex), bins = 30) # 性別在各年齡的分布

# G1成績 箱型圖
ggplot(dataset2) +
    geom_boxplot(aes(x = Mjob, y = G1)) # 不同母親工作的成績分佈

# 缺勤次數與G1成績的關係 散佈圖
ggplot(dataset2) +
    geom_point(aes(x = absences, y = G1))

# ANOVA
# 父親不同職業的平均G1成績是否相等?

# step1:常態性檢定
shapiro.test(dataset2$G1) # p-value<0.05, 拒絕H0, 表示母體資料不呈常態

shapiro.test(log(dataset2$G1)) # p-value<0.05, 拒絕H0, 表示母體資料不呈常態
# 假設母體資料呈常態

# step2:變異數同質檢定
leveneTest(G1 ~ as.factor(Fjob), data = dataset2)
# F = 1.6139, p-value = 0.17(>0.05), 所以不拒絕H0, 表示各組變異數相等

# H0:不同父親職業的平均G1成績皆相等
# H1:至少有兩種父親職業的平均G1成績不相等

res2 <- aov(dataset2$G1 ~ as.factor(dataset2$Fjob))
summary(res2)
# F = 3.692，p-value = 0.00578
# p-value < 0.05，所以拒絕H0，表示至少有兩種父親職業的平均G1成績不相等

# Tukey HSD test:
TukeyHSD(res2, conf.level = .95)

# 視覺化
plot(TukeyHSD(res2, conf.level = .95), las = 2)
# teacher-other & teacher-services 在95%信心水準之下存在顯著差異

# 練習
# 1.每周不同學習時間的G2成績是否相等?
# 2.若不相同, 那麼是否有哪些組別有顯著差異?

# ANOVA
# step1:常態性檢定
shapiro.test(dataset2$G2)

# step2:變異數同質檢定
leveneTest(G2 ~ as.factor(studytime), data = dataset2)

# H0: 不同學習時間的G2成績相等
# H1: 至少有兩種學習時間的G2成績不相等
res3 <- aov(dataset2$G2 ~ as.factor(dataset2$studytime))
summary(res3)
# F = 2.794, p-value = 0.0402
# 因為拒絕 H0 故至少有兩種學習時間的G2成績不相等

# 考試
# 1.畫出G3成績的箱型圖(不同健康狀態的G3成績分佈)
# 2.不同母親教育程度的G3平均成績是否有差異?
# 3.若有顯著差異，分別是哪幾組有顯著差異?

# 1. 畫出G3成績的箱型圖(不同健康狀態的G3成績分佈)
ggplot(dataset2) +
    geom_boxplot(aes(x = factor(health), y = G3))

# 2. 不同母親教育程度的G3平均成績是否有差異?
# ANOVA
# step1:常態性檢定
shapiro.test(dataset2$G3)
# p-value < 0.05 拒絕 H0 => 這不是常態

shapiro.test(sqrt(dataset2$G3))
# p-value < 0.05 拒絕 H0 => 這不是常態

# 假定資料呈現常態

# step2:變異數同質檢定
leveneTest(G3 ~ as.factor(Medu), data = dataset2)
# p-value > 0.05 不拒絕 H0 => 變異數相近

# 假設變異數接近

# H0: 不同母親教育程度的G3平均成績相等
# H1: 至少有兩種母親教育程度的G3平均成績不相等
res4 <- aov(dataset2$G3 ~ as.factor(dataset2$Medu))
summary(res4)
# F = 6.088, p-value = 9.24e-05
# 因為拒絕 H0 故至少有兩種母親教育程度的G3平均成績不相等

# 3. 若有顯著差異，分別是哪幾組有顯著差異?
TukeyHSD(res4, conf.level = .95)

# 視覺化
plot(TukeyHSD(res4, conf.level = .95), las = 2)

# 4-1 & 4-2 在 95% 信心水準下有顯著差異
