### Load the data (diamond.csv) on your own and answering the following question
### Snapshot your code as well as your result to WORD, and hand over your file to CU as PDF file.
setwd("C:/Users/eddie/OneDrive/文档/GitHub/coding-stuff-I-make-from-learning/R/lab4")
data <- read.csv("DiamondsPrices.csv")


# Install & library dplyr
library(dplyr)


### Q1 50% ###
### Recall from the last semester's midterm 1 (If you still remember it, I guess not. )
### Please classifying the diamond depends on its cut and clarity
### and calculate the average price of each group
### Finally, only list the cut, clarity, the amounts diamonds of each group and average price with descending order
diam_cut_clarity <- data %>%
    group_by(cut, clarity) %>%
    summarise(avg_price = mean(price), amount_of_diamond = n()) %>%
    arrange(desc(avg_price))
diam_cut_clarity

### Q2 50% ###
### Subset the data with the following condition:
### cut is good and clarity is VS1,
### and take it as the population
### then we are interest in its price
diam_good_vs1 <- data %>%
    filter(cut == "Good", clarity == "VS1") %>%
    select(price)
# diam_good_vs1

### Plot the population distribution (5%)
hist(diam_good_vs1$price,
    main = "Sampling distribution of diamond in Good VS1",
    xlab = "Price value of diamond",
    col = "cadetblue"
)

### Just like we did in the lecture
### We sampled from the population 10,000 times
### Please plot the sampling distribution with sample size n=50, n=250, n=500, respectively. (45%)
### Note that you need to put the three graphs together as we did it in the lecture
### and name the title to recognize what its sample size is.

par(mfrow = c(1, 3))
# n = 50
dist_of_mean_1 <- rep(0, 10000)

for (i in 1:10000) {
    dist_of_mean_1[i] <- mean(sample(diam_good_vs1$price, 50))
}

### Creating a histogram of the distribution of the sample mean
hist(dist_of_mean_1,
    main = "Sampling size 50",
    xlab = "Price value of diamond",
    col = "cadetblue"
)

# n = 250
dist_of_mean_2 <- rep(0, 10000)

for (i in 1:10000) {
    dist_of_mean_2[i] <- mean(sample(diam_good_vs1$price, 250))
}

### Creating a histogram of the distribution of the sample mean
hist(dist_of_mean_2,
    main = "Sampling size 250",
    xlab = "Price value of diamond",
    col = "cadetblue"
)

# n = 500
dist_of_mean_3 <- rep(0, 10000)

for (i in 1:10000) {
    dist_of_mean_3[i] <- mean(sample(diam_good_vs1$price, 500))
}

### Creating a histogram of the distribution of the sample mean
hist(dist_of_mean_3,
    main = "Sampling size 500",
    xlab = "Price value of diamond",
    col = "cadetblue"
)
