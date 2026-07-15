#include <Windows.h>
#include "Model/SampleRepository.h"
#include "Model/OrderRepository.h"
#include "View/ConsoleView.h"
#include "Controller/AppController.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    SampleRepository sampleRepository;
    OrderRepository orderRepository;
    ConsoleView view;
    AppController controller(sampleRepository, orderRepository, view);

    controller.Run();

    return 0;
}
