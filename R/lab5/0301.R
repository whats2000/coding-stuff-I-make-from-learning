data <- read.csv("C:/Users/eddie/OneDrive/文档/GitHub/coding-stuff-I-make-from-learning/R/lab5/StudentsPerformance.csv")
head(data, 5)
str(data)
library(dplyr)
library(asbio)
library(EnvStats)
library(ggplot2)

# 常用統計函式
mean(data$math.score) # 平均
sd(data$math.score) # 標準差
var(data$math.score) # 變異數
median(data$math.score) # 中位數
range(data$math.score)[1] # 最大值
range(data$math.score)[2] # 最小值
q1 <- quantile(data$math.score, 0.25)
q1
q2 <- quantile(data$math.score, 0.5)
q2
q3 <- quantile(data$math.score, 0.75)
q3

# 常用的圖
# 1.histogram(查看分佈)
data %>%
    ggplot(aes(x = math.score)) +
    geom_histogram(bins = 30)

# 2.boxplot(查看分佈)
data %>%
    ggplot(aes(x = gender, y = math.score)) +
    geom_boxplot()

# 3.散佈圖(兩個數值間的關係)
data %>%
    ggplot(aes(x = reading.score, y = math.score)) +
    geom_point()

# 4.barplot(某類別的次數/頻率)
data %>%
    ggplot(aes(x = gender)) +
    geom_bar()

# 美化plot
data %>%
    ggplot(aes(x = reading.score, y = math.score)) +
    geom_point(aes(colour = gender, shape = lunch)) +
    ggtitle("閱讀成績 VS 數學成績") +
    xlab("閱讀成績") +
    ylab("數學成績")

# 常態性檢查
# 函數 shapiro.test(xxx)
# H0:樣本來自常態分布資料
# H1:樣本"非"來自常態分布資料
# p-value < 0.05時，表示樣本"非"來自常態分佈的資料
# 反之，> 0.05時，表示樣本來自常態分佈的資料
shapiro.test(data$reading.score)
# < 0.05, 所以非來自常態分佈的資料

# (補) 若群體分佈未知或不為常態分佈時，
# 則可以使用不需要假設群體呈常態分佈之統計檢定方法 - 無母數統計檢定

# 母體平均數檢定
# 大樣本且母體變異數(標準差)已知
# 這裡運用sample隨機產生300個樣本，並且定義為學生的成績，假設母體標準差=18，
# 某研究指出現代學生的平均成績會大於40，
# 現在針對這300個樣本，探討母體平均成績是否有大於40，

# H0: mu <= 40, H1: mu > 40

set.seed(123) # 設計隨機編號
# 宣告成績樣本 (score_sample) (大)
score_samplel <- sample(0:100, 300, replace = TRUE)
score_meanl <- mean(score_samplel) # 宣告平均成績(score_mean)

score_z_testl <- one.sample.z(score_samplel, # 放入要檢定資料集
    null.mu = 40, # 虛無假設
    xbar = score_meanl, # 平均值
    sigma = 18, # 標準差
    alternative = "greater", # 檢定方式(右尾)
    conf = 0.95
) # 信心值
score_z_testl
# 結果:z = 9.170247，p-value = 2.359687e-20 -> 拒絕H0，表示有足夠的證據證明母體平均成績大於40
# alternative = "greater"(右尾)；"less"(左尾)；"two.sided"(雙尾)

#---------------------------------------------------------------
# 利用sample隨機產生20個樣本，並且定義為學生的成績，假設母體標準差=18，
# 某研究指出現代學生的平均成績會小於70，
# 現在針對這20個樣本，探討母體平均成績是否有小於70，
# 小樣本且母體變異數(標準差)已知
# H0:mu >= 70, H1:mu < 70

set.seed(123) # 設計隨機編號
# 宣告成績樣本 (score_sample) (小)
score_samples <- sample(0:100, 20, replace = TRUE)
score_means <- mean(score_samples) # 宣告平均成績(score_mean)

score_z_tests <- one.sample.z(score_samples, # 放入預檢定資料集
    null.mu = 70, # 虛無假設
    xbar = score_means, # 平均值
    sigma = 18, # 標準差
    alternative = "less", # 檢定方式(右尾)
    conf = 0.95
) # 信心值
score_z_tests
# 結果:z = -2.633591，p-value = 0.004224357 -> 拒絕H0，表示有足夠的證據證明母體平均成績小於70

