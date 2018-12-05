#manuel Alejandro Hernández Peña
from selenium import webdriver
from selenium.webdriver import ActionChains
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
import xlsxwriter
import time

workbook = xlsxwriter.Workbook('Candidatos.xlsx')
worksheet = workbook.add_worksheet()
worksheet.write(0, 0, "Matricula")
worksheet.write(0, 1, "Nombre")
worksheet.write(0, 2, "Materia")
worksheet.write(0, 3, "CodigoMateria")
row = 1

driver = webdriver.Chrome()
driver.get("http://10.49.71.125:3000/~certificatec/pronosticos/main/login")
driver.implicitly_wait(10) # seconds

driver.find_element_by_css_selector("#login_username").send_keys("ariel.garcia@itesm.mx")
driver.find_element_by_css_selector("#login_password").send_keys("1234")
driver.find_element_by_css_selector("#login_submit").click()
driver.find_element_by_css_selector("#nav > div > ul > li.last").click()
driver.find_element_by_css_selector("#sidebar > ul:nth-child(1) > li:nth-child(5)").click()


#each name and id

table = driver.find_element_by_xpath("//*[@id=\"candidatos_container\"]/tbody")
students = table.find_elements_by_tag_name("tr")

times = len(students)

s = 1
while s <= times:

    sid = driver.find_element_by_xpath("//*[@id=\"candidatos_container\"]/tbody/tr[{}]/td[1]".format(s)).text
    snm = driver.find_element_by_xpath("//*[@id=\"candidatos_container\"]/tbody/tr[{}]/td[2]".format(s)).text
    print(sid)
    print(snm)
    s+=1

    time.sleep(1)
    driver.find_element_by_xpath("//*[@id=\"candidatos_container\"]/tbody/tr[{}]".format(s)).click()
    time.sleep(1)

    driver.find_element_by_xpath("//*[@id=\"sidebar\"]/ul[1]/li[3]/a").click()



    pTable = driver.find_element_by_xpath("//*[@id=\"pronosticos_container\"]/tbody")
    courses = pTable.find_elements_by_tag_name("tr")
    cTimes = len(courses)

    c = 1
    while c <= cTimes:
        tmpId = driver.find_element_by_xpath("//*[@id=\"pronosticos_container\"]/tbody/tr[{}]/td[1]".format(c)).text
        tmpName = driver.find_element_by_xpath("//*[@id=\"pronosticos_container\"]/tbody/tr[{}]/td[2]".format(c)).text
        print(tmpId)
        print(tmpName)
        worksheet.write(row, 0, sid)
        worksheet.write(row, 1, snm)
        worksheet.write(row, 2,tmpName)
        worksheet.write(row, 3, tmpId)

        c+=1
        row += 1

    driver.back()
    driver.back()

workbook.close()

driver.quit()