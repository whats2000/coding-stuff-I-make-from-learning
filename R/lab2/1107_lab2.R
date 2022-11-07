library(ggplot2)
# 安裝 lib 'install.packages("gcookbook")'
library(gcookbook)

# function寫法  function(x,y..) {...return(...)}
# 最小值最大值正規化 (Min-Max Normalization) : 將原始資料的數據按比例縮放於 [0, 1] 區間中，且不改變其原本分佈
minmax <- function(x) {
    return((x - min(x)) / (max(x) - min(x)))
}
minmax(1:20)

## 練習寫出 Zscore 的公式
z_score <- function(x) {
    return((x - mean(x)) / sd(x))
}

z_score(1:10)

# 簡單抽樣
sample(1:6, 10, replace = TRUE) # 'replace = TRUE' 表示對已抽出之數字重新放回母體中

# 使用seed值，則隨機序列將重置為已知狀態。
# 此時R不會創建真正的隨機數，會創建偽隨數（pseudo-random numbers）
set.seed(1) # set.seed() 參數可以是任何整數值
sample(1:6, 10, replace = TRUE)

set.seed(8)
sample(1:6, 10, replace = TRUE)

# 試著用內建資料集 diamonds 取樣 (set.seed 設 123，取 5 筆，不可重複)
diamonds
str(diamonds)

set.seed(123)
s1 <- sample(1:nrow(diamonds), 300, replace = FALSE)
s1
s1 <- diamonds[s1, ]
s1

# ggplot
# 散佈圖(y一定要是連續變數)
ggplot(s1) +
    geom_point(aes(x = carat, y = price)) # 價格和克拉的關係
ggplot(s1) +
    geom_point(aes(x = carat, y = price, color = color, shape = cut))
# 加入color和cut的影響

# 直方圖(x需為連續型變數)
ggplot(s1) +
    geom_histogram(aes(x = price), bins = 30) # 價格分佈
ggplot(diamonds) +
    geom_histogram(aes(x = price, fill = color), bins = 30) # 加入 color 的影響
# 分組直方圖
ggplot(s1) +
    geom_histogram(aes(x = price, fill = cut), position = "dodge")
# 百分比直方圖
ggplot(s1) +
    geom_histogram(aes(x = price, fill = cut), position = "fill")

# 長條圖 (x為類別變數時)
ggplot(s1) +
    geom_bar(aes(x = clarity))
ggplot(s1) +
    geom_bar(aes(x = clarity, fill = color)) # 加入 color 的影響

# 箱型圖
ggplot(s1) +
    geom_boxplot(aes(x = cut, y = price)) # 不同切工下價格的分佈
ggplot(s1) +
    geom_boxplot(aes(x = cut, y = price, fill = color)) # 加入 color 的影響

# 密度圖
ggplot(s1) +
    geom_density(aes(x = price)) # 價格的概率分佈
ggplot(s1) +
    geom_density(aes(x = price, color = cut)) # 加入 cut 的影響
ggplot(s1) +
    geom_density(aes(x = price, color = color)) # 加入 color 的影響

# The Normal Distribution
# 機率密度(probability density)函数
# 'dnorm(x, mean = 0, sd = 1)' 得到的是x的機率分布高度
# x是一個機率密度函數 (PDF, Probability Density Function) 的獨立變量 (數字向量)
# 也能看成一組經過Z轉換後的一組變量
dnorm(0, mean = 0, sd = 1) # 標準常態機率密度函數
dnorm(0)
dnorm(-1)
dnorm(2, mean = 5, sd = 3) # 非標準常態機率密度函數

z_scores <- seq(-3, 3, 0.1)
z_scores
dvalues <- dnorm(z_scores)
dvalues # z_scores 的概率密度
plot(z_scores, dvalues,
    type = "l",
    main = "pdf of the Standard Normal",
    xlab = "Z-score"
)

