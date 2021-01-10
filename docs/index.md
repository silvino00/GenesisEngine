<h1> Genesis Engine </h1>
Genesis Engine made initially by Marc Pagès Francesch was forked by Javier D. Belda González and Silvino Medina Cardona for their third assignment in the Game Engines subject.

<b>Original link:</b> Click <a href="https://github.com/marcpages2020/GenesisEngine">here</a>

<h2>Description</h2>
For our third year at the Design and Development of videogames degree in the Game Engines subject we had had the objective to make a basic engine using several libraries such as
Assimp, DevIL, Glew, ImGUI, Parson, PhysFS and SDL. after a general base in which we have a file system created similar to how unity works, with GameObjects, an inspector, scenes etc. For the third assignment we were given the task to create a high level system, in our case <i>Shaders</i>.

<h3>Shaders </h3>

<h4> Shader Pipeline </h4>

This last assignement consisted on creating a Shader Pipeline that would render a city using only shaders. Apart from that we also had to create a water demo producing simple moving waves using a vertex shader abd also changing the color to produce foam using a fragment shader.

So, to achive the goal of rendering the whole geometry using only shaders we started by drawing everything in red using one vertex shader and one fragment shader. Both types of shaders were imported to the engine to achive that. After that, we had to draw all the geometry of the city with their own color, so we added normals to the code and we changed the vert and frag file to make it render using only shaders.

<dt><img src="https://raw.githubusercontent.com/silvino00/GenesisEngine/master/docs/gif1.gif"></dt>

<h4> Water Simulation </h4>

For the water simulation we created a fragment shader and a vertex shader. 

<dt><img src="https://raw.githubusercontent.com/silvino00/GenesisEngine/master/docs/gif2.gif"></dt>

The fragment shader changes the color of the water to simulate foam and darker areas by using cellular noise, the usage and the properties of this noise can be checked in the tutorial below.

<iframe width="590" height="332" src="https://www.youtube.com/embed/ybbJz6C9YYA" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen>
</iframe>

he vertex shader simulates a waving movement with a simplified formula based in the theory of Franz Josef Gerstner about trochoidal waves, for more information check the links below.

<a href=" https://developer.nvidia.com/gpugems/gpugems/part-i-natural-effects/chapter-1-effective-water-simulation-physical-models">NVIDIA Water simulation documentation</a>

<a href="https://en.wikipedia.org/wiki/Trochoidal_wave">Trochoidal waves wikipedia info</a>

<h2>Our Team</h2>

This engine was developed by a team formed by:
<dl>

<dt><img src="https://raw.githubusercontent.com/silvino00/GenesisEngine/master/docs/Javi.jpg"></dt>
<dt>Javier D. Belda González</dt>
<dd> Water Simulation, webpage and shaders base</dd>
<dd> <b>Github account:</b> Click <a href=" https://github.com/JBGelsenorJ">here</a> </dd>
<dd> <b>Linkedin:</b>  Click <a href=" https://www.linkedin.com/in/javier-belda-gonz%C3%A1lez-59718112b/">here</a></dd>

<dt><img src="https://raw.githubusercontent.com/silvino00/GenesisEngine/master/docs/Silvino.jpeg"> </dt>
<dt>Silvino Medina Cardona</dt>
<dd> Shaders pipeline and shaders base </dd>
<dd> <b>Github account:</b> Click <a href="https://github.com/silvino00">here</a> </dd>
<dd> <b>Linkedin:</b>  Click <a href=" https://www.linkedin.com/in/silvino-medina-cardona-476558197/">here</a></dd>

</dl>

<h2>Video Demo</h2>
<iframe width="1280" height="720" src="https://www.youtube.com/embed/TgtMxueKM-c" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

<h2>License</h2> 	
MIT License

Copyright (c) 2020 JBGelsenorJ & Silvino00

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files Genesis Engine, to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

<h2>Download link</h2> 
<a href="https://i1.wp.com/www.materiagris.es/wp-content/uploads/2018/10/meme.jpg?ssl=1">Here</a>

