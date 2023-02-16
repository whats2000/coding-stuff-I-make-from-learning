library(dplyr)

# 設置工作路徑
setwd("C:/Users/eddie/OneDrive/文档/GitHub/coding-stuff-I-make-from-learning/R/lab4")

# 讀取檔案
data <- read.csv("DiamondsPrices.csv")

# 篩選 cut 為 fair 鑽石
diam_fair <- data %>%
    filter(cut == "Fair")
diam_fair

par(mfrow = c(1, 1))
# 直接分布圖
hist(diam_fair$price,
    main = "Distribution of diamond in Fair",
    xlab = "Price value of diamond",
    col = "cadetblue"
)

# 抽樣分布
par(mfrow = c(1, 3))
# 抽樣 n = 50
dist_of_mean_1 <- rep(0, 10000)

for (i in 1:10000) {
    dist_of_mean_1[i] <- mean(sample(diam_fair$price, 50))
}

### Creating a histogram of the distribution of the sample mean
hist(dist_of_mean_1,
    main = "Sampling size 50",
    xlab = "Price value of diamond",
    col = "cadetblue"
)

# 抽樣 n = 250
dist_of_mean_2 <- rep(0, 10000)

for (i in 1:10000) {
    dist_of_mean_2[i] <- mean(sample(diam_fair$price, 250))
}

### Creating a histogram of the distribution of the sample mean
hist(dist_of_mean_2,
    main = "Sampling size 250",
    xlab = "Price value of diamond",
    col = "cadetblue"
)

# 抽樣 n = 500
dist_of_mean_3 <- rep(0, 10000)

for (i in 1:10000) {
    dist_of_mean_3[i] <- mean(sample(diam_fair$price, 500))
}

### Creating a histogram of the distribution of the sample mean
hist(dist_of_mean_3,
    main = "Sampling size 500",
    xlab = "Price value of diamond",
    col = "cadetblue"
)

par(mfrow = c(1, 1))
# 箱狀圖
boxplot(
    diam_fair$price,
    dist_of_mean_1,
    dist_of_mean_2,
    dist_of_mean_3,
    main = "Distribution of diamond in Fair and sample",
    xlab = "Price value of diamond",
    col = "cadetblue"
)