# 累積分佈函數(CDF,Cumulative Distribution Function)
# 'pnorm(q, mean = 0, sd = 1)' 標準常態累積分布函數
# 會得到p-value
# q即是Z值
pnorm(2, mean = 0, sd = 1) # 負無窮大到Z值等於2的累積機率
pnorm(0)
pnorm(2, mean = 0, sd = 1, lower.tail = FALSE) # Z值等於2到正無窮大的累積機率

pvalues <- pnorm(z_scores)
pvalues
# cdf曲線
plot(z_scores, pvalues,
    type = "l",
    main = "cdf of the Standard Normal",
    xlab = "Z-score"
)

# 累積分佈函數的"反函數"
# 'qnorm(p, mean = 0, sd = 1)' 會得到z值
# p即是p-value
qnorm(0.5, mean = 0, sd = 1)
qnorm(0.5)
quantiles <- seq(0, 1, by = .05)
quantiles
qvalues <- qnorm(quantiles)
qvalues
# 百分位分布對應的Z-score
plot(quantiles, qvalues,
    type = "l",
    main = "標準常態分佈百分位數對應的Z-score",
    xlab = "Quantiles"
)

# 生成一組符合常態分布的隨機數
set.seed(100)
rnorm(5, mean = 0, sd = 1)
rnorm(5)
r10 <- rnorm(10, mean = 50, sd = 5) # 生成10個符合平均值為 50，標準差為5的常態分布的隨機數
r10
r100 <- rnorm(100, mean = 70, sd = 10) # 生成10個符合平均值為 50，標準差為5的常態分布的隨機數
r1000 <- rnorm(1000, mean = 60, sd = 5) # 生成10個符合平均值為 50，標準差為5的常態分布的隨機數

hist(r10, main = "常態分布圖")
hist(r100, main = "常態分布圖")
hist(r1000, main = "常態分布圖")

# 練習
# 1.求出Z-score = 2.5時的p-value為多少?(平均 = 10,標準差 = 3)

v1 <- pnorm(q = 2.5, mean = 10, sd = 3)
v1

# 2.畫一個機率密度曲線圖(生成一個數字向量:從-2~8, 間距 = 0.1, 平均 = 3,標準差 = 2)

v2 <- seq(-2, 8, 0.1)
dv2 <- dnorm(v2, mean = 3, sd = 2)
plot(v2, dv2, type = "l", main = "機率密度曲線圖")

# 3.畫一個常態分布圖(透過隨機生成的 50 個數字, set.seed = 123, 平均 = 5,標準差 = 2)

set.seed(123)
v3 <- rnorm(50, mean = 5, 2)
hist(v3, main = "常態分布圖")

# 區間估計
# μ 的信賴區間
# 大樣本或母體變異數"已知"使用"Z分布"
# 1.大樣本但母體變異數不知道，計算其母體平均數 μ 的 95% 信賴區間
big <- c(
    3.1, 3.5, 2.9, 3.8, 3.6, 2.5, 4.0, 3.3, 3.9, 2.8, 3.1,
    3.5, 2.7, 3.7, 3.6, 2.5, 4.5, 3.2, 3.9, 2.8, 3.3, 3.5,
    2.9, 3.8, 3.6, 2.4, 4.0, 3.3, 3.9, 2.8
)
mean.rangez <- function(x, alpha = 0.05, sigma) {
    n <- length(x) # n 為樣本數
    mx <- mean(x) # mx 即為平均值 mu 的點估計
    r1 <- qnorm(alpha / 2) # 左半邊 z-score
    r2 <- qnorm(1 - alpha / 2) # 右半邊 z-score
    l1 <- mx + r1 * sigma / sqrt(n) # 信賴區間下限
    l2 <- mx + r2 * sigma / sqrt(n) # 信賴區間上限
    return(range = c(l1, mx, l2)) # 信賴區間
}

z <- mean.rangez(big, sigma = sqrt(var(big)))
z

# 2.小樣本，但知道母體變異數為0.25(大樣本一樣)
small <- c(3.1, 3.5, 2.9, 3.8, 3.6, 2.5, 4.0, 3.3, 3.9, 2.8)
z2 <- mean.rangez(small, sigma = sqrt(0.25))
z2