#---------------------------------------------------------------
# 同上面的大樣本，並假設母體標準差未知，
# 某研究指出現代學生的平均成績會大於50，
# 現在針對這個大樣本，探討母體平均成績是否有大於50，
# 大樣本且母體變異數(標準差)未知
# H0:mu <= 50, H1:mu > 50

score_sample_sdl <- sd(score_samplel) # 大樣本的標準差
score_z_testl2 <- one.sample.z(score_samplel, # 放入預檢定資料集
    null.mu = 50, # 虛無假設
    xbar = score_meanl, # 平均值
    sigma = score_sample_sdl, # 標準差
    alternative = "greater", # 檢定方式(右尾)
    conf = 0.95
) # 信心值
score_z_testl2
# 結果:z = -0.2795337，p-value = 0.6100824 -> 無法拒絕H0，表示沒有足夠的證據證明母體平均成績大於50

# 利用t test試試看
score_t_testl <- t.test(score_samplel,
    mu = 50,
    xbar = score_means, # 平均值
    sigma = score_sample_sdl, # 標準差
    alternative = "greater", # 檢定方式(右尾)
    conf = 0.95
) # 信心值
score_t_testl
# 結果:t = -0.27953，p-value = 0.61 -> 無法拒絕H0，表示沒有足夠的證據證明母體平均成績大於50 (結果與Z相近)

#----------------------------------------------------------------
# 同上面的小樣本，假設母體標準差未知，
# 某研究指出現在學生的平均成績會大於40，
# 現在針對這個小樣本，探討母體平均成績是否有大於40，
# 小樣本且母體變異數(標準差)未知，使用T檢定
# H0:mu <= 40, H1:mu > 40

score_sample_sds <- sd(score_samples) # 小樣本的標準差
score_t_tests <- t.test(score_samples,
    mu = 40,
    xbar = score_means, # 平均值
    sigma = score_sample_sds, # 標準差
    alternative = "greater", # 檢定方式(右尾)
    conf = 0.95
) # 信心值
score_t_tests
# 結果:t = 2.7935，p-value = 0.005793 -> 拒絕H0，表示有足夠的證據證明母體平均成績大於40

#----------------------------------------------------------------
# 練習題
# 1.假設該資料集為一"樣本"，根據某報導指出現代學生的數學平均成績會小於67，
# 針對"math.score"探討學生的平均數學成績是否有小於67?顯著水準 α = 0.01

# H0:mu >= 67, H1:mu < 67
score_means <- mean(data$math.score) # 宣告平均成績(score_mean)
score_sample_sds <- sd(data$math.score) # 標準差

score_z_tests <- one.sample.z(data$math.score, # 放入預檢定資料集
    null.mu = 67, # 虛無假設
    xbar = score_means, # 平均值
    sigma = score_sample_sds, # 標準差
    alternative = "less", # 檢定方式(右尾)
    conf = 0.99
) # 信心值
score_z_tests
# 結果:z = -1.899901，p-value = 0.02872306 -> 無法拒絕H0，表示沒有足夠的證據證明現代學生的數學平均成績會小於67

# 2.假設該資料集為一"樣本"，母體標準差 = 8，根據某報導指出現代學生的閱讀平均成績會大於70，
# 針對"reading.score"探討學生的平均閱讀成績是否大於70?顯著水準 α = 0.10

# H0:mu <= 70, H1:mu > 70
score_means <- mean(data$reading.score) # 宣告平均成績(score_mean)

score_z_tests <- one.sample.z(data$reading.score, # 放入預檢定資料集
    null.mu = 70, # 虛無假設
    xbar = score_means, # 平均值
    sigma = 8, # 標準差
    alternative = "greater", # 檢定方式(右尾)
    conf = 0.9
) # 信心值
score_z_tests
# 結果:z = -3.284816，p-value = 0.9994898 -> 無法拒絕H0，表示沒有足夠的證據證明現代學生的閱讀平均成績會大於70

