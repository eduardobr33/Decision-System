/*#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// Enumeraci�n de eventos
enum class EventType {
    RecogerObjeto,
    MatarMonstruo
};

// Enumeraci�n de acciones
enum class ActionType {
    DesbloquearDialogo,
    MostrarNuevoObjeto,
    AbrirPuerta
};

// Definici�n de una acci�n
struct Action {
    ActionType type;
    std::string description;

    Action(ActionType t, const std::string& desc) : type(t), description(desc) {}
};

// Definici�n de un evento y sus acciones asociadas
struct Event {
    std::string name;
    std::vector<Action> actions;

    Event(const std::string& n) : name(n) {}

    void addAction(ActionType type, const std::string& desc) {
        actions.emplace_back(type, desc);
    }
};

// Clase que gestiona los eventos y sus acciones asociadas
class EventManager {
private:
    std::unordered_map<EventType, Event> eventMap;

public:
    void registerEvent(EventType eventType, const std::string& eventName) {
        eventMap.emplace(eventType, Event(eventName));
    }

    void addActionToEvent(EventType eventType, ActionType actionType, const std::string& actionDescription) {
        auto it = eventMap.find(eventType);
        if (it != eventMap.end()) {
            it->second.addAction(actionType, actionDescription);
        }
    }

    void triggerEvent(EventType eventType) {
        auto it = eventMap.find(eventType);
        if (it != eventMap.end()) {
            std::cout << "Event triggered: " << it->second.name << std::endl;
            for (const auto& action : it->second.actions) {
                std::cout << " - Action: " << action.description << std::endl;
            }
        }
    }
};

int main() {
    EventManager eventManager;

    // Registro de eventos
    eventManager.registerEvent(EventType::RecogerObjeto, "Recoger Objeto");
    eventManager.registerEvent(EventType::MatarMonstruo, "Matar Monstruo");

    // A�adir acciones a los eventos
    eventManager.addActionToEvent(EventType::RecogerObjeto, ActionType::MostrarNuevoObjeto, "Mostrar nuevo objeto en el inventario");
    eventManager.addActionToEvent(EventType::MatarMonstruo, ActionType::DesbloquearDialogo, "Desbloquear nuevo di�logo");

    // Simulaci�n de eventos en el juego
    eventManager.triggerEvent(EventType::RecogerObjeto);
    eventManager.triggerEvent(EventType::MatarMonstruo);

    return 0;
}*/