# 母體變異數"未知" 且為小樣本 使用 "t 分布"
# t 分布則會使用到 'df'(自由度)
# 母體變異數為未知，計算其母體平均數 μ 的 95% 信賴區間

x2 <- c(3.1, 3.5, 2.9, 3.8, 3.6, 2.5, 4.0, 3.3, 3.9, 2.8)
mean.ranget <- function(x, alpha = 0.05) {
    n <- length(x) # n 為樣本數
    mx <- mean(x) # mx為平均值 mu 的點估計
    s <- sqrt(var(x)) # S 為標準差的點估計
    r1 <- qt(alpha / 2, df = n - 1) # 左半邊 z-score
    r2 <- qt(1 - alpha / 2, df = n - 1) # 右半邊 z-score
    l1 <- mx + r1 * s / sqrt(n) # 信賴區間下限
    l2 <- mx + r2 * s / sqrt(n) # 信賴區間上限
    return(range = c(l1, mx, l2)) # 信賴區間
}
t <- mean.ranget(x2)
t

# 變異數的信賴區間
# 計算其x2的變異數(σ2)信賴區間(95%信心水準)
var_range <- function(x, alpha = 0.05) {
    n <- length(x) # n 為樣本數
    r1 <- qchisq(alpha / 2, df = n - 1) # 左半邊卡方值 (小)
    r2 <- qchisq(1 - alpha / 2, df = n - 1) # 右半邊卡方值 (大)
    s2 <- var(x) # 樣本變異數
    l1 <- (n - 1) * s2 / r2 # 信賴區間下限
    l2 <- (n - 1) * s2 / r1 # 信賴區間上限
    return(range = c(l1, s2, l2)) # 信賴區間
}
v <- var_range(x2)
v

# 比例的信賴區間
x3 <- c(rep(0, 119), rep(1, 11))

mean.rangep <- function(x, alpha = 0.05) {
    n <- length(x) # n 為樣本數
    proport <- as.vector(table(x))
    p <- proport[2] / n # mx 即為平均值 mu 的點估計
    r1 <- qnorm(alpha / 2) # 左半邊 z-score
    r2 <- qnorm(1 - alpha / 2) # 右半邊 z-score
    l1 <- p + r1 * sqrt(p * (1 - p) / n) # 信賴區間下限
    l2 <- p + r2 * sqrt(p * (1 - p) / n) # 信賴區間上限
    range <- c(l1, p, l2) # 信賴區間
    return(range)
}
p <- mean.rangep(x3)
p

# 例題(p)
# 假設高雄市有 1580000 人，透過隨機抽樣 560 人，發現其中有 263 人支持興建愛情摩天輪
# 請估算高雄市支持愛情摩天輪比率 p 的 99 %信賴區間。
x3 <- c(rep(0, 297), rep(1, 263))
mean.rangep2 <- function(x, alpha = 0.01) {
    n <- length(x) # n 為樣本數
    proport <- as.vector(table(x))
    p <- proport[2] / n # mx 即為平均值 mu 的點估計
    r1 <- qnorm(alpha / 2) # 左半邊z-score
    r2 <- qnorm(1 - alpha / 2) # 右半邊z-score
    l1 <- p + r1 * sqrt(p * (1 - p) / n) # 信賴區間下限
    l2 <- p + r2 * sqrt(p * (1 - p) / n) # 信賴區間上限
    range <- c(l1, p, l2) # 信賴區間
    return(range)
}
p2 <- mean.rangep2(x3)
p2

# 練習題
# 1.假設要調查失業居民的年齡分布情況。現今針對失業居民進行隨機抽樣獲得 30 份樣本，
# 失業居民的年齡資料(單位：歲) 如下所示。假設母體失業居民的年齡分布標準差為 15.2 歲。
# 25 65 54 25 35 45 46 48 52 53
# 56 51 28 35 45 42 41 25 29 28
# 29 26 33 44 54 56 48 47 45 23
# 試估算在 90 %信賴水準下，失業居民年齡平均值之信賴區間。

