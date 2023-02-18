#include "model_facade.h"

void Observered::AddObserver(Observer* observer) {
  observers_.push_back(observer);
}

void Observered::NotifyUpdate(Comand comand) {
  for (Observer* observer : observers_) {
    if (observer) {
      observer->UpDate(comand);
    }
  }
}

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