#----------------------------------------------------------------
# 母體比例檢定
# 一研究人員指出麥當勞的在速食界受消費者喜好的程度超過 35%，為了檢定此一說法，
# 隨機抽取 350 名消費者，其中有 120 人選擇偏好麥當勞，
# 試以 5% 顯著水準檢定該研究人員的說法。
# H0: p <= 0.35, H1: p > 0.35
# 函數 prop.test(x, n, ...)

prop.test(120, 350,
    p = 0.35,
    alternative = ("greater"),
    conf.level = 0.95
)
# p-value = 0.5887, 表示沒有足夠的證據證明麥當勞的受消費者喜愛的程度超過 35%

# 假設去年某次普查指出A社區有 20% 的家庭屬於貧戶，
# 如今隨機抽了 432 戶為樣本，發現其中 104 戶為貧戶。
# 試以 10% 顯著水準檢定該社區的貧戶比例是否有改變。
# H0: p = 0.2, H1: p != 0.2

prop.test(104, 432,
    p = 0.2,
    alternative = ("two.side"),
    conf.level = 0.9
)
# p-value = 0.0397, 拒絕H0，表示有足夠的證據證明該社區的貧戶比例已經有改變

#----------------------------------------------------------------
# 母體變異數檢定
# 假如某篇報導說所有學生的寫作成績變異數大於 200
# 試以 5% 顯著水準檢定該篇報導所說的是否屬實。
# H0: 𝜎2 <= 200, H1: 𝜎2 > 200
varTest(data$writing.score,
    alternative = "greater", conf.level = 0.95,
    sigma.squared = 200
)
# p-value = 0.0004745484, 拒絕H0，表示有足夠的證據證明學生的寫作成績變異數大於200

#----------------------------------------------------------------
# 練習題
# 1.根據某網站指出現在超過25%的學生數學成績 > 60分，依我們的資料集(假設為樣本資料)，試以 5% 顯著水準檢定這網站說的是否是真的。

# H0: p = 0.25, H1: p > 0.25
prop.test(nrow(data[data$math.score > 60, ]), nrow(data),
    p = 0.25,
    alternative = ("greater"),
    conf.level = 0.95
)

# p-value = 2.2e-16，拒絕 H0，表示有足夠的證據證明現在超過25%的學生數學成績 > 60分

# 2.假如某老師說現在女學生的寫作成績變異數小於 250，試以10% 顯著水準檢定這老師說的是否正確。
df1 <- data[data$gender == "female", ]
df1
# H0: 𝜎2 >= 250, H1: 𝜎2 < 250
varTest(df1$writing.score,
    alternative = "less", conf.level = 0.9,
    sigma.squared = 250
)

# p-value = 0.02467152，拒絕 H0，表示有足夠的證據證明現在女學生的寫作成績變異數小於 250

# 1. 假設我們的資料集為一"樣本"，某篇報導指出女性的閱讀成績會大於60, 針對 "reading.score"
# 探討"女性"的母體平均閱讀成績是否有大於60? 顯著水準 α = 0.05
df1 <- data[data$gender == "female", ]
df1

# H0:mu <= 60, H1:mu > 60
score_means <- mean(df1$reading.score)
score_sample_sds <- sd(df1$reading.score) # 標準差

score_z_tests <- one.sample.z(df1$reading.score, # 放入預檢定資料集
    null.mu = 60, # 虛無假設
    xbar = score_means, # 平均值
    sigma = score_sample_sds, # 標準差
    alternative = "greater",
    conf = 0.95
) # 信心值
score_z_tests
# 結果:z = 19.95763，p-value = 6.433882e-89 -> 拒絕H0，表示有足夠的證據證明現代女性學生的閱讀平均成績會大於60

# 2 假設有一篇報導指出低於20%的學生"writing.score">80分，依我們的資料集
# (假設為樣本資料)，試以10%顯著水準檢定這報導說的是否屬實
# H0: p >= 0.2, H1: p < 0.2
prop.test(nrow(data[data$writing.score > 80, ]), nrow(data),
    p = 0.2,
    alternative = ("less"),
    conf.level = 0.9
)
# p-value = 0.7234, 表示沒有足夠的證據證明現代學生的寫作平均分數大於80的占比會小於20%