age <- c(
    25, 65, 54, 25, 35, 45, 46, 48, 52, 53,
    56, 51, 28, 35, 45, 42, 41, 25, 29, 28,
    29, 26, 33, 44, 54, 56, 48, 47, 45, 23
)
mean.rangep3 <- function(x, alpha = 0.1, sigma) {
    n <- length(x) # n 為樣本數
    mx <- mean(x) # mx 即為平均值 mu 的點估計
    r1 <- qnorm(alpha / 2) # 左半邊 z-score
    r2 <- qnorm(1 - alpha / 2) # 右半邊 z-score
    l1 <- mx + r1 * sigma / sqrt(n) # 信賴區間下限
    l2 <- mx + r2 * sigma / sqrt(n) # 信賴區間上限
    return(range = c(l1, mx, l2)) # 信賴區間
}
p3 <- mean.rangep3(x = age, sigma = 15.2)
p3

# 2.
# 某速食餐廳欲對其消費者進行服務滿意度調查，受訪消費者只有兩個選項分別為
# 「滿意」和「不滿意」，隨機抽樣調查結果顯示 650 位消費者中有 210 位表示滿意其服務。
# 試估算滿意該速食餐廳的消費者比例 p 的 95 %信賴區間。

data <- c(rep(0, 440), rep(1, 210))
mean.rangep4 <- function(x, alpha = 0.05) {
    n <- length(x) # n 為樣本數
    proport <- as.vector(table(x))
    p <- proport[2] / n # mx 即為平均值 mu 的點估計
    r1 <- qnorm(alpha / 2) # 左半邊 z-score
    r2 <- qnorm(1 - alpha / 2) # 右半邊 z-score
    l1 <- p + r1 * sqrt(p * (1 - p) / n) # 信賴區間下限
    l2 <- p + r2 * sqrt(p * (1 - p) / n) # 信賴區間上限
    range <- c(l1, p, l2) # 信賴區間
    return(range)
}
p4 <- mean.rangep4(data)
p4

# 假說檢定
# 安裝 lib 'install.packages("asbio")'
library(asbio)
# 單樣本Z檢定
# 1.探討學生平均成績是否大於40分 (抽30個學生，母體變異數未知) (抽樣範圍0-100)
# H0是 μ <= 40
# H1是 μ > 40
set.seed(123) # 設計隨機編號
scores <- sample(0:100, 30, replace = TRUE) # 成績樣本
scores_mean <- mean(scores) # 平均成績
scores_n <- 30 # 樣本數
scores_sd <- sd(scores) # 成績標準差

scores_z_test <- one.sample.z(scores, # 放入預檢定資料集
    null.mu = 40, # 虛無假設
    xbar = scores_mean, # 平均值
    sigma = scores_sd, # 標準差
    alternative = "greater", # 檢定方式 (右尾)
    conf = 0.95
) # 信心值
scores_z_test
# 結果:z = 2.718367，p-value = 0.003280253 -> 拒絕H0，表示有足夠證據證明學生平均成績大於40

# t test試試看
score_t_testl <- t.test(scores,
    mu = 40,
    xbar = scores_means, # 平均值
    sigma = scores_sd, # 標準差
    alternative = "greater", # 檢定方式 (右尾)
    conf.level = 0.95
) # 信心值
score_t_testl
# 結果:t = 2.7184，p-value = 0.005479 -> 拒絕H0，表示有足夠證據證明學生平均成績大於40

