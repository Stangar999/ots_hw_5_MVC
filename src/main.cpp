#include <iostream>
#include <memory>

#include "controller.h"
#include "model_facade.h"
#include "view.h"

using namespace std;

int main() {
  std::shared_ptr model_facade = make_shared<ModelFacade>();
  std::unique_ptr view = make_unique<View>(model_facade);
  std::unique_ptr controller = make_unique<Controller>(model_facade, view.get());
  view->show();

  return 0;
}
