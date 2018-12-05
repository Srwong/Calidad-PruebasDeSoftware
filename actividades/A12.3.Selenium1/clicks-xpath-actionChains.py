from selenium import webdriver
from selenium.webdriver import ActionChains
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.common.by import By

driver = webdriver.Firefox()
driver.get("https://www.w3schools.com")


"""
driver.get("https://www.w3schools.com/html/html5_draganddrop.asp")

image_2_drag = driver.find_element_by_xpath('//*[@id="drag1"]')
element_2_put = driver.find_element_by_css_selector('#div2')

actions = ActionChains(driver)

actions.drag_and_drop(image_2_drag, element_2_put)
actions.click(element_2_put)
actions.release()
actions.perform() #ejecuta todas las funciones guardadas
actions.pause(2)

driver.quit() #cierra la ventana
"""

menu = driver.find_element_by_xpath('//*[@id="navbtn_references"]')

actions = ActionChains(driver)
actions.click(menu)
actions.pause(1)

subMenu = driver.find_element_by_xpath('/html/body/nav[3]/div/div[1]/a[3]')
actions.click(subMenu)
actions.pause(4)
actions.perform()

driver.back()

#como se cambio de pagina se tiene que volver a encontrar
driver.find_element_by_xpath('//*[@id="navbtn_references"]').click()

try:
    element = WebDriverWait(driver, 10)
    element.until(EC.presence_of_element_located((By.XPATH, '/html/body/nav[3]/div/div[1]/a[3]'))).click()
except:
    print('algo fasho')