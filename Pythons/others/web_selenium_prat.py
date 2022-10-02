import time
from selenium import webdriver
from selenium.webdriver.common.by import By

driver = webdriver.Edge()
driver.get("https://www.ptt.cc/bbs/Gossiping/index.html")

time.sleep(3)

button = driver.find_element(By.CLASS_NAME, 'btn-big').click()
