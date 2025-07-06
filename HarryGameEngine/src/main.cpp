#include <stdio.h>
#include "SDL.h"
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

bool isDragging = false;
SDL_Rect rectangle = { 0, 0, 0, 0 };

void handleEvent(SDL_Event* e)
{
    if (e->type == SDL_MOUSEBUTTONDOWN && e->button.button == SDL_BUTTON_LEFT)
    {
        isDragging = true;
        rectangle.x = e->button.x;
        rectangle.y = e->button.y;
        rectangle.w = 0;  // Reset width and height
        rectangle.h = 0;
    }
    else if (e->type == SDL_MOUSEMOTION && isDragging)
    {
        int x, y;
        SDL_GetMouseState(&x, &y);
        rectangle.w = x - rectangle.x;
        rectangle.h = y - rectangle.y;
    }
    else if (e->type == SDL_MOUSEBUTTONUP && e->button.button == SDL_BUTTON_LEFT)
    {
        isDragging = false;
    }
}

void render(SDL_Renderer* renderer)
{    
    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 128, 0, 255);
    SDL_RenderClear(renderer);
        

    if (isDragging)
    {
        SDL_Rect drawRect = rectangle;

        // Ensure width and height are positive
        if (drawRect.w < 0)
        {
            drawRect.x += drawRect.w;
            drawRect.w = -drawRect.w;
        }
        if (drawRect.h < 0)
        {
            drawRect.y += drawRect.h;
            drawRect.h = -drawRect.h;
        }

        // Set gray color for the rectangle
        SDL_SetRenderDrawColor(renderer, 173, 216, 230, 129);
        SDL_RenderFillRect(renderer, &drawRect);
    }

    // Start the Dear ImGui frame
    ImGui_ImplSDLRenderer2_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    // Display a window to customize and create new enemies
    if (ImGui::Begin("Test window")) {
        ImGui::Text("sample text");

    }

    if (ImGui::TreeNode("Vertical Sliders"))
    {
        const float spacing = 4;
        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(spacing, spacing));

        static int int_value = 0;
        ImGui::VSliderInt("##int", ImVec2(18, 160), &int_value, 0, 5);
        ImGui::SameLine();

        static float values[7] = { 0.0f, 0.60f, 0.35f, 0.9f, 0.70f, 0.20f, 0.0f };
        ImGui::PushID("set1");
        for (int i = 0; i < 7; i++)
        {
            if (i > 0) ImGui::SameLine();
            ImGui::PushID(i);
            ImGui::PushStyleColor(ImGuiCol_FrameBg, (ImVec4)ImColor::HSV(i / 7.0f, 0.5f, 0.5f));
            ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, (ImVec4)ImColor::HSV(i / 7.0f, 0.6f, 0.5f));
            ImGui::PushStyleColor(ImGuiCol_FrameBgActive, (ImVec4)ImColor::HSV(i / 7.0f, 0.7f, 0.5f));
            ImGui::PushStyleColor(ImGuiCol_SliderGrab, (ImVec4)ImColor::HSV(i / 7.0f, 0.9f, 0.9f));
            ImGui::VSliderFloat("##v", ImVec2(18, 160), &values[i], 0.0f, 1.0f, "");
            if (ImGui::IsItemActive() || ImGui::IsItemHovered())
                ImGui::SetTooltip("%.3f", values[i]);
            ImGui::PopStyleColor(4);
            ImGui::PopID();
        }
        ImGui::PopID();

        ImGui::SameLine();
        ImGui::PushID("set2");
        static float values2[4] = { 0.20f, 0.80f, 0.40f, 0.25f };
        const int rows = 3;
        const ImVec2 small_slider_size(18, (float)(int)((160.0f - (rows - 1) * spacing) / rows));
        for (int nx = 0; nx < 4; nx++)
        {
            if (nx > 0) ImGui::SameLine();
            ImGui::BeginGroup();
            for (int ny = 0; ny < rows; ny++)
            {
                ImGui::PushID(nx * rows + ny);
                ImGui::VSliderFloat("##v", small_slider_size, &values2[nx], 0.0f, 1.0f, "");
                if (ImGui::IsItemActive() || ImGui::IsItemHovered())
                    ImGui::SetTooltip("%.3f", values2[nx]);
                ImGui::PopID();
            }
            ImGui::EndGroup();
        }
        ImGui::PopID();

        ImGui::SameLine();
        ImGui::PushID("set3");
        for (int i = 0; i < 4; i++)
        {
            if (i > 0) ImGui::SameLine();
            ImGui::PushID(i);
            ImGui::PushStyleVar(ImGuiStyleVar_GrabMinSize, 40);
            ImGui::VSliderFloat("##v", ImVec2(40, 160), &values[i], 0.0f, 1.0f, "%.2f\nsec");
            ImGui::PopStyleVar();
            ImGui::PopID();
        }
        ImGui::PopID();
        ImGui::PopStyleVar();
        ImGui::TreePop();
    }

    ImGui::End();



    // Rendering
    ImGui::Render();
    ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), renderer);

    // Present the updated frame
    SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Retangle to Select Units", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        printf("Error: SDL_CreateWindow(): %s\n", SDL_GetError());
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        SDL_Log("Error creating SDL_Renderer!");
        return -1;
    }

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    

    // Setup Platform/Renderer backends
    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer2_Init(renderer);

 
    bool running = true;
    SDL_Event event;

 

    while (running)
    {
        while (SDL_PollEvent(&event))
        {      
            /// ImGui SDL input
            ImGui_ImplSDL2_ProcessEvent(&event);
           /* ImGuiIO& io = ImGui::GetIO();
            int mouseX, mouseY;
            const int buttons = SDL_GetMouseState(&mouseX, &mouseY);
            io.MousePos = ImVec2(mouseX, mouseY);
            io.MouseDown[0] = buttons & SDL_BUTTON(SDL_BUTTON_LEFT);
            io.MouseDown[1] = buttons & SDL_BUTTON(SDL_BUTTON_RIGHT);*/

            if (event.type == SDL_QUIT)
            {
                running = false;
            }          

            handleEvent(&event);
        }     

       
        render(renderer);
    }

    // Cleanup    
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}