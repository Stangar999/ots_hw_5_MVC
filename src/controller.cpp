#include "controller.h"

Controller::Controller(std::weak_ptr<ModelFacade> model_facade, View* view)
    : model_facade_(model_facade) {
  if (!view) {
    throw std::invalid_argument("!view");
  }
  view->AddObserver(this);
}

void Controller::UpDate(Comand comand) {
  auto model_facade = model_facade_.lock();
  if (!model_facade) {
    return;
  }
  switch (comand) {
    case Comand::CreateNewDocument:
      model_facade->CreateNewDocument();
      break;
    case Comand::CreateGraphicPrimitive:
      model_facade->CreateGraphicPrimitive();
      break;
    case Comand::ExportDocument:
      model_facade->ExportDocument();
      break;
    case Comand::ImportDocument:
      model_facade->ImportDocument();
      break;
    case Comand::RemoveGraphicPrimitive:
      model_facade->RemoveGraphicPrimitive();
      break;
    default:
      break;
  }
}
