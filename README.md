Pong_CV
========================

##Intro

Este proyecto nace a partir de una práctica propuesta por bq para conocer las aptitudes del desarrollador, a grandes rasgos la práctica consta de un pong interactivo en el que las palas son las manos de los jugadores.

En este readme quiero recoger un poco el proceso de realización de la práctica así como para seguirme a mí mismo el progreso que voy siguiendo, y puesto que me encuentro trabajando, para volver a conectar después del trabajo e intentar seguir con el desarrollo de la forma más óptima posible.

##Desarrollo

###Martes 25

Poco me ha dado tiempo a hacer: leer el enunciado y preparar todo para ponerse a programar. Puesto que formateé el portatil hace poco y no había tenido que programar c++ desde entonces no tenía instalados ni un IDE. De momento voy a intentar tirar con sublime text y en mac OS x, ya que al formatear e instalar mavericks machaqué la partición linux y parece que ya no se puede poner dual boot nunca más. Para compilación en linux -> virtual box.

En un principio intentaré, dibujar la esfera encima de la captura de la webcam + reconocer bordes de las manos para los rebotes. Las mejoras se irán añadiendo según vaya avanzando ya que el tiempo es el mayor problema.

###Lunes 31 - Martes 1

No he conseguido sacar tiempo para este proyecto desde el martes pasado, por lo que hoy es el primer día de código, y puede que el último. La causa de esto ha sido una serie de coincidencias que no me han dejado tiempo para nada. Esto pretendía ser un diario pero ahora va a ir actualizado con cada commit, un commit por hito.

####01:19 am 
Clase main que muestra el vídeo: check

###Sábado 5

Primer hito: mostrar y grabar vídeo conseguido. El mayor problema ha sido que intenté hacerlo funcionar con opencv 3.0: si tienes un mac / maquina virtual en un mac: no lo hagas

####20:58 
Clase main que muestra y graba el vídeo: check

####04:39 am

Pequeñas mejoras

###Domingo 6

####00:24 am

Dibujada bola en el centro

####01:41 am

Bola moviéndose con velocidad constante aleatoria

####02:09 am

Rebotes implementados: hito 2 conseguido

####03:17 am

Countdown al empezar implementado

####04:19 am

Canny Edge Detector implementado

##Acknowledgments

Máquina utilizada: Macbook air 

Sistema operativo: linux en máquina virtual (fue imposible hacerlo funcionar en mac os x, problemas de drivers y encodings)

IDEs: eclipse cdt y vim

Guía de estilo seguida en cierta medida: [guía de estilo de google](http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml)

Mejoras off topic:
- Capacidad de grabar vídeo, parar de grabar vídeo y volver a grabar. El espacio cambia entre modo grabación y modo no grabación, por lo que el vídeo generado puede no ser tan largo como el tiempo que se ha estado jugando.
- Cuenta atrás antes de empezar


##Enunciado

Este es el ejercicio propuesto, para ser realizado preferiblemente en un entorno Linux (Ubuntu), aunque si tienes instalado otro sistema operativo no hay problema.
En esta prueba se deben demostrar habilidades como la programación en lenguaje C++, la interacción con el controlador de versiones git, el uso de la biblioteca OpenCV, la compilación con el sistema make y la capacidad de resolución de problemas:
El ejercicio consiste en la realización de un videojuego interactivo con una cámara inspirado en el clásico Pong. Se compone de los siguientes hitos:

1. (obligatorio) Captura y visualización del vídeo de una cámara.

2. (deseable) Representar una esfera con las siguientes características:

	* Aparece en el centro de la pantalla y selecciona una dirección aleatoria
	* Se mueve con velocidad constante rebotando en los bordes de la pantalla

3. (deseable) Interacción con la bola:

	* Desviar la trayectoria de la bola al detectar movimiento o un determinado color o forma.

4. (opcional) Desarrollar un juego para dos jugadores en el que:
	* Aparece una bola en el centro de la pantalla y selecciona una dirección aleatoria
	* Rebota en los bordes horizontales
	* Cuando la bola impacta en cualquiera de los bordes verticales, se suman los puntos correspondientes a
	cada uno de los rivales y vuelve a comenzar el reto
	* Se mostrarán los puntos en la pantalla y ganará el jugador que antes consiga 10 puntos.

