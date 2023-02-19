#pragma once
#include <memory>
#include <vector>

#include "model.h"
#include "observer.h"

enum class Comand {
  CreateNewDocument = 1,
  CreateGraphicPrimitive,
  ExportDocument,
  ImportDocument,
  RemoveGraphicPrimitive,
};

/// @class
/// @brief класс фасада модели
///
/// тонкий фасад модели, существует для отделения толстой модели
/// именно с фасад моделью взаимодействует представление и контроллер
/// реализует слабое связывание с помощью наблюдателя
class ModelFacade : public Observered<Comand>, public IModel {
 public:
  ModelFacade();
  void CreateNewDocument() override;
  void ImportDocument() override;
  void ExportDocument() override;
  void CreateGraphicPrimitive() override;
  void RemoveGraphicPrimitive() override;

 private:
  /// композиция доменной модели
  std::unique_ptr<IModel> model_;
};
