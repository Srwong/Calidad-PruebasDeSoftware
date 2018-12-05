#isntalamos selenium con pip install selenium
#descargamos el driver web y lo agregamos al path
#se ejecuta desde linea de comandos
from selenium import webdriver
from selenium.webdriver.common.keys import Keys

driver = webdriver.Chrome()
#driver.get("http://www.google.com")
driver.get("http://blazedemo.com")

"""

elemento = driver.find_element_by_name("fromPort")
opciones = elemento.find_element_by_tag_name("option") #refresa un arreglo de tags
for opcion in opciones:
    if opcion.get_attribute("value") == "Mexico City":
        opcion.click()
"""

#imput field

text = driver.find_element_by_name("fromPort")

text.send_keys("Boston")
text.send_keys(Keys.ENTER)
text.send_keys(Keys.ENTER)

text = driver.find_element_by_name("toPort")

text.send_keys("New York")
text.send_keys(Keys.ENTER)
text.send_keys(Keys.ENTER)

but = driver.find_element_by_xpath("//input[@type=\"submit\"]")
#but = driver.find_element_by_class_name("btn btn-primary")
but.send_keys(Keys.ENTER)


driver.get("http://blazedemo.com/purchase.php")
#formulario
text = driver.find_element_by_xpath("//input[@id=\"inputName\"]")
text.send_keys("Manuel")

text = driver.find_element_by_id("address")
text.send_keys("mi casa")