# 視覺化呈現
sigma <- scores_sd # 宣告標準差
mu0 <- 40 # 宣告虛無假設
alpha <- scores_z_test$test$`P-value` # 宣告之前計算出來的p-value
x_lims <- c(-100, 200) # 定義X座標軸
crit <- qnorm(1 - alpha, mu0, sigma) # 算出p-value對應X軸的臨界值
crit2 <- qnorm(0.95, mu0, sigma) # 算出95%信心對應X軸的臨界值
right <- seq(crit2, x_lims[2], length.out = 200) # 以臨界值(95%)到X軸邊界切出200個點
y_h0r <- dnorm(right, mu0, sigma) # 利用常態分配以剛剛切出200個點分別計算出機率密度
curve(dnorm(x, mu0, sigma), # 利用算出來的平均值與標準差，畫出常態分配
    xlim = x_lims, lwd = 2, xlab = "x", ylab = "density",
    main = "Normal distribution", xaxs = "i"
)
polygon(c(right, rev(right)),
    c(y_h0r, numeric(length(right))),
    border = NA, # 以臨界值(95%)向右塗上陰影
    col = rgb(1, 0.3, 0.3, 0.6)
)
text(crit2, 0.0015, adj = 0, label = "p-value") # 標記剛剛上色的部分為拒絕域
abline(v = crit2, lty = 1, lwd = 3, col = "blue") # 畫一條藍色的線劃分拒絕域
text(crit2, 0.010, adj = 0, label = "←alpha=0.05") # 標記此線為拒絕域的臨界值

abline(v = crit, lty = 1, lwd = 3, col = "red")
# 利用紅色線段標記出計算出來的p-value值對應臨界值
text(crit, 0.006, adj = 0, label = "←critical value")
# 標記此線段為計算出來的p-value值對應的臨界值

# 2.探討球員身高是否小於200公分(抽20名球員，母體標準差=15)(抽樣範圍170-220，可重複)
# H0為 μ >= 200
# H1為 μ < 200
set.seed(123) # 設計隨機編號
cm <- sample(170:220, 20, replace = TRUE) # 成績樣本
cm_mean <- mean(cm) # 平均成績
cm_n <- 20 # 樣本數

cm_z_test <- one.sample.z(cm, # 放入預檢定資料集
    null.mu = 200, # 虛無假設
    xbar = cm_mean, # 平均值
    sigma = 15, # 標準差
    alternative = "less", # 檢定方式 (左尾)
    conf = 0.95
) # 信心值
cm_z_test
# 結果:z = -0.864613，p-value = 0.1936256 -> 不拒絕H0，表示沒有足夠證據證明球員平均身高小於200

# 視覺化呈現
sigma <- 15 # 宣告標準差
mu0 <- 200 # 宣告虛無假設
alpha <- cm_z_test$test$`P-value` # 宣告之前計算出來的p-value
x_lims <- c(100, 280) # 定義X座標軸
crit <- qnorm(1 - alpha, mu0, sigma) # 算出p-value對應X軸的臨界值
crit2 <- qnorm(0.95, mu0, sigma) # 算出95%信心對應X軸的臨界值
right <- seq(crit2, x_lims[2], length.out = 200) # 以臨界值(95%)到X軸邊界切出200個點
y_h0r <- dnorm(right, mu0, sigma) # 利用常態分配分別以剛剛切出200個點分別計算出機率密度
curve(dnorm(x, mu0, sigma), # 利用算出來的平均值與標準差，畫出常態分配
    xlim = x_lims, lwd = 2, xlab = "x", ylab = "density",
    main = "Normal distribution", xaxs = "i"
)
polygon(c(right, rev(right)),
    c(y_h0r, numeric(length(right))),
    border = NA, # 以臨界值(95%)向右塗上陰影
    col = rgb(1, 0.3, 0.3, 0.6)
)
text(crit2, 0.0015, adj = 0, label = "p-value") # 標記剛剛上色的部分為拒絕域
abline(v = crit2, lty = 1, lwd = 3, col = "blue") # 畫一條藍色的線劃分拒絕域
text(crit2, 0.010, adj = 0, label = "←alpha=0.05") # 標記此線為拒絕域的臨界值

abline(v = crit, lty = 1, lwd = 3, col = "red")
# 利用紅色線段標記出計算出來的p-value值對應臨界值
text(crit, 0.006, adj = 0, label = "←critical value")
# 標記此線段為計算出來的p-value值對應的臨界值

# 練習題
# 1.隨機抽樣30位相撲選手，並探討他們的體重在信心水準99%的情形下，是否大於100公斤？
# 隨機編號=11，抽樣範圍80-180(可重複)

set.seed(11) # 設計隨機編號
kg <- sample(80:180, 30, replace = TRUE) # 體重樣本
kg
kg_mean <- mean(kg) # 平均體重
kg_n <- 30 # 樣本數

