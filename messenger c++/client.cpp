#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>


int port = 1626;
// Метод, который проверяет, что оба участника хотят дальше продолжать переписку.
bool isClientWantToStop(const char* message) {
    if (message[0] == 'e' && message[1] == 'n' && message[2] == 'd') {
        return true;
    }
    return false;
}

int main(){
    int client;
    struct sockaddr_in server_address;
    // Задаём сокет.
    client = socket(AF_INET, SOCK_STREAM, 0);
    if (client < 0) {
        std::cout << "Problems with socket" << std::endl;
        exit(-1);
    }
    // Задаём параметры для соединения.
    server_address.sin_port = htons(port);
    server_address.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);
    server_address.sin_addr.s_addr = htons(INADDR_ANY);
    std::cout << "Client socket created\n";
    // Пытаемся присоединиться.
    if (connect(client, reinterpret_cast<const struct sockaddr*>(&server_address),
                sizeof(server_address)) == 0) {
        std::cout << "Connection to server" << inet_ntoa(server_address.sin_addr)
                  << " with port number: " << port << "\n";
    }
    std::cout << "Waiting for server conformation\n";
    char message[1024];
    recv(client, message, 1024, 0);
    std::cout << "Connection is ready\n Enter end to stop chatting\n";
    while (true) {
        // Читаем сообщение клиента.
        std::cout << "Client: ";
        std::cin.getline(message, 1024);
        // Отправляем сообщение серверу.
        send(client, message, 1024, 0);
        // Смотрим, не хочет ли клиент завершить переписку.
        if (isClientWantToStop(message)) {
            break;
        }
        // Получаем сообщение от сервера.
        std::cout << "Server: ";
        recv(client, message, 1024, 0);
        std::cout << message << "\n";
        // Проверяем не хочет ли сервер завершить переписку.
        if (isClientWantToStop(message)) {
            break;
        }
    }
    // Конец переписки.
    close(client);
    std::cout << "The end of chat!\n";
}
