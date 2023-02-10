<h1 align=center>
	<b>Fract-ol</b>
</h1>

## Introduction
Fractals are very crazy geometric figures, produced through mathematical equations. The main properties that characterize them are self-similarity, infinite complexity and dimension. 
Its shapes can be found in nature, as, for example, in Romanesque broccoli, flowers, and even in snowflakes! 
With this program you will be able to browse fractals!

## General Description

This was the time to create a basic computer graphics project. To fulfill this objective, a graphic library from the 42 school was used: <a href="https://github.com/42Paris/minilibx-linux">MiniLibX</a>! This library was developed in-house and includes the basic tools needed to open a window, create images, and handle keyboard and mouse events.

## Fractal's implemented


<h3 align=center> Mandelbrot set: </h3>

<p align=center>
<img align="center" src="https://github.com/leaozim/42-course--Fract-ol/blob/main/images/mandelbrot1.png"</>
</p>

<h3 align=center> Celtic set: </h3>

<p align=center>
<img align="center" src="https://github.com/leaozim/42-course--Fract-ol/blob/main/images/celtic3.png"</>
</p>

<h3 align=center> Create different Julia sets by passing different parameters to the program: </h3>
<p align=center>
<img align="center"  src="https://github.com/leaozim/42-course--Fract-ol/blob/main/images/JULIA2.png"</>
</p>

## usage

Git clone the project:
```sh
https://github.com/leaozim/42-course--Fract-ol.git
```
To compile, use make
```sh
cd 42-course--Fract-ol && make
```
Run the program
```sh
 ./fractol Mandelbrot
 ./fractol Julia [X.XXX][X.XXX]
 ./fractol Celtic
```

