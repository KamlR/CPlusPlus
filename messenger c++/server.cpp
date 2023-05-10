#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <cstring>

int port = 1626;
// Логин и пароль для авторизации сервера в переписке.
std::string login = "server";
std::string password = "2255";
// Метод, который проверяет, что оба участника хотят дальше продолжать переписку.
bool isClientWantToStop(const char* message) {
    if (message[0] == 'e' && message[1] == 'n' && message[2] == 'd') {
        return true;
    }
    return false;
}


int main() {
    int client, server;
    struct sockaddr_in server_address;
    // Создание сокета.
    client = socket(AF_INET, SOCK_STREAM, 0);
    if (client < 0) {
        std::cout << "Some problems with socket\n";
        exit(-1);
    }
    std::cout << "Socket for server is ready!\n";
    // Заполнение структуры данными для подключения.
    server_address.sin_port = htons(port);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htons(INADDR_ANY);

    // Связываем сокет с данными из структуры.
    int bind_info =
        bind(client, reinterpret_cast<struct sockaddr*>(&server_address), sizeof(server_address));
    if (bind_info < 0) {
        std::cout << "Binding problems\n";
        exit(-1);
    }
    // Сообщаем о том,что сервер готов слушать сообщения.
    std::cout << "Server is waiting for messages ...\n";
    listen(client, 1);
    socklen_t size = sizeof(server_address);
    // Если сервер видит, что к нему подключается клиент, то разрешает начать чат.
    server = accept(client, reinterpret_cast<struct sockaddr*>(&server_address), &size);
    if (server < 0) {
        std::cout << "Cannot link server and client";
        exit(-1);
    }
    // Буфер для хранения сообщений.
    char messages[1024];
    bool exit_ = false;
    // Пока соединение не разорвано идёт переписка.
    while (server > 0) {
        strcpy(messages, "Server connected!\n");
        send(server, messages, 1024, 0);
        std::cout << "Connected to client\nEnter end to stop chatting\n";

        // Принимаем сообщение от клиента.
        std::cout << "Client: ";
        recv(server, messages, 1024, 0);
        std::cout << messages << std::endl;
        // Проверяем, что он не хочет завершить переписку.
        if (isClientWantToStop(messages)) {
            exit_ = true;
        }
        while (!exit_) {
            // Теперь сервер отправляет сообщение клиенту.
            std::cout << "Server: ";
            // Считываем данное сообщение.
            std::cin.getline(messages, 1024);
            // Отправляем сообщение.
            send(server, messages, 1024, 0);
            // Проверяем, что сервер не хочет завершить чат.
            if (isClientWantToStop(messages)) {
                break;
            }
            // Получаем сообщение от клиента и проверяем, что он не хочет завершить переписку.
            std::cout << "Client: ";
            recv(server, messages, 1024, 0);
            std::cout << messages << std::endl;
            if (isClientWantToStop(messages)) {
                break;
            }
        }
        // Если пришли сюда, то кто-то решил завершить чат.
        std::cout << "The end of chat!\n" << std::endl;
        exit_ = false;
        close(client);
        exit(-1);
    }
}

