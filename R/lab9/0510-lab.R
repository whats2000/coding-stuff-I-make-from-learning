# MIS241-0510LAB
library(ggplot2)
library(ggfortify)
library(caTools)
library(car)

## 讀取資料集BankChurners.csv
bank <- read.csv("C:/Users/eddie/OneDrive/文档/GitHub/coding-stuff-I-make-from-learning/R/lab9/BankChurners.csv")
View(bank)

### 小考題目：嘗試建立一個簡單線性模型，以總交易次數(Total_Trans_Ct)去預測總交易金額(Total_Trans_Amt)

## 畫出散佈圖 (20%)
ggplot(bank, aes(x = Total_Trans_Ct, y = Total_Trans_Amt)) +
    geom_point() +
    labs(
        y = "總交易次數",
        x = "總交易金額"
    )

## 建立模型 (20%)
model <- lm(Total_Trans_Ct ~ Total_Trans_Amt, bank)
summary(model)
# load necessary libraries
library(ggpubr)

# create plot with regression line, regression equation and R^2
ggplot(bank, aes(x = Total_Trans_Ct, y = Total_Trans_Amt)) +
    geom_smooth(method = "lm") +
    geom_point() +
    stat_regline_equation(label.x = 3, label.y = 32) + # for regression equation
    stat_cor(aes(label = after_stat(rr.label)), label.x = 3, label.y = 30) + # for R^2
    theme_minimal()

## 檢查模型是否符合assumption (20%)
## Normality test of residuals：
# H0：殘差符合常態分配
# H1：殘差不符合常態分配
shapiro.test(model$residual)

# 結果 p-value = 2.987e-09 拒絕 H0 不呈現常態

## Indepenence test of residuals：
# H0：殘差間互相獨立
# H1：殘差間有關聯
durbinWatsonTest(model)

# 結果 p-value = 0 拒絕 H0 殘差有關連

## Homoscedasticity of the residuals：
# H0：殘差間的變異數具有同質性
# H1：殘差間的變異數不具有同質性
ncvTest(model)

# 結果 p-value = 0.042622 拒絕 H0 殘差間的變異數不具有同質性

## 請解釋模型的beta0與beta1的意義 (40%)
# 回歸線是 y = beta0 + beta1 * x
# beta1 是回歸線斜率
# beta0 是回歸線的y的截距
