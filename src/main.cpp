#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Conan + SFML + ImGui");
    window.setFramerateLimit(60);

    if (!ImGui::SFML::Init(window)) {
        return EXIT_FAILURE;
    }

    sf::Clock deltaClock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        // --- ImGui demo window ---
        ImGui::ShowDemoWindow();

        // --- Custom window ---
        ImGui::Begin("Hello");
        ImGui::Text("Hello from ImGui + SFML + Conan!");
        ImGui::End();

        window.clear(sf::Color(30, 30, 30));
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return EXIT_SUCCESS;
}
