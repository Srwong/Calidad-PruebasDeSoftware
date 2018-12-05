from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.select import Select
import unittest
import time
import os

chrome_path = r"""C:\Users\Kaleb\Documents\Tec\CyPS\chromedriver"""
driver = webdriver.Chrome(chrome_path)
html_file = os.getcwd() + "//" + "Inicio.html"
driver.get("file://" + html_file)

def TESTAdmision():
    start = time.time()
    driver.find_element_by_css_selector(".nav-left > ul:nth-child(1) > li:nth-child(1) > a:nth-child(1)").click()
    end = time.time()
    print("Tiempo prueba Admisiones: {}".format(end - start))
    return driver.current_url

def TESTLIFE():
    global html_file
    start = time.time()
    driver.get("file://" + html_file)
    driver.find_element_by_css_selector("li.expanded:nth-child(2) > a:nth-child(1)").click()
    end = time.time()
    print("Tiempo prueba LIFE: {}".format(end - start))
    return driver.current_url

def TESTOfertaEducativa():
    global html_file
    start = time.time()
    driver.get("file://" + html_file)
    driver.find_element_by_css_selector("li.expanded:nth-child(3) > a:nth-child(1)").click()
    end = time.time()
    print("Tiempo prueba Oferta Educativa: {}".format(end - start))
    return driver.current_url

def TESTDirectorio():
    global html_file
    start = time.time()
    driver.get("file://" + html_file)
    driver.find_element_by_css_selector(".nav-right > ul:nth-child(1) > li:nth-child(3) > a:nth-child(1)").click()
    end = time.time()
    print("Tiempo prueba Directorio: {}".format(end - start))
    return driver.current_url

def TESTOrientaTec():
    global html_file
    start = time.time()
    driver.get("file://" + html_file)
    driver.find_element_by_css_selector(".nav-right > ul:nth-child(1) > li:nth-child(2) > a:nth-child(1)").click()
    end = time.time()
    print("Tiempo prueba OrientaTec: {}".format(end - start))
    return driver.current_url

def TESTEventos():
    global html_file
    start = time.time()
    driver.get("file://" + html_file)
    driver.find_element_by_css_selector(".nav-right > ul:nth-child(1) > li:nth-child(1) > a:nth-child(1)").click()
    end = time.time()
    print("Tiempo prueba Eventos: {}".format(end - start))
    return driver.current_url

class TestStringMethods(unittest.TestCase):
    def test_upper(self):
        self.assertEqual(TESTAdmision(), """file:///C:/Users/Kaleb/Documents/GitHub/CyPS/Proyecto//admision.html""")
        self.assertEqual(TESTLIFE(), """file:///C:/Users/Kaleb/Documents/GitHub/CyPS/Proyecto//life.html""")
        self.assertEqual(TESTOfertaEducativa(), """file:///C:/Users/Kaleb/Documents/GitHub/CyPS/Proyecto//oferta.html""")
        self.assertEqual(TESTDirectorio(), """file:///C:/Users/Kaleb/Documents/GitHub/CyPS/Proyecto//directorio.html""")
        self.assertEqual(TESTOrientaTec(), """file:///C:/Users/Kaleb/Documents/GitHub/CyPS/Proyecto//orientatec.html""")
        self.assertEqual(TESTEventos(), """file:///C:/Users/Kaleb/Documents/GitHub/CyPS/Proyecto//eventos.html""")

if __name__ == '__main__':
    unittest.main()