# Loading the dataset
# 可使用 getwd() 來看目前的工作目錄
# 或是點選上方選項的 Tools->Global options 來看目前工作目錄

setwd("C:/Users/eddie/OneDrive/文档/GitHub/coding-stuff-I-make-from-learning/R/lab4")
data <- read.csv("DiamondsPrices.csv")


# Install & library dplyr
install.packages("dplyr")
library(dplyr)

# 函數 select()
carat_and_price_data <- data %>%
    select(carat, price) %>%
    head(5)
carat_and_price_data

# 函數 filter()
above_300_usd_diamond <- data %>%
    filter(price > 300) %>%
    head(5)
above_300_usd_diamond

data %>% filter(price > 300, cut == "Premium")


### Practice for the function of select() & filter() ###

## List the diamond that its cut is "Premium" and show its clarity
premium_clarity <- data %>%
    filter(cut == "Premium") %>%
    select(cut, clarity) %>%
    head(5)
premium_clarity

# 函數 mutate()
sumofxyz_data <- data %>%
    mutate(sumofxyz = x + y + z) %>%
    select(sumofxyz, price) %>%
    head(5)
sumofxyz_data

# 函數 arrange()
desc_list_the_carat_and_price <- carat_and_price_data %>%
    arrange(desc(price)) %>%
    head(5)
desc_list_the_carat_and_price


# 函數 summarise()
data %>% summarise(avgprice = mean(price), 顆 = n())


# 函數 group_by()
data %>%
    group_by(color) %>%
    summarise(avgprice = mean(price), 顆 = n())



### Practice 2 ###

## Add a new column which is calculated by the price divided by table
## and classifying the data depends on its clarity
## and summarise the average of the new column
## (the price divided by table) with descending order
data %>%
    mutate(price_div_table = price / table) %>%
    group_by(price_div_table, clarity) %>%
    summarise(avg = mean(price_div_table)) %>%
    arrange(desc(price_div_table)) %>%
    head(5)

## Find the diamond that its price is above 500 USD
## and list the cut and price with the ascending order
data %>%
    filter(price > 500) %>%
    select(cut, price) %>%
    arrange(price) %>%
    head(5)

### End of introduction of dplyr ###



### Sampling distribution of R ###

## Assumption: the file is the population
population <- read.csv("DiamondsPrices.csv")


## Obtaining the sample & set seed based on the last two digit number
## from your student ID
set.seed(41)
mysample <- sample(population$price, 50)
mysample

## Find the mean of your sample
mean(mysample)


## If I want to repeat the above process 10,000 times ,calculate its mean
## and the form a sampling distribution
# create a vector
dist_of_mean <- rep(0, 10000)

for (i in 1:10000) {
    dist_of_mean[i] <- mean(sample(population$price, 50))
}

### Creating a histogram of the distribution of the sample mean
hist(dist_of_mean,
    main = "Sampling distribution of diamond",
    xlab = "Price value of diamond",
    col = "cadetblue"
)

### let's see the distribution of the population
hist(population$price,
    main = "Sampling distribution of diamond",
    xlab = "Price value of diamond",
    col = "cadetblue"
)

### It's obviously right-skewed distribution
### but still, on the basis of central limit theorem
### No matter WHAT THE POPULATION DISTRIBUTION BE
### If sample size is large enough (n>30)
### We can apply CLT and the sampling distribution will be normal distribution

### Compare the population mean and the mean of the sampling distribution
print(mean(population$price))
print(mean(dist_of_mean))

### Compare the population variance and the std of sampling distribution
print(var(population$price))
print(var(dist_of_mean))


### What the sampling distribution be if we increase the sample size to 100 ?
dist_of_mean_2 <- rep(0, 10000)

for (i in 1:10000) {
    dist_of_mean_2[i] <- mean(sample(population$price, 100))
}


### Let's put the two graphs together

par(mfrow = c(1, 2))

hist(dist_of_mean,
    main = "Sample size = 50",
    xlab = "Price value of diamond",
    col = "cadetblue"
)

hist(dist_of_mean_2,
    main = "Sample size = 100",
    xlab = "Price value of diamond",
    col = "cadetblue"
)
