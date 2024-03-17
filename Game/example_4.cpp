#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


// Definición de eventos y acciones
enum class EventType {
    RecogerObjeto,
    MatarMonstruo
};

enum class ActionType {
    DesbloquearDialogo,
    MostrarNuevoObjeto,
    AbrirPuerta
};

// Mapeo entre los valores enumerados EventType y sus nombres correspondientes
const std::unordered_map<EventType, string> eventTypeNames{
    {EventType::RecogerObjeto, "RecogerObjeto"},
    {EventType::MatarMonstruo, "MatarMonstruo"}
};

// Mapeo entre los valores enumerados ActionType y sus nombres correspondientes
const std::unordered_map<ActionType, string> actionTypeNames{
    {ActionType::DesbloquearDialogo, "DesbloquearDialogo"},
    {ActionType::MostrarNuevoObjeto, "MostrarNuevoObjeto"},
    {ActionType::AbrirPuerta, "AbrirPuerta"}
};

// Clase que representa un evento con sus acciones asociadas
class Event {
public:
    EventType type;
    vector<ActionType> actions;

    // Constructor predeterminado
    Event() : type(EventType::RecogerObjeto) {} // Aquí puedes asignar el valor por defecto que prefieras

    // Constructor que toma un parámetro del tipo EventType
    Event(EventType eventType) : type(eventType) {}
};

// Clase que gestiona los eventos y sus acciones asociadas
class EventManager {
public:
    std::unordered_map<EventType, Event> events;

    void registerEvent(EventType eventType, const vector<ActionType>& actions) {
        events[eventType] = Event(eventType);
        events[eventType].actions = actions;
    }
};

void printEvents(const EventManager& eventManager) {
    for (const auto& pair : eventManager.events) {
        cout << "Evento: " << eventTypeNames.at(pair.first) << endl;
        cout << "Acciones asociadas:" << endl;
        for (const auto& action : pair.second.actions) {
            cout << "  - " << actionTypeNames.at(action) << endl;
        }
        cout << endl;
    }
}

int main() {
    EventManager eventManager;

    ifstream file("config.twee");
    if (file.is_open()) {
        string line;
        EventType currentEvent = EventType::RecogerObjeto; // Supongamos que comenzamos con este evento
        while (getline(file, line)) {
            // Aquí analiza cada línea del archivo .twee y determina si es un evento o una acción
            // y extrae la información relevante para crear eventos y acciones en el EventManager
            if (line.find("[[") != string::npos) {
                // Si encuentra una etiqueta de evento
                if (line.find("[[RecogerObjeto]]") != string::npos) {
                    currentEvent = EventType::RecogerObjeto;
                }
                else if (line.find("[[MatarMonstruo]]") != string::npos) {
                    currentEvent = EventType::MatarMonstruo;
                }
            }
            else if (line.find("->") != string::npos) {
                // Si encuentra una acción
                if (currentEvent != EventType::RecogerObjeto && currentEvent != EventType::MatarMonstruo) {
                    continue; // Ignorar acciones que no están asociadas con un evento
                }

                if (line.find("DesbloquearDialogo") != string::npos) {
                    eventManager.events[currentEvent].actions.push_back(ActionType::DesbloquearDialogo);
                }
                else if (line.find("MostrarNuevoObjeto") != string::npos) {
                    eventManager.events[currentEvent].actions.push_back(ActionType::MostrarNuevoObjeto);
                }
                else if (line.find("AbrirPuerta") != string::npos) {
                    eventManager.events[currentEvent].actions.push_back(ActionType::AbrirPuerta);
                }
            }
        }
        file.close();
    }
    else {
        cerr << "Error al abrir el archivo .twee" << endl;
    }

    printEvents(eventManager);

    // Ahora tienes eventos y acciones creadas en el EventManager basadas en el archivo .twee
    // Puedes utilizar estos eventos y acciones en la lógica de tu juego

    return 0;
}