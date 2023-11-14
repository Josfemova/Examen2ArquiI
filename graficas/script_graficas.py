import os # acceso a carpetas
import re # manejo de expresiones regulares

# Ruta de la carpeta principal
carpeta_principal = "pruebas/fusion"


# Esto es para saber como buscar en los archivos txt
patrones = {
    "numCycles": re.compile(r"system\.cpu\.numCycles\s+(\d+)"),
    "ipc": re.compile(r"system\.cpu\.ipc\s+([\d.]+)"),
    "dcacheMissRate": re.compile(r"system\.cpu\.dcache\.overallMissRate::total\s+([\d.]+)"),
    "icacheMissRate": re.compile(r"system\.cpu\.icache\.overallMissRate::total\s+([\d.]+)"),
    "l2MissRate": re.compile(r"system\.l2\.overallMissRate::total\s+([\d.]+)"),
}

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
                        datos[tipo_dato].append({
                            "subcarpeta": subdir,
                            "archivo": archivo,
                            "valor": val,
                        })


#print(datos.items()) # diccionario completo (tiene mucha cosa, si)

# Imprime los resultados
for tipo_dato, lista in datos.items():
    print(f"\n{tipo_dato}:\n")
    for item in lista:
        print(f"{item['subcarpeta']}\{item['archivo']}, Valor: {item['valor']}")


'''# Editar
for tipo_dato, lista in datos.items():
    print(f"\n{tipo_dato}:\n")
    for item in lista:
        print(f"{item['subcarpeta']}\{item['archivo']}, Valor: {item['valor']}")'''
        
