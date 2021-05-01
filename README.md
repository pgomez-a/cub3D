# cub3D
### What is raycasting?
According to <a href="https://www.computerhope.com/jargon/r/ray-casting.htm">computer hope</a>, a ray casting is the most basic form of raytracing in CGI (computer-generated imagery). Unlike other forms of ray tracing, where rays originate grom a light source and bounce off objects to arrive at the observer, in ray casting, they are cast directly from the viewpoint. When cast rays intersect an object, the object's color and brightness at that point determines the value of one pixel in the final image.<br>
A direction vector represents the orientation of the observer extending forward. A camera plane, perpendicular to the direction vector and representing the shape of the final rendered image, is also required.

### Curiosities of ray casting
The first game built on a ray casting engine to achieve massive success was <b>Wolfenstein 3D</b>. The game provided and interactive 3D world, displaying it at a higher frame rate and with a more advanced level of photorealism than previous games.<br>
Moder video games have advanced significantly since Wolfenstein 3D, with faster CPUs, more memory, ant the availability of GPUs to accelerate the computation of 3D graphics. However, most modern video game 3D engines still use an advanced form of raycasting, because it remains the most efficient methos to render a 3D image.

### What is MinilibX?
MinilibX is the graphic library that 42 allows us to use to made our cub3D project. With it, we have some of the most basics tasks we can use to draw pixels on a screen or to make an image before putting it into that screen. Some of the most useful functions are:
<ul>
  <li><b>mlx_init:</b> initializes the MLX library. Is the first function we have call before using the rest of the functions. Will return NULL in case of a failed initialization.</li>
  <li><b>mlx_clear_window:</b> clears the current window.</li>
  <li><b>mlx_get_color_value:</b> get the color value accordingly from a int.</li>
  <li><b>mlx_pixel_put:</b> puts a pixel on the screen.</li>
  <li><b>mlx_new_image:</b> create a new mlx image.</li>
  <li><b>mlx_get_data_addr:</b> gets the memory address of the given image.</li>
  <li><b>mlx_put_image_to_window:</b> puts an image to the given window.</li>
  <li><b>mlx_loop_hook:</b> hook into the loop.</li>
  <li><b>mlx_loop:</b> loop over the given mlx pointer.</li>
  <li><b>mlx_xmp_file_to_image:</b> converts an xmp file to a new image instance.</li>
</ul>
These are the ones that I consider they are the most important. However, you will have to <b>RFM</b> if you want to prevent some problems in the future. Take in mind that, if you want to do a good project, you first have to understand the tools your are going to work with. And because I know that the manual is a bit quiet, I suggest you to read some of these pages to get a better idea of the things you can do with mlx.

### How does the color work?

### The technique of castin rays
