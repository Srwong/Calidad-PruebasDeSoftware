# Manuel Alejandro Hernandez Peña
# A01022089

import math
from selenium import webdriver
from selenium.webdriver.common.keys import Keys

driver = webdriver.Chrome()
driver.get("http://blazedemo.com")
driver.implicitly_wait(10) # seconds

# origin and destination
text = driver.find_element_by_name("fromPort")

text.send_keys("Boston")
text.send_keys(Keys.ENTER)
text.send_keys(Keys.ENTER)

text = driver.find_element_by_name("toPort")

text.send_keys("New York")
text.send_keys(Keys.ENTER)
text.send_keys(Keys.ENTER)

but = driver.find_element_by_xpath("//input[@value='Find Flights']")
but.click()

# select flight
flights = driver.find_element_by_tag_name("table")

rows = flights.find_elements_by_tag_name("tr") # get all of the rows in the table
lowestPrice = 1000
flight = None

#Find the lowest price
for row in rows:
	try:
		price = row.find_element_by_name("price").get_attribute("value")
		#print(price)
		if float(price) < lowestPrice:
			lowestPrice = float(price)
			flight = row
	except Exception:
		pass

flight.find_element_by_tag_name("td").find_element_by_tag_name("input").click()

#form

inp = driver.find_element_by_xpath("//input[@id=\"inputName\"]")
inp.send_keys("Alejandro")

inp = driver.find_element_by_id("address")
inp.send_keys("calle x")

inp = driver.find_element_by_id("city")
inp.send_keys("CDMX")

inp = driver.find_element_by_id("state")
inp.send_keys("CDMX")

inp = driver.find_element_by_id("zipCode")
inp.send_keys("69693")


inp = driver.find_element_by_id("cardType")
inp.send_keys("American Express")
inp.send_keys(Keys.ENTER)
inp.send_keys(Keys.ENTER)

inp = driver.find_element_by_id("creditCardNumber")
inp.send_keys("1111222233334444")

inp = driver.find_element_by_id("creditCardYear")
inp.clear()
inp.send_keys("2077")

inp = driver.find_element_by_id("nameOnCard")
inp.send_keys("Manuel Hernandez")

inp = driver.find_element_by_xpath("//input[@id=\"rememberMe\"]")
inp.click()

inp = driver.find_element_by_xpath("//input[@type=\"submit\"]")
inp.click()
