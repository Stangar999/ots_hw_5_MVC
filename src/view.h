#pragma once

#include <memory>

#include "model_facade.h"

/// @class
/// @brief класс активное представление
///
/// уведомляет о изменениях введенных пользователем черз паттерн наблюдатель реализуя слабое
/// связывание также сам подписан на изменения модели что бы обновиться в соответствии с ее
/// изменениями
class View : public Observer<Comand>, public Observered<Comand> {
 public:
  View(std::weak_ptr<ModelFacade> model);
  void show();

 private:
  /// вызывается при обновленеии фасада модели
  void UpDate(Comand comand) override;

 private:
  /// агрегация фасада модели
  std::weak_ptr<ModelFacade> model_facade_;
};
