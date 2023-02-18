/// @file
#include "view.h"

#include <iostream>
#include <memory>

#include "controller.h"

using namespace std;

int main() {
  std::shared_ptr model_facade = make_shared<ModelFacade>();
  std::shared_ptr view = make_shared<View>(model_facade);
  std::unique_ptr controller = make_unique<Controller>(model_facade, view);
  view->show();

  return 0;
}

View::View(std::weak_ptr<ModelFacade> model_facade) : model_facade_(model_facade) {
  model_facade_.lock()->AddObserver(this);
}

void View::show() {
  long command;
  do {
    std::cout << std::endl;
    std::cout << "0 - exit" << std::endl;
    std::cout << "1 - CreateNewDocument" << std::endl;
    std::cout << "2 - CreateGraphicPrimitive" << std::endl;
    std::cout << "3 - ExportDocument" << std::endl;
    std::cout << "4 - ImportDocument" << std::endl;
    std::cout << "5 - RemoveGraphicPrimitive" << std::endl;
    std::cout << "command -> ";

    std::cin >> command;

    switch (command) {
      case 0:
        break;
      case 1:
        NotifyUpdate(Comand::CreateNewDocument);
        break;
      case 2:
        NotifyUpdate(Comand::CreateGraphicPrimitive);
        break;
      case 3:
        NotifyUpdate(Comand::ExportDocument);
        break;
      case 4:
        NotifyUpdate(Comand::ImportDocument);
        break;
      case 5:
        NotifyUpdate(Comand::RemoveGraphicPrimitive);
        break;
      default:
        std::cout << "Not comand " << command << '\n';
    }

  } while (command);
}

void View::UpDate(Comand comand) {
  std::cout << "view update to comand " << static_cast<int>(comand) << std::endl;
}
