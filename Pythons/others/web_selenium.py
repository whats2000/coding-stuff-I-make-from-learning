import time
from selenium import webdriver
from selenium.webdriver import ActionChains
from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions as ec

driver = webdriver.Edge()
driver.get("http://www.google.com")

time.sleep(1)

# Use send_keys
search = driver.find_element(By.CLASS_NAME, 'gLFyf')
search.send_keys('Selenium tutorial')
search.submit()

time.sleep(5)

# Use ActionChains
search = driver.find_element(By.CLASS_NAME, 'gLFyf')
ActionChains(driver).move_to_element(search).send_keys('/ Hello') \
    .pause(3).double_click().pause(3).send_keys('changed').perform()
search.submit()

time.sleep(5)

# Wait until page respond
driver.get("https://shop.pxmart.com.tw/v2/official/SalePageCategory/255?sortMode=Sales")
element = WebDriverWait(driver, 100).until(
  ec.presence_of_all_elements_located((By.CSS_SELECTOR, "div.sc-fzXfNM"))
)
print(len(element))

driver.close()
