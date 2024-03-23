#include <stdio.h>
#include <iostream>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#define GLFW_INCLUDE_ES3
#include <GLES3/gl3.h>
#include <GLFW/glfw3.h>

#include "fonts/ubuntu_compressed.h"
#include "menu/menu.h"

GLFWwindow* glfw_window;
int window_width;
int window_height;

EM_JS(int, canvas_get_width, (),
{
    return Module.canvas.width;
});

EM_JS(int, canvas_get_height, (),
{
    return Module.canvas.height;
});

EM_JS(void, resizeCanvas, (),
{
    js_resizeCanvas();
});

void on_size_changed()
{
    glfwSetWindowSize(glfw_window, window_width, window_height);

    SetCurrentContext(GetCurrentContext());
}

void loop()
{
    int width = canvas_get_width();
    int height = canvas_get_height();

    if (width != window_width || height != window_height)
    {
        window_width = width;
        window_height = height;
        on_size_changed();
    }

    glfwPollEvents();

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    NewFrame();

    menu::render();

    Render();

    int display_w, display_h;
    glfwMakeContextCurrent(glfw_window);
    glfwGetFramebufferSize(glfw_window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(0.078f, 0.078f, 0.078f, 1.00f);
    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL3_RenderDrawData(GetDrawData());
    glfwMakeContextCurrent(glfw_window);
}

int init_gl()
{
    if (!glfwInit())
    {
        fprintf(stderr, "failed to initialize GLFW\n");
        return 1;
    }

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfw_window = glfwCreateWindow(window_width, window_height, "nixware", NULL, NULL);
    if (glfw_window == NULL)
    {
        fprintf(stderr, "failed to open GLFW window.\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(glfw_window);

    return 0;
}

int init_imgui()
{
    IMGUI_CHECKVERSION();
    CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(glfw_window, true);
    ImGui_ImplOpenGL3_Init();

    StyleColorsDark();

    ImGuiIO& io = GetIO();

    ImFontConfig config = ImFontConfig();
    config.FontBuilderFlags = ImGuiFreeTypeBuilderFlags_MonoHinting;

    io.Fonts->AddFontFromMemoryCompressedTTF(ubuntu_compressed_data, ubuntu_compressed_size, 13, &config, io.Fonts->GetGlyphRangesCyrillic());

    resizeCanvas();

    return 0;
}

int init()
{
    init_gl();
    init_imgui();
    return 0;
}

void quit()
{
    glfwTerminate();
}

extern "C" int main(int argc, char** argv)
{
    window_width = canvas_get_width();
    window_height = canvas_get_height();
    if (init() != 0) return 1;

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(loop, 0, 1);
#endif

    quit();

    return 0;
}
