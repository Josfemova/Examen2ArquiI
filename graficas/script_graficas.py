import os # acceso a carpetas
import re # manejo de expresiones regulares
import matplotlib.pyplot as plt # graficar

def generarPatrones():
    # Esto es para saber como buscar en los archivos txt
    patrones = {
        "numCycles": re.compile(r"system\.cpu\.numCycles\s+(\d+)"),
        "ipc": re.compile(r"system\.cpu\.ipc\s+([\d.]+)"),
        "dcacheMissRate": re.compile(r"system\.cpu\.dcache\.overallMissRate::total\s+([\d.]+)"),
        "icacheMissRate": re.compile(r"system\.cpu\.icache\.overallMissRate::total\s+([\d.]+)"),
        "l2MissRate": re.compile(r"system\.l2\.overallMissRate::total\s+([\d.]+)"),
    }
    return patrones

def extraerValores(carpeta_principal, patrones):
    # Diccionario para almacenar los datos. Contiene una lista para almacenar los valores de 
    # cada caracteristica
    datos = {
        "numCycles": [],
        "ipc": [],
        "dcacheMissRate": [],
        "icacheMissRate": [],
        "l2MissRate": [],
    }
    
    # Recorre la carpeta principal y subcarpetas
    for subdir, dirs, files in os.walk(carpeta_principal):
        for archivo in files:
            if archivo.endswith(".txt"):
                ruta_completa = os.path.join(subdir, archivo)
                
                # Lee el archivo
                with open(ruta_completa, 'r') as f:
                    contenido = f.read()
                    
                    # Busca los patrones en el contenido del txt y agrega los datos a las listas
                    for tipo_dato, patron in patrones.items():
                        valores = patron.findall(contenido)
                        for val in valores:
                            datos[tipo_dato] += [float(val)]          
    return datos

def graficarBarras(datos, titulo, subdir):
    indices = ["F01", "F11", "F02", "F12", "F03", 
               "F13", "F04", "F14", "F05", "F15",
               "F06", "F16", "F07", "F17"]
    plt.bar(indices, datos, color='blue')
    plt.xlabel('Prueba y tamaño de array: F(prueba)(tamaño array)')
    plt.ylabel('Valor')
    plt.title(titulo)
    plt.savefig(os.path.join(subdir, titulo))

def graficarCaracteristicas(datos, subdir):
    for tipo in datos:    
        print(datos[tipo])
        graficarBarras(datos[tipo], tipo, subdir)

def main():
    patrones = generarPatrones()
    datosFusion = extraerValores('pruebas/fusion', patrones)
    datosIntercambio = extraerValores('pruebas/intercambio', patrones)
    graficarCaracteristicas(datosFusion, 'graficas/fusion')
    #graficarCaracteristicas(datosIntercambio, 'graficas/intercambio')
    
main()
        
