#include "model_facade.h"

ModelFacade::ModelFacade() : model_(std::make_unique<detail::Model>()) {
}

void ModelFacade::CreateNewDocument() {
  model_->CreateNewDocument();
  NotifyUpdate(Comand::CreateNewDocument);
}

void ModelFacade::ImportDocument() {
  model_->ImportDocument();
  NotifyUpdate(Comand::ImportDocument);
}

void ModelFacade::ExportDocument() {
  model_->ExportDocument();
  NotifyUpdate(Comand::ExportDocument);
}

void ModelFacade::CreateGraphicPrimitive() {
  model_->CreateGraphicPrimitive();
  NotifyUpdate(Comand::CreateGraphicPrimitive);
}

void ModelFacade::RemoveGraphicPrimitive() {
  model_->RemoveGraphicPrimitive();
  NotifyUpdate(Comand::RemoveGraphicPrimitive);
}
