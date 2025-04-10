import pandas as pd

from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By

service = Service()

options = webdriver.ChromeOptions()

driver = webdriver.Chrome(service=service, options=options)

# -----------------

url = 'https://books.toscrape.com'

driver.get(url)

titleElements = driver.find_elements(By.TAG_NAME, 'a')[54:94:2]

titleList = [title.get_attribute('title') for title in titleElements]


# Clicando na Página

stockList = []
for title in titleElements:
    
    title.click()
    
    qtdEstoque = int(driver.find_element(By.CLASS_NAME, 'instock').text.replace('In stock (','').replace(' available)',''))
    stockList.append(qtdEstoque)
    
    driver.back()


# DATAFRAME
digitDF = { 'Title': titleList,
            'Stock': stockList}

DF = pd.DataFrame(digitDF)

print(DF)