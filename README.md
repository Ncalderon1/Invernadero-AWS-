# Intro


Este es un proyecto y una guia de como se creo un invernadero hidroponico vertical con tecnologias asociadas a la nuve , control matematico PID , circuitos , iot , y sistemas de control.

Para el control climático en los invernaderos, se ha implementado un sistema controlado por PID (potencial integral derivativo). Este sistema se ejecuta en un servicio de AWS Lambda, que recopila los datos de los sensores instalados en el invernadero y calcula los ajustes necesarios para mantener un clima estable y favorable para el crecimiento de las plantas.

Integrar tecnología de vanguardia, como la hidroponía y la iluminación LED, junto con un sistema de control climático basado en PID y alojado en AWS Lambda, ofrece numerosas ventajas en la agricultura urbana. Además de superar las dificultades asociadas con el espacio, el suelo y las condiciones ambientales, esta solución tecnológica promueve una producción más eficiente, sostenible y de mayor calidad en el cultivo de fresas y tomates en invernaderos urbanos. El uso de GitHub para compartir y colaborar en el desarrollo de este tipo de tecnologías permite que la comunidad agrícola y científica continúe impulsando la innovación en el sector y asegure un futuro más próspero para la agricultura urbana.
![inver](https://github.com/Ncalderon1/Invernadero-AWS-/assets/82462335/12c66cd5-1b6f-4ddb-bc6d-969177c5cb24)

![IMG-20230601-WA0001](https://github.com/Ncalderon1/Invernadero-AWS-/assets/82462335/b677328b-ec61-4111-a694-924243945d95)



## Agricultura vertical
La agricultura vertical es una forma de aprovechar el entorno controlado de un edificio comercial moderno y convertirlo en una instalación apta para invernaderos. Al apilar las plantas verticalmente en estanterías o pilares altos, la agricultura vertical permite un mayor rendimiento para una superficie de terreno determinada.

![vertical](https://github.com/Ncalderon1/Invernadero-AWS-/assets/82462335/6017b2b2-bdf6-42bc-9f12-cc92f167f532)


## Controlador PID
Los sistemas de control son omnipresentes en aplicaciones industriales, médicas, militares, de automoción, de servicios públicos y muchas otras, y a veces aparecen en nuestra vida cotidiana. Sin embargo, los hay de muchos tipos, de los cuales el control PID es sólo uno, aunque el más sofisticado.
La nube de AWS
Amazon Web Services (AWS) es la plataforma en la nube más completa y ampliamente adoptada del mundo, que ofrece más de 200 servicios con todas las funciones desde centros de datos de todo el mundo. Millones de clientes, entre los que se incluyen las startups de más rápido crecimiento, las empresas más grandes y las principales agencias gubernamentales, utilizan AWS para reducir costes, ser más ágiles e innovar con mayor rapidez.
Implementación


# Caracterización del sistema

## Matlab

Con la ayuda de la herramienta Ident, se llevó a cabo la caracterización del sistema, utilizando la temperatura del sistema y la tensión aplicada a la resistencia como variables para ajustar la temperatura al punto de consigna deseado.
![pid_cong](https://github.com/Ncalderon1/Invernadero-AWS-/assets/82462335/046fa5d5-3ff2-4c87-8618-ca294de75e91)

Además, utilizando la herramienta de sintonización Simulink, fue posible encontrar los coeficientes para el control PID.

## Circuito electrónico

El circuito consta de control de temperatura, la variable temperatura es leída por un sensor DHT11 debido a su alta resolución, Es leída por el Microcontrolador ESP32,. Como actuador, vamos a utilizar una bombilla que nos permite controlar la intensidad en un intento de gestionar la temperatura en el interior de un jardín vertical.

En el circuito se utiliza un amplificador operacional que detecta el cruce con cero, con la finalidad de sincronizar el PWM con la frecuencia de la red eléctrica. Para la alimentación se utiliza un optoacoplador que envía la señal al Triac para controlar la tensión sobre la resistencia.

La siguiente imagen muestra el circuito del esquema electrónico.
![circuito](https://github.com/Ncalderon1/Invernadero-AWS-/assets/82462335/886e7518-7b21-4563-8033-65870d554e71)


## Control en Python

Se desarrolló un programa en python que se configura con los coeficientes PID, la idea del programa es poder conectarse con los datos que se envían a la nube, de esta manera python se suscribe al tema que se genera cada vez que se envía un dato, y así mismo, el control en python ajusta el ancho de pulso que el microcontrolador(ESP32) enviará al circuito, para controlar la temperatura de la resistencia.

 En la siguiente imagen se muestra el código desarrollado.
![pid_txt](https://github.com/Ncalderon1/Invernadero-AWS-/assets/82462335/92c1ce97-5f6f-4b56-9221-bbf419f6da2e)
![pid_test](https://github.com/Ncalderon1/Invernadero-AWS-/assets/82462335/575e7c65-ec62-406d-9bfe-5113e00e15bb)




En la siguiente imagen se muestra la respuesta.
![PID](https://github.com/Ncalderon1/Invernadero-AWS-/assets/82462335/1d901a45-2a49-4089-893a-c1418b0c640a)


# Comunicacion

Como resultado, el objetivo principal fue completado, y es posible enviar los datos a la nube en AWS, en la siguiente imagen es posible ver como los datos son subidos a la nube.



En la siguiente imagen es posible ver el control de PWM en la señal AC, y la sincronización con la señal de red.

![ociloscopio](https://github.com/Ncalderon1/Invernadero-AWS-/assets/82462335/b2d17f6f-f40c-4da9-a69d-f28414857adb)


En la última imagen, es posible ver el modelo que se realizó, que consta de dos plantas del cultivo vertical de fresas.
![invs](https://github.com/Ncalderon1/Invernadero-AWS-/assets/82462335/4c2117ca-6b57-473e-ae0c-742cc6452869)

