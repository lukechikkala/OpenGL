# OpenGL
A set of OpenGL examples built on macOS.

Every example so far can be compiled using:
```bash
clang -framework OpenGL main.cpp -o app libglfw.3.dylib 
```
Some issues related to macOS are addressed [here](https://www.lukechikkala.com/post/opengl-on-macos).

## 0_Window
Creates an empty window.

![0_Window](0_Window/docs/0_Window.png)

## 1_Triangle
Renders a triangle.

![1_Triangle](1_Triangle/docs/1_Triangle.png)

## 2_Window_Color
There's no triangle for this time, but this demo shows how a window's color can be modified.

![2_Window_Color](2_Window_Color/docs/2_Window_Color.png)

## 3_Triangle_Color
The triangle is back but now with a different color built with the help of some vertex & fragment shader code.

![3_Triangle_Color](3_Triangle_Color/docs/3_Triangle_Color.png)

## 4_Shaders
This example shows how to use vertex attributes with both position and color data.

![4_Shaders](4_Shaders/docs/4_Shaders.png)
