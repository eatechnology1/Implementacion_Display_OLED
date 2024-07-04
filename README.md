# Implementación de Pantalla OLED con PSoC 5 LP

**Alexander Calderón Leal - julio 2, 2024**

## Contenido

1. [¿Qué es una Pantalla OLED?](#qué-es-una-pantalla-oled)
2. [Protocolo I2C](#protocolo-i2c)
3. [Implementación de una Pantalla OLED en PSoC 5LP](#implementación-de-una-pantalla-oled-en-psoc-5lp)

---

## ¿Qué es una Pantalla OLED?

Una pantalla OLED (Organic Light Emitting Diode) es un tipo de pantalla que utiliza diodos orgánicos emisores de luz para producir imágenes con alta eficiencia energética y calidad visual.

### Ventajas de las Pantallas OLED

- **Alta calidad de imagen:** Ofrecen un excelente contraste y colores vivos.
- **Bajo consumo energético:** Solo los píxeles iluminados consumen energía.
- **Ángulo de visión amplio:** La calidad de la imagen no se degrada desde ángulos extremos.
- **Rápido tiempo de respuesta:** Ideal para mostrar imágenes en movimiento sin desenfoque.

---

## Protocolo I2C

I2C (Inter-Integrated Circuit) es un protocolo de comunicación serial que permite la conexión de múltiples dispositivos a través de dos líneas (SDA para datos y SCL para el reloj).

### Ventajas de I2C

- **Simplicidad:** Solo requiere dos líneas de comunicación.
- **Flexibilidad:** Permite conectar múltiples dispositivos en el mismo bus.
- **Eficiencia:** Adecuado para aplicaciones con requerimientos de velocidad moderada.

### Cómo Funciona I2C

- **Maestro y esclavo:** El maestro controla la comunicación, mientras que los esclavos responden.
- **Dirección de dispositivos:** Cada dispositivo en el bus tiene una dirección única.
- **Transferencia de datos:** Utiliza un formato de trama con bits de inicio, dirección, datos y parada.

---

## Implementación de una Pantalla OLED en PSoC 5LP

### Conexión Física

1. **SDA (Data):** Conectar al pin I2C SDA del PSoC.
2. **SCL (Clock):** Conectar al pin I2C SCL del PSoC.
3. **VCC:** Conectar al pin de 3.3V o 5V del PSoC.
4. **GND:** Conectar al pin GND del PSoC.

### Configuración del Proyecto en PSoC Creator

#### Crear un Nuevo Proyecto

- Abre PSoC Creator y crea un nuevo proyecto.
- Selecciona el microcontrolador adecuado.

#### Agregar y Configurar el Componente I2C

- En el `TopDesign.cysch`, arrastra el componente I2C a tu diseño.
- Configura la velocidad de reloj y dirección del dispositivo según la pantalla OLED.

#### Asignación de Pines

- Abre el archivo de diseño de pines (`pins.cydwr`) y asigna los pines SDA y SCL a los pines físicos de tu placa.

### Inicialización del I2C y la Pantalla OLED en el Código

1. **Agregar Librerías Necesarias:** Incluye las librerías estándar y específicas para la pantalla OLED en tu archivo `main.c`.
2. **Inicialización del I2C y la Pantalla OLED:** En la función `main`, inicia el I2C y la pantalla OLED.
3. **Código de Ejemplo para Mostrar Texto:** Utiliza las funciones de la librería de la pantalla OLED para mostrar texto.

### Compilación y Programación

- **Compilación:** Compila el proyecto en PSoC Creator para verificar que no haya errores.
- **Programación:** Programa tu microcontrolador PSoC con el binario generado.

### Prueba y Verificación

- **Verificar Conexiones:** Asegúrate de que todas las conexiones físicas estén correctas.
- **Observación de Resultados:** Verifica que la pantalla OLED muestre el texto esperado (“Hola Mundo!”).

---

## Recursos Adicionales

- [Documentación de PSoC Creator](https://www.cypress.com/documentation/software-and-drivers/psoc-creator-integrated-design-environment-ide)
- [Guía del Usuario de PSoC 5LP](https://www.cypress.com/file/42091/download)
- [Librería para Pantalla OLED](https://github.com/adafruit/Adafruit_SSD1306)
- [EA Technology - Alexander Calderon Leal](https://ea-tech.site)
---


