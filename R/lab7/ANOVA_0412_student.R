# Read the file
stu_pf <- read.csv("C:/Users/eddie/OneDrive/文档/GitHub/coding-stuff-I-make-from-learning/R/lab7/StudentsPerformance.csv")
View(stu_pf)

### ISSUE：不同族群對於數學成績是否有差異 ###

## 畫出盒狀圖（x-各族群、y-數學成績）
library(ggplot2)
ggplot(stu_pf, aes(x = race.ethnicity, y = math.score)) +
    geom_boxplot()


## 跑ANOVA前須檢查是否有符合三個條件
# (1)常態性：樣本必須符合常態分配，也就是分配至少要長得差不多，奇形怪狀的分配是沒辦法比較的。
# (2)同質性：各組變異數必須相等或接近，也就是兩組常態分配曲線的高矮胖瘦要差不多，差太多代表長得不一樣，不一樣的東西怎麼能比較呢。
# (3)獨立性：樣本要有獨立性，也就是抽樣一定要隨機。


# (1) 常態性檢查
# 使用shapiro.test：
# 在 R 中若要進行常態性檢定，最常用的方式就是 Shapiro-Wilk 檢定
# shapiro.test函數檢查資料是否為常態分布。
# p-value > 0.05，不拒絕虛無假設，資料符合常態分布。
# p-value < 0.05，拒絕虛無假設，資料不符合常態分布。

library(dplyr)
# 看各族群的數學成績是否符合常態分佈
stu_pf %>%
    group_by(race.ethnicity) %>%
    summarize(p_value = shapiro.test(math.score)$p.value)

# race.ethnicity p_value
#<chr>            <dbl>
# 1 group A         0.855
# 2 group B         0.0104
# 3 group C         0.0174
# 4 group D         0.0593
# 5 group E         0.0185


# (2) 同質性檢查
# 使用leveneTest：
# 確認不同組別數值是否變異數相等。
# p-value > 0.05，資料數值符合相同變異數。
# p-value < 0.05，資料數值不符合相同變異數。
library(car)
leveneTest(math.score ~ race.ethnicity, stu_pf)

# output P = 0.6697


# ANOVA
# 不同族群對於數學成績是否有差異?
# H0: A = B = C = D = E (math.score)。
# HA: Otherwise

# ANOVA在R裡面有兩種寫法

# 寫法一
aov_race <- aov(math.score ~ race.ethnicity, data = stu_pf)
summary(aov_race)

# 寫法二
oneway.test(math.score ~ race.ethnicity, data = stu_pf, var.equal = TRUE)

## p-value 具顯著性，拒絕H0，


## Follow-up analysis
## Apply TukeyHSD() in R
## TukeyHSD() document ->
## https://www.rdocumentation.org/packages/stats/versions/3.6.2/topics/TukeyHSD

## The intervals constructed in this way would only apply exactly to
## balanced designs where there are the same number of observations made
## at each level of the factor.

## This function incorporates an adjustment for sample size
## that produces sensible intervals for mildly unbalanced designs.

## 懶人包：treatment的sample size就算沒有一致，一樣能使用TukeyHSD()

result <- TukeyHSD(aov_race, conf.level = 0.95)

## 使y軸的標題為橫向使用 las=1
plot(result, las = 1, col = "red", cex.axis = 0.5)


## 練習題：沿用這份資料集，探討不同的父母學位對於閱讀成績是否有差異？

# 畫出盒狀圖
ggplot(stu_pf, aes(x = parental.level.of.education, y = reading.score)) +
    geom_boxplot()

# 檢查是否符合ANOVA的假設（常態性、同質性）
# 看各族群的閱讀成績是否符合常態分佈
stu_pf %>%
    group_by(parental.level.of.education) %>%
    summarize(p_value = shapiro.test(reading.score)$p.value)

leveneTest(reading.score ~ parental.level.of.education, stu_pf)

# 建立ANOVA模型
# H0: A = B = C = D = E = F (reading.score)。
# HA: Otherwise
aov_parent <- aov(reading.score ~ parental.level.of.education, data = stu_pf)
summary(aov_parent)

# Follow-up analysis
## 懶人包：treatment的sample size就算沒有一致，一樣能使用TukeyHSD()

result <- TukeyHSD(aov_parent, conf.level = 0.95)

## 使y軸的標題為橫向使用 las=1
plot(result, las = 1, col = "red", cex.axis = 0.5)

# 報告題目
# 組別 : 1,3,4,6,7
# 使用資料集：diamond.csv
# (1,3,4)：試探討鑽石的clarity對於其價格的影響
# (6,7) ： 試探討鑽石的color對於其價格的影響
#
