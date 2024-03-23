### Showcase

Here is a preview of the [cheat](https://github.com/pa1n-dev/nixware_x64) menu. It's completely clickable

I saw this idea in a popular cheat on gmod (meth)

This example uses Emscripted to compile c++ into Web Assembly (WASM) binaries that can be run as an application in the browser.

The source depends on OpenGL3, ES3, GLFW as well as Freetype and IMGui. I have attempted to make the most lightweight version of IMGUI possible to run in the browser.

#### How to build

You need to install [EMCC](https://emscripten.org/docs/getting_started/downloads.html) (Emscripten Compiler) and [GNU make](https://www.gnu.org/software/make/#download)

Execute this in the showcase folder:

```bash
make clean # Delete all files that should be compiled again
make
```

To see the result of your work you need to start a local web server:
```bash
python -m http.server 8080
```

Open in browser:

http://localhost:8080/index.html

#### Screenshots

![image](https://github.com/pa1n-dev/nixware/assets/74207477/9eecc286-ff9e-440d-97c1-149d5aa880e0)
