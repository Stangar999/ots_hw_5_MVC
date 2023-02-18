#pragma once
#include <memory>
#include <vector>

#include "model.h"

enum class Comand {
  CreateNewDocument = 1,
  CreateGraphicPrimitive,
  ExportDocument,
  ImportDocument,
  RemoveGraphicPrimitive,
};
/// @class
/// @brief класс наблюдатель
class Observer {
 public:
  virtual void UpDate(Comand) = 0;
};

/// @class
/// @brief класс наблюдаемый
class Observered {
 public:
  /// добавить наблюдателя
  void AddObserver(Observer* observer);
  /// уведомить наблюдателей
  void NotifyUpdate(Comand comand);

 private:
  /// наблюдатели
  std::vector<Observer*> observers_;
};

/// @class
/// @brief класс фасада модели
///
/// тонкий фасад модели, существует для отделения толстой модели
/// именно с фасад моделью взаимодействует представление и контроллер
/// реализует слабое связывание с помощью наблюдателя
class ModelFacade : public Observered, public IModel {
 public:
  ModelFacade();
  void CreateNewDocument() override;
  void ImportDocument() override;
  void ExportDocument() override;
  void CreateGraphicPrimitive() override;
  void RemoveGraphicPrimitive() override;

 private:
  /// композиция доменной модели
  std::unique_ptr<detail::Model> model_;
};
