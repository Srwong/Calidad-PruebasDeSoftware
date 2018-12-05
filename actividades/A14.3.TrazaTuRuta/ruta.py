from selenium import webdriver
from selenium.webdriver.common.keys import Keys

driver = webdriver.Chrome()
driver.get("http://app.sct.gob.mx/sibuac_internet/ControllerUI?action=cmdEscogeRuta")
driver.implicitly_wait(5) # segundos


#seleccion de origen y destino
origen = driver.find_element_by_xpath("//*[@id=\"headerEPN\"]/table[3]/tbody/tr/td/table/tbody/tr[3]/td/table/tbody/tr[2]/td[2]/select")
origen.send_keys("Distrito Federal")
#origen.send_keys(Keys.ENTER)
#origen.send_keys(Keys.ENTER)

origenCiudad = driver.find_element_by_name("ciudadOrigen")
origenCiudad.send_keys("Chapultepec")
#origenCiudad.send_keys(Keys.ENTER)


destino = driver.find_element_by_name("edoDestino")
destino.send_keys("Guerrero")
#destino.send_keys(Keys.ENTER)


destinoCiudad = driver.find_element_by_name("ciudadDestino")
destinoCiudad.send_keys("Ixtapa")
#destinoCiudad.send_keys(Keys.ENTER)

#puntos intermedios

driver.find_element_by_xpath("//*[@id=\"headerEPN\"]/table[3]/tbody/tr/td/table/tbody/tr[3]/td/table/tbody/tr[5]/td/a").click()

intermedio = driver.find_element_by_name("edoIntermedio1")
intermedio.send_keys("Morelos")

ciudadIntermedia = driver.find_element_by_name("ciudadIntermedia1")
ciudadIntermedia.send_keys("Cuernavaca")

#estimacion de combustible

driver.find_element_by_xpath("//*[@id=\"headerEPN\"]/table[3]/tbody/tr/td/table/tbody/tr[3]/td/table/tbody/tr[14]/td/a").click()

tamanioVehiculo = driver.find_element_by_name("tamanioVehiculo")
tamanioVehiculo.send_keys("4")

motor = driver.find_element_by_name("desplazamiento")
motor.send_keys("27")

rendimiento = driver.find_element_by_name("rendimiento")
rendimiento.clear()
rendimiento.send_keys("8.36")

combustible = driver.find_element_by_name("combustible")
combustible.send_keys("Gasolina Magna")

#enviar consulta
driver.find_element_by_xpath("//*[@id=\"headerEPN\"]/table[3]/tbody/tr/td/table/tbody/tr[4]/td[2]/input").click()


#resultado

"""
·         Número total de estados visitados
·         Número total de casetas atravesadas
"""
costoTotal = driver.find_element_by_xpath("//*[@id=\"tContenido\"]/tbody/tr[19]/td[5]")
print("EL COSTO TOTAL DEL VIAJE SERIA: {}".format(costoTotal.text))

costoCasetas = driver.find_element_by_xpath("//*[@id=\"tContenido\"]/tbody/tr[15]/td[5]")
print("EL COSTO DE LAS CASETAS: {}".format(costoCasetas.text))

gastoGasolina = driver.find_element_by_xpath("//*[@id=\"tContenido\"]/tbody/tr[17]/td[5]")
print("EL COSTO DE LA GASOLINA: {}".format(gastoGasolina.text))

distancia = driver.find_element_by_xpath("//*[@id=\"tContenido\"]/tbody/tr[15]/td[2]")
print("DISTANCIA TOTAL A RECORRER EN KM: {}".format(distancia.text))

tiempo = driver.find_element_by_xpath("//*[@id=\"tContenido\"]/tbody/tr[15]/td[3]")
print("TIEMPO APROXIMADO EN HORAS: {}".format(tiempo.text))

table = driver.find_element_by_xpath("//*[@id=\"tContenido\"]/tbody")
rows = table.find_elements_by_tag_name("tr")


estados = []
casetas = []
i = 0
for x in rows:
    if i > 2 and i < len(rows) - 9: #saltarse lineas que no contienen informacion
        #contar estados
        temp = driver.find_element_by_xpath("//*[@id=\"tContenido\"]/tbody/tr[{}]/td[2]".format(i))
        #print(temp.text)
        if len(estados) == 0:
            estados.append(temp.text)
        elif temp.text not in estados:
            estados.append(temp.text)
        
        #contar casetas
        try:
            temp = driver.find_element_by_xpath("//*[@id=\"tContenido\"]/tbody/tr[{}]/td[6]".format(i))
            casetas.append(temp.text)
        except:
            pass
        
        if casetas[len(casetas)-1] == ' ':
            casetas[len(casetas)-1:len(casetas)] = []
    i += 1
        
print("NUMERO DE ESTADOS RECORRIDOS: {}".format(len(estados)))
print("NUMERO DE CASETAS RECORRIDOS: {}".format(len(casetas)))

driver.quit() #cierra la ventana




#//*[@id="tContenido"]/tbody/tr[3]/td[2]
#//*[@id="tContenido"]/tbody/tr[4]/td[2]
