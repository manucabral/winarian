# Winarian
Una herramienta que te permite habilitar o deshabilitar ciertas llaves del registro de Windows que pueden servirte.

## Uso
1. Descarga la última versión de Winarian desde [acá]()
2. Extrae y ejecuta el archivo `winarian.exe`

Winaria no es un malware, simplemente automatiza el cambio de registro por ti.

## Llaves disponibles
- Mostrar segundos en el reloj `Requiere reiniciar`
- OneDrive en el explorador de archivos `Requiere reiniciar`
- Buscar mediante Bing en el explorador de Windows
- Mostrar version de Windows en el escritorio `Requiere actualizar el escritorio`

## Compilar
`gcc main.c src/winarian.c src/color.c -o winarian`
