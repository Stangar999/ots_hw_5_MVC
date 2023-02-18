#include "controller.h"

Controller::Controller(std::weak_ptr<ModelFacade> model_facade, std::weak_ptr<View> view)
    : model_facade_(model_facade), view_(view) {
  view_.lock()->AddObserver(this);
}

void Controller::UpDate(Comand comand) {
  switch (comand) {
    case Comand::CreateNewDocument:
      model_facade_.lock()->CreateNewDocument();
      break;
    case Comand::CreateGraphicPrimitive:
      model_facade_.lock()->CreateGraphicPrimitive();
      break;
    case Comand::ExportDocument:
      model_facade_.lock()->ExportDocument();
      break;
    case Comand::ImportDocument:
      model_facade_.lock()->ImportDocument();
      break;
    case Comand::RemoveGraphicPrimitive:
      model_facade_.lock()->RemoveGraphicPrimitive();
      break;
    default:
      break;
  }
}
