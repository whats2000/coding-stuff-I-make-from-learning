# MIS241-0412LAB
str(iris)
View(iris)

# 花萼長度(Sepal.Length)：計算單位是公分。(連續)
# 花萼寬度(Sepal.Width)：計算單位是公分。(連續)
# 花瓣長度(Petal.Length) ：計算單位是公分。(連續)
# 花瓣寬度(Petal.Width)：計算單位是公分。(連續)
# 品種(Species)：可分為Setosa，Versicolor和Virginica。(類別)


### 小考題目：探討不同品種(Species)的花瓣長度(Petal.Length)是否有差異？（80%
# 畫出盒狀圖
library(ggplot2)
library(dplyr)
library(car)

ggplot(iris, aes(x = Species, y = Petal.Length)) +
    geom_boxplot()

# 檢查是否符合ANOVA的假設（常態性、同質性）
# 看各族群的是否符合常態分佈
iris %>%
    group_by(Species) %>%
    summarize(p_value = shapiro.test(Petal.Length)$p.value)
# 假設均是常態

leveneTest(Petal.Length ~ Species, iris)
# 得到 p-value = 3.129e-08 (變異數不同)
# 假設變異數相同

# 建立ANOVA模型
# H0: A = B = C (Petal.Length)。
# HA: Otherwise
aov_iris <- aov(Petal.Length ~ Species, data = iris)
summary(aov_iris)
# 得到 p-value = 2e-16 < 0.05 (拒絕 H0)
# 代表有顯著差異

result <- TukeyHSD(aov_iris, conf.level = 0.95)

## 使y軸的標題為橫向使用 las=1
plot(result, las = 1, col = "red", cex.axis = 0.5)
# 圖示有顯著差異

### 若ANOVA為拒絕虛無假設，請由「大到小」排出不同品種的花瓣長度 (20%)
# 由 Setosa，Versicolor和Virginica 的 TukeyHSD 圖可知

# Versicolor - Setosa 的信賴區間 > 0
# 故 Versicolor的花瓣長度 > Setosa的花瓣長度

# Virginica - Versicolor 的信賴區間 > 0
# 故 Virginica的花瓣長度 > Versicolor的花瓣長度

# 故 Virginica的花瓣長度 > Versicolor的花瓣長度 > Setosa的花瓣長度
