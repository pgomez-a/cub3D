# cub3D
### What is raycasting?
According to <a href="https://www.computerhope.com/jargon/r/ray-casting.htm">computer hope</a>, a ray casting is the most basic form of raytracing in CGI (computer-generated imagery). Unlike other forms of ray tracing, where rays originate grom a light source and bounce off objects to arrive at the observer, in ray casting, they are cast directly from the viewpoint. When cast rays intersect an object, the object's color and brightness at that point determines the value of one pixel in the final image.<br>
A direction vector represents the orientation of the observer extending forward. A camera plane, perpendicular to the direction vector and representing the shape of the final rendered image, is also required.

### Curiosities of ray casting
The first game built on a ray casting engine to achieve massive success was <b>Wolfenstein 3D</b>. The game provided and interactive 3D world, displaying it at a higher frame rate and with a more advanced level of photorealism than previous games.<br>
Moder video games have advanced significantly since Wolfenstein 3D, with faster CPUs, more memory, ant the availability of GPUs to accelerate the computation of 3D graphics. However, most modern video game 3D engines still use an advanced form of raycasting, because it remains the most efficient methos to render a 3D image.

### What is MinilibX?
MinilibX is the graphic library that 42 allows us to use to made our cub3D project. With it, we have some of the most basics tasks we can use to draw pixels on a screen or to make an image before putting it into that screen. Mlx provides us a call to the creation of screens, a drawing tool and a system to manage events. Some of the most useful functions are:
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
These are the ones that I consider the most important. However, you will have to <b>RFM</b> if you want to prevent some problems in the future. Take in mind that, if you want to do a good project, you first have to understand the tools your are going to work with. And because I know that the manual is a bit quiet, I suggest you to read some of these pages to get a better idea of the things you can do with mlx:
<ul>
  <li><a href="https://harm-smits.github.io/42docs/libs/minilibx">42 Docs.</a></li>
  <li><a href="https://qst0.github.io/ft_libgfx/man_mlx.html">Mlx Manual.</a></li>
</ul>

    Clue: mlx_pixel_put writes directly over the screen without caring about any render frame. It sound good to use a temporary buffer.

### How does the color work?
Colors are represented in an <b>int format.</b> The color type we will use is the <b>TRUE COLOR</b>, also known as <b>TRGB.</b> To define a color, we initialize as: 0xTTRRGGBB, where each character means the following:
<ul>
  <li><b>T:</b> transparency --> 0xFF000000</li>
  <li><b>R:</b> red --> 0x00FF0000</li>
  <li><b>G:</b> green --> 0x0000FF00</li>
  <li><b>B:</b> blue --> 0x000000FF/li>
</ul>
Now that we know how colors are represented, it might be nice to know how to manipulate them in case we want to change some of the values of a color. For example, if all the walls in a room are white, it might be a good idea to change the transparency of some of the walls to differentiate them. The variables that we will use to manipulate the colors are:
<ul>
  <li><b>Bits per pixel:</b> (bpp) is the number of different colors in an image based on the color depth.</li>
  <li><b>Line-length:</b> image width size.</li>
  <li><b>Endian:</b> a term that describes how a sequence of bytes is sorted in computer memory. The adjectives "big" and "small" are used to specify which value is stored first. <b>Big Endian</b> stores the most significant value first, and <b>Small Endian</b> stores the least significant value first.</li>
</ul>

### Events

### The technique of castin rays