kg_z_test <- one.sample.z(kg, # 放入預檢定資料集
    null.mu = 100, # 虛無假設
    xbar = kg_mean, # 平均值
    sigma = sd(kg), # 標準差
    alternative = "greater", # 檢定方式 (左尾)
    conf = 0.99
) # 信心值
kg_z_test

# 2.呈上題，90%情形下，是否有研究指出等於150公斤？

kg_z_test <- one.sample.z(kg, # 放入預檢定資料集
    null.mu = 150, # 虛無假設
    xbar = kg_mean, # 平均值
    sigma = sd(kg), # 標準差
    alternative = "two.sided", # 檢定方式 (左尾)
    conf = 0.9
) # 信心值
kg_z_test

library(gcookbook)
library(asbio)
# 考試
# 1.假設要調查人民的所得分布情況。現今進行隨機抽樣獲得 20 份樣本，
# 資料如下(單位：K) 假設母體人民的所得分布標準差為 5k。
# 25 34 54 25 35 45 22 48 52 42
# 57 41 38 24 49 67 55 23 29 33
# 試估算在 95 %信賴水準下，人民的平均所得之信賴區間為何。

income <- c(
    25, 34, 54, 25, 35, 45, 22, 48, 52, 42,
    57, 41, 38, 24, 49, 67, 55, 23, 29, 33
)
mean.range_income <- function(x, alpha = 0.05, sigma) {
    n <- length(x) # n 為樣本數
    mx <- mean(x) # mx 即為平均值 mu 的點估計
    r1 <- qnorm(alpha / 2) # 左半邊 z-score
    r2 <- qnorm(1 - alpha / 2) # 右半邊 z-score
    l1 <- mx + r1 * sigma / sqrt(n) # 信賴區間下限
    l2 <- mx + r2 * sigma / sqrt(n) # 信賴區間上限
    return(range = c(l1, mx, l2)) # 信賴區間
}
v1 <- mean.range_income(income, sigma = 5)
v1

# 2.假設想調查學校學生「吃素食」的比例，調查選項僅有「吃葷」或「吃素」，
# 現今隨機抽樣調查結果顯示 120 個學生中有 18 個表示自己是吃素的。
# 試估算學校學生吃素食的比例 p 的 99 %信賴區間。

eat <- c(rep(1, 18), rep(0, 102))

mean.range_eat <- function(x, alpha = 0.01) {
    n <- length(x) # n 為樣本數
    proport <- as.vector(table(x))
    p <- proport[2] / n # mx 即為平均值 mu 的點估計
    r1 <- qnorm(alpha / 2) # 左半邊z-score
    r2 <- qnorm(1 - alpha / 2) # 右半邊z-score
    l1 <- p + r1 * sqrt(p * (1 - p) / n) # 信賴區間下限
    l2 <- p + r2 * sqrt(p * (1 - p) / n) # 信賴區間上限
    range <- c(l1, p, l2) # 信賴區間
    return(range)
}
v2 <- mean.range_eat(eat)
v2

# 3.某研究指出國小學生平均的國文分數約為70分，因此，我們透過隨機抽樣獲得20個學生的國文成績，
# 隨機編號=20，抽樣範圍0-100(可重複)，假設母體標準差為3。試問，在 90% 的信心水準之下，
# 該研究說的是否屬實？

# H0為 平均為70
# H1為 平均不為70

set.seed(20) # 設計隨機編號
scores <- sample(0:100, 20, replace = TRUE)

scores_mean <- mean(scores) # 平均體重
scores_n <- 20 # 樣本數

scores_z_test <- one.sample.z(scores, # 放入預檢定資料集
    null.mu = 70, # 虛無假設
    xbar = scores_mean, # 平均值
    sigma = 3, # 標準差
    alternative = "two.sided", # 檢定方式 (左尾)
    conf = 0.9
) # 信心值
scores_z_test
# z score 為 -23.62778, 其 p-value 為 1.997422e-123 < 0.1 拒絕 H0，代表研究分數約為70分不屬實
