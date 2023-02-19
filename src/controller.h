#pragma once

#include <memory>

#include "view.h"

/// @class
/// @brief класс контроллер
///
/// подписан на изменения представления передает их фасаду модели
/// является тонкой прослойкой между gui и фасадом модели
class Controller : public Observer<Comand> {
 public:
  Controller(std::weak_ptr<ModelFacade> model_facade, View* view);

  /// вызывается при обновленеии представления
  void UpDate(Comand comand) override;

 private:
  /// агрегация фасада модели
  std::weak_ptr<ModelFacade> model_facade_;
};
