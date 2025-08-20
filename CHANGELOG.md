# 📜 Historial de Cambios

Todos los cambios importantes de este proyecto se documentarán en este archivo.  
El formato sigue las recomendaciones de [Keep a Changelog](https://keepachangelog.com/es-ES/1.0.0/)  
y utiliza [Semantic Versioning](https://semver.org/lang/es/).

---

## **[1.2.0] - 2025-08-19**
### **Agregado**
- Implementación de la **captura automática de imágenes** desde la cámara OV2640.
- Integración del **servidor web** para **streaming en tiempo real** desde la ESP32-CAM.
- Nuevo sistema de manejo de errores para la inicialización de la cámara.
- Documentación extendida sobre la configuración de la placa en Arduino IDE.

### **Cambiado**
- Se mejoró la estructura del código para facilitar el mantenimiento.
- Optimización de la configuración de **frame size** para mejorar la calidad de imagen.

### **Corregido**
- Solucionado el error **"Detected camera not supported"** usando la configuración correcta de pines AI Thinker.
- Resuelto problema con la conexión WiFi en redes con seguridad WPA2.

---

## **[1.1.0] - 2025-08-10**
### **Agregado**
- Implementación de conexión **WiFi** configurable.
- Soporte básico para capturar fotos manualmente desde el monitor serie.
- Incorporación de logs en el **Serial Monitor** para depuración.

### **Cambiado**
- Ajuste en la configuración del baud rate a **115200** para mejorar la estabilidad.

### **Corregido**
- Resuelto el error de inicialización causado por conflicto en la asignación de pines.

---

## **[1.0.0] - 2025-08-01**
### **Agregado**
- Versión inicial del proyecto.
- Configuración base de la **ESP32-CAM AI Thinker**.
- Captura de imagen estática y guardado en la memoria interna.

---

## **📌 Leyenda de estados**
| **Etiqueta**    | **Significado**                                   |
|---------------|--------------------------------------------------|
| **Agregado**   | Nueva funcionalidad.                            |
| **Cambiado**   | Comportamiento o estructura modificada.         |
| **Corregido**  | Errores solucionados.                           |
| **Eliminado**  | Funciones o dependencias que se quitaron.       |
| **Deprecado**  | Características que serán eliminadas en el futuro. |

---

> **Nota:** Cada vez que avances en tu proyecto, actualiza este archivo con una nueva versión, la fecha y los cambios realizados.
