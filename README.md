<p align="center">
<img src="https://github.com/manucabral/winarian/blob/main/images/logo.png" width="250" title="example">
</p>
<p align="center">
  Una herramienta que te permite habilitar o deshabilitar ciertas llaves del registro de Windows que pueden servirte.
  Esto no es un malware, simplemente automatiza el cambio manual que tu harías.
</p>

## Uso
1. Descarga la última versión de Winarian desde [acá]()
2. Extrae y ejecuta el archivo `winarian.exe`
3. Desactivar el antivirus si no se efectuan los cambios.

<img src="https://github.com/manucabral/winarian/blob/main/images/main.png" width="450" title="example">

## Llaves disponibles
- Mostrar segundos en el reloj `Requiere reiniciar`
- OneDrive en el explorador de archivos `Requiere reiniciar`
- Buscar mediante Bing en el explorador de Windows
- Mostrar version de Windows en el escritorio `Requiere actualizar el escritorio`

## Compilar
`gcc main.c src/winarian.c src/color.c -o winarian`
